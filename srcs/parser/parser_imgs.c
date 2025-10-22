/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_imgs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandro <alejandro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 18:34:47 by alejandro         #+#    #+#             */
/*   Updated: 2025/10/22 21:50:02 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include "../../include/parser.h"

int	get_no(t_ctx *cube, int	*mapfd)
{
	char	*temp;

	temp = get_next_line(*mapfd);
	if (temp == NULL)
		return (exit_parser(NULL, mapfd, "No GNL\n", INPUT_ERROR));
	if (ft_strncmp(temp, "NO ", 3))
		return (exit_parser(temp, mapfd, "Invalid NO\n", INPUT_ERROR));
	cube->tex_north.addr = ft_strtrim(temp + 3, " \t\n");
	free(temp);
	ft_printf("%s\n", cube->tex_north.addr);
	return (SUCCESS);
}

int	get_so(t_ctx *cube, int	*mapfd)
{
	char	*temp;

	temp = get_next_line(*mapfd);
	if (temp == NULL)
		return (exit_parser(NULL, mapfd, "No GNL\n", INPUT_ERROR));
	if (ft_strncmp(temp, "SO ", 3))
		return (exit_parser(temp, mapfd, "Invalid SO\n", INPUT_ERROR));
	cube->tex_south.addr = ft_strtrim(temp + 3, " \t\n");
	free(temp);
	ft_printf("%s\n", cube->tex_south.addr);
	return (SUCCESS);
}

int	get_we(t_ctx *cube, int	*mapfd)
{
	char	*temp;

	temp = get_next_line(*mapfd);
	if (temp == NULL)
		return (exit_parser(NULL, mapfd, "No GNL\n", INPUT_ERROR));
	if (ft_strncmp(temp, "WE ", 3))
		return (exit_parser(temp, mapfd, "Invalid WE\n", INPUT_ERROR));
	cube->tex_west.addr = ft_strtrim(temp + 3, " \t\n");
	free(temp);
	ft_printf("%s\n", cube->tex_west.addr);
	return (SUCCESS);
}

int	get_ea(t_ctx *cube, int	*mapfd)
{
	char	*temp;

	temp = get_next_line(*mapfd);
	if (temp == NULL)
		return (exit_parser(NULL, mapfd, "No GNL\n", INPUT_ERROR));
	if (ft_strncmp(temp, "EA ", 3))
		return (exit_parser(temp, mapfd, "Invalid EA\n", INPUT_ERROR));
	cube->tex_east.addr = ft_strtrim(temp + 3, " \t\n");
	free(temp);
	ft_printf("%s\n", cube->tex_east.addr);
	return (SUCCESS);
}
