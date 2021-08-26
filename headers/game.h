/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   game.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pdruart <pdruart@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/12 15:14:27 by pdruart       #+#    #+#                 */
/*   Updated: 2021/08/26 12:54:12 by pdruart       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H
# include "map.h"
typedef struct s_gamestate {
	unsigned int	moves;
	int				exited;
	int				random;
	t_map			map;
}	t_gamestate;
void	move_player(t_gamestate *state, t_direction direction);
void	setup_state(t_gamestate *state, char *map_filename);

#endif