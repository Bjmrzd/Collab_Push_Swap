/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brouzaud <brouzaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 14:45:07 by brouzaud          #+#    #+#             */
/*   Updated: 2026/02/04 20:23:48 by brouzaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_list(t_list **list)
{
	t_list	*tmp;

	while (*list)
	{
		tmp = (*list);
		*list = (*list)->next;
		free(tmp);
	}
	return ;
}

void	free_malloc_main(t_list **list, t_count *count, t_dis *init_dis,
		t_free not_free)
{
	if (not_free == FREE)
	{
		free(init_dis);
		free(count);
		free_list(list);
		free(list);
		exit(2);
	}
}

void	free_all(t_list **list, t_count *count, t_dis *init_dis)
{
	free(init_dis);
	free(count);
	free_list(list);
	free(list);
}
