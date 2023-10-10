/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrandria <hrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:58:58 by hrandria          #+#    #+#             */
/*   Updated: 2023/10/10 21:04:57 by hrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three_elements(t_lst **h_a, t_node *head)
{
	int	two;
	int	last;

	two = (*h_a)->next->value;
	last = (*h_a)->next->next->value;
	while (is_sorted(*h_a) != 0)
	{
		if (ft_nb_min(*h_a) == (*h_a)->value && ft_nb_max(*h_a) == two)
		{
			ft_rra_rotate(h_a, "rra", head);
			ft_sa_swap(h_a, "sa", head);
		}
		else if (ft_nb_max(*h_a) > (*h_a)->value && ft_nb_min(*h_a) == last)
			ft_rra_rotate(h_a, "rra", head);
		else if (ft_nb_max(*h_a) == (*h_a)->value && ft_nb_min(*h_a) == two)
			ft_ra_rotate(h_a, "ra", head);
		else if (two < (*h_a)->value && two < last)
			ft_sa_swap(h_a, "sa", head);
		else if (ft_nb_max(*h_a) == (*h_a)->value && ft_nb_min(*h_a) == last)
		{
			ft_ra_rotate(h_a, "ra", head);
			ft_sa_swap(h_a, "sa", head);
		}
	}
}

int	ft_sort_three_or_swap(t_lst **h_a, t_node *head)
{
	int	on;

	on = 0;
	if (h_a == NULL)
		return (0);
	if (lstsize(*h_a) == 3 && is_sorted(*h_a) != 0)
	{
		ft_sort_three_elements(h_a, head);
		on = 3;
	}
	else if (lstsize(*h_a) == 2 && is_sorted(*h_a) != 0)
	{
		ft_sa_swap(h_a, "sa", head);
		on = 2;
	}
	return (on);
}

int	ft_is_inverse_sorted(t_lst **a, int nb)
{
	t_lst	*tmp;
	int		i;

	tmp = *a;
	i = 0;
	if (tmp == NULL)
		return (FAIL);
	if (lstsize(tmp) == 1)
		return (SUCCESS);
	while (i < nb && tmp->next != NULL)
	{
		if (tmp->value < tmp->next->value)
			return (FAIL);
		tmp = tmp->next;
		i++;
	}
	return (SUCCESS);
}

void	ft_inverse_sort(t_lst **h_a, t_node *head)
{
	if (ft_is_inverse_sorted(h_a, lstsize(*h_a)) == FAIL)
	{
		if (lstsize(*h_a) == 2)
		{
			if ((*h_a)->value < (*h_a)->next->value)
				ft_sa_swap(h_a, "sb", head);
			return ;
		}
		else if (ft_is_max((*h_a)->next->value, *h_a) == SUCCESS && \
		ft_is_min((*h_a)->next->next->value, *h_a) == SUCCESS)
			ft_sa_swap(h_a, "sb", head);
		else if (ft_is_min((*h_a)->value, *h_a) == SUCCESS)
			ft_ra_rotate(h_a, "rb", head);
		else
			ft_rra_rotate(h_a, "rrb", head);
		if (ft_is_inverse_sorted(h_a, lstsize(*h_a)) == FAIL)
			ft_sa_swap(h_a, "sb", head);
	}
}
