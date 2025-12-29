/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjmrzd <bjmrzd@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 09:03:06 by brouzaud          #+#    #+#             */
/*   Updated: 2025/12/29 21:16:06 by bjmrzd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	*tmp;
	t_list	**list;
	t_count	*count;

	list = malloc(sizeof(t_list *));
	count = malloc(sizeof(t_count));
	*list = NULL;
	parsing(argc, argv, list);
	init_count(count);
	simple_sort(argc, argv, list, count);
		// doit le mettre dans fonction qui repera les algos selon flag apres
	bench(argc, argv, list, count);
	tmp = (*list);
	while (tmp)
	{
		printf("arg 1 = %d\n", tmp->data);
		tmp = tmp->next;
	}
	return (0);
}
