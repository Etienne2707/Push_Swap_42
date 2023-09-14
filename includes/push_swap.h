#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef int			t_bool;
# define FALSE 0
# define TRUE 1

typedef struct s_list
{
	int				data;
	int				pos;
	struct s_list	*next;
}					t_list;

int	ft_isdigit(int c);
size_t	ft_strlen(const char *s);
long long int	atoi_checker(const char *nptr);
long long int	ft_atoi(const char *str);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*find_pre_last(t_list *stack);
int	init_count(t_list **stack_a);
int	get_pos(t_list **stack_a, int min);
int	min_pile(t_list **stack_a);
void	sort_five(t_list **stack_a, t_list **stack_b);
void	sort_four(t_list **stack_a, t_list **stack_b);
void	sort_three(t_list **stack_a);
void	sort_x500(t_list **stack_a, t_list **stack_b, int ac);
void	sort_x100(t_list **stack_a, t_list **stack_b, int ac);
void	sorting_b(t_list **stack_a, t_list **stack_b, int ac);
int	rb_or_rrb(t_list **stack_b, int size);
int *init_tab(int *tab, int ac);
void	init_pos(t_list **stack_a, int *tab, int ac);
t_list	*create_nb(int a, int b, t_list **stack_a, int *tab);
void	init_stack(t_list **stack_a, int ac, char **av,int *tab);
void	free_a(t_list **stack_a, int *tab);
void	free_all(t_list **stack_a, t_list **stack_b, int *tab);
void	push_a(t_list **stack_b, t_list **stack_a);
void	push_b(t_list **stack_b, t_list **stack_a);
void	rotate_b(t_list **stack_b);
void	rotate_a(t_list **stack_a);
void	reverse_b(t_list **stack_b);
void	reverse_a(t_list **stack_a);
int check_int(char **argv);
int all_digits(int argc, char **argv);
int	check_double(int argc, char **argv);
int	checker(int argc, char **argv);
void	sort_choice(t_list **stack_a, t_list **stack_b, int ac);
int	aldready_sort(t_list **stack_a);
void	swap_b(t_list **stack_b);
void	swap_a(t_list **stack_a);





#endif