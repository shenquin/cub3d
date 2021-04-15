/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 16:50:35 by thgillai          #+#    #+#             */
/*   Updated: 2021/04/15 13:43:29 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

void *ft_calloc2(size_t size)
{
	void *str;

	if (!(str = malloc(size)))
		return (NULL);
	ft_bzero(str, size);
	if (!str)
		return (NULL);
	return (str);
}
