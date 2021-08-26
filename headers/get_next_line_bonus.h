/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.h                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: pdruart <pdruart@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/12 11:12:00 by pdruart       #+#    #+#                 */
/*   Updated: 2021/05/27 13:16:54 by pdruart       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# include "stddef.h"

typedef struct s_string_buffer
{
	int						fd;
	char					*buff;
	struct s_string_buffer	*next;
}				t_string_buffer;
t_string_buffer	*create_string_buffer(int fd, t_string_buffer *next);
int				get_next_line(int fd, char **line);
int				gnl_strlen(const char *str);
char			*ft_strndup(const char *str, size_t n);
char			*str_join(char **origin, char *addition, size_t offset, long j);
long			read_into_buff(int fd, char **buff);
#endif
