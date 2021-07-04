/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pdruart <pdruart@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/07 16:07:04 by pdruart       #+#    #+#                 */
/*   Updated: 2020/11/25 18:45:18 by pdruart       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*chrs;

	chrs = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (*chrs == (unsigned char)c)
			return (chrs);
		chrs++;
		i++;
	}
	return (NULL);
}
