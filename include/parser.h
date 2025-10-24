/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandro <alejandro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 19:34:35 by acastrov          #+#    #+#             */
/*   Updated: 2025/10/24 18:29:27 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// System libraries
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

// User macros
#define MAX_LINES 50

// Functions


// parser_utils.c
void	gnl_cleanup(int	fd);
int		exit_parser(char *temp, int *fd, char *message, int flag);
int		free_grid(char **grid, char *message, int flag);
int		print_map(char **map, int height);


//parser_imgs.c
int		get_no(t_ctx *cube, int	*mapfd, char *temp);
int		get_so(t_ctx *cube, int	*mapfd, char *temp);
int		get_we(t_ctx *cube, int	*mapfd, char *temp);
int		get_ea(t_ctx *cube, int	*mapfd, char *temp);

//parser_cf.c
int		get_f(t_ctx *cube, int *mapfd, char *temp);
int		get_c(t_ctx *cube, int *mapfd, char *temp);

//parser_map.c
int	store_map(t_ctx *cube, int *mapfd, char *temp);