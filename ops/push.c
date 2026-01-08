#include "../push_swap.h"

void	pb(t_list **a, t_list **b, t_count *count)
{
	t_list	*tmp;

	if (!a || !*a)
		return ;
	tmp = (*a);
	(*a) = (*a)->next;
	tmp->next = *b;
	(*b) = tmp;
	count->pb_count++;
}

void	pa(t_list **a, t_list **b, t_count *count)
{
	t_list *tmp;

	if (!b || !*b)
		return ;
	tmp = (*b);
	(*b) = (*b)->next;
	tmp->next = *a;
	(*a) = tmp;
	count->pa_count++;
}