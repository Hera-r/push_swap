/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrandria <hrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 22:15:26 by hrandria          #+#    #+#             */
/*   Updated: 2023/10/12 22:19:35 by hrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	del_mv(t_node head, const char *del, const char *next, int *n)
{
	t_move	*tmp;
	t_move	*new_next;

	tmp = head;
	while (tmp != NULL && tmp->next != NULL && tmp->next->next != NULL)
	{
		if (cmp(tmp->next->next->move, next) == SUCCESS && \
		cmp(tmp->next->move, del) == SUCCESS)
		{
			new_next = tmp->next->next;
			(free(tmp->next->move), free(tmp->next));
			if (new_next->next != NULL)
				tmp->next = new_next->next;
			else
				tmp->next = NULL;
			(free(new_next->move), free(new_next), new_next = NULL);
			(*n)++;
		}
		else if (tmp->next)
			tmp = tmp->next;
		else
			tmp = NULL;
	}
	return (head);
}

t_node	check_swap(t_node mv, int *n, const char *s1, const char *s2)
{
	t_move	*tmp;
	t_move	*tmp2;

	tmp = mv;
	while (tmp != NULL)
	{
		if (cmp(tmp->move, s1) == SUCCESS && (tmp->next != NULL && \
		cmp(tmp->next->move, s2) == SUCCESS))
		{
			free(tmp->move);
			tmp->move = NULL;
			tmp->move = ft_strdup("ss");
			tmp2 = tmp->next;
			if (tmp2->next != NULL)
				tmp->next = tmp2->next;
			else
				tmp->next = NULL;
			free(tmp2->move);
			free(tmp2);
			(*n)++;
		}
		tmp = tmp->next;
	}
	return (mv);
}

void	ft_check_move_chained(t_node head)
{
	int		del;

	del = 0;
	head = del_mv(head, "rb", "rrb", &del);
	head = del_mv(head, "rrb", "rb", &del);
	head = del_mv(head, "rra", "ra", &del);
	head = del_mv(head, "ra", "rra", &del);
	head = del_mv(head, "pa", "pb", &del);
	head = del_mv(head, "pb", "pa", &del);
	head = check_swap(head, &del, "sa", "sb");
	head = check_swap(head, &del, "sb", "sa");
	if (del > 0)
		ft_check_move_chained(head);
}
