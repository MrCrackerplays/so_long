/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   scaling.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pdruart <pdruart@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/21 02:14:20 by pdruart       #+#    #+#                 */
/*   Updated: 2021/08/26 14:15:17 by pdruart       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/scaling.h"

t_img	scale(void *mlx, t_img *img, t_dimensions from, t_dimensions to)
{
	t_img	scaled;
	double	x_ratio;
	double	y_ratio;
	int		px;
	int		py;
	int		i;
	int		j;
//todo test if works and make norm compliant (if that's even possible)
	x_ratio = from.width / (double) to.width;
	y_ratio = from.height / (double) to.height;
	i = 0;
	scaled.img_ptr = mlx_new_image(mlx, to.width, to.height);
	scaled.address = mlx_get_data_addr(scaled.img_ptr, &scaled.bits_per_pixel, &scaled.line_size, &scaled.endian);
	while (i < to.height) {
		j = 0;
		while (j < to.width) {
			px = (int)(j * x_ratio);
			py = (int)(i * y_ratio);
			// i * img->line_size + j * (img->bits_per_pixel / 8)
			((int *)scaled.address)[(i * to.width) + j] = ((int *)img->address)[(py * from.width) + px];
			j++;
		}
		i++;
	}
	return (scaled);
}

void	apply_scale(void *mlx, t_img *img, t_dimensions from, t_dimensions to)
{
	t_img	scaled;

	scaled = scale(mlx, img, from, to);
	mlx_destroy_image(mlx, img->img_ptr);
	*img = scaled;
}
