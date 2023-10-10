/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrandria <hrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 17:38:09 by hrandria          #+#    #+#             */
/*   Updated: 2023/10/10 23:20:38 by hrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_nb_push(int nb, t_lst **head_nb)
{
	t_lst	*elmt;

	elmt = malloc(sizeof(*elmt));
	if (elmt == NULL)
		return ;
	elmt->value = nb;
	elmt->next = NULL;
	if (*head_nb == NULL)
		*head_nb = elmt;
	else
	{
		elmt->next = *head_nb;
		*head_nb = elmt;
	}
}

void	ft_pop_last(t_lst **h_a)
{
	t_lst	*tmp;
	t_lst	*last;

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

int	ft_is_max(int firstn, t_lst *a)
{
	t_lst	*tmp;

	tmp = a;
	while (tmp != NULL)
	{
		if (tmp->value > firstn)
			return (FAIL);
		tmp = tmp->next;
	}
	return (SUCCESS);
}

t_lst	*extract_partial_list(t_lst *h_a, int n)
{
	t_lst	*list_asc;
	t_lst	*tmp;
	int		i;

	i = 0;
	tmp = h_a;
	list_asc = NULL;
	if (tmp == NULL)
		return (list_asc);
	if (n == 0)
		n = lstsize(h_a);
	while (i < n)
	{
		list_asc = ft_lstappend(list_asc, tmp->value);
		tmp = tmp->next;
		i++;
	}
	return (list_asc);
}
