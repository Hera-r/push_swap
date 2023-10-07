/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrandria <hrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 18:20:44 by hrandria          #+#    #+#             */
/*   Updated: 2023/10/08 00:37:53 by hrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
# define INT_MIN -2147483648

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

int	lstsize(t_lst *h_a)
{
	t_lst *tmp;
	int	size;

	tmp = h_a;
	size = 0;
	while (tmp != NULL)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}

int	ft_nb_min(t_lst *h_a)
{
	t_lst *tmp;
	int	min;

	tmp = h_a;
	min = tmp->value;
	while (tmp != NULL)
	{
		if (tmp->value < min)
			min = tmp->value;
		tmp = tmp->next;
	}
	return (min);
}

int	ft_nb_max(t_lst *h_a)
{
	t_lst *tmp;
	int	max;

	tmp = h_a;
	max = tmp->value;
	while (tmp != NULL)
	{
		if (tmp->value > max)
			max = tmp->value;
		tmp = tmp->next;
	}
	return (max);
}

int	is_sorted(t_lst *h_a)
{
	t_lst	*tmp;

	tmp = h_a;
	if (tmp == NULL)
		return (1);
	while (tmp->next != NULL)
	{
		if (tmp->value > tmp->next->value)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void display(t_lst *h_b)
{
	// printf("*******************\n");
	t_lst *tmp_b =  NULL;
		tmp_b = h_b;
	while (tmp_b != NULL)
	{
		printf("- %d\n", tmp_b->value);
		tmp_b = tmp_b->next;
	}
}

void	ft_pb_push(t_lst **h_a, t_lst **h_b, char *str)
{
	t_lst	*tmp_a;
	t_lst	*tmp_b;
	t_lst	*tmp_c;

	tmp_a = (*h_a)->next;
	tmp_b = *h_b;
	if (*h_b == NULL)
	{
		tmp_b = *h_a;
		tmp_b->next = NULL;
		*h_b = tmp_b;
		*h_a = tmp_a;
	}
	else
	{
		tmp_c = *h_a;
		tmp_c->next = tmp_b;
		*h_b = tmp_c;
		*h_a = tmp_a;
	}
	printf("%s\n", str);
}

void	ft_nb_push(int nb, t_lst **head_nb)
{
	t_lst	*elmt;

	elmt = malloc(sizeof(*elmt));
	if (elmt == NULL)
		return ;
	elmt->value = nb;
	elmt->next = NULL;
	if (head_nb == NULL)
		*head_nb = elmt;
	else
	{
		elmt->next = *head_nb;
		*head_nb = elmt;
	}
}

void	ft_sa_swap(t_lst **h_a, char *str)
{
	int	tmp;

	tmp = (*h_a)->next->value;
	(*h_a)->next->value = (*h_a)->value;
	(*h_a)->value = tmp;
	printf("%s\n",str);
}

void	ft_pop_last(t_lst **h_a)
{
	t_lst *tmp;
	t_lst *last;

	tmp = *h_a;
	last = NULL;
	if (h_a == NULL)
		return ;
	while (tmp->next != NULL)
	{
		last = tmp;
		tmp = tmp->next;
	}
	last->next = NULL;
}

void	ft_pop_front(t_lst **h_a)
{
	t_lst	*tmp;

	if ((*h_a)->next == NULL)
	{
		*h_a = NULL;
		return ;
	}
	tmp = (*h_a)->next;
	*h_a = tmp;
}

void	ft_rra_rotate(t_lst **h_a, char *str)
{
	t_lst *tmp;

	tmp = *h_a;
	if (tmp == NULL)
		return ;
	while (tmp && tmp->next != NULL)
		tmp = tmp->next;
	ft_pop_last(h_a);
	tmp->next = *h_a;
	*h_a = tmp;
	printf("%s\n",str);
}

void	ft_ra_rotate(t_lst **h_a, char *str)
{
	t_lst	*tmp;
	t_lst	*first;

	tmp = *h_a;
	if (tmp == NULL)
		return ;
	first = (*h_a)->next;
	while (tmp && tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = *h_a;
	tmp->next->next = NULL;
	*h_a = first;
	printf("%s\n",str);
}

t_lst	*ft_lstappend(t_lst *h_a, int value)
{
	t_lst	*element;
	t_lst	*tmp;

	tmp = h_a;
	element = malloc(sizeof(*element));
	if (element == NULL)
		return (NULL);
	element->value = value;
	element->next = NULL;
	if (h_a == NULL)
		h_a = element;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = element;
	}
	tmp = NULL;
	return (h_a);
}

t_lst	*extract_partial_list(t_lst *h_a, int n)
{
	t_lst	*list_asc;
	t_lst	*tmp;
	int		i;

	i = 0;
	tmp = h_a;
	list_asc = NULL;
	if (tmp == NULL)
		return (list_asc);
	if (n == 0)
		n = lstsize(h_a);
	while (i < n)
	{
		list_asc = ft_lstappend(list_asc, tmp->value);
		tmp = tmp->next;
		i++;
	}
	return (list_asc);
}

int find_last_unsorted_value(t_lst *head)
{
	t_lst	*tmp;
	int		last_unsorted;

	tmp = head;
	last_unsorted = INT_MIN;
	while (tmp != NULL && tmp->next != NULL)
	{
		if (tmp->value > tmp->next->value) {
			last_unsorted = tmp->next->value;
		}
		tmp = tmp->next;
	}
	return last_unsorted;
}

int	get_index_unsorted_value(t_lst *head)
{
	t_lst	*tmp;
	int		n;
	int		target;

	tmp = head;
	n = 0;
	if (is_sorted(head) == 0)
		return (n);
	target = find_last_unsorted_value(head);
	while (tmp != NULL)
	{
		n++;
		if (tmp->value == target)
			return (n);
		tmp = tmp->next;
	}
	return (n);
}

void	sort_list_in_ascending_order(t_lst **h_a)
{
	t_lst	*lstmp;
	int		tmp;

	lstmp = *h_a;
	if (lstmp == NULL)
		return ;
	while (lstmp->next != NULL)
	{
		if (lstmp->value > lstmp->next->value)
		{
			tmp = lstmp->next->value;
			lstmp->next->value = lstmp->value;
			lstmp->value = tmp;
		}
		lstmp = lstmp->next;
		if (lstmp->next == NULL && is_sorted(*h_a) != 0)
			lstmp = *h_a;
	}
}

int	ft_find_median(t_lst *h_a)
{
	t_lst	*tmp;
	t_lst	*prev;
	int		size_list;
	int		i;

	i = 0;
	tmp = h_a;
	size_list = lstsize(h_a);
	while (i < (size_list / 2))
	{
		prev = tmp;
		tmp = tmp->next;
		i++;
	}
	if (size_list % 2 != 0)
		return (tmp->value);
	return ((prev->value + tmp->value) / 2);
}

t_part	sort_get_median(t_lst *h_a, int n)
{
	t_lst	*tmp;
	t_part	data;
	int		median;

	tmp = extract_partial_list(h_a, n);
	data.size_sub = lstsize(tmp);
	data.listpa = tmp;
	sort_list_in_ascending_order(&tmp);
	median = ft_find_median(tmp);
	data.median = median;
	return (data);
}

int	ft_check_below_median(t_lst *h_a, int median)
{
	t_lst	*tmp;

	tmp = h_a;
	while (tmp != NULL)
	{
		if (tmp->value > median)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void ft_sort_three_elements(t_lst **h_a)
{
	int	one;
	int two;
	int	last;

	one = (*h_a)->value;
	two = (*h_a)->next->value;
	last = (*h_a)->next->next->value;
	while (is_sorted(*h_a) != 0)
	{
		if (ft_nb_min(*h_a) == one && ft_nb_max(*h_a) == two)
		{
			ft_rra_rotate(h_a, "rra");
			ft_sa_swap(h_a, "sa");
		}
		else if (ft_nb_max(*h_a) > one && ft_nb_min(*h_a) == last)
			ft_rra_rotate(h_a, "rra");
		else if (ft_nb_max(*h_a) == one && ft_nb_min(*h_a) == two)
			ft_ra_rotate(h_a, "ra");
		else if (two < one && two < last)
			ft_sa_swap(h_a, "sa");
		else if (ft_nb_max(*h_a) == one && ft_nb_min(*h_a) == last)
		{
			ft_ra_rotate(h_a, "ra");
			ft_sa_swap(h_a, "sa");
		}
	}
}

int	ft_sort_three_or_swap(t_lst **h_a, int *ison)
{
	int	on;

	on = 0;
	if (h_a == NULL)
		return (0);
	if (lstsize(*h_a) == 3 && is_sorted(*h_a) != 0)
	{
		ft_sort_three_elements(h_a);
		on = 3;
		*ison = 1;
	}
	else if (lstsize(*h_a) == 2 && is_sorted(*h_a) != 0)
	{
		ft_sa_swap(h_a, "sa");
		on = 2;
		*ison = 1;
	}
	return (on);
}

int	is_max_last(t_lst **h_a)
{
	t_lst *tmp;
	int		max;

	tmp = *h_a;
	if (tmp == NULL)
		return (1);
	max = ft_nb_max(*h_a);
	while (tmp->value != max)
		tmp = tmp->next;
	if (tmp->next != NULL)
		return (1);
	return (0);
}

int	ft_max_to_last(t_lst **h_a)
{
	t_lst *tmp;
	int		max;
	int		n;

	tmp = *h_a;
	if (tmp == NULL)
		return (0);
	n = 0;
	if (lstsize(*h_a) > 3)
	{
		max = ft_nb_max(*h_a);
		while (tmp->value != max)
			tmp = tmp->next;
		while (tmp->next != NULL)
		{
			ft_rra_rotate(h_a, "rra");
			if (h_a && (*h_a)->next != NULL && (*h_a)->value > (*h_a)->next->value)
				ft_sa_swap(h_a, "sa");
			n++;
		}
	}
	return (n);
}

int	send_to_h_a(t_lst **h_b, t_lst **h_a, t_lst **h_nb)
{
	int	i;
	int	isexec;

	i = 0;
	isexec = 0;
	if (is_max_last(h_a) == 0 && is_sorted(*h_a) == 0)
 	{
		if ((*h_nb)->value == 2)
		{
			if (h_b && (*h_b)->value < (*h_b)->next->value)
				ft_sa_swap(h_b, "sb");
		}
		while (i < (*h_nb)->value)
		{
			ft_pb_push(h_b, h_a, "pa");
			i++;
		}
	isexec = 1;
	}
	if (isexec == 1)
	{
		if (h_nb != NULL)
			isexec = (*h_nb)->value;
		else
			isexec = 0;
		ft_pop_front(h_nb);
		return (isexec);
	}
	return (isexec);
}

void	partition(t_lst **h_a, t_lst **h_b, t_lst **nb, int n)
{
	t_lst		*tmp;
	t_part		rec;

	tmp = *h_a;
	if (tmp == NULL)
		return ;

	rec = sort_get_median(tmp, n);
	rec.nb = 0;
	rec.i = 0;

	while (rec.size_sub > 0)
	{
		if (tmp && tmp->value < rec.median)
		{
			ft_pb_push(h_a, h_b, "pb");
			rec.nb++;
		}
		else if (tmp->value >= rec.median)
			ft_ra_rotate(h_a, "ra");
		tmp = *h_a;
		rec.size_sub--;
	}

	if (rec.nb != 0)
		ft_nb_push(rec.nb, nb);
}

void	ft_push_swap(t_lst **h_a, t_lst **h_b, t_lst **h_nb, int *ison)
{
	t_lst	*tmp;
	t_part	rec;

	rec.n = 0;
	rec.max_v = 0;
	rec.unsorted_v = 0;
	rec.send_ha_v = 0;
	rec.nb_three = 0;


// ***Decouper la liste tant qu'il est superieur a 3 apres trier le N elements restant *****
	while (lstsize(*h_a) > 3)
	{
		partition(h_a, h_b, h_nb, rec.n);
	}
	ft_sort_three_or_swap(h_a, ison);
// ***************************************************

	while (is_sorted(*h_a) != 0 || lstsize(*h_nb) != 0)
	{
		if (rec.unsorted_v < 3)
		{
			rec.send_ha_v = send_to_h_a(h_b, h_a, h_nb);
		}
			
	// 	// ***********************************************************************************************


	// 	// *********** rentre dans cette condition si l'un des deux condition son rempli ************
		if (rec.send_ha_v > 2 || rec.unsorted_v > 2)
		{
			if (rec.send_ha_v > 2)
			{
				rec.n = rec.send_ha_v;
				partition(h_a, h_b, h_nb, rec.n);
			}
			else
				partition(h_a, h_b, h_nb, rec.unsorted_v);
		}
		// ******************************************************************************************
		// ** on verifier si Nombre-Max est a la dernire position, si c'est non on le remet **********
		ft_max_to_last(h_a);
		// ********************************************************************************************
		// ********* Initialiser les deux valeurs a zero ********************************************
		rec.send_ha_v = 0;
		rec.unsorted_v = 0;
		// *****************************************************************************************
		rec.unsorted_v = get_index_unsorted_value(*h_a);
	}
}




#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int	main(void)
{
	t_lst	*my_list;
	t_lst	*h_b;
	t_lst	*list_nb;
	int		ison;

	my_list = NULL;
	h_b = NULL;
	list_nb = NULL;
	srand(time(NULL));
	ison = 0;
	int	size = 0;
	int	min;

// ***********************BASIC ELEMENTS****************************************************
	//{1,2, 3, 4, 5, 6, 7, 8} {0, 4 ,3, 8, 1, 2};
	// int randomNumber[] = {185, 361, 83, 286, 405, 469, 297, 221, 198, 496, 128, 372, 319, 346, 98, 203, 354, 28, 148, 413};  //{11, 4 ,3, 8, 1, 2}; //{11, 2, 1, 8, 7, 9, 5, 3, 6, 10};
	// int taille = sizeof(randomNumber) / sizeof(randomNumber[0]);
    // srand(time(NULL));

    // for (int i = taille - 1; i > 0; i--) {
    //     int j = rand() % (i + 1);
    //     int temp = randomNumber[i];
    //     randomNumber[i] = randomNumber[j];
    //     randomNumber[j] = temp;
    // }
// ****************************************************************************
// ***************RANDOM ELEMENTS**********************************************
    srand(time(NULL));

    const int taille = 100; // taille de la liste
    int randomNumber[taille];

    // Remplir le tableau avec des nombres aléatoires uniques de 0 à 100
    for (int i = 0; i < taille; ++i) {
        int nombreAleatoire;
        int estDejaPresent;

        do {
            estDejaPresent = 0;
            nombreAleatoire = rand() % 1001 - 500;  // Génère un nombre aléatoire entre 0 et 100

            for (int j = 0; j < i; ++j) {
                if (randomNumber[j] == nombreAleatoire) {
                    estDejaPresent = 1;
                    break;
                }
            }
        } while (estDejaPresent);

        randomNumber[i] = nombreAleatoire;
    }
// // **********************************************************************************
    for (int i = 0; i < taille; i++) {
        my_list = ft_lstappend(my_list, randomNumber[i]);
		// printf("%d\n", randomNumber[i]);
    }
// 	// printf("*******************\n");




// *********************************************************************************
	// t_part data = 	sort_get_median(my_list, 0);
	// printf("data %d\n", data.median);

	// my_list = ft_lstappend(my_list, 11);
	// my_list = ft_lstappend(my_list, 4);
	// my_list = ft_lstappend(my_list, 3);
	// my_list = ft_lstappend(my_list, 18);
	// my_list = ft_lstappend(my_list, 1);
	// my_list = ft_lstappend(my_list, 2);
	// my_list = ft_lstappend(my_list, 5);
	// my_list = ft_lstappend(my_list, 6);
	// my_list = ft_lstappend(my_list, 12);
	// my_list = ft_lstappend(my_list, 20);
	// my_list = ft_lstappend(my_list, 10);
	// my_list = ft_lstappend(my_list, 0);
	// my_list = ft_lstappend(my_list, 7);
	// my_list = ft_lstappend(my_list, 13);
	// my_list = ft_lstappend(my_list, 9);
	// my_list = ft_lstappend(my_list, 14);
	// my_list = ft_lstappend(my_list, 8);
	// my_list = ft_lstappend(my_list, 17);
	// my_list = ft_lstappend(my_list, 16);
	// my_list = ft_lstappend(my_list, 15);
	// my_list = ft_lstappend(my_list, 19);
	// my_list = ft_lstappend(my_list, 656);
	// my_list = ft_lstappend(my_list, 105);
	// my_list = ft_lstappend(my_list, 500);
	// my_list = ft_lstappend(my_list, 449);
	// my_list = ft_lstappend(my_list, 593);




	// partition(&my_list, &h_b, &list_nb, 0);


	// h_b = ft_lstappend(h_b, 1);
	// h_b = ft_lstappend(h_b, 2);
	// printf("*******************\n");
	// ft_nb_push(2, &list_nb);
	// send_to_h_a(&h_b, &my_list, &list_nb);

	ft_push_swap(&my_list, &h_b, &list_nb, &ison);

	// sort_list_in_ascending_order(&my_list);

	// printf("*******************\n");

	// t_lst *tmp = my_list;

	// while (tmp != NULL)
	// {
	// 	printf("%d\n", tmp->value);
	// 	tmp = tmp->next;
	// }

	// int sortd = is_sorted(my_list);
	// if (sortd == 0)
	// 	printf("OK\n");
	// printf("*******************\n");
	// t_lst *tmp_b = h_b;
	// while (tmp_b != NULL)
	// {
	// 	printf("- %d\n", tmp_b->value);
	// 	tmp_b = tmp_b->next;
	// }
	// printf("*******************\n");
	// t_lst *tmp_b = h_b;
	// while (tmp_b != NULL)
	// {
	// 	printf("- %d\n", tmp_b->value);
	// 	tmp_b = tmp_b->next;
	// }

// 	// int med = ft_find_median(my_list);
// 	// printf("median - %d\n", med);


// 	// printf("**************************\n");
// 	// ft_ra_rotate(&my_list);
// 	// ft_sa_swap(&my_list);
// 	// ft_pb_push(&my_list, &h_b);
// 	// ft_pb_push(&my_list, &h_b);
// 	// ft_pb_push(&my_list, &h_b);
// 	// ft_pb_push(&my_list, &h_b);
// 	// ft_pb_push(&my_list, &h_b);


//     // for (int i = 0; i < taille/2; i++) {
//     //     ft_pb_push(&my_list, &h_b);
//     // }

// 	// t_lst *tmp = my_list;

// 	// while (tmp != NULL)
// 	// {
// 	// 	printf("----=> %d\n", *tmp->value);
// 	// 	tmp = tmp->next;
// 	// }	t_lst *tmp;

// 	// printf("**************************\n");
// 	// ft_rra_rotate(&my_list);
// 	// min = ft_nb_min(my_list);
// 	// printf("Nb-Min: %d\n", min);

// 	// while (h_b != NULL)
// 	// {
// 	// 	printf("+++++=> %d\n", *h_b->value);
// 	// 	h_b = h_b->next;
// 	// }
// 	// return (0);
// 	// while (my_list != NULL)
// 	// {
// 	// 	printf("----=> %d\n", *my_list->value);
// 	// 	my_list = my_list->next;
// 	// }
	return (0);
 }



/*

ra : Le premier élément devient le dernier
rra: Le dernier élément devient le premier.

*/


/*

{167, 48, 38, 131, 37, 7, 138
	, 181, 137, 10, 103, 14, 178, 129, 73, 
	80, 41, 154, 30, 98, 65, 136, 90, 
	21, 22, 176, 159, 25, 26, 55, 170, 19, 3, 56, 9, 77, 93, 16, 15, 74, 105}


*/





	// 	// *********Si la liste A est trier et la taille de B est inferieur ou egal a 3 *************
		// if (h_b != NULL && is_sorted(*h_a) == 0 && lstsize(*h_b) <= 3)
		// {
		// 	if (lstsize(*h_b) == 1)
		// 	{
		// 		ft_pb_push(h_b, h_a);
		// 		h_nb = NULL;
		// 	}
		// 	else
		// 		{
		// 			rec.nb_three = ft_sort_three_or_swap(h_b, ison); // A coder une fonction qui inverse sort
		// 			while (rec.nb_three > 0)
		// 			{
		// 				ft_pb_push(h_b, h_a);
		// 				rec.nb_three--;
		// 			}
		// 			h_nb = NULL;
		// 		}
		// }
	// 	// ******************************************************************************************