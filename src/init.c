#include "push_swap.h"

void	init_stack(t_list **stack_a, int ac, char **av,int *tab)
{
	int		i;
	int		j;
	t_list	*tmp;

	i = 1;
	j = 0;
	while (i < ac)
	{
		tab[j] = atoi_checker(av[i]);
		tmp = create_nb(ft_atoi(av[i]), j, stack_a, tab);
		ft_lstadd_back(stack_a, tmp);
		i++;
		j++;
	}
}

t_list	*create_nb(int a, int b, t_list **stack_a, int *tab)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
	{
		free_a(stack_a, tab);
		return (NULL);
	}
	new->data = a;
	new->pos = b;
	new->next = NULL;
	return (new);
}

void	init_pos(t_list **stack_a, int *tab, int ac)
{
	
	t_list	*tmp;
	int		i;

	tmp = *stack_a;
	while (tmp != NULL)
	{
		i = 0;
		while (i < ac - 1)
		{
			if (tmp->data == tab[i])
				tmp->pos = i;
			i++;
		}
		tmp = tmp->next;
	}
}

int *init_tab(int *tab, int ac)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	j = 0;

	while (i < ((ac - 1) - 1))
	{
		j = 0;
		while (j < ((ac - 1) - i - 1))
		{
			if (tab[j] > tab[j + 1])
			{
				tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
    return (tab);
}