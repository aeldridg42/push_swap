#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_ints
{
	int	i;
	int	i2;
	int	num;
	int	opsa;
	int	opsb;
	int	tmpops;
	int	mainops;
	int	mainindex;
	int	rarra;
	int	rbrrb;
}				t_ints;

typedef struct s_swap
{
	t_list		*a;
	t_list		*b;
	t_list		*tmp;
	t_ints		ints;
	int			firstindex;
	int			markindex;
	int			alen;
	int			check;
	int			check2;
}				t_swap;

int		findnext(t_swap *swap, int	index);
char	**ft_split(char const *s, char c);
void	*ft_free(char **split, int	words);
void	ra(t_swap *swap, int i);
void	rb(t_swap *swap, int i);
void	rra(t_swap *swap, int i);
void	rrb(t_swap *swap, int i);
void	pb(t_swap *swap, int i);
void	pa(t_swap *swap, int i);
void	rr(t_swap *swap, int i);
void	rrr(t_swap *swap, int i);
void	sa(t_swap *swap, int i);
void	parser(t_swap *swap, int argc, char **argv);
void	indexgiving(t_swap *swap, int lenght);
void	marking(t_swap *swap, int lenght);
void	pushingb(t_swap *swap);
void	b_ops(t_swap *swap);
void	a_ops(t_swap *swap);
void	pushinga(t_swap *swap);
void	sort5(t_swap *swap, int len);
void	sorting(t_swap *swap);
void	ft_errorout(t_swap *swap);

#endif