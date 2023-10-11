/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrandria <hrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 10:48:59 by hrandria          #+#    #+#             */
/*   Updated: 2023/10/11 23:44:28 by hrandria         ###   ########.fr       */
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
			j++;
		}
	}
	tab[j] = 0;
	return (tab);
}


int b_atoi(char *str)
{
	int	i;
	int	nb;
	int	sign;

	i = 0;
	nb = 0;
	sign = 1;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}	
	while (str[i])
	{
		nb = (nb * 10) + str[i] - '0';
		i++;
	}
	return (nb * sign);
}

int	one_argv(int argc, char *argv[])
{
	if(argc == 2)
	{
		if (has_digit(argv[1]) == 1)
		{
			printf("Error\n");
			return (1);
		}
		else if (not_space_or_digit(argv[1]) == 1)
		{
			printf("Error\n");
			return (1);
		}
	}
	return (0);
}

int	check_more_args(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	if (argc >= 2)
	{
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
	}
	return (0);
}

int	is_good_args(int argc, char *argv[])
{
	if (one_argv(argc, argv) == 1)
		return (1);
	else if (check_more_args(argc, argv) == 1)
		return (1);
	return (0);
}

// t_lst	list_one(t_lst *my_list)
// {
	
// }


int main(int argc, char *argv[])
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
		if (is_good_args(argc, argv) == 1)
			return (0);
		// if (argc == 2)
		// {
			
		// }
	}
	return (0);
}
