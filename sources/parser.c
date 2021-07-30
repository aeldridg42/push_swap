#include "../includes/push_swap.h"

static void	checkarg(char *argv, t_swap *swap)
{
	int	l;

	l = 0;
	if (!argv[l])
		ft_errorout(swap);
	while (ft_isspace(argv[l]))
		l++;
	if ((argv[l] == '-' || argv[l] == '+') && argv[l + 1])
		l++;
	while (argv[l])
	{
		if (argv[l] >= '0' && argv[l] <= '9')
			l++;
		else
			ft_errorout(swap);
	}
}

static void	checkargs(char **argv, t_swap *swap)
{
	int	i;
	int	l;

	i = 0;
	while (argv[i])
	{
		l = 0;
		while (ft_isspace(argv[i][l]))
			l++;
		if ((argv[i][l] == '-' || argv[i][l] == '+') && argv[i][l + 1])
			l++;
		while (argv[i][l])
		{
			if (argv[i][l] >= '0' && argv[i][l] <= '9')
				l++;
			else
				ft_errorout(swap);
		}
		++i;
	}
}

static void	parseonearg(t_swap *swap, char *argv)
{
	char	**str;
	int		i;

	str = ft_split(argv, ' ');
	if (!str)
		ft_errorout(swap);
	i = 0;
	checkargs(str, swap);
	while (str[i])
	{
		swap->tmp = swap->a;
		while (swap->tmp)
		{
			if (ft_atoi(str[i]) == swap->tmp->number)
				ft_errorout(swap);
			swap->tmp = swap->tmp->next;
		}
		swap->tmp = ft_lstnew(ft_atoi(str[i]));
		ft_lstadd_back(&swap->a, swap->tmp);
		++i;
	}
	ft_free(str, i);
}

void	parser(t_swap *swap, int argc, char **argv)
{
	int		i;

	i = 1;
	while (--argc)
	{
		if (ft_strchr(argv[i], ' '))
			parseonearg(swap, argv[i++]);
		else
		{
			checkarg(argv[i], swap);
			swap->tmp = swap->a;
			while (swap->tmp)
			{
				if (ft_atoi(argv[i]) == swap->tmp->number)
					ft_errorout(swap);
				swap->tmp = swap->tmp->next;
			}
			swap->tmp = ft_lstnew(ft_atoi(argv[i++]));
			ft_lstadd_back(&swap->a, swap->tmp);
		}
	}
}
