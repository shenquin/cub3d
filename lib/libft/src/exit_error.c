/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 13:46:27 by thgillai          #+#    #+#             */
/*   Updated: 2021/10/19 14:58:58 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	exit_error(char *error_string)
{
	ft_putstr_fd(error_string, 1);
	ft_putstr_fd(", cub3d can't launch.\n", 1);
	system("leaks cub3d");
	exit(0);
}
