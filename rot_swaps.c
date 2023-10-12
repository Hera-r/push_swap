/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_swaps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrandria <hrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:43:00 by hrandria          #+#    #+#             */
/*   Updated: 2023/10/12 22:44:45 by hrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa_swap(t_lst **h_a, const char *str, t_node *head)
{
	int	tmp;

	tmp = (*h_a)->next->value;
	(*h_a)->next->value = (*h_a)->value;
	(*h_a)->value = tmp;
	*head = ft_append_move(*head, str);
}

void	ft_rra_rotate(t_lst **h_a, const char *str, t_node *head)
{
	t_lst	*tmp;

	tmp = *h_a;
	if (tmp == NULL || tmp->next == NULL)
		return ;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	tmp->next->next = *h_a;
	*h_a = tmp->next;
	tmp->next = NULL;
	*head = ft_append_move(*head, str);
}

void	ft_ra_rotate(t_lst **h_a, const char *str, t_node *head)
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
	*head = ft_append_move(*head, str);
}
