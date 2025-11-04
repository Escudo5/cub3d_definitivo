/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastrov <acastrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 19:48:01 by acastrov          #+#    #+#             */
/*   Updated: 2025/11/04 16:11:35 by acastrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "../../include/parser.h"

int	parser_extension(char *filename, int *mapfd)
{
	size_t	len;

	len = ft_strlen(filename);
	if (len < 4 || ft_strncmp(filename + len - 4, ".cub", 4) != 0)
	{
		ft_putstr_fd("Invalid '.cub' extension\n", STDERR_FILENO);
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

int	store_imgs(t_ctx *cube, char *temp)
{
	if (!ft_strchr("NSWE", *temp))
		return (INPUT_ERROR);
	if (get_no(cube, temp) != SUCCESS)
		return (INPUT_ERROR);
	if (get_so(cube, temp) != SUCCESS)
		return (INPUT_ERROR);
	if (get_we(cube, temp) != SUCCESS)
		return (INPUT_ERROR);
	if (get_ea(cube, temp) != SUCCESS)
		return (INPUT_ERROR);
	return (SUCCESS);
}

int	store_cf(t_ctx *cube, char *temp)
{
	if (!ft_strchr("CF", *temp))
		return (INPUT_ERROR);
	if (get_f(cube, temp) != SUCCESS)
		return (INPUT_ERROR);
	if (get_c(cube, temp) != SUCCESS)
		return (INPUT_ERROR);
	return (SUCCESS);
}

int	parser(char *argv, t_ctx *cube)
{
	int		mapfd;
	char	*temp;

	if (parser_extension(argv, &mapfd) != SUCCESS)
		return (INPUT_ERROR);
	temp = get_next_line(mapfd);
	if (!temp)
		return (exit_parser(&mapfd, "Empty file\n", INPUT_ERROR));
	while (temp)
	{
		if (temp[0] == '\n')
			;
		else if (store_imgs(cube, temp) == SUCCESS || store_cf(cube,
				temp) == SUCCESS)
			;
		else if (ft_strcharset(temp, " 01NSEW") == SUCCESS)
			break ;
		else
			return (exit_parser(&mapfd, "Invalid file\n", INPUT_ERROR));
		free(temp);
		temp = get_next_line(mapfd);
	}
	if (store_map(cube, &mapfd, temp) != SUCCESS)
		return (exit_parser(&mapfd, "Invalid map\n", INPUT_ERROR));
	return (exit_parser(&mapfd, "", SUCCESS));
}

// int	main(int argc, char **argv)
// {
// 	t_ctx	*cube;

// 	if (argc != 2 || !argv[1])
// 	{
// 		ft_printf("Incorrect number of arguments\n");
// 		return (SUCCESS);
// 	}
// 	cube = ft_calloc(1, sizeof(t_ctx));
// 	if (!cube)
// 		return (MALLOC_ERROR);
// 	if (parser(argv[1], cube) != SUCCESS)
// 	{
// 		free_paths(cube);
// 		free(cube);
// 		return (INPUT_ERROR);
// 	}
// 	printf("Player orientation %c\n", cube->player_start.orientation);
// 	printf("Player position y: %d\n and x: %d\n",
// 		cube->player_start.y, cube->player_start.x);
// 	free_paths(cube);
// 	free(cube);
// 	return (SUCCESS);
// }
