/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrandria <hrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 18:20:44 by hrandria          #+#    #+#             */
/*   Updated: 2023/10/10 21:05:05 by hrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	ft_push_swap(t_lst **h_a, t_lst **h_b, t_lst **h_nb, t_node *move_chained)
{
	t_part	rec;
	int		result;

	rec.n = 0;
	rec.max_v = 0;
	rec.unsorted_v = 0;
	rec.send_ha_v = 0;
	rec.nb_three = 0;


// ***Decouper la liste tant qu'il est superieur a 3 apres trier le N elements restant *****
	while (lstsize(*h_a) > 3)
	{
		// printf("********* HERE before partition *********\n");
		// display(*h_a);
		result = partition(h_a, h_b, rec.n, move_chained);
		if (result != 0)
			ft_nb_push(result, h_nb);
	}
	ft_sort_three_or_swap(h_a, move_chained);
// ***************************************************

	while (is_sorted(*h_a) != 0 || lstsize(*h_nb) != 0)
	{
		if (rec.unsorted_v < 3)
		{
			rec.send_ha_v = send_to_h_a(h_b, h_a, h_nb, move_chained);
			if (is_sorted(*h_a) == 0 && ft_is_inverse_sorted(h_b, lstsize(*h_b)) == 1)
			{
				final_merge(h_a, h_b, move_chained);
				ft_pop_front(h_nb);
				// printf("HERE stack A\n");
				// display(*h_a);
				break ;
			}
		}
			
	// 	// ***********************************************************************************************


	// 	// *********** rentre dans cette condition si l'un des deux condition son rempli ************
		if (rec.send_ha_v > 2 || rec.unsorted_v > 2)
		{
			if (rec.send_ha_v > 2)
			{
				rec.n = rec.send_ha_v;
				result = partition(h_a, h_b, rec.n, move_chained);
				if (result != 0)
					ft_nb_push(result, h_nb);
			}
			else
			{
				result = partition(h_a, h_b, rec.unsorted_v, move_chained);
				if (result != 0)
					ft_nb_push(result, h_nb);
			}
		}

		// ******************************************************************************************
		// ** on verifier si Nombre-Max est a la dernire position, si c'est non on le remet **********
		ft_max_to_last(h_a, move_chained);
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
	t_node	move_chained;

	my_list = NULL;
	h_b = NULL;
	list_nb = NULL;
	move_chained = NULL;
	// srand(time(NULL));
	// int	size = 0;
	// int	min;

// ***********************BASIC ELEMENTS****************************************************
	//{1,2, 3, 4, 5, 6, 7, 8} {0, 4 ,3, 8, 1, 2};
	// int randomNumber[] = {185, 361, 83, 286, 405, 469, 297, 221, 198, 496, 128, 372, 319, 346, 98, 203, 354, 28, 148, 413};  //{11, 4 ,3, 8, 1, 2}; //{11, 2, 1, 8, 7, 9, 5, 3, 6, 10};
	// int randomNumber[] =  {444, 260, 359, 353, 153, 39, 145, 295, 348, 244, 123, 219, 361, 473, 176, 131, 89, 453, 381, 234, 173, 174, 108, 311, 268, 243, 401, 195, 197, 315, 141, 188, 30, 466, 206, 411, 452, 52, 379, 277, 8, 14, 439, 97, 455, 498, 198, 187, 36, 447, 82, 262, 4, 405, 284, 448, 144, 76, 138, 489, 482, 150, 216, 266, 416, 257, 422, 265, 475, 282, 121, 189, 6, 208, 432, 233, 373, 68, 196, 256, 248, 413, 326, 249, 42, 194, 84, 186, 471, 32, 221, 341, 368, 236, 62, 87, 336, 220, 175, 464, 320, 225, 468, 449, 66, 27, 53, 414, 274, 232, 56, 230, 273, 142, 420, 185, 63, 2, 104, 469, 313, 151, 80, 288, 263, 360, 112, 55, 118, 258, 227, 19, 73, 371, 318, 454, 163, 493, 370, 241, 272, 34, 490, 228, 43, 404, 492, 203, 166, 450, 161, 74, 375, 436, 312, 212, 51, 431, 324, 350, 296, 386, 45, 362, 213, 376, 400, 25, 115, 101, 171, 299, 303, 417, 467, 412, 330, 458, 304, 429, 49, 139, 497, 85, 168, 224, 264, 229, 92, 333, 383, 480, 24, 474, 488, 178, 314, 147, 427, 207, 465, 246, 406, 47, 159, 364, 167, 397, 338, 250, 275, 305, 291, 339, 442, 484, 445, 310, 61, 111, 28, 200, 387, 261, 218, 116, 242, 394, 143, 193, 152, 90, 179, 298, 182, 286, 31, 356, 177, 349, 395, 456, 477, 306, 321, 239, 437, 329, 114, 393, 199, 155, 380, 124, 75, 146, 170, 426, 222, 9, 78, 252, 382, 372, 164, 129, 120, 190, 134, 105, 297, 377, 478, 223, 499, 81, 13, 86, 21, 421, 235, 44, 172, 309, 5, 302, 285, 201, 107, 65, 438, 22, 54, 37, 494, 463, 385, 162, 18, 316, 1, 255, 407, 446, 451, 209, 457, 210, 88, 354, 434, 363, 102, 352, 180, 290, 301, 384, 470, 132, 215, 169, 292, 366, 98, 389, 460, 374, 64, 280, 461, 149, 126, 355, 481, 253, 204, 214, 342, 403, 402, 247, 109, 487, 127, 325, 226, 50, 351, 211, 60, 12, 399, 495, 58, 240, 91, 41, 300, 202, 441, 391, 415, 332, 148, 183, 72, 140, 71, 340, 100, 276, 237, 117, 388, 483, 251, 184, 158, 346, 11, 365, 357, 23, 59, 334, 267, 122, 430, 192, 410, 335, 205, 113, 418, 337, 69, 40, 106, 125, 165, 35, 231, 281, 293, 99, 271, 390, 378, 396, 344, 156, 26, 10, 217, 327, 345, 128, 419, 392, 269, 83, 358, 103, 70, 459, 7, 20, 409, 93, 319, 136, 323, 347, 238, 491, 48, 181, 94, 33, 369, 17, 110, 440, 160, 424, 428, 79, 16, 15, 328, 462, 96, 279, 367, 254, 137, 130, 486, 259, 133, 29, 343, 331, 0, 433, 476, 472, 57, 191, 119, 294, 408, 485, 77, 398, 67, 283, 443, 500, 157, 289, 307, 135, 154, 278, 38, 425, 245, 3, 308, 423, 270, 435, 322, 496, 46, 95, 479, 317, 287};
	// int taille = sizeof(randomNumber) / sizeof(randomNumber[0]);
    // // srand(time(NULL));

    // for (int i = taille - 1; i > 0; i--) {
    //     int j = rand() % (i + 1);
    //     int temp = randomNumber[i];
    //     randomNumber[i] = randomNumber[j];
    //     randomNumber[j] = temp;
    // }
// ****************************************************************************
// ***************RANDOM ELEMENTS**********************************************
    srand(time(NULL));

    const int taille = 500; // taille de la liste
    int randomNumber[taille];

    // Remplir le tableau avec des nombres aléatoires uniques de 0 à 100
    for (int i = 0; i < taille; ++i) {
        int nombreAleatoire;
        int estDejaPresent;

        do {
            estDejaPresent = 0;
            nombreAleatoire = rand() % 1000;  // Génère un nombre aléatoire entre 0 et 100

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
		//printf("%d ", randomNumber[i]);
    }
	// printf("*******************\n");


	// h_b = ft_lstappend(h_b, 1);
	// h_b = ft_lstappend(h_b, 2);
	// printf("*******************\n");
	// ft_nb_push(2, &list_nb);
	// send_to_h_a(&h_b, &my_list, &list_nb);

	ft_push_swap(&my_list, &h_b, &list_nb, &move_chained);
	ft_check_move_chained(move_chained);
	// printf("HERE stack A\n");
	// display(my_list);
	// printf("HERE stack B\n");
	// display(h_b);
	ft_display_move(move_chained);
	// printf("Number of move = %d\n", ft_size_move(move_chained));
	// printf("AFTER CHECK MOVE\n");
	// printf("Number of move = %d\n", ft_size_move(move_chained));
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

*/

