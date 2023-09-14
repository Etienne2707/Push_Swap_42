#include "push_swap.h"

int	aldready_sort(t_list **stack_a)
{
    while ((*stack_a) && (*stack_a)->next)
    {
        if ((*stack_a)->data > (*stack_a)->next->data)
        {
            return 0; // La liste n'est pas triée
        }
        *stack_a = (*stack_a)->next;
    }
    write(1, "Deja trier", 10);
    return 1; // La liste est triée
}

void	sort_choice(t_list **stack_a, t_list **stack_b, int ac)
{
	int	count;


	count = init_count(stack_a);
	if (count == 2)
		swap_a(stack_a);
	else if (count == 3)
		sort_three(stack_a);
	else if (count == 4)
		sort_four(stack_a,
			stack_b);
	else if (count == 5)
		sort_five(stack_a, stack_b);
	else if (count > 5 && count <= 100)
		sort_x100(stack_a, stack_b, ac);
	else
		sort_x500(stack_a, stack_b, ac);
}