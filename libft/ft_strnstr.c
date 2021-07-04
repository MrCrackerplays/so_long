/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pdruart <pdruart@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/01 16:22:43 by pdruart       #+#    #+#                 */
/*   Updated: 2020/11/22 11:07:59 by pdruart       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	a;
	size_t	ndllen;

	ndllen = ft_strlen(needle);
	if (ndllen == 0)
		return ((char *)haystack);
	i = 0;
	if (len > ft_strlen(haystack))
		len = ft_strlen(haystack);
	while (i < len && haystack[i] != '\0')
	{
		a = 0;
		while ((i + a) < len && a <= ndllen && haystack[i + a] == needle[a])
			a++;
		if (a == ndllen)
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}
