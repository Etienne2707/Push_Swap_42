#include "push_swap.h"

void	reverse_a(t_list **stack_a)
{
	t_list	*pre_last;
	t_list	*last;
	t_list	*tmp;

	if (*stack_a && (*stack_a)->next)
	{
		tmp = *stack_a;
		pre_last = find_pre_last(*stack_a);
		last = pre_last->next;
		pre_last->next = NULL;
		last->next = tmp;
		*stack_a = last;
		write(1, "rra\n", 4);
	}
}

void	reverse_b(t_list **stack_b)
{
	t_list	*pre_last;
	t_list	*last;
	t_list	*tmp;

	if (*stack_b && (*stack_b)->next)
	{
		tmp = *stack_b;
		pre_last = find_pre_last(*stack_b);
		last = pre_last->next;
		pre_last->next = NULL;
		last->next = tmp;
		*stack_b = last;
		write(1, "rrb\n", 4);
	}
}

void	rotate_a(t_list **stack_a)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = *stack_a;
	tmp2 = *stack_a;
	*stack_a = (*stack_a)->next;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = tmp2;
	tmp->next->next = NULL;
	write(1, "ra\n", 3);
}

void	rotate_b(t_list **stack_b)
{
	t_list	*last;
	t_list	*tmp;

	last = *stack_b;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	if (*stack_b == NULL)
		return ;
	while (last->next)
		last = last->next;
	last->next = tmp;
	tmp->next = NULL;
	write(1, "rb\n", 3);
}