#include "../push_swap.h"

void	strategy(int argc, char *argv[])
{
	t_flag	flag;
	t_flag	isbench;

	isbench = arg_error(argc, argv);
	if (isbench == BENCH)
		flag = second_flag(argc, argv);
	else
		flag = arg_error(argc, argv);
	if (flag == ADAPTIVE)
		ft_printf("[bench] strategy:  Adaptive / O(n√n)\n");
	if (flag == SIMPLE)
		ft_printf("[bench] strategy: Simple / O(n2)\n");
	if (flag == COMPLEX)
		ft_printf("[bench] strategy: Complex / O(n log n)\n");
	if (flag == MEDIUM)
		ft_printf("[bench] strategy: Medium / O(n√n)\n");
	return ;
}

int	count_ops(t_count *count)
{
	count->total_count = (count->ra_count + count->rb_count + count->rr_count
			+ count->sa_count + count->sb_count + count->ss_count
			+ count->rra_count + count->rrb_count + count->rrr_count
			+ count->pb_count + count->pa_count);
	return (count->total_count);
}

void	bench(int argc, char *argv[], t_count *count, t_dis *init_dis)
{
	t_flag flag;

	flag = arg_error(argc, argv);

	if (flag == BENCH)
	{
		printf("[bench] disorder: %f%%\n", init_dis->dis * 100);
		// marche avec printf mais doit modifier ft_printf pour faire float
		strategy(argc, argv);
		ft_printf("[bench] total_ops: %d\n", count_ops(count));
		ft_printf("[bench] sa: %d sb: %d ss: %d pa: %d pb: %d\n",
			count->sa_count, count->sb_count, count->ss_count, count->pa_count,
			count->pb_count);
		ft_printf("[bench] ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d\n",
			count->ra_count, count->rb_count, count->rr_count, count->rra_count,
			count->rrb_count, count->rrr_count);
	}
}