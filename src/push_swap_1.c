/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:43:22 by pcervill          #+#    #+#             */
/*   Updated: 2022/10/05 13:48:39 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/* static void	leaks(void)
{
	system("leaks -q push_swap");
} */

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
		j = 0;
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

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	int		*number;
	int		i;

	//atexit(leaks);
	if (argc > 1)
	{
		stack_a = NULL;
		number = NULL;
		checkparams(argv);
		number = strnumber(argv, argc);
		norepeat(number);
		i = 1;
		while (number[i])
		{
			if (!stack_a)
			{
				stack_a = ft_lstnew(number[i]);
				free(stack_a);
			}
			else
			{
				ft_lstadd_back(stack_a, ft_lstnew(number[i]));
				free(stack_a);
			}
			i++;
		}
		while (stack_a)
		{
			printf("%d\n", stack_a->content);
			stack_a = stack_a->next;
		}
	}
	return (0);
}
