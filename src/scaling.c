/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   scaling.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pdruart <pdruart@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/21 02:14:20 by pdruart       #+#    #+#                 */
/*   Updated: 2021/08/31 11:46:59 by pdruart       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/scaling.h"

t_img	scale(void *mlx, t_img img, t_dimensions from, t_dimensions to)
{
	t_img		scaled;
	t_scaling	info;
	int			i;
	int			j;

	info.x_ratio = from.width / (double) to.width;
	info.y_ratio = from.height / (double) to.height;
	i = 0;
	scaled.img_ptr = mlx_new_image(mlx, to.width, to.height);
	scaled.address = mlx_get_data_addr(scaled.img_ptr, &scaled.bits_per_pixel,
			&scaled.line_size, &scaled.endian);
	while (i < to.height)
	{
		j = 0;
		while (j < to.width)
		{
			info.px = (int)(j * info.x_ratio);
			info.py = (int)(i * info.y_ratio);
			((int *)scaled.address)[(i * to.width) + j]
				= ((int *)img.address)[(info.py * from.width) + info.px];
			j++;
		}
		i++;
	}
	return (scaled);
}

void	apply_scale(void *mlx, void **img_ptr, t_dimensions from,
	t_dimensions to)
{
	t_img	scaled;
	t_img	img;

	img = sl_image_from_ximage(*img_ptr);
	scaled = scale(mlx, img, from, to);
	mlx_destroy_image(mlx, *img_ptr);
	*img_ptr = scaled.img_ptr;
}
