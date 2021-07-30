#include "../includes/push_swap.h"

static void	sort3(t_swap *swap)
{
	if (swap->a->next->next->number < swap->a->number
		&& swap->a->next->next->number > swap->a->next->number)
		ra(swap, 1);
	else if (swap->a->next->next->number < swap->a->number
		&& swap->a->number < swap->a->next->number)
		rra(swap, 1);
	else if (swap->a->next->next->number > swap->a->number
		&& swap->a->number > swap->a->next->number)
		sa(swap, 1);
	else if (swap->a->next->next->number > swap->a->number
		&& swap->a->next->next->number < swap->a->next->number)
	{	
		rra(swap, 1);
		sa(swap, 1);
	}
	else if (swap->a->next->next->number < swap->a->number
		&& swap->a->number > swap->a->next->number)
	{
		sa(swap, 1);
		rra(swap, 1);
	}
}

void	sort5(t_swap *swap, int len)
{
	if (len == 3)
		sort3(swap);
	else
	{
		while (swap->a->index > 1)
			ra(swap, 1);
		pb(swap, 1);
		while (swap->a->index > 1)
			ra(swap, 1);
		pb(swap, 1);
		sort3(swap);
	}
	pushinga(swap);
	sorting(swap);
	ft_lstclear(&swap->a);
	exit (0);
}

void	sorting(t_swap *swap)
{
	int	i;

	i = 0;
	swap->alen = ft_lstsize(swap->a);
	swap->tmp = swap->a;
	while (swap->tmp->index != 0)
	{
		swap->tmp = swap->tmp->next;
		++i;
	}
	swap->tmp = swap->a;
	if (i > swap->alen / 2 + swap->alen % 2)
	{
		while (swap->tmp->index != 0)
		{
			rra(swap, 1);
			swap->tmp = swap->a;
		}
		return ;
	}
	while (swap->tmp->index != 0)
	{
		ra(swap, 1);
		swap->tmp = swap->a;
	}
}
