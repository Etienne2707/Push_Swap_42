/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educlos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:26:43 by educlos           #+#    #+#             */
/*   Updated: 2023/09/19 17:38:42 by educlos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all(t_list **stack_a, t_list **stack_b, int *tab)
{
	t_list	*tmp;

	while (*stack_a != NULL)
	{
		tmp = (*stack_a)->next;
		free(*stack_a);
		*stack_a = tmp;
	}
	while (*stack_b != NULL)
	{
		tmp = (*stack_b)->next;
		free(*stack_b);
		*stack_b = tmp;
	}
	free(tab);
}

void	free_a(t_list **stack_a, int *tab)
{
	t_list	*tmp;

	while (*stack_a != NULL)
	{
		tmp = (*stack_a)->next;
		free(*stack_a);
		*stack_a = tmp;
	}
	free(tab);
}
