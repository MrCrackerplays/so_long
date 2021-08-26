/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils_bonus.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pdruart <pdruart@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/12 11:12:03 by pdruart       #+#    #+#                 */
/*   Updated: 2021/08/26 14:29:09 by pdruart       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/get_next_line_bonus.h"
#include "unistd.h"
#include "stdlib.h"

int	gnl_strlen(const char *str)
{
	int	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strndup(const char *str, size_t n)
{
	char	*new;
	size_t	len;
	size_t	i;

	len = gnl_strlen(str);
	new = malloc(len + 1);
	if (new == NULL)
		return (NULL);
	new[n] = '\0';
	i = 0;
	while (i <= len && i < n)
	{
		new[i] = str[i];
		i++;
	}
	new[len] = '\0';
	return (new);
}

char	*str_join(char **original, char *addition, size_t offset, long j)
{
	char	*temp;
	long	i;

	i = gnl_strlen(original[0]) - offset;
	i = (i < 0) * 0 + (i >= 0) * i;
	temp = malloc(i + j + 1);
	if (temp == NULL)
		return (NULL);
	temp[i + j] = '\0';
	while (j > 0)
	{
		temp[i + j - 1] = addition[j - 1];
		j--;
	}
	if (*original != NULL)
	{
		while (i > 0)
		{
			temp[i - 1] = original[0][offset + i - 1];
			i--;
		}
		free(original[0]);
	}
	original[0] = temp;
	return (original[0]);
}

long	read_into_buff(int fd, char **buff)
{
	char	temp_buffer[BUFFER_SIZE + 1];
	long	bytes;

	bytes = read(fd, &(temp_buffer[0]), BUFFER_SIZE);
	if (bytes < 0)
		return (bytes);
	temp_buffer[bytes] = '\0';
	if (!str_join(buff, &(temp_buffer[0]), 0, gnl_strlen(&(temp_buffer[0]))))
		return (-1);
	return (bytes);
}

t_string_buffer	*create_string_buffer(int fd, t_string_buffer *next)
{
	t_string_buffer	*result;

	result = malloc(sizeof(t_string_buffer));
	if (result == NULL)
		return (next);
	result->buff = NULL;
	result->fd = fd;
	result->next = next;
	return (result);
}
