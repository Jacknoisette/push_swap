/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:27:16 by jdhallen          #+#    #+#             */
/*   Updated: 2024/12/17 12:28:40 by jdhallen         ###   ########.fr       */
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
				return (ft_printf("%i\n", stack[j]), 1);
			j++;
		}
		i++;
	}
	return (0);
}

int	stackcreation(int *stack, const int argc, const char **argv)
{
	long	numb;
	int		i;
	int		j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (ft_isdigit(argv[i][j]) == 0 && (j == 0 && argv[i][0] != '-'))
				return (ft_printf("Error\n"), 1);
			j++;
		}
		if ((j > 10 && argv[i][0] != '-') || (j > 11 && argv[i][0] == '-'))
			return (ft_printf("Error\n"), 1);
		numb = ft_atol(argv[i]);
		if (numb > INT_MAX || numb < INT_MIN)
			return (ft_printf("Error\n"), 1);
		stack[i - 1] = (int)numb;
		i++;
	}
	if (check_double(stack, argc) == 1)
		return (ft_printf("Error\n"), 1);
	return (stack[i - 1] = '\0', 0);
}

int	main(int argc, char **argv)
{
	int	*stack;
	int	stackres;
	int	i;
	int	len;

	len = argc;
	stack = malloc((len) * sizeof(int));
	if (stack == NULL)
		return (ft_printf("Error\n"), 0);
	stackres = stackcreation(stack, len, (const char **)argv);
	if (stackres == 1)
		return (free(stack), 0);
	push_swap(stack, len - 1);
	ft_printf("\n________\n");
	i = 0;
	while (i < len - 1)
		ft_printf("%i, ", stack[i++]);
	ft_printf("\n");
	return (free(stack), 1);
}
