/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   controls.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pdruart <pdruart@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/19 10:55:14 by pdruart       #+#    #+#                 */
/*   Updated: 2021/08/26 14:13:58 by pdruart       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/controls.h"
#include "../headers/so_long.h"

t_keys	get_mac_keys(void)
{
	t_keys	keys;

	keys.left = 0;
	keys.right = 2;
	keys.up = 13;
	keys.down = 1;
	keys.exit = 53;
	return (keys);
}

t_keys	get_linux_keys(void)
{
	t_keys	keys;

	keys.left = 'a';
	keys.right = 'd';
	keys.up = 'w';
	keys.down = 's';
	keys.exit = 65307;
	return (keys);
}

t_keys	get_keys(void)
{
	if (LINUX == 0)
		return (get_mac_keys());
	return (get_linux_keys());
}
