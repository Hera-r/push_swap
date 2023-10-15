/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrandria <hrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 17:39:50 by hrandria          #+#    #+#             */
/*   Updated: 2023/10/15 18:34:18 by hrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	len_tab(char *argv[])
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}

int	isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	compare_elem_tab(char **tab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tab[i])
	{
		j = i + 1;
		while (tab[j])
		{
			if (xstrcmp(tab[i], tab[j]) == 0)
				return (ft_printf("Error\n"), 1);
			j++;
		}
	i++;
	}
	return (0);
}

int	compare_lst(t_lst **head)
{
	t_lst	*tmp;
	t_lst	*after;

	tmp = *head;
	while (tmp != NULL)
	{
		after = tmp->next;
		while (after != NULL)
		{
			if (tmp->value == after->value)
				return (ft_printf("Error\n"), 1);
			after = after->next;
		}
	tmp = tmp->next;
	}
	return (0);
}

int	split_size(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while(str[i] && str[i] == ' ')
		i++;
		if (str[i] && str[i] != ' ')
		{
			while (str[i] && str[i] != ' ')
				i++;
			count++;
		}
	}
	return (count);
}