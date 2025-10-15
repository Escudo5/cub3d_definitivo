/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarquez <smarquez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:18:43 by smarquez          #+#    #+#             */
/*   Updated: 2025/10/15 17:05:29 by smarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	main(void)
{
	void *mlx_init();
	void *mlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title);
	void *mlx_new_image(void *mlx_ptr, int width, int height);
	char *mlx_get_data_addr(void *img_ptr, int *bits_per_pixel, int *size_line,
		int *endian);
	int mls_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr,
		int x, int y);
	int mlx_loop(void *mlx_ptr);
	int mlx_hook(void *win_ptr, int x_event, int x_mask, int (*funct)(),
		void *param);
	int mlx_loop_hook(void *mlx_ptr, int (*funct_ptr)(), void *param);
}
