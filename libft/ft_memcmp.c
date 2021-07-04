/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pdruart <pdruart@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/07 16:43:33 by pdruart       #+#    #+#                 */
/*   Updated: 2021/04/21 16:38:39 by pdruart       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*chrs1;
	unsigned char	*chrs2;
	size_t			i;

	chrs1 = (unsigned char *)s1;
	chrs2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (*chrs1 != *chrs2)
			return (*chrs1 - *chrs2);
		i++;
		chrs1++;
		chrs2++;
	}
	return (0);
}
