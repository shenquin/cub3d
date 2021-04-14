/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 13:37:05 by thgillai          #+#    #+#             */
/*   Updated: 2021/03/16 16:22:53 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first;
	t_list	*ele;
	t_list	*prev;

	if (!lst || !f)
		return (NULL);
	first = ft_lstnew(f(lst->content));
	if (!first)
		return (NULL);
	ele = first;
	while (lst->next)
	{
		lst = lst->next;
		prev = ele;
		ele = ft_lstnew(f(lst->content));
		if (ele == NULL)
		{
			ft_lstclear(&first, del);
			return (NULL);
		}
		prev->next = ele;
	}
	ele->next = NULL;
	return (first);
}
