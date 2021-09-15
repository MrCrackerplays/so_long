/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sl_random.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pdruart <pdruart@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/19 14:51:58 by pdruart       #+#    #+#                 */
/*   Updated: 2021/09/15 15:04:29 by pdruart       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SL_RANDOM_H
# define SL_RANDOM_H
# include "so_long.h"

int		sl_random(t_gamestate *gamestate);
void	prepare_random(t_gamestate *gamestate);

#endif