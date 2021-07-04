/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pdruart <pdruart@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/11 17:30:02 by pdruart       #+#    #+#                 */
/*   Updated: 2021/04/21 16:44:54 by pdruart       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdlib.h"

int	contains(char const *set, char const chr)
{
	unsigned int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == chr)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*str;
	char			*ptr;
	unsigned int	end;

	if (s1 == NULL || set == NULL)
		return (NULL);
	str = (char *)s1;
	while (*str != '\0' && contains(set, *str) != 0)
		str++;
	end = ft_strlen(str);
	while (end > 0 && contains(set, str[end - 1]) != 0)
		end--;
	ptr = malloc(end + 1);
	if (ptr == NULL)
		return (NULL);
	ft_memmove(ptr, str, end);
	ptr[end] = '\0';
	return (ptr);
}
