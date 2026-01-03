#include "push_swap.h"

void	adaptive(int argc, char *argv[], t_list **list, t_count *count)
		// peut etre renvoyer le disorder ici dans strat select puis faire dans le main pour avoir le disorder pour bench
{
	float dis;

	dis = disorder(list);
	if (dis < 0.2)
		simple_sort(argc, argv, list, count);
	if (dis >= 0.2 && dis < 0.5)
		chunk_sort();
	if (dis >= 0.5)
		radix_sort();
}

void	strat_select(int argc, char *argv[], t_list **list, t_count *count)
{
	t_flag flag;
	t_flag isbench;

	isbench = arg_error(argc, argv);
	if (isbench == BENCH)
		flag = second_flag(argc, argv);
	else
		flag = arg_error(argc, argv);
	if (flag == ADAPTIVE)
		adaptive(argc, argv, list, count);
	if (flag == SIMPLE)
		simple_sort(argc, argv, list, count);
	else if (flag == MEDIUM)
		chunk_sort();
	else if (flag == COMPLEX)
		radix_sort();
}