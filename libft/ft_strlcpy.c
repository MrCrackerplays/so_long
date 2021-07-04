/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pdruart <pdruart@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/28 15:09:39 by pdruart       #+#    #+#                 */
/*   Updated: 2021/04/21 16:54:42 by pdruart       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	srclen;

	i = 0;
	if (dst == NULL || src == NULL)
		return (0);
	srclen = ft_strlen(src);
	while (i < dstsize && src[i] != 0)
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize != 0)
		dst[((srclen >= dstsize) * -1) + i] = '\0';
	return (ft_strlen(src));
}
