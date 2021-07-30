#include "../includes/push_swap.h"

static void	push_value(t_swap *swap, int index, int rarra, t_list *c)
{
	swap->ints.tmpops = swap->ints.tmpops + swap->tmp->ops;
	if (swap->tmp->rarra == c->rarra)
	{
		if (swap->tmp->ops > c->ops)
			swap->ints.tmpops -= c->ops;
		else
			swap->ints.tmpops -= swap->tmp->ops;
	}
	if (swap->ints.mainops > swap->ints.tmpops || swap->ints.mainops == -1)
	{
		swap->ints.mainops = swap->ints.tmpops;
		swap->ints.mainindex = index;
		swap->ints.rarra = rarra;
	}
}

static void	pushinga2(t_swap *swap)
{
	t_list	*c;
	int		index;
	int		i;
	int		rarra;

	swap->ints.mainops = -1;
	swap->ints.mainindex = 0;
	c = swap->b;
	swap->tmp = swap->b;
	while (swap->tmp)
	{
		swap->ints.tmpops = swap->tmp->ops;
		index = swap->tmp->index;
		rarra = swap->tmp->rarra;
		swap->tmp = swap->b;
		i = findnext(swap, index);
		c->nextindex = index + i;
		swap->tmp = swap->a;
		while (index + i != swap->tmp->index)
			swap->tmp = swap->tmp->next;
		push_value(swap, index, rarra, c);
		c = c->next;
		swap->tmp = c;
	}
}

static void	movestacks(t_swap *swap)
{
	int		i;
	t_list	*c;

	swap->tmp = swap->b;
	while (swap->tmp->index != swap->ints.mainindex)
		swap->tmp = swap->tmp->next;
	c = swap->a;
	while (c->index != swap->tmp->nextindex)
		c = c->next;
	if (c->rarra == swap->tmp->rarra)
	{
		if (c->ops > swap->tmp->ops)
			i = swap->tmp->ops;
		else
			i = c->ops;
		while (i--)
		{
			if (c->rarra == 1)
				rr(swap, 1);
			else
				rrr(swap, 1);
		}
	}
}

static void	moveina(t_swap *swap)
{
	int	nextindex;

	nextindex = swap->tmp->nextindex;
	swap->tmp = swap->a;
	while (swap->tmp->index != nextindex)
		swap->tmp = swap->tmp->next;
	if (swap->tmp->rarra == 1)
		while (swap->a->index != nextindex)
			ra(swap, 1);
	else
		while (swap->a->index != nextindex)
			rra(swap, 1);
}

void	pushinga(t_swap *swap)
{
	int	len;

	len = ft_lstsize(swap->b);
	while (len)
	{
		b_ops(swap);
		a_ops(swap);
		pushinga2(swap);
		movestacks(swap);
		swap->tmp = swap->b;
		while (swap->tmp->index != swap->ints.mainindex)
		{
			if (swap->ints.rarra == 1)
				rb(swap, 1);
			else
				rrb(swap, 1);
			swap->tmp = swap->b;
		}
		swap->tmp = swap->b;
		moveina(swap);
		pa(swap, 1);
		len--;
	}
}
