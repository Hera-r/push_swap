/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_tmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrandria <hrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 17:11:45 by hrandria          #+#    #+#             */
/*   Updated: 2023/10/15 17:49:01 by hrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cmp(const char *str1, const char *str2)
{
	int	i;

	if (str1 == NULL || str2 == NULL)
		return (FAIL);
	i = 0;
	while (str1[i] && str2[i])
	{
		if (str1[i] != str2[i])
			return (FAIL);
		i++;
	}
	if (str1[i])
		return (FAIL);
	return (SUCCESS);
}

void	free_lst(t_lst **head)
{
	t_lst *tmp;
	t_lst *next;

	tmp = *head;
	while (tmp != NULL)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
}

void free_t_nod(t_node head) 
{
	t_node	tmp; 
	t_node	next;

	tmp = head;
	while (tmp != NULL) {
		next = tmp->next;
		free(tmp->move);
		free(tmp);
		tmp = next;
	}
}

void free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free (tab);
}

char	**ft_split(char *str)
{
	char	**tab;
	int		size;
	int		tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	size = split_size(str);
	tab = malloc((size + 1) * sizeof(char *));
	if (tab == NULL)
		return (NULL);
	while (str[i])
	{
		while (str[i] && str[i] == ' ')
			i++;
		if (str[i] && str[i] != ' ')
		{
			tmp = i;
			while (str[i] && str[i] != ' ')
				i++;
			tab[j] = strdupx(str + tmp);
			if (!tab[j])
				return (free_tab(tab), NULL);
			j++;
		}
	}
	tab[j] = 0;
	return (tab);
}