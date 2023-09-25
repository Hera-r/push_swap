/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrandria <hrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 18:20:44 by hrandria          #+#    #+#             */
/*   Updated: 2023/09/25 20:23:14 by hrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
	int			*value;
	struct s_list	*next;
}					t_list;

int	ft_list_size(t_list *array)
{
	t_list *tmp;
	int	size;

	tmp = array;
	size = 0;
	while (tmp != NULL)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}

int	ft_nb_min(t_list *array)
{
	t_list *tmp;
	int	min;

	tmp = array;
	min = *tmp->value;
	while (tmp != NULL)
	{
		if (*tmp->value < min)
			min = *tmp->value;
		tmp = tmp->next;
	}
	return (min);
}

int	ft_nb_max(t_list *array)
{
	t_list *tmp;
	int	max;

	tmp = array;
	max = *tmp->value;
	while (tmp != NULL)
	{
		if (*tmp->value > max)
			max = *tmp->value;
		tmp = tmp->next;
	}
	return (max);
}

int	ft_is_sorting(t_list *array)
{
	t_list	*tmp;

	tmp = array;
	while (tmp->next != NULL)
	{
		if (*tmp->value > *tmp->next->value)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	ft_pb_push(t_list **array, t_list **list_b)
{
	t_list	*tmp_a;
	t_list	*tmp_b;
	t_list	*tmp_c;

	tmp_a = (*array)->next;
	tmp_b = *list_b;
	if (*list_b == NULL)
	{
		tmp_b = *array;
		tmp_b->next = NULL;
		*list_b = tmp_b;
		*array = tmp_a;
		// printf("pb\n");
	}
	else
	{
		tmp_c = *array;
		tmp_c->next = tmp_b;
		*list_b = tmp_c;
		*array = tmp_a;
		// printf("pb\n");
	}
}

void	ft_sa_swap(t_list **array)
{
	int	*tmp;

	tmp = (*array)->next->value;
	(*array)->next->value = (*array)->value;
	(*array)->value = tmp;
}

void	ft_pop_last(t_list **array)
{
	t_list *tmp;
	t_list *last;

	tmp = *array;
	last = NULL;
	while (tmp->next != NULL)
	{
		last = tmp;
		tmp = tmp->next;
	}
	last->next = NULL;
}

void	ft_rra_rotate(t_list **array)
{
	t_list *tmp;

	tmp = *array;
	while (tmp->next != NULL)
		tmp = tmp->next;
	ft_pop_last(array);
	tmp->next = *array;
	*array = tmp;
}

void	ft_ra_rotate(t_list **array)
{
	t_list	*tmp;
	t_list	*first;

	tmp = *array;
	first = (*array)->next;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = *array;
	tmp->next->next = NULL;
	*array = first;
}

t_list	*ft_lstappend(t_list *array, int *value)
{
	t_list	*element;
	t_list	*tmp;

	tmp = array;
	element = malloc(sizeof(*element));
	if (element == NULL)
		return (NULL);
	element->value = value;
	element->next = NULL;
	if (array == NULL)
		array = element;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = element;
	}
	return (array);
}

// mettre les 3 fonctions du dessous dans une fonction "sort_and_get_median(list, n)"
t_list	*extract_partial_list(t_list *array, int n)
{
	t_list	*list_asc;
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = array;
	if (n == 0)
		n = ft_list_size(array);
	while (i < n)
	{
		list_asc = ft_lstappend(list_asc, *tmp->value);
		tmp = tmp->next;
		i++;
	}
	return (list_asc);
}

// {1, 2, 11, 8, 7, 9, 5, 3, 6, 10}
void	sort_list_in_ascending_order(t_list **array)
{
	t_list	*lstmp;
	int		*tmp;

	lstmp = *array;
	while (lstmp->next != NULL)
	{
		if (*lstmp->value > *lstmp->next->value)
		{
			tmp = lstmp->next->value;
			lstmp->next->value = lstmp->value;
			lstmp->value = tmp;
		}
		lstmp = lstmp->next;
		if (lstmp->next == NULL && ft_is_sorting(*array) != 0)
			lstmp = *array;
	}
}

int	ft_find_median(t_list *array)
{
	t_list	*tmp;
	int		size_list;
	int		i;

	i = 0;
	tmp = array;
	size_list = ft_list_size(array);
	while (i < (size_list / 2))
	{
		tmp = tmp->next;
		i++;
	}
	if (size_list % 2 != 0)
		return (*tmp->value);
	else
		return ((*tmp->value + *tmp->next->value) / 2);
}

int	ft_check_below_median(t_list *array, int median)
{
	t_list	*tmp;

	tmp = array;
	while (tmp != NULL)
	{
		if (*tmp->value > median)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void ft_sort_three_elements(t_list **array)
{
	int	*one;
	int *two;
	int	*last;

	one = (*array)->value;
	two = (*array)->next->value;
	last = (*array)->next->next->value;
	while (ft_is_sorting(*array) != 0)
	{
		if (ft_nb_min(*array) == *one && ft_nb_max(*array) == *two)
		{
			ft_rra_rotate(array);
			ft_sa_swap(array);
		}
		else if (ft_nb_max(*array) > *one && ft_nb_min(*array) == *last)
			ft_rra_rotate(array);
		else if (ft_nb_max(*array) == *one && ft_nb_min(*array) == *two)
			ft_ra_rotate(array);
		else if (*two < *one && *two < *last)
			ft_sa_swap(array);
		else if (ft_nb_max(*array) == *one && ft_nb_min(*array) == *last)
		{
			ft_ra_rotate(array);
			ft_sa_swap(array);
		}
	}
}

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int	main(void)
{
	t_list *my_list;
	t_list *list_b;

	srand(time(NULL));
	int	size = 0;
	int	min;
	my_list = NULL;
	list_b = NULL;

	// {1,2, 3, 4, 5, 6, 7, 8}
	int randomNumber[] = {1,2, 3}; //{11, 2, 1, 8, 7, 9, 5, 3, 6, 10};
	int taille = sizeof(randomNumber) / sizeof(randomNumber[0]);
    srand(time(NULL));

    for (int i = taille - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = randomNumber[i];
        randomNumber[i] = randomNumber[j];
        randomNumber[j] = temp;
    }

    for (int i = 0; i < taille; i++) {
		printf("app - %d\n", randomNumber[i]);
        my_list = ft_lstappend(my_list, &randomNumber[i]);
    }


	ft_sort_three_elements(&my_list);

	t_list *tmp = my_list;

	while (tmp != NULL)
	{
		printf("%d\n", *tmp->value);
		tmp = tmp->next;
	}
	if (ft_is_sorting(my_list) == 0)
		printf("OK\n");
	else
		printf("error\n");

	// int med = ft_find_median(my_list);
	// printf("median - %d\n", med);


	// printf("**************************\n");
	// ft_ra_rotate(&my_list);
	// ft_sa_swap(&my_list);
	// ft_pb_push(&my_list, &list_b);
	// ft_pb_push(&my_list, &list_b);
	// ft_pb_push(&my_list, &list_b);
	// ft_pb_push(&my_list, &list_b);
	// ft_pb_push(&my_list, &list_b);


    // for (int i = 0; i < taille/2; i++) {
    //     ft_pb_push(&my_list, &list_b);
    // }

	// t_list *tmp = my_list;

	// while (tmp != NULL)
	// {
	// 	printf("----=> %d\n", *tmp->value);
	// 	tmp = tmp->next;
	// }
	// printf("**************************\n");
	// ft_rra_rotate(&my_list);
	// min = ft_nb_min(my_list);
	// printf("Nb-Min: %d\n", min);

	// while (list_b != NULL)
	// {
	// 	printf("+++++=> %d\n", *list_b->value);
	// 	list_b = list_b->next;
	// }
	// return (0);
	// while (my_list != NULL)
	// {
	// 	printf("----=> %d\n", *my_list->value);
	// 	my_list = my_list->next;
	// }
	return (0);
}


// TO DO
/*
 - faire une fonction pop_front
*/

/*

ra : Le premier élément devient le dernier
rra: Le dernier élément devient le premier.

*/

