/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:56:57 by pcervill          #+#    #+#             */
/*   Updated: 2022/09/14 17:55:07 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	error(void)
{
	printf("ERROR\nSin argumentos");
}

int	main(int argc, char *argv[])
{
	argv[0] = 0;
	if (argc == 1)
		exit (error);
}
