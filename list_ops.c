/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrandria <hrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:26:23 by hrandria          #+#    #+#             */
/*   Updated: 2023/10/08 17:13:09 by hrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lstsize(t_lst *h_a)
{
	t_lst *tmp;
	int	size;

	tmp = h_a;
	size = 0;
	while (tmp != NULL)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}

int	ft_nb_min(t_lst *h_a)
{
	t_lst *tmp;
	int	min;

	tmp = h_a;
	min = tmp->value;
	while (tmp != NULL)
	{
		if (tmp->value < min)
			min = tmp->value;
		tmp = tmp->next;
	}
	return (min);
}

int	ft_nb_max(t_lst *h_a)
{
	t_lst *tmp;
	int	max;

	tmp = h_a;
	max = tmp->value;
	while (tmp != NULL)
	{
		if (tmp->value > max)
			max = tmp->value;
		tmp = tmp->next;
	}
	return (max);
}

int	is_sorted(t_lst *h_a)
{
	t_lst	*tmp;

	tmp = h_a;
	if (tmp == NULL)
		return (1);
	while (tmp->next != NULL)
	{
		if (tmp->value > tmp->next->value)
			return (1);
		tmp = tmp->next;
	}
	return (0);
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