#include "push_swap.h"

void	push_b(t_list **stack_b, t_list **stack_a)

{
	t_list	*tmp;

	if (*stack_a)
	{
		tmp = (*stack_a)->next;
		(*stack_a)->next = *stack_b;
		*stack_b = *stack_a;
		*stack_a = tmp;
		write(1, "pb\n", 3);
	}
}

void	push_a(t_list **stack_b, t_list **stack_a)
{
	t_list	*tmp;

	if (*stack_b)
	{
		tmp = (*stack_b)->next;
		(*stack_b)->next = *stack_a;
		*stack_a = *stack_b;
		*stack_b = tmp;
		write(1, "pa\n", 3);
	}
}

void	swap_a(t_list **stack_a)
{
	int	tmp;

	if (!(*stack_a))
		return ;
	tmp = (*stack_a)->data;
	(*stack_a)->data = (*stack_a)->next->data;
	(*stack_a)->next->data = tmp;
	tmp = (*stack_a)->pos;
	(*stack_a)->pos = (*stack_a)->next->pos;
	(*stack_a)->next->pos = tmp;
	write(1, "sa\n", 3);
}

void	swap_b(t_list **stack_b)
{
	int	tmp;

	if (!(*stack_b))
		return ;
	tmp = (*stack_b)->data;
	(*stack_b)->data = (*stack_b)->next->data;
	(*stack_b)->next->data = tmp;
	tmp = (*stack_b)->pos;
	(*stack_b)->pos = (*stack_b)->next->pos;
	(*stack_b)->next->pos = tmp;
	write(1, "sb\n", 3);
}
