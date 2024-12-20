/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:27:16 by jdhallen          #+#    #+#             */
/*   Updated: 2024/12/20 17:06:35 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_double(int *stack, const int max)
{
	int	i;
	int	j;

	i = 0;
	while (i < max - 1)
	{
		j = 0;
		while (j < max - 1)
		{
			if (stack[i] == stack[j] && j != i)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	stackcreation(int *stack, const int argc, const char **argv)
{
	long	numb;
	t_v		v;

	v.i = 1;
	while (v.i < argc)
	{
		v.j = ft_strlen(argv[v.i]);
		v.k = 0;
		while (argv[v.i][v.k] == '-' || argv[v.i][v.k] == '+'
			|| argv[v.i][v.k] == '0')
			v.k++;
		v.j -= v.k;
		if (v.j > 10 && argv[v.i][0] != '-')
			return (ft_printf("Error\n"), 1);
		numb = ft_atol(argv[v.i], &v.n, 0, 0);
		if (numb > INT_MAX || numb < INT_MIN || v.n == 1)
			return (ft_printf("Error\n"), 1);
		stack[v.i++ - 1] = (int)numb;
	}
	if (check_double(stack, argc) == 1)
		return (ft_printf("Error\n"), 1);
	return (stack[v.i - 1] = '\0', 0);
}

int	main(int argc, char **argv)
{
	int	*stack;
	int	stackres;
	int	len;

	len = argc;
	stack = malloc((len) * sizeof(int));
	if (stack == NULL)
		return (ft_printf("Error\n"), 0);
	stackres = stackcreation(stack, len, (const char **)argv);
	if (stackres == 1)
		return (free(stack), 0);
	push_swap(stack, len - 1, 0);
	return (free(stack), 1);
}

	// int	i;
	// i = 0;
	// while (i < len - 1)
	// 	ft_printf("%i, ", stack[i++]);
	// ft_printf("\n");