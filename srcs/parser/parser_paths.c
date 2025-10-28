/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_paths.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acastrov <acastrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 17:54:00 by acastrov          #+#    #+#             */
/*   Updated: 2025/10/28 18:17:58 by acastrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "../../include/parser.h"

int	parser_xpm_extension(char *filename)
{
	char	*find;
	int		fd;

	find = ft_strnstr(filename, ".xpm", ft_strlen(filename));
	if (!find)
	{
		ft_putstr_fd("Invalid '.xpm' extension\n", STDERR_FILENO);
		return (INPUT_ERROR);
	}
	if (find != ft_strrchr(filename, '.'))
	{
		ft_putstr_fd("Invalid '.xpm' extension\n", STDERR_FILENO);
		return (INPUT_ERROR);
	}
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror("Can't open texture");
		close (fd);
		return (INPUT_ERROR);
	}
	close (fd);
	return (SUCCESS);
}

int	validate_textures(t_ctx *cube)
{
	if (parser_xpm_extension(cube->path.n) != SUCCESS)
		return (INPUT_ERROR);
	if (parser_xpm_extension(cube->path.s) != SUCCESS)
		return (INPUT_ERROR);
	if (parser_xpm_extension(cube->path.w) != SUCCESS)
		return (INPUT_ERROR);
	if (parser_xpm_extension(cube->path.e) != SUCCESS)
		return (INPUT_ERROR);
	return (SUCCESS);
}
