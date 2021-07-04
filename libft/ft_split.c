/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pdruart <pdruart@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/13 14:56:02 by pdruart       #+#    #+#                 */
/*   Updated: 2021/04/21 16:41:04 by pdruart       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdlib.h"

size_t	ft_str_count(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (*(s + i) != '\0')
	{
		if (*(s + i) != c && (i == 0 || *(s + i - 1) == c))
			count++;
		i++;
	}
	return (count);
}

int	add_to_arr(char const *s, size_t i, long *start, char ***arr)
{
	char	*ptr;

	ptr = malloc(i - *start + 1);
	if (ptr == NULL)
		return (1);
	ft_memmove(ptr, (s + *start), i - *start);
	*(ptr + i - *start) = '\0';
	**arr = ptr;
	*arr = *arr + 1;
	*start = -1;
	return (0);
}

int	clean_up_arr(char ***arr, size_t wi)
{
	size_t	i;

	i = 0;
	while (i < wi)
	{
		free(*((*(arr - wi)) + i));
		i++;
	}
	free(*arr);
	return (1);
}

int	fill_arr(char const *s, char ***arr, char c)
{
	size_t	i;
	size_t	wi;
	long	start;

	i = 0;
	start = -1;
	wi = 0;
	while (*(s + i) != '\0')
	{
		if (start == -1 && *(s + i) != c)
			start = i;
		else if (start != -1 && *(s + i) == c)
		{
			if (add_to_arr(s, i, &start, arr) == 1)
				return (clean_up_arr(arr, wi));
			wi++;
		}
		i++;
	}
	if (start != -1 && add_to_arr(s, i, &start, arr) == 1)
		return (clean_up_arr(arr, wi));
	*(*arr) = NULL;
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	num;

	if (s == NULL)
		return (NULL);
	num = ft_str_count(s, c);
	arr = malloc((num + 1) * sizeof(char *));
	if (arr == NULL)
		return (NULL);
	if (fill_arr(s, &arr, c) == 1)
		return (NULL);
	return (arr - num);
}
