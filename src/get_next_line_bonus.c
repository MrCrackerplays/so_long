/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: pdruart <pdruart@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/12 11:10:34 by pdruart       #+#    #+#                 */
/*   Updated: 2021/08/26 14:29:04 by pdruart       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/get_next_line_bonus.h"
#include "unistd.h"
#include "stdlib.h"

ssize_t	find_line(int fd, char **buff, char **line, int count)
{
	int		i;
	ssize_t	bytes;

	bytes = buff[0] != NULL && buff[0][0] == '\n';
	i = 0;
	while (buff[0][i] != '\n')
	{
		if (buff[0][i] == '\0')
		{
			if (fd != 0 || count != 0)
				bytes = read_into_buff(fd, buff);
			if (bytes < 0)
				return (-1);
			if (bytes == 0)
				break ;
		}
		else
			i++;
		if (bytes == 0)
			bytes = 1;
	}
	line[0] = ft_strndup(buff[0], i);
	if (!str_join(buff, NULL, i + 1, 0))
		return (-1);
	return (bytes);
}

int	setup_buff(char **buff, int fd)
{
	ssize_t	bytes;
	char	tmp_buffer[BUFFER_SIZE + 1];

	if (buff == NULL)
		return (-1);
	bytes = 1;
	if (buff[0] == NULL)
	{
		bytes = read(fd, &(tmp_buffer[0]), BUFFER_SIZE);
		if (bytes < 0)
			return (-1);
		tmp_buffer[bytes] = '\0';
		buff[0] = malloc(sizeof(char));
		if (buff[0] == NULL)
			return (-1);
		buff[0][0] = '\0';
		if (!str_join(buff, &(tmp_buffer[0]), 0, gnl_strlen(&(tmp_buffer[0]))))
			return (-1);
	}
	return (bytes);
}

t_string_buffer	**get_buff(int fd, t_string_buffer **buffer_list)
{
	t_string_buffer	*buff_list;

	if (buffer_list == NULL || buffer_list[0] == NULL)
		return (NULL);
	if (buffer_list[0]->fd > fd)
		buffer_list[0] = create_string_buffer(fd, buffer_list[0]);
	buff_list = buffer_list[0];
	if (buff_list->fd < fd)
	{
		if (buff_list->next == NULL)
			buff_list->next = create_string_buffer(fd, NULL);
		else if (buff_list->next->fd > fd)
			buff_list->next = create_string_buffer(fd, buff_list->next);
	}
	if (buff_list->fd == fd)
		return (buffer_list);
	return (get_buff(fd, &(buffer_list[0]->next)));
}

void	clean_fd_buffer(int fd, t_string_buffer **buffer_list)
{
	t_string_buffer	*holder;
	t_string_buffer	*prev;

	if (buffer_list == NULL || buffer_list[0] == NULL)
		return ;
	if (buffer_list[0]->fd == fd)
	{
		holder = buffer_list[0];
		buffer_list[0] = buffer_list[0]->next;
		free(holder->buff);
		free(holder);
		return ;
	}
	prev = buffer_list[0];
	holder = prev->next;
	while (holder != NULL && holder->fd != fd)
	{
		prev = prev->next;
		holder = prev->next;
	}
	if (holder == NULL)
		return ;
	prev->next = holder->next;
	free(holder->buff);
	free(holder);
}

int	get_next_line(int fd, char **line)
{
	static t_string_buffer	*buffer_list;
	char					**buff;
	ssize_t					bytes;

	if (fd < 0 || line == NULL || BUFFER_SIZE < 1)
		return (-1);
	if (buffer_list == NULL)
		buffer_list = create_string_buffer(fd, NULL);
	buff = &((get_buff(fd, &(buffer_list))[0])->buff);
	bytes = setup_buff(buff, fd);
	if (bytes >= 0)
		bytes = find_line(fd, buff, line, bytes);
	if (bytes < 1 && buff[0][0] == '\0')
	{
		free(buff[0]);
		buff[0] = NULL;
		clean_fd_buffer(fd, &(buffer_list));
	}
	if (bytes >= 0)
		return (bytes > 0);
	return (-1);
}
