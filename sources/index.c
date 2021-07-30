#include "../includes/push_swap.h"

static void	sortindex(int *index, int lenght)
{
	int	i;
	int	tmp;
	int	tmp2;

	tmp2 = lenght;
	i = 0;
	while (lenght - 1)
	{
		if (index[i] > index[i + 1])
		{
			tmp = index[i];
			index[i] = index[i + 1];
			index[i + 1] = tmp;
			i = 0;
			lenght = tmp2;
		}
		else
		{
			++i;
			lenght--;
		}
	}
}

static void	giveindex(int *index, t_swap *swap, int lenght)
{
	int	i;
	int	indexnum;

	i = 0;
	indexnum = 0;
	while (i < lenght)
	{
		swap->tmp = swap->a;
		while (index[i] != swap->tmp->number)
			swap->tmp = swap->tmp->next;
		swap->tmp->index = indexnum++;
		++i;
	}
}

void	indexgiving(t_swap *swap, int lenght)
{
	int	*index;
	int	i;

	index = (int *)malloc(sizeof(int) * lenght);
	if (index == NULL)
		ft_errorout(swap);
	swap->tmp = swap->a;
	i = 0;
	while (swap->tmp)
	{
		index[i++] = swap->tmp->number;
		swap->tmp = swap->tmp->next;
	}
	i = 0;
	sortindex(index, lenght);
	giveindex(index, swap, lenght);
	free (index);
}
