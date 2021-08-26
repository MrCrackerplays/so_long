/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pdruart <pdruart@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/11 14:35:41 by pdruart       #+#    #+#                 */
/*   Updated: 2021/08/25 13:52:25 by pdruart       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H
typedef enum e_direction {
	UP = 3,
	DOWN = 2,
	LEFT = 0,
	RIGHT = 1
}	t_direction;

typedef struct s_player
{
	unsigned int	x;
	unsigned int	y;
	unsigned int	score;
	int				type;
	t_direction		facing;
}	t_player;

#endif