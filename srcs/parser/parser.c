/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandro <alejandro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 19:48:01 by acastrov          #+#    #+#             */
/*   Updated: 2025/10/22 21:50:35 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "../../include/parser.h"

int	parser_extension(char *filename, int *mapfd)
{
	char	*find;

	find = ft_strnstr(filename, ".cub", ft_strlen(filename));
	if (!find)
	{
		ft_putstr_fd("Invalid '.cub' extension", STDERR_FILENO);
		return (INPUT_ERROR);
	}
	if (find != ft_strrchr(filename, '.'))
	{
		ft_putstr_fd("Invalid '.cub' extension", STDERR_FILENO);
		return (INPUT_ERROR);
	}
	*mapfd = open(filename, O_RDONLY);
	if (*mapfd < 0)
	{
		perror("Can't open map");
		return (INPUT_ERROR);
	}
	return (SUCCESS);
}

int	store_imgs(t_ctx *cube, int *mapfd)
{
	if (get_no(cube, mapfd) != SUCCESS)
		return (INPUT_ERROR);
	if (get_so(cube, mapfd) != SUCCESS)
		return (INPUT_ERROR);
	if (get_we(cube, mapfd) != SUCCESS)
		return (INPUT_ERROR);
	if (get_ea(cube, mapfd) != SUCCESS)
		return (INPUT_ERROR);
	ft_putstr_fd("Textures path ok\n", 2);
	return (SUCCESS);
}

int	store_cf(t_ctx *cube, int *mapfd)
{
	if (get_f(cube, mapfd) != SUCCESS)
		return (INPUT_ERROR);
	if (get_C(cube, mapfd) != SUCCESS)
		return (INPUT_ERROR);
	return (SUCCESS);
}

// int	parser_clean_map(char *filename, t_map *map)
// {
// 	int		mapfd;
// 	char	*temp;

// 	mapfd = open(filename, O_RDONLY);
// 	temp = ft_strtrim(get_next_line(mapfd));
// 	if (temp == NULL){
// 		close(mapfd);
// 		return (INPUT_ERROR);
// 	}
// 	map->height = 1;
// 	map->width = ft_strlen(temp);
// 	while (temp)
// }

int	parser(char *argv, t_ctx *cube)
{
	int		mapfd;

	if (parser_extension(argv, &mapfd) != SUCCESS)
		return (INPUT_ERROR);
	if (store_imgs(cube, &mapfd) != SUCCESS)
		return (INPUT_ERROR);
	if (store_cf(cube, &mapfd) != SUCCESS)
		return (INPUT_ERROR);
	// map = malloc(sizeof(t_map));
	// if (!map)
	// 	return (MALLOC_ERROR);
	// if (parser_store_map(argv[1], &map) != SUCCESS)
	// {
	// 	free(map);
	// 	return (INPUT_ERROR);
	// }
	// cube->map = map;
	gnl_cleanup(mapfd);
	ft_putstr_fd("Textures path ok\n", 2);
	close(mapfd);
	return (SUCCESS);
}

int	main(int argc, char **argv)
{
	t_ctx	*cube;

	if (argc != 2 || !argv[1])
	{
		ft_printf("Incorrect number of arguments\n");
		return (SUCCESS);
	}
	cube = ft_calloc(1, sizeof(t_ctx));
	if (!cube)
		return (MALLOC_ERROR);
	if (parser(argv[1], cube) != SUCCESS)
	{
		free(cube->tex_north.addr);
		free(cube->tex_south.addr);
		free(cube->tex_west.addr);
		free(cube->tex_east.addr);
		free(cube);
		return (INPUT_ERROR);
	}
	// free(cube->map);
	free(cube->tex_north.addr);
	free(cube->tex_south.addr);
	free(cube->tex_west.addr);
	free(cube->tex_east.addr);
	free(cube);
	return (SUCCESS);
}
