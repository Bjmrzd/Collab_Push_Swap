/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brouzaud <brouzaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 14:44:54 by brouzaud          #+#    #+#             */
/*   Updated: 2026/01/20 17:50:55 by brouzaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

float	disorder(t_list **list)
{
	int		mistakes;
	int		total_args;
	float	dis;
	t_list	*tmp;
	t_list	*temp;

	temp = (*list);
	mistakes = 0;
	total_args = 0;
	while (temp->next)
	{
		tmp = temp->next;
		while (tmp)
		{
			if (temp->data > tmp->data)
				mistakes += 1;
			total_args++;
			tmp = tmp->next;
		}
		temp = temp->next;
	}
	dis = (float)mistakes / (float)total_args;
	return (dis);
}

void	init_disorder(t_list **list, t_dis *init)
{
	init->dis = disorder(list);
}
