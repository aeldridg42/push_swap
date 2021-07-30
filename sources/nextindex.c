#include "../includes/push_swap.h"

int	findnext(t_swap *swap, int index)
{
	int	i;

	i = 1;
	while (swap->tmp)
	{
		if (swap->tmp->index == index + i)
		{
			i++;
			swap->tmp = swap->b;
		}
		else if (index + i != swap->tmp->index)
		{
			if (swap->tmp->next == NULL)
				break ;
			else
				swap->tmp = swap->tmp->next;
		}
	}
	return (i);
}
