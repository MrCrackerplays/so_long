/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   assets.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pdruart <pdruart@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/21 02:55:56 by pdruart       #+#    #+#                 */
/*   Updated: 2021/08/31 11:39:58 by pdruart       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stddef.h>
#include "../headers/assets.h"
#include "../headers/scaling.h"
#include "../headers/shutdown.h"

void	setup_canvas(t_application *application)
{
	application->canvas = mlx_new_image(application->mlx,
			SPRITE_WIDTH * application->gamestate.map.width,
			SPRITE_HEIGHT * application->gamestate.map.height);
}

void	load_assets(t_application *application)
{
	t_dimensions	ss_dim;
	t_dimensions	ts_dim;

	application->spritesheet = mlx_xpm_file_to_image(application->mlx,
			"assets/spritesheet.xpm", &ss_dim.width, &ss_dim.height);
	if (application->spritesheet == NULL)
		call_error("Failed to load spritesheet.xpm\n");
	application->tileset = mlx_xpm_file_to_image(application->mlx,
			"assets/tileset.xpm", &ts_dim.width, &ts_dim.height);
	if (application->tileset == NULL)
		call_error("Failed to load tileset.xpm\n");
	if (SPRITE_HEIGHT != 16 || SPRITE_WIDTH != 16)
	{
		apply_scale(application->mlx, &application->spritesheet, ss_dim,
			(t_dimensions){ss_dim.width * SPRITE_WIDTH / 16, ss_dim.height
			* SPRITE_HEIGHT / 16});
		apply_scale(application->mlx, &application->tileset, ts_dim,
			(t_dimensions){ts_dim.width * SPRITE_WIDTH / 16, ts_dim.height
			* SPRITE_HEIGHT / 16});
	}
	setup_canvas(application);
}
