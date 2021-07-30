#include "../includes/checker.h"

void	ft_errorout(t_swap *swap)
{
	ft_lstclear(&swap->a);
	ft_lstclear(&swap->b);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

static void	ft_putko(t_swap *swap)
{
	ft_lstclear(&swap->a);
	ft_lstclear(&swap->b);
	ft_putstr_fd("KO\n", 1);
	exit (0);
}

static void	init_check(t_swap *swap, int argc, char **argv)
{
	int		i;
	char	*line;

	swap->a = NULL;
	swap->b = NULL;
	if (argc == 1)
		exit (0);
	parser(swap, argc, argv);
	i = ft_lstsize(swap->a);
	indexgiving(swap, i);
	i = get_next_line(&line);
	while (i && i != -1)
	{
		filter(line, swap);
		doop(line, swap);
		free(line);
		i = get_next_line(&line);
	}
	if (i == -1)
		ft_errorout(swap);
}

int	main(int argc, char **argv)
{
	t_swap	swap;
	int		i;

	init_check(&swap, argc, argv);
	i = ft_lstsize(swap.b);
	swap.tmp = swap.a;
	if (i != 0 || swap.tmp->index != 0)
		ft_putko(&swap);
	while (swap.tmp->next != NULL)
	{
		if (swap.tmp->index + 1 == swap.tmp->next->index)
			swap.tmp = swap.tmp->next;
		else
			ft_putko(&swap);
	}
	ft_putstr_fd("OK\n", 1);
	ft_lstclear(&swap.a);
	return (0);
}
