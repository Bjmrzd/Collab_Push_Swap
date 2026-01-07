/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brouzaud <brouzaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 09:03:06 by brouzaud          #+#    #+#             */
/*   Updated: 2026/01/07 21:09:58 by brouzaud         ###   ########.fr       */
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
	strat_select(argc, argv, list, count);
	bench(argc, argv, list, count);
	tmp = (*list);
	while (tmp)
	{
		printf("arg 1 = %d\n", tmp->data);
		tmp = tmp->next;
	}
	return (0);
}
