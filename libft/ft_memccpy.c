/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memccpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pdruart <pdruart@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/04 16:26:07 by pdruart       #+#    #+#                 */
/*   Updated: 2020/11/29 10:55:19 by pdruart       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*l;
	unsigned char	*r;
	size_t			i;

	l = (unsigned char *)dst;
	r = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		l[i] = r[i];
		if (r[i] == (unsigned char)c)
			return (&(l[i + 1]));
		i++;
	}
	return (NULL);
}
