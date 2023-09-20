/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educlos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:26:59 by educlos           #+#    #+#             */
/*   Updated: 2023/09/20 12:22:28 by educlos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	aldready_sort(t_list **stack_a, t_list **stack_b, int *tab)
{
	t_list	*tmp;

	tmp = *stack_a;
	while ((*stack_a)->next != NULL)
	{
		if ((*stack_a)->data > (*stack_a)->next->data)
		{
			*stack_a = tmp;
			return (0);
		}
		*stack_a = (*stack_a)->next;
	}
	*stack_a = tmp;
	free_all(stack_a, stack_b, tab);
	write(1, "Deja trier", 10);
	return (1);
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
		sort_four(stack_a, stack_b);
	else if (count == 5)
		sort_five(stack_a, stack_b);
	else if (count > 5 && count <= 100)
		sort_x100(stack_a, stack_b, ac);
	else
		sort_x500(stack_a, stack_b, ac);
}
