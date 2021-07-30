#include "../includes/push_swap.h"

void	b_ops(t_swap *swap)
{
	t_list	*c;
	int		len;
	int		i;

	len = ft_lstsize(swap->b);
	c = swap->b;
	i = 0;
	while (i < len / 2 + len % 2)
	{
		c->ops = i;
		i++;
		c->rarra = 1;
		c = c->next;
	}
	if (len % 2 == 1)
		i--;
	while (c)
	{
		c->ops = i--;
		c->rarra = 0;
		c = c->next;
	}
}

void	a_ops(t_swap *swap)
{
	t_list	*c;
	int		len;
	int		i;

	len = ft_lstsize(swap->a);
	c = swap->a;
	i = 0;
	while (i < len / 2 + len % 2)
	{
		c->ops = i++;
		c->rarra = 1;
		c = c->next;
	}
	if (len % 2 == 1)
		i--;
	while (c)
	{
		c->ops = i--;
		c->rarra = 0;
		c = c->next;
	}
}
