/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memccpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 12:40:38 by thgillai          #+#    #+#             */
/*   Updated: 2021/03/15 14:17:58 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void *ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;

	i = 0;
	s1 = (unsigned char*)dest;
	s2 = (unsigned char*)src;
	while (i < n)
	{
		s1[i] = s2[i];
		if ((unsigned char)c == s1[i])
			return ((void*)(s1 + i + 1));
		i++;
	}
	return (NULL);
}
