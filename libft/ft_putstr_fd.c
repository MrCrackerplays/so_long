/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pdruart <pdruart@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/11 15:18:55 by pdruart       #+#    #+#                 */
/*   Updated: 2020/11/22 13:22:24 by pdruart       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"
#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (s != NULL)
		write(fd, s, ft_strlen(s));
}
