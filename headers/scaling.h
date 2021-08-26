/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   scaling.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pdruart <pdruart@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/21 02:10:18 by pdruart       #+#    #+#                 */
/*   Updated: 2021/08/24 12:55:52 by pdruart       ########   odam.nl         */
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
t_img	scale(void *mlx, t_img *img, t_dimensions from, t_dimensions to);
void	apply_scale(void *mlx, t_img *img, t_dimensions from, t_dimensions to);

#endif