/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pdruart <pdruart@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/12 17:46:06 by pdruart       #+#    #+#                 */
/*   Updated: 2021/09/15 15:04:37 by pdruart       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# ifndef LINUX
#  define LINUX 0
# endif
# ifndef SPRITE_WIDTH
#  define SPRITE_WIDTH 16
# endif
# ifndef SPRITE_HEIGHT
#  define SPRITE_HEIGHT 16
# endif
# include "controls.h"
# include "game.h"

typedef struct s_application
{
	void		*mlx;
	void		*win;
	void		*tileset;
	void		*spritesheet;
	void		*canvas;
	t_keys		keys;
	t_gamestate	gamestate;
}	t_application;

#endif