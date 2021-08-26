/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shutdown.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pdruart <pdruart@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/17 12:52:40 by pdruart       #+#    #+#                 */
/*   Updated: 2021/08/26 14:15:37 by pdruart       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "../headers/shutdown.h"
#include "../libft/libft.h"

void	call_error(char *message)
{
	write(2, "Error\n", 7);
	if (message != NULL)
		write(2, message, ft_strlen(message));
	exit(1);
}
