#include "push_swap.h"

int	rb_or_rrb(t_list **stack_b, int size)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = *stack_b;
	while (tmp)
	{
		if (tmp->pos == size)
			break ;
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void	sorting_b(t_list **stack_a, t_list **stack_b, int ac)
{
	int	size;
	int	half;
	int	location;

	size = ac - 2;
	location = 0;
	half = 0;
	while (*stack_b != NULL)
	{
		half = (size + 1) / 2;
		location = rb_or_rrb(stack_b, size);
		if ((*stack_b)->pos == size)
		{
			push_a(stack_b, stack_a);
			size--;
		}
		else if (location <= half && (*stack_b)->pos != size)
			rotate_b(stack_b);
		else
			reverse_b(stack_b);
	}
}

void	sort_x100(t_list **stack_a, t_list **stack_b, int ac)
{
	int	i;

	i = 0;
	while (*stack_a)
	{
		if ((*stack_a)->pos <= i && i > 1)
		{
			push_b(stack_b, stack_a);
			rotate_b(stack_b);
			i++;
		}
		else if ((*stack_a)->pos <= (i + 15))
		{
			push_b(stack_b, stack_a);
			i++;
		}
		else if ((*stack_a)->pos >= i)
			rotate_a(stack_a);
	}
	sorting_b(stack_a, stack_b, ac);
}

void	sort_x500(t_list **stack_a, t_list **stack_b, int ac)
{
	int	i;

	i = 0;
	while (*stack_a)
	{
		if ((*stack_a)->pos <= i && i > 1)
		{
			push_b(stack_b, stack_a);
			rotate_b(stack_b);
			i++;
		}
		else if ((*stack_a)->pos <= (i + 25))
		{
			push_b(stack_b, stack_a);
			i++;
		}
		else if ((*stack_a)->pos >= i)
			rotate_a(stack_a);
	}
	sorting_b(stack_a, stack_b, ac);
}