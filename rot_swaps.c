/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_swaps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrandria <hrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:43:00 by hrandria          #+#    #+#             */
/*   Updated: 2023/10/08 16:45:31 by hrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa_swap(t_lst **h_a, char *str)
{
	int	tmp;

	tmp = (*h_a)->next->value;
	(*h_a)->next->value = (*h_a)->value;
	(*h_a)->value = tmp;
	printf("%s\n",str);
}

void	ft_pop_last(t_lst **h_a)
{
	t_lst *tmp;
	t_lst *last;

	tmp = *h_a;
	last = NULL;
	if (h_a == NULL)
		return ;
	while (tmp->next != NULL)
	{
		last = tmp;
		tmp = tmp->next;
	}
	last->next = NULL;
}

void	ft_pop_front(t_lst **h_a)
{
	t_lst	*tmp;

	if ((*h_a)->next == NULL)
	{
		*h_a = NULL;
		return ;
	}
	tmp = (*h_a)->next;
	*h_a = tmp;
}

void	ft_rra_rotate(t_lst **h_a, char *str)
{
	t_lst *tmp;

	tmp = *h_a;
	if (tmp == NULL)
		return ;
	while (tmp && tmp->next != NULL)
		tmp = tmp->next;
	ft_pop_last(h_a);
	tmp->next = *h_a;
	*h_a = tmp;
	printf("%s\n",str);
}

void	ft_ra_rotate(t_lst **h_a, char *str)
{
	t_lst	*tmp;
	t_lst	*first;

	tmp = *h_a;
	if (tmp == NULL)
		return ;
	first = (*h_a)->next;
	while (tmp && tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = *h_a;
	tmp->next->next = NULL;
	*h_a = first;
	printf("%s\n",str);
}