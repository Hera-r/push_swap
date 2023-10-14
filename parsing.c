/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrandria <hrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 10:48:59 by hrandria          #+#    #+#             */
/*   Updated: 2023/10/15 01:58:59 by hrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_list
{
	int				value;
	struct s_list	*next;
}					t_lst;

typedef struct s_move{
	char			*move;
	struct s_move	*next;
}					t_move;

typedef t_move*	t_node;
# define SUCCESS 1
# define FAIL 0
# define INT_MIN -2147483648
# define INT_MAX +2147483647

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

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

int	has_digit(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (isdigit(argv[i]) == 1)
			return (0);
		i++;
	}
	return (1);
}

void free_tab(char **tab)
{
	int	size;
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free (tab);
}

int	xstrcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	not_space_or_digit(char argv[])
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (isdigit(argv[i]) != 1 && argv[i] != ' ')
			return (1);
	i++;
	}
	return (0);
}

int	len_dup(char *str)
{
	int	i;

	i = 0;
	while(str[i] && str[i] != ' ')
	i++;
	return (i);
}

char	*strdupx(char *str)
{
	char	*str_buffer;
	int		size;
	int		i;
	
	i = 0;
	size = len_dup(str);
	str_buffer = malloc((size + 1) * sizeof(char));
	if (str_buffer == NULL)
		return (NULL);
	while (str[i] && str[i] != ' ')
	{
		str_buffer[i] = str[i];
		i++;
	}
	str_buffer[i] = '\0';
	return (str_buffer);
}

static int	is_space(char c)
{
	if ((c >= 9 && c <= 13) || (c == ' '))
		return (1);
	return (0);
}

int	xatoi(const char *nptr)
{
	int	i;
	int	sign;
	int	n;

	i = 0;
	sign = 1;
	n = 0;
	while (is_space(nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (isdigit(nptr[i]))
	{
		n = n * 10 + (nptr[i] - '0');
		i++;
	}
	return (n * sign);
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
				return (printf("Error\n"), 1);
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
				return (printf("Error\n"), 1);
			after = after->next;
		}
	tmp = tmp->next;
	}
	return (0);
}

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

int	init_value(int argc, t_lst **head, char *argv[])
{
	int	i;
	int	test;

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
	int		i;

	i = 0;
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
		if (check_more_args(argc, argv) == 0)
			if (init_value(argc, head, argv) == 1)
				return (1);
			else
				return (0);
	}
	if (one_argv(argc, argv, head) == 1)
		return (1);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_lst	*my_list;
	t_lst	*h_b;
	t_lst	*list_nb;
	t_node	head;

	my_list = NULL;
	h_b = NULL;
	list_nb = NULL;
	head = NULL;
	if (argc > 1)
	{
		if (is_good_args(argc, argv, &my_list) == 1)
			return (0); // meettre le free t_lst aussi ici
		if (compare_lst(&my_list) == 1)
			return (0); // meettre le free t_lst aussi ici
	}
	return (0);
}

		// t_lst *tmp_b =  my_list;
		// while (tmp_b != NULL)
		// {
		// 	printf("-> %d\n", tmp_b->value);
		// 	tmp_b = tmp_b->next;
		// }