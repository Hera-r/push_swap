/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrandria <hrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 18:20:44 by hrandria          #+#    #+#             */
/*   Updated: 2023/10/15 18:34:13 by hrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_rec(t_part *rec)
{
	(*rec).n = 0;
	(*rec).max_v = 0;
	(*rec).unsorted_v = 0;
	(*rec).send_ha_v = 0;
	(*rec).nb_three = 0;
	(*rec).result = 0;
}

static void	first_part_ps(t_lst **a, t_lst **b, t_lst **h_nb, t_node *move)
{
	int	result;

	result = 0;
	while (lstsize(*a) > 3)
	{
		result = partition(a, b, 0, move);
		if (result != 0)
			ft_nb_push(result, h_nb);
	}
	ft_sort_three_or_swap(a, move);
}

static void	last_part_ps(t_lst **h_a, t_part *rec, t_node *head)
{
	ft_max_to_last(h_a, head);
	(*rec).send_ha_v = 0;
	(*rec).unsorted_v = get_index_unsorted_value(*h_a);
}

static void	sub_partition(t_lst **a, t_lst **b, t_part *rec, t_node *move)
{
	if ((*rec).send_ha_v > 2)
		(*rec).result = partition(a, b, (*rec).send_ha_v, move);
	else
		(*rec).result = partition(a, b, (*rec).unsorted_v, move);
}

void	ft_push_swap(t_lst **a, t_lst **b, t_lst **h_nb, t_node *move)
{
	t_part	rec;

	init_rec(&rec);
	first_part_ps(a, b, h_nb, move);
	while (is_sorted(*a) != 0 || lstsize(*h_nb) != 0)
	{
		if (rec.unsorted_v < 3)
		{
			rec.send_ha_v = send_to_h_a(b, a, h_nb, move);
			if (is_sorted(*a) == 0 && ft_is_inverse_sorted(b, lstsize(*b)) == 1)
				final_merge(a, b, h_nb, move);
		}
		if (rec.send_ha_v > 2 || rec.unsorted_v > 2)
		{
			sub_partition(a, b, &rec, move);
			if (rec.result != 0)
				ft_nb_push(rec.result, h_nb);
		}
		last_part_ps(a, &rec, move);
	}
}

int	main(int argc, char *argv[])
{
	t_lst	*my_list;
	t_lst	*h_b;
	t_lst	*list_nb;
	t_node	head;

	my_list = NULL;
	h_b = NULL;
	list_nb = NULL;
	head = NULL;
	if (argc > 1)
	{
		if (is_good_args(argc, argv, &my_list) == 1)
			return (free_lst(&my_list), 0);
		if (compare_lst(&my_list) == 1)
			return (free_lst(&my_list), 0);
		ft_push_swap(&my_list, &h_b, &list_nb, &head);
		ft_check_move_chained(head);
		ft_display_move(head);
		free_lst(&list_nb);
		free_lst(&my_list);
		free_t_nod(head);
	}
	return (0);
}
