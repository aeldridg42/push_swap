#include "../includes/checker.h"

int	get_next_line(char **line)
{
	char	*arr;
	int		i;
	char	buff;

	i = 0;
	if (!line)
		return (-1);
	arr = malloc(4);
	if (!arr)
		return (-1);
	while (read(0, &buff, 1) > 0)
	{
		arr[i] = buff;
		if (arr[i] == '\n')
		{
			arr[i] = '\0';
			*line = arr;
			return (1);
		}
		++i;
	}
	arr[i] = '\0';
	*line = arr;
	return (0);
}
