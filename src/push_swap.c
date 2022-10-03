/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:56:57 by pcervill          #+#    #+#             */
/*   Updated: 2022/10/03 15:42:32 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	leaks(void)
{
	system("leaks push_swap");
}

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

void	*fillstack(char **argv, t_stack *stack_a)
{
	int	i;
	int	number;

	number = 0;
	i = 1;
	while (argv[i])
	{
		number = ft_atoi(argv[i]);
		stack_a = addnumber(stack_a, number);
		i++;
	}
	return (stack_a);
}

/* t_stack	*initstack(t_stack *stack_a)
{
	stack_a = NULL;
	return (stack_a);
} */

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

/* void	ft_stackdelone(t_stack *stack_a, void (*del) (void *))
{
	if (!stack_a)
		return ;
	del((void *)stack_a->content);
	free(stack_a);
} */

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	int		i;

	atexit(leaks);
	i = 0;
	stack_a = NULL;
	if (argc > 1)
	{
		stack_a = fillstack(argv, stack_a);
		printf("Total numeros: %d\n", ft_stacksize(stack_a));
	}
	while (stack_a)
	{
		printf("   %d\n", stack_a->content);
		stack_a = stack_a->next;
	}
	printf("-------	-------\nSTACK A	STACK B\n");
	return (0);
}
