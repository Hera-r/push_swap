/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_tmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrandria <hrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 17:11:45 by hrandria          #+#    #+#             */
/*   Updated: 2023/10/08 16:23:56 by hrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_space(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	return (0);
}

t_fatoi	ft_atoi(char *str)
{
	t_fatoi fnumber;
	int		i;
	int		sign;

	i = 0;
	sign = 1;
	fnumber.n = 0;
	while (is_space(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			sign *= -1;
		}
		i++;
	}
	if (ft_isdigit(str[i]) == 0)
	{
		fnumber.err = 'X';
		return (fnumber);
	}
	while (ft_isdigit(str[i]))
	{
		fnumber.n = fnumber.n * 10 + (str[i] - '0');
		i++;
	}
	fnumber.n = fnumber.n * sign;
	return (fnumber);
}
