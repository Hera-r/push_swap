/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrandria <hrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:58:58 by hrandria          #+#    #+#             */
/*   Updated: 2023/10/08 17:13:03 by hrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_sort_three_elements(t_lst **h_a)
{
	int	one;
	int two;
	int	last;

	one = (*h_a)->value;
	two = (*h_a)->next->value;
	last = (*h_a)->next->next->value;
	while (is_sorted(*h_a) != 0)
	{
		if (ft_nb_min(*h_a) == one && ft_nb_max(*h_a) == two)
		{
			ft_rra_rotate(h_a, "rra");
			ft_sa_swap(h_a, "sa");
		}
		else if (ft_nb_max(*h_a) > one && ft_nb_min(*h_a) == last)
			ft_rra_rotate(h_a, "rra");
		else if (ft_nb_max(*h_a) == one && ft_nb_min(*h_a) == two)
			ft_ra_rotate(h_a, "ra");
		else if (two < one && two < last)
			ft_sa_swap(h_a, "sa");
		else if (ft_nb_max(*h_a) == one && ft_nb_min(*h_a) == last)
		{
			ft_ra_rotate(h_a, "ra");
			ft_sa_swap(h_a, "sa");
		}
	}
}

int	ft_sort_three_or_swap(t_lst **h_a, int *ison)
{
	int	on;

	on = 0;
	if (h_a == NULL)
		return (0);
	if (lstsize(*h_a) == 3 && is_sorted(*h_a) != 0)
	{
		ft_sort_three_elements(h_a);
		on = 3;
		*ison = 1;
	}
	else if (lstsize(*h_a) == 2 && is_sorted(*h_a) != 0)
	{
		ft_sa_swap(h_a, "sa");
		on = 2;
		*ison = 1;
	}
	return (on);
}