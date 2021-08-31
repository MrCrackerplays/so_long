/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   scaling.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pdruart <pdruart@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/21 02:10:18 by pdruart       #+#    #+#                 */
/*   Updated: 2021/08/31 11:43:20 by pdruart       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALING_H
# define SCALING_H
# include <mlx.h>
# include "canvas_management.h"
typedef struct s_dimensions
{
	int	width;
	int	height;
}	t_dimensions;
typedef struct s_scaling
{
	double	x_ratio;
	double	y_ratio;
	int		px;
	int		py;
}	t_scaling;
t_img	scale(void *mlx, t_img img, t_dimensions from, t_dimensions to);
void	apply_scale(void *mlx, void **img_ptr, t_dimensions from,
			t_dimensions to);

#endif