/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrandria <hrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:47:25 by hrandria          #+#    #+#             */
/*   Updated: 2023/10/08 23:02:05 by hrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pb_push(t_lst **h_a, t_lst **h_b, const char *str)
{
	t_lst	*tmp_a;
	t_lst	*tmp_b;
	t_lst	*tmp_c;

	tmp_a = (*h_a)->next;
	tmp_b = *h_b;
	if (*h_b == NULL)
	{
		tmp_b = *h_a;
		tmp_b->next = NULL;
		*h_b = tmp_b;
		*h_a = tmp_a;
	}
	else
	{
		tmp_c = *h_a;
		tmp_c->next = tmp_b;
		*h_b = tmp_c;
		*h_a = tmp_a;
	}
	printf("%s\n", str);
}

void	ft_nb_push(int nb, t_lst **head_nb)
{
	t_lst	*elmt;

	elmt = malloc(sizeof(*elmt));
	if (elmt == NULL)
		return ;
	elmt->value = nb;
	elmt->next = NULL;
	if (head_nb == NULL)
		*head_nb = elmt;
	else
	{
		elmt->next = *head_nb;
		*head_nb = elmt;
	}
}

t_lst	*ft_lstappend(t_lst *h_a, int value)
{
	t_lst	*element;
	t_lst	*tmp;

	tmp = h_a;
	element = malloc(sizeof(*element));
	if (element == NULL)
		return (NULL);
	element->value = value;
	element->next = NULL;
	if (h_a == NULL)
		h_a = element;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = element;
	}
	tmp = NULL;
	return (h_a);
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