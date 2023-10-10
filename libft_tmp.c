/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_tmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrandria <hrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 17:11:45 by hrandria          #+#    #+#             */
/*   Updated: 2023/10/10 21:05:16 by hrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cmp(const char *str1, const char *str2)
{
	int	i;

	i = 0;
	while (str1[i] && str2[i])
	{
		if (str1[i] != str2[i])
			return (FAIL);
		i++;
	}
	if (str1[i])
		return (FAIL);
	return (SUCCESS);
}

int	ft_check_below_median(t_lst *h_a, int median)
{
	t_lst	*tmp;

	tmp = h_a;
	while (tmp != NULL)
	{
		if (tmp->value > median)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
