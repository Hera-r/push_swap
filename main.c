/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrandria <hrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 18:20:44 by hrandria          #+#    #+#             */
/*   Updated: 2023/09/17 01:18:48 by hrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
	int			*value;
	struct s_list	*next;
}					t_list;

typedef struct s_pos
{
	int			min;
	int			index;
}					t_posi;

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

t_posi	ft_nb_min(t_list *array)
{
	t_list *tmp;
	t_list *tmp2;

	t_posi data;
	int	min;
	int	index;

	index = 0;
	tmp = array;
	tmp2 = array;
	min = *tmp->value;

	while (tmp != NULL)
	{
		if (*tmp->value < min)
			min = *tmp->value;
		tmp = tmp->next;
	}
	while (tmp2 != NULL)
	{
		if (*tmp2->value == min)
		{
			index++;
			break;
		}
		tmp2 = tmp2->next;
		index++;
	}
	data.min = min;
	data.index = index;
	return (data);
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

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int	main(void)
{
	t_list *my_list;
	t_list *list_b;
	t_posi data;

	srand(time(NULL));
	int	size = 0;
	int	min;
	my_list = NULL;
	list_b = NULL;

	// int a = 3;
	// int b = 2;
	// int c = 7;
	// int d = 0;
	// // int d = 9;

	// my_list = ft_lstappend(my_list, &a);
	// my_list = ft_lstappend(my_list, &b);
	// my_list = ft_lstappend(my_list, &c);
	// my_list = ft_lstappend(my_list, &d);
	
	// {1,2, 3, 4, 5, 6, 7, 8}
	int randomNumber[] = {986, 682, 121, 743, 226, 759, 827, 455,
	 788, 290, 888, 37, 241, 466, 618, 684, 891, 815, 923, 
	 485, 301, 896, 27, 975, 769, 735, 594, 990, 53, 575, 361,
	  175, 426, 260, 625, 207, 488, 333, 434, 638, 864, 699, 197, 
	  521, 411, 315, 753, 984, 218, 541, 149, 33, 951, 610, 19, 102, 993, 721, 357, 35, 131, 912, 373, 718, 886, 832, 876, 162, 665, 240, 906, 387, 608, 559, 268, 120, 467, 139, 758, 22, 634, 251, 42, 879, 337, 283, 346, 407, 664, 825, 772, 670, 767, 104, 93, 648, 46, 582, 502, 846, 939, 748, 861, 430, 454, 809, 545, 617, 655, 608, 171, 23, 689, 605, 522, 501, 696, 285, 179, 882, 66, 25, 749, 729, 570, 752, 44, 220, 781, 973, 875, 406, 445, 92, 103, 30, 872, 324, 738, 848, 67, 461, 107, 75, 860, 865, 482, 432, 458, 140, 930, 331, 415, 802, 706, 547, 157, 195, 736, 259, 161, 789, 216, 892, 996, 598, 370, 124, 615, 580, 151, 867, 368, 493, 229, 720, 299, 322, 657, 900, 531, 258, 732, 870, 70, 969, 593, 800, 709, 583, 273, 754, 91, 782, 221, 738, 184, 189, 906, 508, 104, 265, 937, 227, 153, 156, 377, 854, 971, 471, 94, 472, 784, 491, 745, 790, 39, 77, 940, 729, 458, 694, 275, 741, 991, 351, 888, 34, 320, 562, 71, 194, 581, 330, 933, 894, 224, 885, 947, 478, 716, 424, 765, 388, 15, 898, 606, 591, 685, 116, 579, 622, 172, 208, 838, 530, 286, 512, 98, 429, 376, 506, 242, 928, 539, 31, 711, 248, 960, 678, 438, 893, 400, 269, 465, 859, 236, 311, 270, 288, 980, 306, 334, 852, 631, 858, 268, 558, 683, 468, 826, 166, 582, 746, 513, 187, 95, 777, 968, 
	972, 713, 433, 761, 587, 239, 914, 58, 509, 328, 122, 109, 881}; //{1, 2, 11, 8, 7, 9, 5, 3, 6, 10};
	int taille = sizeof(randomNumber) / sizeof(randomNumber[0]);
    // Initialiser le générateur de nombres aléatoires avec le temps actuel
    srand(time(NULL));

    // Mélanger le tableau en utilisant l'algorithme de Fisher-Yates
    for (int i = taille - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        // Échanger randomNumber[i] et randomNumber[j]
        int temp = randomNumber[i];
        randomNumber[i] = randomNumber[j];
        randomNumber[j] = temp;
    }

    for (int i = 0; i < taille; i++) {
        my_list = ft_lstappend(my_list, &randomNumber[i]);
    }

	int count = 0;
	while (ft_list_size(my_list) != 1)
	{
		// {2, 1, 11, 7, 4}
		// printf("tmp --- %d\n", tmp);
		int size_lsit = ft_list_size(my_list);
		int half_list = size_lsit  / 2;
		int	half = size_lsit  / 2;
		data = ft_nb_min(my_list);
		if (data.index <= half)
		{
			if (data.min != *my_list->value)
			{
				while (data.min != *my_list->value)
				{
					ft_ra_rotate(&my_list);
					count++;
				}
				ft_pb_push(&my_list, &list_b);
				count++;
				data = ft_nb_min(my_list);
			}
			else
			{
			ft_pb_push(&my_list, &list_b);
			count++;
			data = ft_nb_min(my_list);
			}
		}
		if (data.index > half)
		{
			if (data.min != *my_list->value)
			{
				while (data.min != *my_list->value)
				{
					ft_rra_rotate(&my_list);
				count++;
				}
				ft_pb_push(&my_list, &list_b);
				count++;
				data = ft_nb_min(my_list);
			}
			else
			{
				ft_pb_push(&my_list, &list_b);
				count++;
				data = ft_nb_min(my_list);
			}
		}
	}
	ft_pb_push(&my_list, &list_b);
	count++;
	// t_list *tmp = my_list;

	// while (tmp != NULL)
	// {
	// 	printf("%d\n", *tmp->value);
	// 	tmp = tmp->next;
	// }
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

	while (list_b != NULL)
	{
		printf("+++++=> %d\n", *list_b->value);
		list_b = list_b->next;
	}
	printf("nb coup %d\n", count);
	// return (0);
	// while (my_list != NULL)
	// {
	// 	printf("----=> %d\n", *my_list->value);
	// 	my_list = my_list->next;
	// }
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


/*
- Manao fonction iray mizara ny liste ho roa

- Manao fonction izay anaovana trie (listra A, listra B)
	- manao fonction mijery hoe efa trier ve sa tsia ny liste roa
		- mijery hoe raha faha-roa ve ilay nombre min
			*raha izay dia manao "sa" na "sb"
			* dia aveo sady manao pb
		- manao fonction mijery hoe inférieur sa supérieur

*/
