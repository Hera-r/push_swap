/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrandria <hrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 10:48:59 by hrandria          #+#    #+#             */
/*   Updated: 2023/10/15 18:10:29 by hrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_more_args(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	if (argc >= 3)
		i = 1;
	while (argv[i])
	{
		if (argv[i][0] != '+' && argv[i][0] != '-' && \
			isdigit(argv[i][0]) == 0)
			return (printf("Error\n"), 1);
		while (argv[i][j])
		{
			if (isdigit(argv[i][j]) == 0)
				return (printf("Error\n"), 1);
			j++;
		}
	i++;
	j = 1;
	}
	return (0);
}

int	init_value(int argc, t_lst **head, char *argv[])
{
	int	i;

	i = 1;
	if (argc == 2)
		i = 0;
	while (argv[i])
	{
		if (xatoi(argv[i]) <= INT_MIN || xatoi(argv[i]) >= INT_MAX)
			return (printf("Error\n"), 1);
		ft_lstappend(head, xatoi(argv[i]));
		i++;
	}
	return (0);
}

int	one_argv(int argc, char *argv[], t_lst **head)
{
	char	**tab;
	int		resutl;
	int		duplicate;

	if(argc == 2)
	{
		tab = ft_split(argv[1]);
		if (tab == NULL)
			return (1);
		resutl = check_more_args(argc, tab);
		duplicate = compare_elem_tab(tab);
		if (resutl == 1 || duplicate == 1)
			return (free_tab(tab), 1);
		if (init_value(argc, head, tab) == 1)
			return (free_tab(tab), 1);
	}
	return (free_tab(tab), 0);
}

int	is_good_args(int argc, char *argv[], t_lst **head)
{
	if (argc >= 3)
	{
		if (check_more_args(argc, argv) == 1)
			return (1);
		else
			return (init_value(argc, head, argv));
	}
	if (one_argv(argc, argv, head) == 1)
		return (1);
	return (0);
}
