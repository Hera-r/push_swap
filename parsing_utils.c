/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrandria <hrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 17:33:40 by hrandria          #+#    #+#             */
/*   Updated: 2023/10/15 17:47:44 by hrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	len_dup(char *str)
{
	int	i;

	i = 0;
	while(str[i] && str[i] != ' ')
	i++;
	return (i);
}

char	*strdupx(char *str)
{
	char	*str_buffer;
	int		size;
	int		i;
	
	i = 0;
	size = len_dup(str);
	str_buffer = malloc((size + 1) * sizeof(char));
	if (str_buffer == NULL)
		return (NULL);
	while (str[i] && str[i] != ' ')
	{
		str_buffer[i] = str[i];
		i++;
	}
	str_buffer[i] = '\0';
	return (str_buffer);
}

static int	is_space(char c)
{
	if ((c >= 9 && c <= 13) || (c == ' '))
		return (1);
	return (0);
}

int	xatoi(const char *nptr)
{
	int	i;
	int	sign;
	int	n;

	i = 0;
	sign = 1;
	n = 0;
	while (is_space(nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (isdigit(nptr[i]))
	{
		n = n * 10 + (nptr[i] - '0');
		i++;
	}
	return (n * sign);
}

