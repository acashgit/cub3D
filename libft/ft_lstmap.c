/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjodge <mjodge@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:03:59 by mjodge            #+#    #+#             */
/*   Updated: 2022/02/07 19:14:05 by mjodge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*map_elper(t_list *lst, void *(*f)(void *))
{
	t_list	*new_list;
	t_list	*curr_new_list;

	while (lst)
	{
		new_list = ft_lstnew((*f)(lst->value));
		if (new_list)
		{
			lst = lst->next;
			while (lst)
			{
				curr_new_list = ft_lstnew((*f)(lst->value));
				if (curr_new_list)
					ft_lstadd_back(&new_list, curr_new_list);
				else
					return (new_list);
				lst = lst->next;
			}
		}
		else
			return (new_list);
	}
	ft_lstclear(&lst);
	return (new_list);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *))
{
	if (!lst)
		return (lst);
	return (map_elper(lst, f));
}
