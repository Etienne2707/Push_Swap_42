/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educlos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:26:53 by educlos           #+#    #+#             */
/*   Updated: 2023/09/20 12:22:11 by educlos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		*tab;

	stack_a = NULL;
	stack_b = NULL;
	if (ac == 1)
		return (0);
	tab = malloc(sizeof(int) * (ac - 1));
	if (!tab)
		return (0);
	if (!checker(ac, av))
	{
		free_all(&stack_a, &stack_b, tab);
		return (0);
	}
	init_stack(&stack_a, ac, av, tab);
	if (aldready_sort(&stack_a, &stack_b, tab))
		return (0);
	init_tab(tab, ac);
	init_pos(&stack_a, tab, ac);
	sort_choice(&stack_a, &stack_b, ac);
	free_all(&stack_a, &stack_b, tab);
}
