/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrandria <hrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:58:58 by hrandria          #+#    #+#             */
/*   Updated: 2023/10/10 21:05:02 by hrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_size_move(t_node head)
{
	int	size;

	size = 0;
	while (head != NULL)
	{
		size++;
		head = head->next;
	}
	return (size);
}

void	ft_display_move(t_node head)
{
	t_move	*tmp;

	tmp = head;
	while (tmp != NULL)
	{
		printf("%s\n", tmp->move);
		tmp = tmp->next;
	}
}

int	is_max_last(t_lst **h_a)
{
	t_lst	*tmp;
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

int	ft_max_to_last(t_lst **h_a, t_node *head)
{
	t_lst	*tmp;
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
			ft_rra_rotate(h_a, "rra", head);
			if (h_a && (*h_a)->next != NULL && \
				(*h_a)->value > (*h_a)->next->value)
				ft_sa_swap(h_a, "sa", head);
			n++;
		}
	}
	return (n);
}

int	ft_is_min(int lastn, t_lst *a)
{
	t_lst	*tmp;

	tmp = a;
	while (tmp != NULL)
	{
		if (tmp->value < lastn)
			return (FAIL);
		tmp = tmp->next;
	}
	return (SUCCESS);
}
