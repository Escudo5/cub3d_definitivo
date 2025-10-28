/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastrov <acastrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 18:26:54 by alejandro         #+#    #+#             */
/*   Updated: 2025/10/28 18:18:08 by acastrov         ###   ########.fr       */
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

int	print_map(char **map, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		ft_putendl_fd(map[i], 1);
		i++;
	}
	return (0);
}

int	has_char(const char *str, int start)
{
	int	i;

	i = start;
	while (str[i])
	{
		if (ft_strchr("01NSEW", str[i]))
			return (1);
		i++;
	}
	return (0);
}

char	*pad_map(char *line, int width)
{
	int		len;
	int		i;
	char	*new_line;

	len = ft_strlen(line);
	new_line = malloc(width + 1);
	if (!new_line)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new_line[i] = line[i];
		i++;
	}
	new_line[i] = 'Z';
	i++;
	while (i < width)
	{
		new_line[i] = ' ';
		i++;
	}
	new_line[i] = '\0';
	free(line);
	return (new_line);
}

int	normalize_map(t_ctx *cube, char ***map)
{
	int	max_len;
	int	i;

	max_len = 0;
	i = 0;
	while (i < cube->map.h)
	{
		if (ft_strlen((*map)[i]) > max_len)
			max_len = ft_strlen((*map)[i]);
		i++;
	}
	cube->map.w = max_len;
	i = 0;
	while (i < cube->map.h)
	{
		if (ft_strlen((*map)[i]) < cube->map.w)
			(*map)[i] = pad_map((*map)[i], cube->map.w);
		i++;
	}
	return (SUCCESS);
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
