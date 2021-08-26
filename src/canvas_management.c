/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   canvas_management.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: pdruart <pdruart@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/19 12:43:10 by pdruart       #+#    #+#                 */
/*   Updated: 2021/08/26 14:13:39 by pdruart       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "../headers/canvas_management.h"

t_img	sl_image_from_ximage(void *img_ptr)
{
	t_img	image;

	image.img_ptr = img_ptr;
	image.address = mlx_get_data_addr(image.img_ptr, &image.bits_per_pixel,
			&image.line_size, &image.endian);
	return (image);
}

void	sl_pixel_put(t_img *img, int x, int y, unsigned int color)
{
	char	*dst;
	int		offset;

	if (color == 0xFF000000)
		return ;
	offset = y * img->line_size + x * (img->bits_per_pixel / 8);
	dst = img->address + offset;
	*(unsigned int *)dst = color;
}

unsigned int	sl_get_color(t_img *img, int x, int y)
{
	char	*dst;
	int		offset;

	offset = y * img->line_size + x * (img->bits_per_pixel / 8);
	dst = img->address + offset;
	return (*((unsigned int *)dst));
}

void	sl_combine_image(t_img *canvas, t_position pos, t_img *img,
		t_boundaries boundaries)
{
	int	x;
	int	y;

	y = 0;
	while (y < boundaries.height)
	{
		x = 0;
		while (x < boundaries.width)
		{
			sl_pixel_put(canvas, x + pos.x, y + pos.y, sl_get_color(img,
					x + boundaries.x_origin, y + boundaries.y_origin));
			x++;
		}
		y++;
	}
}
