#include "../includes/checker.h"

static void	doop2(char *line, t_swap *swap)
{
	if (ft_strnstr(line, "rra", 3))
		rra(swap, 0);
	else if (ft_strnstr(line, "rrb", 3))
		rrb(swap, 0);
	else if (ft_strnstr(line, "rrr", 3))
		rrr(swap, 0);
}

void	doop(char *line, t_swap *swap)
{
	int	l;

	l = ft_strlen(line);
	if (l == 2)
	{
		if (ft_strnstr(line, "ra", l))
			ra(swap, 0);
		else if (ft_strnstr(line, "rb", l))
			rb(swap, 0);
		else if (ft_strnstr(line, "sa", l))
			sa(swap, 0);
		else if (ft_strnstr(line, "sb", l))
			sb(swap, 0);
		else if (ft_strnstr(line, "pb", l))
			pb(swap, 0);
		else if (ft_strnstr(line, "pa", l))
			pa(swap, 0);
		else if (ft_strnstr(line, "rr", l))
			rr(swap, 0);
		else if (ft_strnstr(line, "ss", l))
			ss(swap, 0);
	}
	else
		doop2(line, swap);
}
