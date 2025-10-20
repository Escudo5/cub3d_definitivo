/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarquez <smarquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 18:41:06 by acastrov          #+#    #+#             */
/*   Updated: 2025/05/07 17:08:57 by smarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// Call to write with variable file descriptor
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
