/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_psb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrandria <hrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 22:15:44 by hrandria          #+#    #+#             */
/*   Updated: 2023/10/15 23:10:03 by hrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quick_sort_hb(t_lst **h_b, t_lst **h_a, t_node *move, t_part *rec)
{
	t_lst	*tmp;

	tmp = *h_b;
	if (tmp && tmp->value >= (*rec).median)
	{
		ft_pb_push(h_b, h_a, "pa", move);
		if ((*h_a)->value > (*h_a)->next->value)
			ft_sa_swap(h_a, "sa", move);
	}
	else if (tmp->value < (*rec).median)
		ft_ra_rotate(h_b, "rb", move);
	tmp = *h_b;
	(*rec).size_sub--;
}

int	ft_psb(t_lst **h_b, t_lst **h_a, t_lst **h_nb, t_node *head)
{
	int		isexec;
	t_lst	*tmp;
	t_part	rec;

	isexec = 0;
	tmp = *h_b;
	if (tmp == NULL)
		return (0);
	rec = sort_get_median(tmp, lstsize(*h_b));
	rec.nb = 0;
	rec.i = 0;
	while (rec.size_sub > 0)
	{
		if (lstsize(*h_b) > 1 && lstsize(*h_b) <= 3)
		{
			ft_inverse_sort(h_b, head);
			break ;
		}
		else
			quick_sort_hb(h_b, h_a, head, &rec);
	}
	if (h_nb != NULL)
		isexec = lstsize(*h_b);
	ft_pop_front(h_nb);
	return (isexec);
}

void	init_rec(t_part *rec)
{
	(*rec).n = 0;
	(*rec).max_v = 0;
	(*rec).unsorted_v = 0;
	(*rec).send_ha_v = 0;
	(*rec).nb_three = 0;
	(*rec).result = 0;
}
