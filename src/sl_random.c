/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_random.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pdruart <pdruart@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/19 14:47:55 by pdruart       #+#    #+#                 */
/*   Updated: 2021/08/26 14:15:54 by pdruart       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/sl_random.h"

/**
 * Linear congrential generator using width height and addition for start seed
 */
int	sl_random(t_gamestate *gamestate)
{
	int			m;
	int			a;
	int			c;

	m = 65537;
	a = 75;
	c = 74;
	gamestate->random = (a * (gamestate->random) + c) % m;
	return (gamestate->random);
}

void	prepare_random(t_gamestate *gamestate)
{
	int	additive;
	int	width;
	int	height;
	int	i;

	height = gamestate->map.height;
	width = gamestate->map.width;
	additive = 0;
	i = 0;
	while (i < height * width)
	{
		additive += get_tile_at(gamestate->map, i % width,
				i / width);
		i++;
	}
	gamestate->random = ((height * additive) + width) % 65537;
	gamestate->map.player.type = gamestate->random % 3;
}
