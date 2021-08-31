/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_rendering.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pdruart <pdruart@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/19 15:01:41 by pdruart       #+#    #+#                 */
/*   Updated: 2021/08/31 14:15:55 by pdruart       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "../headers/canvas_management.h"
#include "../headers/sl_rendering.h"

t_boundaries	player_sprite_bounds(t_application *application)
{
	t_boundaries	boundaries;

	boundaries.height = SPRITE_HEIGHT;
	boundaries.width = SPRITE_WIDTH;
	boundaries.x_origin = SPRITE_WIDTH * (application->gamestate.moves % 4)
		+ (application->gamestate.map.player.type * 4 * SPRITE_WIDTH);
	boundaries.y_origin = SPRITE_HEIGHT
		* application->gamestate.map.player.facing;
	return (boundaries);
}

void	render_player(t_application *application)
{
	t_img	canvas;
	t_img	spritesheet;

	canvas = sl_image_from_ximage(application->canvas);
	spritesheet = sl_image_from_ximage(application->spritesheet);
	sl_combine_image(&canvas, (t_position){
		((int)(application->gamestate.map.player.x)) * SPRITE_WIDTH,
		((int)(application->gamestate.map.player.y)) * SPRITE_HEIGHT},
		&spritesheet,
		player_sprite_bounds(application));
}

void	render(t_application *application)
{
	render_map(application);
	render_player(application);
	mlx_clear_window(application->mlx, application->win);
	mlx_put_image_to_window(application->mlx, application->win,
		application->canvas, 0, 0);
}
