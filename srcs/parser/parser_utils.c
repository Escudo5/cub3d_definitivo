/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandro <alejandro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 18:26:54 by alejandro         #+#    #+#             */
/*   Updated: 2025/10/22 21:51:11 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "../../include/parser.h"

void	gnl_cleanup(int fd)
{
	char	*temp;

	temp = get_next_line(fd);
	while (temp)
	{
		free(temp);
		temp = get_next_line(fd);
	}
}

int	exit_parser(char *temp, int *fd, char *message, int flag)
{
	ft_putstr_fd(message, 2);
	gnl_cleanup(*fd);
	close(*fd);
	if (temp)
		free(temp);
	return (flag);
}
