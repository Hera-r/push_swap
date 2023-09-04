/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrandria <hrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 18:20:44 by hrandria          #+#    #+#             */
/*   Updated: 2023/09/04 17:15:47 by hrandria         ###   ########.fr       */
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

void	ft_sa_swap(t_list **array)
{
	t_list	*tmp;
	t_list	*first;
	t_list	*second;

	first = (*array)->next;
	tmp = (*array)->next->next;
	second = *array;
	first->next = second;
	second->next = tmp;
	*array = first;
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

int	main(void)
{
	t_list *my_list;

	int	size = 0;
	int	min;
	my_list = NULL;

	int a = 2;
	int b = 3;
	int c = 7;
	int d = 0;
	my_list = ft_lstappend(my_list, &a);
	my_list = ft_lstappend(my_list, &b);
	my_list = ft_lstappend(my_list, &c);
	my_list = ft_lstappend(my_list, &d);

	t_list *tmp = my_list;

	while (tmp != NULL)
	{
		printf("%d\n", *tmp->value);
		tmp = tmp->next;
	}
	printf("**************************\n");

	// ft_ra_rotate(&my_list);
	ft_sa_swap(&my_list);
	// ft_rra_rotate(&my_list);
	// min = ft_nb_min(my_list);
	// printf("Nb-Min: %d\n", min);

	while (my_list != NULL)
	{
		printf("----=> %d\n", *my_list->value);
		my_list = my_list->next;
	}
	return (0);
}


/*

maka taille liste ohatra 10, dia aveo divisena en deux lasa 5
jerena ny nombre min ohatra hoe 0
dia aveo jerena ny index any hoe supérieur ou inférieur an'ilay moitié taille liste

raha inférieur dia mampiasa "ra" jusqu'à ce que le min soit dans la première
raha supérieur dia "rra" no ampesaina
 position de la liste, dia aveo rehefa hita push ao anatin'ny liste b
dia aveo mamerina process jusqu'à ce que le (n) de la pile A == 1 


ra : Le premier élément devient le dernier
rra: Le dernier élément devient le premier.

*/

