/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   game.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pdruart <pdruart@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/18 13:13:08 by pdruart       #+#    #+#                 */
/*   Updated: 2021/08/26 14:14:52 by pdruart       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../headers/game.h"

void	attempt_collect(t_gamestate *state)
{
	t_player	player;

	player = state->map.player;
	if (get_tile_at(state->map, player.x, player.y) != COLLECTIBLE)
		return ;
	state->map.data[player.x + player.y * state->map.width] = '0';
	state->map.player.score++;
}

void	attempt_exit(t_gamestate *state)
{
	t_player	player;

	player = state->map.player;
	if (get_tile_at(state->map, player.x, player.y) != EXIT
		|| player.score != state->map.collectibles)
		return ;
	state->exited = 1;
	printf("Congratulations! You managed to exit with %i moves!\n",
		state->moves);
}

void	move_player(t_gamestate *state, t_direction direction)
{
	t_map	*map;

	if (state == NULL)
		return ;
	map = &state->map;
	state->moves++;
	map->player.facing = direction;
	if (direction == UP
		&& get_tile_at(*map, map->player.x, map->player.y - 1) != WALL)
		map->player.y--;
	else if (direction == DOWN
		&& get_tile_at(*map, map->player.x, map->player.y + 1) != WALL)
		map->player.y++;
	else if (direction == LEFT
		&& get_tile_at(*map, map->player.x - 1, map->player.y) != WALL)
		map->player.x--;
	else if (direction == RIGHT
		&& get_tile_at(*map, map->player.x + 1, map->player.y) != WALL)
		map->player.x++;
	attempt_collect(state);
	printf("Move count: %u, Score: %u/%u\n", state->moves,
		state->map.player.score, state->map.collectibles);
	attempt_exit(state);
}
