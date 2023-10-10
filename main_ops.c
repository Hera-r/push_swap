/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrandria <hrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 17:04:48 by hrandria          #+#    #+#             */
/*   Updated: 2023/10/10 23:23:50 by hrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	merge_ab(t_lst **b, t_lst **a, t_lst **h_nb, t_node *head)
{
	int	i;

	i = 0;
	if ((*h_nb)->value == 2 && b && (*b)->value < (*b)->next->value)
		ft_sa_swap(b, "sb", head);
	while (i < (*h_nb)->value)
	{
		ft_pb_push(b, a, "pa", head);
		if (lstsize(*b) > 1 && lstsize(*b) <= 3)
			ft_inverse_sort(b, head);
		i++;
	}
}

static int	final_part(t_lst **h_nb)
{
	int	result;

	result = 0;
	if (h_nb != NULL)
		result = (*h_nb)->value;
	else
		result = 0;
	return (result);
}

int	send_to_h_a(t_lst **b, t_lst **a, t_lst **h_nb, t_node *head)
{
	int	isexec;

	isexec = 0;
	if (is_max_last(a) == 0 && is_sorted(*a) == 0)
	{
		if (lstsize(*h_nb) == 1)
		{
			isexec = ft_psb(b, a, h_nb, head);
			if (isexec != 0)
				ft_nb_push(isexec, h_nb);
		}
		else
		{
			merge_ab(b, a, h_nb, head);
			isexec = 1;
		}
		if (isexec == 1)
		{
			isexec = final_part(h_nb);
			ft_pop_front(h_nb);
		}
	}
	return (isexec);
}

int	partition(t_lst **h_a, t_lst **h_b, int n, t_node *head)
{
	t_lst		*tmp;
	t_part		rec;

	tmp = *h_a;
	if (tmp == NULL)
		return (0);
	rec = sort_get_median(tmp, n);
	rec.nb = 0;
	rec.i = 0;
	while (rec.size_sub > 0)
	{
		if (tmp && tmp->value < rec.median)
		{
			ft_pb_push(h_a, h_b, "pb", head);
			rec.nb++;
		}
		else if (tmp->value >= rec.median)
			ft_ra_rotate(h_a, "ra", head);
		tmp = *h_a;
		rec.size_sub--;
	}
	free_lst(rec.listpa);
	return (rec.nb);
}

void	final_merge(t_lst **a, t_lst **b, t_lst **h_nb, t_node *head)
{
	t_lst	*tmp;
	int		i;
	int		end;

	i = 0;
	end = lstsize(*b);
	tmp = *b;
	while (i < end && tmp != NULL)
	{
		ft_pb_push(b, a, "pa", head);
		if ((*a)->value > (*a)->next->value)
			ft_sa_swap(a, "sa", head);
		tmp = *b;
		i++;
	}
	ft_pop_front(h_nb);
}
