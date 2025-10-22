/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandro <alejandro@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 19:34:35 by acastrov          #+#    #+#             */
/*   Updated: 2025/10/22 18:58:19 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// System libraries
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

// Functions


// parser_utils.c
void	gnl_cleanup(int	fd);

//parser_imgs.c
int	get_NO(t_ctx *cube, int	*map_fd);
int	get_SO(t_ctx *cube, int	*map_fd);
int	get_WE(t_ctx *cube, int	*map_fd);
int	get_EA(t_ctx *cube, int	*map_fd);