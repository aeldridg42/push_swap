#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"

typedef struct s_swap
{
	t_list		*a;
	t_list		*b;
	t_list		*tmp;
}				t_swap;

int		get_next_line(char **line);
void	parser(t_swap *swap, int argc, char **argv);
void	ra(t_swap *swap, int i);
void	rb(t_swap *swap, int i);
void	rra(t_swap *swap, int i);
void	rrb(t_swap *swap, int i);
void	sa(t_swap *swap, int i);
void	sb(t_swap *swap, int i);
void	pb(t_swap *swap, int i);
void	pa(t_swap *swap, int i);
void	ss(t_swap *swap, int i);
void	rr(t_swap *swap, int i);
void	rrr(t_swap *swap, int i);
void	ft_errorout(t_swap *swap);
void	filter(char *line, t_swap *swap);
void	doop(char *line, t_swap *swap);
void	indexgiving(t_swap *swap, int lenght);

#endif