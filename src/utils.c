#include "push_swap.h"

int	init_count(t_list **stack_a)
{
	int		count;
	t_list	*tmp;

	count = 1;
	tmp = *stack_a;
	while ((*stack_a)->next != NULL)
	{
		count++;
		
		*stack_a = (*stack_a)->next;
	}
	*stack_a = tmp;
	return (count);
}

t_list	*find_pre_last(t_list *stack)
{
	t_list	*pre_last;

	pre_last = NULL;
	if (stack && stack->next)
	{
		pre_last = stack;
		while (pre_last->next->next)
			pre_last = pre_last->next;
	}
	return (pre_last);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst)
		return ;
	new->next = *lst;
	*lst = new;
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!*lst)
		*lst = new;
	else
		ft_lstlast(*lst)->next = new;
}

t_list	*ft_lstlast(t_list *lst)
{
	while (lst != NULL)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}
