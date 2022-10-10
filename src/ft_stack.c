/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:12:00 by pcervill          #+#    #+#             */
/*   Updated: 2022/10/10 17:41:53 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_stacksize(t_stack *stack_a)
{
	int	i;

	i = 0;
	while (stack_a)
	{
		i++;
		stack_a = stack_a->next;
	}
	return (i);
}

t_stack	*addnumber(t_stack *stack_a, int number)
{
	t_stack	*newnumber;
	t_stack	*aux;

	aux = (t_stack *) malloc(sizeof(t_stack));
	newnumber = (t_stack *) malloc(sizeof(t_stack));
	newnumber->content = number;
	newnumber->next = NULL;
	if (stack_a == NULL)
		stack_a = newnumber;
	else
	{
		aux = stack_a;
		while (aux->next)
			aux = aux->next;
		aux->next = newnumber;
	}
	return (stack_a);
}

t_stack	*freestack(t_stack *stack_a)
{
	t_stack	*cpy;
	t_stack	*aux;

	cpy = stack_a;
	while (!cpy)
	{
		aux = cpy->next;
		free(cpy);
		cpy = aux;
	}
	stack_a = NULL;
	return (stack_a);
}
