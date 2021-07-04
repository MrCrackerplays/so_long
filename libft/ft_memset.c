/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pdruart <pdruart@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/08 15:18:15 by pdruart       #+#    #+#                 */
/*   Updated: 2020/11/08 15:22:47 by pdruart       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	chr;
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	chr = c;
	ptr = b;
	while (i < len)
	{
		*ptr = chr;
		ptr++;
		i++;
	}
	return (b);
}
