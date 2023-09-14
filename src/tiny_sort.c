#include "push_swap.h"

void	sort_three(t_list **stack_a)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->data;
	b = (*stack_a)->next->data;
	c = (*stack_a)->next->next->data;
	if (a > b && c > b && c > a)
		swap_a(stack_a);
	else if (a > b && a > c && b > c)
	{
		swap_a(stack_a);
		reverse_a(stack_a);
	}
	else if (a > b && c > b && a > c)
		rotate_a(stack_a);
	else if (a < b && a < c && b > c)
	{
		swap_a(stack_a);
		rotate_a(stack_a);
	}
	else if (a < b && a > c && b > c)
		reverse_a(stack_a);
}

void	sort_four(t_list **stack_a, t_list **stack_b)
{
	int	min;

	min = min_pile(stack_a);
	while ((*stack_a)->data != min)
		rotate_a(stack_a);
	push_b(stack_b, stack_a);
	sort_three(stack_a);
	push_a(stack_a, stack_b);
}

void	sort_five(t_list **stack_a, t_list **stack_b)
{
	int	min;
	int	min2;
	int	half;
	int	pos;

	half = (init_count(stack_a) / 2);
	min = min_pile(stack_a);
	pos = get_pos(stack_a, min);
	while ((*stack_a)->data != min)
	{
		if (pos >= half)
			reverse_a(stack_a);
		else
			rotate_a(stack_a);
	}
	push_b(stack_b, stack_a);
	min2 = min_pile(stack_a);
	while ((*stack_a)->data != min2)
		rotate_a(stack_a);
	push_b(stack_b, stack_a);
	sort_three(stack_a);
	push_a(stack_a, stack_b);
	push_a(stack_a, stack_b);
}

int	min_pile(t_list **stack_a)
{
	t_list	*tmp;
	int		min;

	tmp = *stack_a;
	min = (*stack_a)->data;
	while ((*stack_a) != NULL)
	{
		if (min > (*stack_a)->data)
			min = (*stack_a)->data;
		*stack_a = (*stack_a)->next;
	}
	*stack_a = tmp;
	return (min);
}

int	get_pos(t_list **stack_a, int min)
{
	t_list	*tmp;
	int		pos;

	tmp = *stack_a;
	pos = 0;
	while ((*stack_a)->data != min)
	{
		pos++;
		*stack_a = (*stack_a)->next;
	}
	*stack_a = tmp;
	return (pos);
}