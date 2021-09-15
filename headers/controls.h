/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   controls.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pdruart <pdruart@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/19 10:55:49 by pdruart       #+#    #+#                 */
/*   Updated: 2021/09/15 15:03:41 by pdruart       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTROLS_H
# define CONTROLS_H

typedef struct s_keys
{
	int	up;
	int	down;
	int	left;
	int	right;
	int	exit;
}	t_keys;

t_keys	get_keys(void);

#endif