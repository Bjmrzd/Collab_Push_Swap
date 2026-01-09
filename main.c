/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brouzaud <brouzaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 09:03:06 by brouzaud          #+#    #+#             */
/*   Updated: 2026/01/09 20:42:47 by brouzaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	*tmp;
	t_list	**list;
	t_count	*count;
	t_dis	*init_dis;

	list = malloc(sizeof(t_list *));
	count = malloc(sizeof(t_count));
	init_dis = malloc(sizeof(t_dis));
	*list = NULL;
	parsing(argc, argv, list);
	init_count(count);
	init_disorder(list, init_dis);
	strat_select(argc, argv, list, count);
	bench(argc, argv, count, init_dis);
	tmp = (*list);
	while (tmp)
	{
		printf("arg 1 = %d\n", tmp->data);
		tmp = tmp->next;
	}
	free(list);
	free(count);
	free(init_dis);
	return (0);
}
