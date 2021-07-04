/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pdruart <pdruart@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/30 12:02:52 by pdruart       #+#    #+#                 */
/*   Updated: 2020/10/31 15:24:55 by pdruart       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*result;

	result = NULL;
	while (*s != '\0' && *s != c)
		s++;
	if (*s == c)
		result = (char *)s;
	return (result);
}
