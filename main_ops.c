/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrandria <hrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 17:04:48 by hrandria          #+#    #+#             */
/*   Updated: 2023/10/08 21:19:04 by hrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_max_last(t_lst **h_a)
{
	t_lst *tmp;
	int		max;

	tmp = *h_a;
	if (tmp == NULL)
		return (1);
	max = ft_nb_max(*h_a);
	while (tmp->value != max)
		tmp = tmp->next;
	if (tmp->next != NULL)
		return (1);
	return (0);
}

int	ft_max_to_last(t_lst **h_a)
{
	t_lst *tmp;
	int		max;
	int		n;

	tmp = *h_a;
	if (tmp == NULL)
		return (0);
	n = 0;
	if (lstsize(*h_a) > 3)
	{
		max = ft_nb_max(*h_a);
		while (tmp->value != max)
			tmp = tmp->next;
		while (tmp->next != NULL)
		{
			ft_rra_rotate(h_a, "rra");
			if (h_a && (*h_a)->next != NULL && (*h_a)->value > (*h_a)->next->value)
				ft_sa_swap(h_a, "sa");
			n++;
		}
	}
	return (n);
}

int	send_to_h_a(t_lst **h_b, t_lst **h_a, t_lst **h_nb)
{
	int	i;
	int	isexec;

	i = 0;
	isexec = 0;
	if (is_max_last(h_a) == 0 && is_sorted(*h_a) == 0)
 	{
		if ((*h_nb)->value == 2)
		{
			if (h_b && (*h_b)->value < (*h_b)->next->value)
				ft_sa_swap(h_b, "sb");
		}
		while (i < (*h_nb)->value)
		{
			ft_pb_push(h_b, h_a, "pa");
			i++;
		}
	isexec = 1;
	}
	if (isexec == 1)
	{
		if (h_nb != NULL)
			isexec = (*h_nb)->value;
		else
			isexec = 0;
		ft_pop_front(h_nb);
		return (isexec);
	}
	return (isexec);
}

void	partition(t_lst **h_a, t_lst **h_b, t_lst **nb, int n)
{
	t_lst		*tmp;
	t_part		rec;

	tmp = *h_a;
	if (tmp == NULL)
		return ;

	rec = sort_get_median(tmp, n);
	rec.nb = 0;
	rec.i = 0;

	while (rec.size_sub > 0)
	{
		if (tmp && tmp->value < rec.median)
		{
			ft_pb_push(h_a, h_b, "pb");
			rec.nb++;
		}
		else if (tmp->value >= rec.median)
			ft_ra_rotate(h_a, "ra");
		tmp = *h_a;
		rec.size_sub--;
	}

	if (rec.nb != 0)
		ft_nb_push(rec.nb, nb);
}