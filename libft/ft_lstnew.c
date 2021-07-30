#include "libft.h"

t_list	*ft_lstnew(int content)
{
	t_list	*the_new;

	the_new = (t_list *)malloc(sizeof(t_list));
	if (!the_new)
		return (NULL);
	the_new->number = content;
	the_new->next = NULL;
	return (the_new);
}
