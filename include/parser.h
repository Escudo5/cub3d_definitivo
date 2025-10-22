/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandro <alejandro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 19:34:35 by acastrov          #+#    #+#             */
/*   Updated: 2025/10/22 21:49:08 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// System libraries
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

// Functions


// parser_utils.c
void	gnl_cleanup(int	fd);
int		exit_parser(char *temp, int *fd, char *message, int flag);

//parser_imgs.c
int		get_no(t_ctx *cube, int	*mapfd);
int		get_so(t_ctx *cube, int	*mapfd);
int		get_we(t_ctx *cube, int	*mapfd);
int		get_ea(t_ctx *cube, int	*mapfd);

//parser_cf.c
int		get_f(t_ctx *cube, int *mapfd);
int		get_c(t_ctx *cube, int *mapfd);