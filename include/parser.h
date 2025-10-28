/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarquez <smarquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 19:34:35 by acastrov          #+#    #+#             */
/*   Updated: 2025/10/28 18:53:12 by smarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// System libraries
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

// User macros
#define MAX_LINES 50

// parser.c
int	parser_extension(char *filename, int *mapfd);
int parser(char *argv, t_ctx *cube);

// parser_utils.c
void	gnl_cleanup(int fd);
int		print_map(char **map, int height);
int		has_char(const char *str, int start);
char	*pad_map(char *line, int width);
int		normalize_map(t_ctx *cube, char ***map);

//parser_imgs.c
int		get_no(t_ctx *cube, char *temp);
int		get_so(t_ctx *cube, char *temp);
int		get_we(t_ctx *cube, char *temp);
int		get_ea(t_ctx *cube, char *temp);
int		validate_textures(t_ctx *cube);


//parser_cf.c
int		get_f(t_ctx *cube, char *temp);
int		get_c(t_ctx *cube, char *temp);

//parser_map.c
int		store_map(t_ctx *cube, int *mapfd, char *temp);

//parser_free.c
int		exit_parser(int *fd, char *message, int flag);
int		free_grid(char **grid, char *message, int flag);
void	free_paths(t_ctx *cube);

//parser_paths.c
int	validate_textures(t_ctx *cube);
int	parser_xpm_extension(char *filename);


