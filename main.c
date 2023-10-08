/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrandria <hrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 18:20:44 by hrandria          #+#    #+#             */
/*   Updated: 2023/10/08 17:38:22 by hrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static void display(t_lst *head)
// {
// 	// printf("*******************\n");
// 	t_lst *tmp =  NULL;
// 		tmp = head;
// 	while (tmp != NULL)
// 	{
// 		printf("- %d\n", tmp->value);
// 		tmp = tmp->next;
// 	}
// }

void	ft_push_swap(t_lst **h_a, t_lst **h_b, t_lst **h_nb, int *ison)
{
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