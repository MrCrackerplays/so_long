/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_rendering_map.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: pdruart <pdruart@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/25 12:53:43 by pdruart       #+#    #+#                 */
/*   Updated: 2021/08/26 14:16:05 by pdruart       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/canvas_management.h"
#include "../headers/sl_rendering.h"

t_boundaries	tile_in_row(int rand, int row, int row_width)
{
	t_boundaries	boundaries;

	boundaries.height = SPRITE_HEIGHT;
	boundaries.width = SPRITE_WIDTH;
	boundaries.y_origin = row * SPRITE_HEIGHT;
	boundaries.x_origin = (rand % row_width) * SPRITE_WIDTH;
	return (boundaries);
}

void	background(t_application *application)
{
	unsigned int	x;
	unsigned int	y;
	t_img			canvas;
	t_img			tileset;

	y = 0;
	canvas = sl_image_from_ximage(application->canvas);
	tileset = sl_image_from_ximage(application->tileset);
	while (y < application->gamestate.map.height)
	{
		x = 0;
		while (x < application->gamestate.map.width)
		{
			sl_combine_image(&canvas, (t_position){(int)x * SPRITE_WIDTH, (int)y
				* SPRITE_HEIGHT}, &tileset,
				tile_in_row(application->gamestate.map.random_data[x + y
					* (application->gamestate.map.width)], 0, 4));
			x++;
		}
		y++;
	}
}

t_boundaries	tile_boundary(t_application *application, unsigned int x,
		unsigned int y)
{
	t_tile				tile;
	t_boundaries		boundaries;
	const static int	width[5] = {6, 6, 1, 1, 2};

	tile = get_tile_at(application->gamestate.map, x, y);
	boundaries = tile_in_row(application->gamestate.map.random_data[x + y
			* (application->gamestate.map.width)], tile + 1, width[tile]);
	if (tile == WALL && (x > 0 && x < application->gamestate.map.width - 1
			&& y > 0 && y < application->gamestate.map.height - 1))
		boundaries.x_origin += 4 * SPRITE_WIDTH;
	return (boundaries);
}

void	map_tiles(t_application *application)
{
	unsigned int	x;
	unsigned int	y;
	t_img			canvas;
	t_img			tileset;

	y = 0;
	canvas = sl_image_from_ximage(application->canvas);
	tileset = sl_image_from_ximage(application->tileset);
	while (y < application->gamestate.map.height)
	{
		x = 0;
		while (x < application->gamestate.map.width)
		{
			if (get_tile_at(application->gamestate.map, x, y) != EMPTY
				|| (application->gamestate.map.random_data[x + y
						* (application->gamestate.map.width)] % 4) == 0)
				sl_combine_image(&canvas, (t_position){
					(int)x * SPRITE_WIDTH,
					(int)y * SPRITE_HEIGHT},
					&tileset,
					tile_boundary(application, x, y));
			x++;
		}
		y++;
	}
}

void	render_map(t_application *application)
{
	background(application);
	map_tiles(application);
}
