/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pdruart <pdruart@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/19 10:48:08 by pdruart       #+#    #+#                 */
/*   Updated: 2021/08/26 14:29:50 by pdruart       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <mlx.h>
#include "../headers/so_long.h"
#include "../headers/shutdown.h"
#include "../headers/assets.h"
#include "../headers/sl_rendering.h"

int	closure(t_application *application)
{
	mlx_destroy_image(application->mlx, application->canvas);
	mlx_destroy_image(application->mlx, application->tileset);
	mlx_destroy_image(application->mlx, application->spritesheet);
	mlx_destroy_window(application->mlx, application->win);
	exit(0);
	return (1);
}

int	key_hook(int keycode, t_application *application)
{
	if (keycode == application->keys.exit)
		return (closure(application));
	else if (application->gamestate.exited)
	{
		printf("You've already finished with a move count of %i!\n",
			application->gamestate.moves);
		return (0);
	}
	else if (keycode == application->keys.up)
		move_player(&application->gamestate, UP);
	else if (keycode == application->keys.down)
		move_player(&application->gamestate, DOWN);
	else if (keycode == application->keys.left)
		move_player(&application->gamestate, LEFT);
	else if (keycode == application->keys.right)
		move_player(&application->gamestate, RIGHT);
	else
		return (0);
	render(application);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_application	application;

	if (argc != 2)
		call_error("Incorrect amount of arguments\n");
	application.mlx = mlx_init();
	setup_state(&application.gamestate, argv[1]);
	application.win = mlx_new_window(application.mlx,
			SPRITE_WIDTH * application.gamestate.map.width,
			SPRITE_HEIGHT * application.gamestate.map.height,
			"So long! Bearly any gold.");
	application.keys = get_keys();
	load_assets(&application);
	mlx_hook(application.win, 2, 1L << 0, key_hook, &application);
	if (LINUX == 1)
		mlx_hook(application.win, 33, 0, closure, &application);
	else
		mlx_hook(application.win, 17, 1l << 17, closure, &application);
	render(&application);
	mlx_string_put(application.mlx, application.win, 10, 20, (int)0X00FFFFFF,
		"Collect gold and go to the flags!");
	printf("Collect gold and go to the flags!\n");
	mlx_loop(application.mlx);
}
