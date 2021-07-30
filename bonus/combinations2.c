#include "../includes/checker.h"

void	sb(t_swap *swap, int i)
{
	t_list	*c;

	if (swap->b != NULL)
	{
		if (swap->b->next != NULL)
		{
			c = swap->b;
			c = c->next;
			swap->tmp = c;
			c = c->next;
			swap->b->next = c;
			swap->tmp->next = swap->b;
			swap->b = swap->tmp;
		}
	}
	if (i)
		ft_putstr_fd("sb\n", 1);
}

void	pb(t_swap *swap, int i)
{
	t_list	*c;

	if (swap->a != NULL)
	{
		c = swap->a;
		c = c->next;
		if (swap->b == NULL)
			swap->a->next = NULL;
		else
			swap->a->next = swap->b;
		swap->b = swap->a;
		swap->a = c;
	}
	if (i)
		ft_putstr_fd("pb\n", 1);
}

void	pa(t_swap *swap, int i)
{
	t_list	*c;

	if (swap->b != NULL)
	{
		c = swap->b;
		c = c->next;
		if (swap->a == NULL)
			swap->b->next = NULL;
		else
			swap->b->next = swap->a;
		swap->a = swap->b;
		swap->b = c;
	}
	if (i)
		ft_putstr_fd("pa\n", 1);
}

void	rr(t_swap *swap, int i)
{
	ra(swap, 0);
	rb(swap, 0);
	if (i)
		ft_putstr_fd("rr\n", 1);
}

void	rrr(t_swap *swap, int i)
{
	rra(swap, 0);
	rrb(swap, 0);
	if (i)
		ft_putstr_fd("rrr\n", 1);
}
