#include "../includes/checker.h"

void	filter(char *line, t_swap *swap)
{
	int	l;
	int	i;

	l = ft_strlen(line);
	if (l != 2 && l != 3)
		ft_errorout(swap);
	i = 0;
	if (line[i] != 'r' && line[i] != 's' && line[i] != 'p')
		ft_errorout(swap);
	if (line[i] == 'r' && line[i + 1] != 'r' && line[i + 1] != 'a'
		&& line[i + 1] != 'b')
		ft_errorout(swap);
	if (line[i] == 's' && line[i + 1] != 'a' && line[i + 1] != 'b'
		&& line[i + 1] != 's')
		ft_errorout(swap);
	if (line[i] == 'p' && (line[i + 1] != 'a' && line[i + 1] != 'b'))
		ft_errorout(swap);
	if (l == 3)
		if (line[i + 1] != 'r' || (line[i + 2] != 'r' && line[i + 2] != 'a'
				&& line[i + 2] != 'b'))
			ft_errorout(swap);
}
