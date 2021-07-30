#include "libft.h"

int	ft_isspace(int c)
{
	if (c == ' ' || c == '\r' || c == '\f' || c == '\n'
		|| c == '\t' || c == '\v')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	long	i;
	long	int_max;
	int		neg;

	i = 0;
	neg = 1;
	int_max = 2147483647;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg = -1;
		str++ ;
	}
	while (ft_isdigit(*str))
	{
		i = i * 10 + *str++ - '0';
		if ((i > int_max + 1 && neg == -1) || (i > int_max && neg == 1))
		{
			ft_putstr_fd("Error\n", 2);
			exit (1);
		}
	}
	return ((int)i * neg);
}
