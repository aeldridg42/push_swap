#include "../includes/push_swap.h"

void	ra(t_swap *swap, int i)
{
	if (swap->a != NULL)
	{
		if (swap->a->next != NULL)
		{
			swap->tmp = swap->a;
			swap->a = swap->a->next;
			ft_lstadd_back(&swap->a, swap->tmp);
			swap->tmp->next = NULL;
		}
	}
	if (i)
		ft_putstr_fd("ra\n", 1);
}

void	rb(t_swap *swap, int i)
{
	if (swap->b != NULL)
	{
		if (swap->b->next != NULL)
		{
			swap->tmp = swap->b;
			swap->b = swap->b->next;
			ft_lstadd_back(&swap->b, swap->tmp);
			swap->tmp->next = NULL;
		}
	}
	if (i)
		ft_putstr_fd("rb\n", 1);
}

void	rra(t_swap *swap, int i)
{
	t_list	*c;
	int		size;

	if (swap->a != NULL)
	{
		if (swap->a->next != NULL)
		{
			c = swap->a;
			swap->tmp = ft_lstlast(swap->a);
			size = ft_lstsize(swap->a);
			while ((size - 2) != 0)
			{
				c = c->next;
				--size;
			}
			c->next = NULL;
			swap->tmp->next = swap->a;
			swap->a = swap->tmp;
		}
	}
	if (i)
		ft_putstr_fd("rra\n", 1);
}

void	rrb(t_swap *swap, int i)
{
	t_list	*c;
	int		size;

	if (swap->b != NULL)
	{
		if (swap->b->next != NULL)
		{
			c = swap->b;
			swap->tmp = ft_lstlast(swap->b);
			size = ft_lstsize(swap->b);
			while ((size - 2) != 0)
			{
				c = c->next;
				--size;
			}
			c->next = NULL;
			swap->tmp->next = swap->b;
			swap->b = swap->tmp;
		}
	}
	if (i)
		ft_putstr_fd("rrb\n", 1);
}
