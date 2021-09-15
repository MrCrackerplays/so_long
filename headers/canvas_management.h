/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   canvas_management.h                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: pdruart <pdruart@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/19 11:56:57 by pdruart       #+#    #+#                 */
/*   Updated: 2021/09/15 15:03:34 by pdruart       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CANVAS_MANAGEMENT_H
# define CANVAS_MANAGEMENT_H

typedef struct s_img
{
	void	*img_ptr;
	char	*address;
	int		bits_per_pixel;
	int		line_size;
	int		endian;
}	t_img;

typedef struct s_position
{
	int	x;
	int	y;
}	t_position;

typedef struct s_boundaries
{
	int	x_origin;
	int	y_origin;
	int	width;
	int	height;
}	t_boundaries;

t_img			sl_image_from_ximage(void *img_ptr);
void			sl_pixel_put(t_img *img, int x, int y, unsigned int colour);
unsigned int	sl_get_color(t_img *img, int x, int y);
void			sl_combine_image(t_img *canvas, t_position pos, t_img *img,
					t_boundaries boundaries);

#endif