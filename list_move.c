/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrandria <hrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:56:53 by hrandria          #+#    #+#             */
/*   Updated: 2023/10/10 21:07:10 by hrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	del_mv(t_node chained, const char *del, const char *next, int *n)
{
	t_move	*tmp;
	t_move	*new_next;

	tmp = chained;
	while (tmp != NULL && tmp->next != NULL && tmp->next->next != NULL)
	{
		if (cmp(tmp->next->next->move, next) == SUCCESS && \
		cmp(tmp->next->move, del) == SUCCESS)
		{
			new_next = tmp->next->next;
			free(tmp->next->move);
			free(tmp->next);
			if (new_next->next != NULL)
				tmp->next = new_next->next;
			else
				tmp->next = NULL;
			free(new_next->move);
			free(new_next);
		}
		else if (tmp->next)
			tmp = tmp->next;
		else
			tmp = NULL;
	}
	return ((*n)++, chained);
}

static t_node	check_swap(t_node mv, int *n, const char *s1, const char *s2)
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
			tmp->move = ft_strdup("ss");
			tmp2 = tmp->next;
			if (tmp2->next != NULL)
				tmp->next = tmp2->next;
			else
				tmp->next = NULL;
			free(tmp2->move);
			free(tmp2);
		}
		tmp = tmp->next;
	}
	(*n)++;
	return (mv);
}

static void	ft_second_check(t_node chained)
{
	t_move	*tmp;
	int		del;

	tmp = chained;
	while (tmp != NULL && tmp->next != NULL)
	{
		del = 0;
		if (cmp(tmp->move, "rb") == SUCCESS && \
		cmp(tmp->next->move, "rrb") == SUCCESS)
			chained = del_mv(chained, tmp->move, tmp->next->move, &del);
		else if (cmp(tmp->move, "rrb") == SUCCESS && \
		cmp(tmp->next->move, "rb") == SUCCESS)
			chained = del_mv(chained, tmp->move, tmp->next->move, &del);
		else if (cmp(tmp->move, "ra") == SUCCESS && \
		cmp(tmp->next->move, "rra") == SUCCESS)
			chained = del_mv(chained, tmp->move, tmp->next->move, &del);
		else if (cmp(tmp->move, "rra") == SUCCESS && \
		cmp(tmp->next->move, "ra") == SUCCESS)
			chained = del_mv(chained, tmp->move, tmp->next->move, &del);
		if (del > 0)
			tmp = chained;
		tmp = tmp->next;
	}
	if (del > 0)
		ft_check_move_chained(chained);
}

void	ft_check_move_chained(t_node chained)
{
	t_move	*tmp;
	int		del;

	tmp = chained;
	while (tmp != NULL && tmp->next != NULL)
	{
		del = 0;
		if (cmp(tmp->move, "pa") == SUCCESS && \
		cmp(tmp->next->move, "pb") == SUCCESS)
			chained = del_mv(chained, tmp->move, tmp->next->move, &del);
		else if (cmp(tmp->move, "pb") == SUCCESS && \
		cmp(tmp->next->move, "pa") == SUCCESS)
			chained = del_mv(chained, tmp->move, tmp->next->move, &del);
		else if (cmp(tmp->move, "sa") == SUCCESS && \
		cmp(tmp->next->move, "sb") == SUCCESS)
			chained = check_swap(chained, &del, "sa", "sb");
		else if (cmp(tmp->move, "sb") == 1 && cmp(tmp->next->move, "sa") == 1)
			chained = check_swap(chained, &del, "sb", "sa");
		if (del > 0)
			tmp = chained;
		tmp = tmp->next;
	}
	if (del > 0)
		ft_check_move_chained(chained);
	ft_second_check(chained);
}
