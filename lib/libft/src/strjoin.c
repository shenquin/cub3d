/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 15:49:08 by thgillai          #+#    #+#             */
/*   Updated: 2021/03/15 16:22:17 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char *ft_strjoin(char const *s1, char const *s2)
{
	int i;
	int j;
	int len;
	char *dest;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(dest = malloc((len + 1) * sizeof(char))))
		return (NULL);
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2[j])
		dest[i++] = s2[j++];
	dest[i] = '\0';
	return (dest);
}
