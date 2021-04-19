/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgillai <thgillai@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 12:19:53 by thgillai          #+#    #+#             */
/*   Updated: 2021/04/17 17:19:45 by thgillai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cube3d.h"

void	parsing(t_data *data, char *line)
{
	if (line[0] == 'R' && line[1] == ' ')
		res(&line[1], data);
	if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ')
		north(&line[2], data);
	if (line[0] == 'S' && line[1] == 'O' && line[2] == ' ')
		south(&line[2], data);
	if (line[0] == 'W' && line[1] == 'E' && line[2] == ' ')
		west(&line[2], data);
	if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ')
		east(&line[2], data);
	if (line[0] == 'S' && line[1] == ' ')
		sprite(&line[1], data);
	if (line[0] == 'C' && line[1] == ' ')
		ce(&line[1], data);
	if (line[0] == 'F' && line[1] == ' ')
		fl(&line[1], data);
	if (line[0] == '1')
		return ; //à changer et envoyer dans allocmap(&line[0], data);
	/*else
			exit_error("Parsing data error");*/
}

// mlx_xpm_file_to_image <-- regarde si path invalide
// mettre compteur pour ne pas que la map se fasse parsée trop tot
