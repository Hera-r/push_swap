/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrandria <hrandria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 17:38:09 by hrandria          #+#    #+#             */
/*   Updated: 2023/10/08 20:19:49 by hrandria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct s_listr
{
	char			*str;
	struct s_listr	*next;
}					t_lstr;



static void display(t_lstr *head)
{
	printf("*******************\n");
	t_lstr *tmp =  NULL;
		tmp = head;
	while (tmp != NULL)
	{
		printf("- %s\n", tmp->str);
		tmp = tmp->next;
	}
}


t_lstr	*strappend(t_lstr *h_a, char *str)
{
	t_lstr	*element;
	t_lstr	*tmp;

	tmp = h_a;
	element = malloc(sizeof(*element));
	if (element == NULL)
		return (NULL);
	element->str = str;
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

void	delete_occurrence(t_lstr *head)
{
	t_lstr *tmp;
	t_lstr *new;
	t_lstr *prev;

	tmp = head;
	while (tmp != NULL && tmp->next != NULL)
	{
		if ((tmp->str == "ra" && tmp->next->str == "rra") ||
			(tmp->str == "rra" && tmp->next->str == "ra"))
		{
			new = tmp->next->next;
			free(tmp->next);
			tmp->next = new;
		}
		else 
		{
			if (prev == NULL)
				head = tmp;
			else
				prev->next = tmp;
			prev = tmp;
			tmp = tmp->next;
		}
    }
    if (prev != NULL) {
        prev->next = NULL;
    }
}

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
int main(void)
{
	t_lstr *principal;
	t_lstr *disp;

	principal = NULL;
	disp = NULL;


	principal = strappend(principal, "pb");
	principal = strappend(principal, "ra");
	principal = strappend(principal, "rra");
	principal = strappend(principal, "pa");
	principal = strappend(principal, "rra");
	principal = strappend(principal, "ra");
	principal = strappend(principal, "rra");


	display(principal);

	delete_occurrence(principal);

	display(principal);
	

	return (0);
}