/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastrov <acastrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 18:26:54 by alejandro         #+#    #+#             */
/*   Updated: 2025/10/23 19:02:20 by acastrov         ###   ########.fr       */
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

// Delete when not neccesary pls
// int	map_test(t_ctx *ctx)
// {
// 	static char *map[] = {
// 		"11111",
// 		"10001",
// 		"10101",
// 		"10001",
// 		"11111",
// 		NULL
// 	};

// 	ctx->map.grid = map;
// 	ctx->map.h = 5;
// 	ctx->map.w = 5;

// 	for (int y = 0; y < ctx->map.h; y++)
// 		printf("%s\n", ctx->map.grid[y]);

// 	return (0);
// }
