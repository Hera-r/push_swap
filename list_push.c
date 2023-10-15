/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrandria <hrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:47:25 by hrandria          #+#    #+#             */
/*   Updated: 2023/10/15 23:10:06 by hrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pb_push(t_lst **h_a, t_lst **h_b, const char *str, t_node *head)
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
	*head = ft_append_move(*head, str);
}

t_node	ft_append_move(t_node head, const char *move)
{
	t_move	*new_elem;
	t_move	*temp;

	new_elem = malloc(sizeof(t_move));
	if (!new_elem)
		return (NULL);
	new_elem->move = ft_strdup(move);
	new_elem->next = NULL;
	if (head == NULL)
		return (new_elem);
	else
	{
		temp = head;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new_elem;
		return (head);
	}
}

int	ft_lstappend(t_lst **h_a, int value)
{
	t_lst	*element;
	t_lst	*tmp;

	tmp = *h_a;
	element = malloc(sizeof(*element));
	if (element == NULL)
		return (FAIL);
	element->value = value;
	element->next = NULL;
	if (*h_a == NULL)
		*h_a = element;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = element;
	}
	return (SUCCESS);
}
