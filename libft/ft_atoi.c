/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pdruart <pdruart@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/04 13:07:15 by pdruart       #+#    #+#                 */
/*   Updated: 2021/04/21 16:29:06 by pdruart       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	unsigned long long	val;
	int					i;
	int					pos;

	i = 0;
	val = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || str[i] == '\f'
		|| str[i] == '\r' || str[i] == ' ')
		i++;
	pos = 1;
	if (str[i] == '-')
		pos = -1;
	i = i + (str[i] == '-' || str[i] == '+');
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0)
			break ;
		else if (val > 922337203685477580ll
			|| (val == 922337203685477580ll && str[i] > '7'))
			return ((pos == -1) * -1);
		else
			val = (val * 10) + (str[i] - '0');
		i++;
	}
	return (val * pos);
}
