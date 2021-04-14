/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 12:49:22 by thgillai          #+#    #+#             */
/*   Updated: 2021/03/15 14:08:11 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void *ft_calloc(size_t count, size_t size)
{
	void *str;

	if (!(str = malloc(size * count)))
		return (NULL);
	ft_bzero(str, size * count);
	if (!str)
		return (NULL);
	return (str);
}
