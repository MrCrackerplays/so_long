/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: pdruart <pdruart@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/10 17:42:24 by pdruart       #+#    #+#                 */
/*   Updated: 2021/08/26 14:15:02 by pdruart       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/player.h"
#include "../headers/game.h"

t_tile	get_tile_at(t_map map, unsigned int x, unsigned int y)
{
	char	value;

	if (!x || !y || x >= map.width - 1 || y >= map.height - 1)
		return (WALL);
	value = map.data[y * (map.width) + x];
	if (value == '0')
		return (EMPTY);
	if (value == 'C')
		return (COLLECTIBLE);
	if (value == 'E')
		return (EXIT);
	if (value == 'P')
		return (START);
	return (WALL);
}
