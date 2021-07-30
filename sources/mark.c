#include "../includes/push_swap.h"

static void	givemark(t_swap *swap)
{
	int	i;
	int	num;

	i = 0;
	while (swap->tmp->index != swap->markindex)
		swap->tmp = swap->tmp->next;
	swap->tmp->mark = 1;
	num = swap->tmp->number;
	swap->tmp = swap->tmp->next;
	while (i++ < swap->alen - 1)
	{
		if (num < swap->tmp->number)
		{
			swap->tmp->mark = 1;
			num = swap->tmp->number;
		}
		else
			swap->tmp->mark = 0;
		swap->tmp = swap->tmp->next;
	}
}

static void	marking2(t_swap *swap, int cindex)
{
	t_list	*c;

	swap->tmp = swap->tmp->next;
	c = swap->tmp;
	if (swap->ints.i2 <= swap->ints.i)
	{
		if (swap->ints.i2 == swap->ints.i)
		{
			if (cindex < swap->markindex || swap->markindex == -1)
				swap->markindex = cindex;
		}
		else
			swap->markindex = cindex;
		swap->ints.i2 = swap->ints.i;
	}
}

static void	marking1(t_swap *swap)
{
	int	ctr;

	givemark(swap);
	while (swap->tmp->index != swap->firstindex)
		swap->tmp = swap->tmp->next;
	swap->a = swap->tmp;
	ctr = 0;
	while (ctr++ < swap->alen - 1)
		swap->tmp = swap->tmp->next;
	swap->tmp->next = NULL;
}

static void	marking3(t_swap *swap, t_list *c)
{
	swap->ints.num = c->number;
	swap->ints.i++;
}

void	marking(t_swap *swap, int lenght)
{
	t_list	*c;
	int		i3;
	int		cindex;

	c = ft_lstlast(swap->a);
	c->next = swap->a;
	c = c->next;
	swap->tmp = swap->a;
	while (lenght--)
	{
		swap->ints.i = 1;
		i3 = 0;
		swap->ints.num = c->number;
		cindex = c->index;
		c = c->next;
		while (i3++ < swap->alen)
		{
			if (swap->ints.num < c->number)
				marking3(swap, c);
			c = c->next;
		}
		marking2(swap, cindex);
	}
	marking1(swap);
}
