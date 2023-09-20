/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: educlos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:26:28 by educlos           #+#    #+#             */
/*   Updated: 2023/09/19 17:43:20 by educlos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	checker(int argc, char **argv)
{
	if (!all_digits(argc, argv))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (!check_int(argv))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (!check_double(argc, argv))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	return (1);
}

int	check_double(int argc, char **argv)
{
	int	i;
	int	c;

	i = 1;
	while (i < argc)
	{
		c = i + 1;
		while (c < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[c]))
				return (0);
			c++;
		}
		if (argv[i][0] == '\0')
			return (0);
		i++;
	}
	return (1);
}

int	all_digits(int argc, char **argv)
{
	int	i;
	int	j;
	int	k;

	i = 1;
	j = 0;
	k = 0;
	while (i < argc)
	{
		j = 0;
		k = ft_strlen(argv[i]);
		while (j < k)
		{
			if ((argv[i][j] == '-' || argv[i][j] == '+'))
				j++;
			if (!ft_isdigit(argv[i][j]) && argv[i][j] != 32)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_int(char **argv)
{
	int	i;

	i = 0;
	while (argv[i] != 0)
	{
		if (ft_atoi(argv[i]) < -2147483648 || ft_atoi(argv[i]) > 2147483647)
			return (0);
		i++;
	}
	return (1);
}
