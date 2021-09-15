/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: pdruart <pdruart@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/10 17:42:31 by pdruart       #+#    #+#                 */
/*   Updated: 2021/09/15 15:04:03 by pdruart       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H
# include "player.h"

typedef enum e_tile {
	EMPTY = 0,
	WALL = 1,
	COLLECTIBLE = 2,
	EXIT = 3,
	START = 4
}	t_tile;

typedef struct s_map
{
	unsigned int	width;
	unsigned int	height;
	unsigned int	collectibles;
	char			*data;
	int				*random_data;
	t_player		player;
}	t_map;

t_tile	get_tile_at(t_map map, unsigned int x, unsigned int y);

#endif