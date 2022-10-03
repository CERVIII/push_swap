/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:43:22 by pcervill          #+#    #+#             */
/*   Updated: 2022/10/03 18:10:51 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
				printf("ERROR:\nParametros incorrectos\n");
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

	number = malloc((argc - 1) * sizeof(int));
	i = 1;
	if (argc > 1)
	{
		checkparams(argv);
		//number[i] = ft_atoi(argv[i]);
		number[i] = atoi(argv[i]);
		stack_a = ft_lstnew(&number[i]);
		i = 2;
		while (argv[i])
		{
			//number[i] = ft_atoi(argv[i]);
			number[i] = atoi(argv[i]);
			ft_lstadd_back(&stack_a, ft_lstnew(&number[i]));
			i++;
		}
		printf("Total de numeros: %d\n", ft_lstsize(stack_a));
		while (stack_a)
		{
			printf("   %d\n", *(int *) stack_a->content);
			stack_a = stack_a->next;
		}
	}
	return (0);
}
