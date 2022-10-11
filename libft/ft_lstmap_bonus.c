/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 13:37:35 by pcervill          #+#    #+#             */
/*   Updated: 2022/10/04 12:58:42 by pcervill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, int (*f)(int), void (*del)(int))
{
	t_list	*new;
	t_list	*lstcp;
	int		lstcont;

	if (!lst)
		return (NULL);
	lstcp = NULL;
	while (lst)
	{
		lstcont = (*f)(lst->content);
		if (lstcont)
		{
			new = ft_lstnew(lstcont);
			if (!new)
			{
				del(lstcont);
				ft_lstclear(lstcp);
				return (NULL);
			}
			ft_lstadd_back(lstcp, new);
			lst = lst -> next;
		}
	}
	return (lstcp);
}
