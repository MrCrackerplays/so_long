/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   game_setup.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pdruart <pdruart@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/08/17 11:54:32 by pdruart       #+#    #+#                 */
/*   Updated: 2021/08/31 14:23:09 by pdruart       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "../libft/libft.h"
#include "../headers/get_next_line_bonus.h"
#include "../headers/game.h"
#include "../headers/shutdown.h"
#include "../headers/sl_random.h"

int	open_file(char *map_filename)
{
	int	size;
	int	fd;

	size = ft_strlen(map_filename);
	if (size < 4
		|| map_filename[size - 4] != '.' || map_filename[size - 3] != 'b'
		|| map_filename[size - 2] != 'e' || map_filename[size - 1] != 'r')
		call_error("Wrong filetype\n");
	fd = open(map_filename, O_RDONLY);
	if (fd <= 2)
		call_error("Something went wrong opening the file\n");
	return (fd);
}

void	check_map(t_gamestate *state)
{
	int	i;
	int	contents;

	i = 0;
	contents = 0b000;
	while (state->map.data[i] != '\0')
	{
		if (i / state->map.width == 0
			|| i / state->map.width == state->map.height - 1
			|| i % state->map.width == 0
			|| i % state->map.width == state->map.width - 1)
			if (state->map.data[i] != '1')
				call_error("Map not surrounded by walls\n");
		if (state->map.data[i] == 'C')
			contents = contents | 0b001;
		if (state->map.data[i] == 'E')
			contents = contents | 0b010;
		if (state->map.data[i] == 'P')
			contents = contents | 0b100;
		i++;
	}
	if (contents != 0b111)
		call_error("Map missing at least one of: 'C', 'E', 'P'\n");
	state->map.random_data = ft_calloc(i, sizeof(int));
}

void	place_player_and_count(t_gamestate *state)
{
	int	i;
	int	position;

	state->map.player.facing = DOWN;
	state->map.player.score = 0;
	state->exited = 0;
	i = 0;
	while (state->map.data[i] != '\0')
	{
		if (state->map.data[i] == 'P')
			position = i;
		if (state->map.data[i] == 'C')
			state->map.collectibles++;
		state->map.random_data[i] = sl_random(state);
		i++;
	}
	state->map.player.x = position % state->map.width;
	state->map.player.y = position / state->map.width;
}

void	check_buffer(t_gamestate *state, char *buffer)
{
	unsigned int	width;
	int				i;

	width = (unsigned int) ft_strlen(buffer);
	if (state->map.height == 0)
		state->map.width = width;
	if (state->map.width != width)
		call_error("Uneven map\n");
	state->map.height++;
	i = 0;
	while (buffer[i] != '\0' && ft_strchr("01CEP", buffer[i]) != NULL)
		i++;
	if (buffer[i] != '\0')
		call_error("Unknown character in map\n");
}

void	setup_state(t_gamestate *state, char *map_filename)
{
	int		fd;
	int		read_status;
	char	*buffer;

	state->moves = 0;
	state->map.data = NULL;
	state->map.height = 0;
	buffer = NULL;
	fd = open_file(map_filename);
	read_status = 1;
	while (read_status > 0)
	{
		read_status = get_next_line(fd, &buffer);
		if (read_status < 0)
			call_error("Reading error\n");
		check_buffer(state, buffer);
		if (str_join(&state->map.data, buffer, 0, ft_strlen(buffer)) == NULL)
			call_error("Malloc fail\n");
		free(buffer);
	}
	close(fd);
	check_map(state);
	prepare_random(state);
	state->map.collectibles = 0;
	place_player_and_count(state);
}
