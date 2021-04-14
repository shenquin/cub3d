/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsingchaîné.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 14:41:04 by thgillai          #+#    #+#             */
/*   Updated: 2021/04/13 13:31:04 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

t_list	*parsing(char *file)
{
	int		fd;
	char	*line;
	t_list	*content;
	t_list	*list;

	fd = open(file, O_RDONLY);
	list = NULL;
	while ((get_next_line(fd, &line)) >= 0)
	{
		content = ft_lstnew(line);
		ft_lstadd_back(&list, content);
	}
	return (list);
}
