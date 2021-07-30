#include "../includes/push_swap.h"

static int	pushingb2(t_swap *swap)
{
	int	i;

	i = 0;
	swap->tmp = swap->a;
	while (swap->tmp)
	{
		if (swap->tmp->mark == 0)
			return (i);
		i++;
		swap->tmp = swap->tmp->next;
	}
	return (-1);
}

void	pushingb(t_swap *swap)
{
	int	i;
	int	len;

	i = 1;
	len = swap->alen;
	while (i > -1)
	{
		i = pushingb2(swap);
		if (i != -1)
		{
			if (i >= (len / 2 + len % 2))
				while (swap->a->mark != 0)
					rra(swap, 1);
			else
				while (swap->a->mark != 0)
					ra(swap, 1);
			pb(swap, 1);
			len--;
		}
	}
}
