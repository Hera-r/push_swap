/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrandria <hrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:51:11 by hrandria          #+#    #+#             */
/*   Updated: 2023/10/10 23:20:27 by hrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_last_unsorted_value(t_lst *head)
{
	t_lst	*tmp;
	int		last_unsorted;

	tmp = head;
	last_unsorted = INT_MIN;
	while (tmp != NULL && tmp->next != NULL)
	{
		if (tmp->value > tmp->next->value)
		{
			last_unsorted = tmp->next->value;
		}
		tmp = tmp->next;
	}
	return (last_unsorted);
}

int	get_index_unsorted_value(t_lst *head)
{
	t_lst	*tmp;
	int		n;
	int		target;

	tmp = head;
	n = 0;
	if (is_sorted(head) == 0)
		return (n);
	target = find_last_unsorted_value(head);
	while (tmp != NULL)
	{
		n++;
		if (tmp->value == target)
			return (n);
		tmp = tmp->next;
	}
	return (n);
}

void	sort_list_in_ascending_order(t_lst **h_a)
{
	t_lst	*lstmp;
	int		tmp;

	lstmp = *h_a;
	if (lstmp == NULL)
		return ;
	while (lstmp->next != NULL)
	{
		if (lstmp->value > lstmp->next->value)
		{
			tmp = lstmp->next->value;
			lstmp->next->value = lstmp->value;
			lstmp->value = tmp;
		}
		lstmp = lstmp->next;
		if (lstmp->next == NULL && is_sorted(*h_a) != 0)
			lstmp = *h_a;
	}
}

int	ft_find_median(t_lst *h_a)
{
	t_lst	*tmp;
	t_lst	*prev;
	int		size_list;
	int		i;

	i = 0;
	tmp = h_a;
	size_list = lstsize(h_a);
	while (i < (size_list / 2))
	{
		prev = tmp;
		tmp = tmp->next;
		i++;
	}
	if (size_list % 2 != 0)
		return (tmp->value);
	return ((prev->value + tmp->value) / 2);
}

t_part	sort_get_median(t_lst *h_a, int n)
{
	t_lst	*tmp;
	t_part	data;
	int		median;

	tmp = extract_partial_list(h_a, n);
	data.size_sub = lstsize(tmp);
	data.listpa = tmp;
	sort_list_in_ascending_order(&tmp);
	median = ft_find_median(tmp);
	data.median = median;
	return (data);
}
