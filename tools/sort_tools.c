#include "../push_swap.h"

int	get_min(t_list **list)
{
	int		min;
	t_list	*tmp;

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

int	min_index(t_list **list)
{
	int		min;
	t_list	*tmp;
	int		index;

	index = 0;
	tmp = (*list);
	min = get_min(list);
	while (tmp)
	{
		if (tmp->data == min)
			return (index);
		index++;
		tmp = tmp->next;
	}
	return (index);
}
