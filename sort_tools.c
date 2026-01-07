#include "push_swap.h"

int	getMin(t_list **list)
{
	int min;
	t_list *tmp;

	tmp = (*list);
	min = tmp->data;
	while (tmp)
	{
		if (tmp->data < min)
			min = tmp->data;
		tmp = tmp->next;
	}
	return (min);
}

