/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrandria <hrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 13:21:07 by hrandria          #+#    #+#             */
/*   Updated: 2023/10/15 17:52:33 by hrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define SUCCESS 1
# define FAIL 0
# define INT_MIN -2147483648
# define INT_MAX +2147483647

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

typedef struct s_move{
	char			*move;
	struct s_move	*next;
}					t_move;

typedef t_move*	t_node;

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
	int			result;
	t_lst		*listpa;
}				t_part;

int			lstsize(t_lst *h_a);
int			cmp(const char *str1, const char *str2);
int			ft_psb(t_lst **h_b, t_lst **h_a, t_lst **h_nb, t_node *head);
int			ft_size_move(t_node head);
int			ft_nb_min(t_lst *h_a);
int			ft_nb_max(t_lst *h_a);
int			is_sorted(t_lst *h_a);
int			xatoi(const char *nptr);
int			ft_is_max(int firstn, t_lst *a);
int			find_last_unsorted_value(t_lst *head);
int			get_index_unsorted_value(t_lst *head);
int			ft_find_median(t_lst *h_a);
int			ft_sort_three_or_swap(t_lst **h_a, t_node *head);
int			is_max_last(t_lst **h_a);
int			ft_max_to_last(t_lst **h_a, t_node *head);
int			ft_is_min(int lastn, t_lst *a);
int			ft_is_inverse_sorted(t_lst **a, int nb);
int			send_to_h_a(t_lst **b, t_lst **a, t_lst **h_nb, t_node *head);
int			partition(t_lst **h_a, t_lst **h_b, int n, t_node *head);
int			ft_check_below_median(t_lst *h_a, int median);
int			ft_lstappend(t_lst **h_a, int value);
int			len_tab(char *argv[]);
int			isdigit(int c);
int			compare_lst(t_lst **head);
int			compare_elem_tab(char **tab);
int			split_size(char *str);
int			check_more_args(int argc, char *argv[]);
int			init_value(int argc, t_lst **head, char *argv[]);
int			one_argv(int argc, char *argv[], t_lst **head);
int			is_good_args(int argc, char *argv[], t_lst **head);

void		ft_pb_push(t_lst **h_a, t_lst **h_b, \
			const char *str, t_node *head);
void		ft_sa_swap(t_lst **h_a, const char *str, t_node *head);
void		ft_sort_three_elements(t_lst **h_a, t_node *head);
void		ft_nb_push(int nb, t_lst **head_nb);
void		free_lst(t_lst **head);
void		free_t_nod(t_node head);
void		ft_pop_last(t_lst **h_a);
void		ft_pop_front(t_lst **h_a);
void		ft_check_move_chained(t_node chained);
void		ft_display_move(t_node head);
void		ft_rra_rotate(t_lst **h_a, const char *str, t_node *head);
void		ft_ra_rotate(t_lst **h_a, const char *str, t_node *head);
void		sort_list_in_ascending_order(t_lst **h_a);
void		ft_inverse_sort(t_lst **h_a, t_node *head);
void		quick_sort_hb(t_lst **h_b, t_lst **h_a, \
			t_node *move, t_part *rec);
void		final_merge(t_lst **a, t_lst **b, t_lst **h_nb, t_node *head);
void		ft_check_move_chained(t_node head);
void		free_tab(char **tab);

char		*strdupx(char *str);
char		**ft_split(char *str);

t_lst		*extract_partial_list(t_lst **h_a, int n);
t_part		sort_get_median(t_lst *h_a, int n);

t_node		del_mv(t_node head, const char *del, const char *next, int *n);
t_node		check_swap(t_node mv, int *n, const char *s1, const char *s2);
t_node		ft_append_move(t_node head, const char *move);
#endif