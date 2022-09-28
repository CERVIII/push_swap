/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:56:57 by pcervill          #+#    #+#             */
/*   Updated: 2022/09/28 17:23:42 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	fillstack(char **argv, t_list stack_a)
{
	int	i;

	i = 0;
	while (argv[i] != '\0')
	{
		stack_a = *ft_lstnew(argv[i]);
		i++;
	}
}

void	init_struct(t_list *stack_a)
{
	stack_a->content = 0;
}

int	main(int argc, char *argv[])
{
	t_list	stack_a;
//	t_list	stack_b;

	if (argc > 1)
	{
		init_struct(&stack_a);
		fillstack(argv, stack_a);
	}
	return (0);
}
