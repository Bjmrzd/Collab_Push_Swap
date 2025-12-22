#include "push_swap.h"

float	disorder(t_list **list) // marche pas, doit faire fonctionner
{
	int mistakes;
	int total_args;
	float dis;
	t_list *tmp;

	tmp = (*list);
	total_args = ft_lstsize(tmp);
	if (sorted(tmp) == 0)
		mistakes = 0;
	while (tmp && tmp->next)
	{
		if (tmp->data > tmp->next->data)
		{
			mistakes += 1;
		}
		tmp = tmp->next;
	}
	dis = mistakes / total_args;
	return (dis);
}