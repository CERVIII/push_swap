/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:56:57 by pcervill          #+#    #+#             */
/*   Updated: 2022/10/10 17:50:04 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	leaks(void)
{
	system("leaks -q push_swap");
}

void	checkparams(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if ((argv[i][j] < 48 || argv[i][j] > 57) && argv[i][j] != 45)
			{
				printf("%sERROR:\nArgumentos no validos%s\n", RED, NORMAL);
				exit (1);
			}
			if (argv[i][j + 1] == 45)
			{
				printf("%sERROR:\nArgumentos no validos%s\n", RED, NORMAL);
				exit (1);
			}
			j++;
		}
		i++;
	}
	return ;
}

int	*strnumber(char **argv, int argc)
{
	int	*number;
	int	i;
	int	j;

	number = (int *) malloc(argc * sizeof(int));
	if (!number)
		return (0);
	i = 1;
	j = 0;
	while (argv[i])
	{
		number[j++] = ft_atoi(argv[i++]);
	}
	number[j] = '\0';
	free(number);
	return (number);
}

void	norepeat(int *number)
{
	int	i;
	int	j;

	i = 0;
	while (number[i])
	{
		j = i + 1;
		while (number[j])
		{
			if (number[i] == number[j])
			{
				printf("%sERROR:\nArgumentos repetidos%s\n", RED, NORMAL);
				exit (1);
			}
			j++;
		}
		i++;
	}
	return ;
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	int		i;
	int		*number;

	atexit(leaks);
	stack_a = NULL;
	if (argc > 1)
	{
		checkparams(argv);
		number = strnumber(argv, argc);
		printf("Total numeros: %d\n", ft_stacksize(stack_a));
		i = 0;
		/* while (number[i])
		{
			stack_a = addnumber(stack_a, number[i++]);
		} */
		while (stack_a)
		{
			printf("   %d\n", stack_a->content);
			stack_a = stack_a->next;
		}
		printf("-------	-------\nSTACK A	STACK B\n");
		//stack_a = freestack(stack_a);
	}
	return (0);
}
