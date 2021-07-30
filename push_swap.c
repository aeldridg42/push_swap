#include "includes/push_swap.h"

void	ft_errorout(t_swap *swap)
{
	ft_lstclear(&swap->a);
	ft_lstclear(&swap->b);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

static void	structinit(t_swap *swap)
{
	swap->b = NULL;
	swap->a = NULL;
	swap->tmp = NULL;
	swap->check = 0;
	swap->check2 = 0;
	swap->markindex = -1;
	swap->ints.i = 0;
	swap->ints.i2 = 0;
}

static void	alreadysorted(t_swap *swap)
{
	swap->tmp = swap->a;
	if (swap->tmp->index == 0)
	{
		while (swap->tmp->next != NULL)
		{
			if (swap->tmp->index + 1 == swap->tmp->next->index)
				swap->tmp = swap->tmp->next;
			else
				return ;
		}
		ft_lstclear(&swap->a);
		exit (0);
	}
}

int	main(int argc, char **argv)
{
	t_swap	swap;

	if (argc == 1)
		return (0);
	structinit(&swap);
	parser(&swap, argc, argv);
	swap.alen = ft_lstsize(swap.a);
	indexgiving(&swap, swap.alen);
	alreadysorted(&swap);
	if (swap.alen == 5 || swap.alen == 3)
		sort5(&swap, swap.alen);
	swap.firstindex = swap.a->index;
	marking(&swap, swap.alen);
	pushingb(&swap);
	pushinga(&swap);
	sorting(&swap);
	ft_lstclear(&swap.a);
	return (0);
}
