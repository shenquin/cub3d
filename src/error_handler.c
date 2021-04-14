/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 13:43:33 by thgillai          #+#    #+#             */
/*   Updated: 2021/04/13 13:47:54 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

void	exit_error(char *error_string)
{
	ft_putstr_fd(error_string, 1);
	ft_putchar_fd('\n', 1);
	exit(0);
}
