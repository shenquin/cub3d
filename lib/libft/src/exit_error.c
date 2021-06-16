/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 13:46:27 by thgillai          #+#    #+#             */
/*   Updated: 2021/04/30 13:46:56 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	exit_error(char *error_string)
{
	ft_putstr_fd(error_string, 1);
	ft_putstr_fd(", cub3d can't launch.\n", 1);
	exit(0);
}