/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listadd_back.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 12:51:33 by thgillai          #+#    #+#             */
/*   Updated: 2021/03/16 13:07:44 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *back;

	back = *alst;
	if (*alst)
	{
		while (back->next != NULL)
			back = back->next;
		back->next = new;
	}
	else
		*alst = new;
}
