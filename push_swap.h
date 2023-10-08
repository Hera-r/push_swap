/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrandria <hrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 13:21:07 by hrandria          #+#    #+#             */
/*   Updated: 2023/10/08 21:21:37 by hrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP
# define SUCCESS 1
# define FAIL 0
# define INT_MIN -2147483648

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "ft_printf/ft_printf.h"
# include "my_libft/libft.h"

typedef struct s_list
{
	int				value;
	struct s_list	*next;
}					t_lst;

typedef struct s_partial
{
	int			median;
	int			size_sub;
	int			ison;
	int			maxon;
	int			i;
	int			n;
	int			nb;
	int			max_v;
	int			unsorted_v;
	int			send_ha_v;
	int			nb_value;
	int			nb_three;
	t_lst		*listpa;
}				t_part;

typedef struct t_fatoi{
	int     n;
	char    err;
}			t_fatoi;

int	lstsize(t_lst *h_a);
int	ft_nb_min(t_lst *h_a);
int	ft_nb_max(t_lst *h_a);
int	is_sorted(t_lst *h_a);
int find_last_unsorted_value(t_lst *head);
int	get_index_unsorted_value(t_lst *head);
int	ft_find_median(t_lst *h_a);
int	ft_check_below_median(t_lst *h_a, int median);
int	ft_sort_three_or_swap(t_lst **h_a, int *ison);
int	is_max_last(t_lst **h_a);
int	ft_max_to_last(t_lst **h_a);
int	send_to_h_a(t_lst **h_b, t_lst **h_a, t_lst **h_nb);
int find_last_unsorted_value(t_lst *head);
int	get_index_unsorted_value(t_lst *head);
int	ft_check_below_median(t_lst *h_a, int median);

void	ft_sa_swap(t_lst **h_a, char *str);
void	ft_pop_last(t_lst **h_a);
void	ft_pop_front(t_lst **h_a);
void	ft_rra_rotate(t_lst **h_a, char *str);
void	ft_ra_rotate(t_lst **h_a, char *str);
void	ft_pb_push(t_lst **h_a, t_lst **h_b, const char *str);
void	ft_nb_push(int nb, t_lst **head_nb);
void	sort_list_in_ascending_order(t_lst **h_a);
void	partition(t_lst **h_a, t_lst **h_b, t_lst **nb, int n);

t_lst	*ft_lstappend(t_lst *h_a, int value);
t_lst	*extract_partial_list(t_lst *h_a, int n);
// t_lst	delete_occurrence(t_lst *head);

t_part	sort_get_median(t_lst *h_a, int n);


t_fatoi	ft_atoi(char *str);

#endif
