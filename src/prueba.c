/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:43:43 by pcervill          #+#    #+#             */
/*   Updated: 2022/10/05 13:37:35 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	leaks(void)
{
	system("leaks -q push_swap");
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

int	main(int argc, char **argv)
{
	int		*number;
	int		i;

	atexit(leaks);
	if (argc > 1)
	{
		i = 0;
		number = NULL;
		number = strnumber(argv, argc);
		while (number[i])
		{
			printf("%d\n", number[i]);
			i++;
		}
	}
}