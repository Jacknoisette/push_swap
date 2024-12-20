/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:52:06 by jdhallen          #+#    #+#             */
/*   Updated: 2024/12/20 17:52:59 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printf_all(t_stack stack_a, t_stack stack_b, int len, int count)
{
	int	i;

	i = len - stack_a.len;
	ft_printf("\nstack_a\n");
	while (i < len)
		ft_printf("%i, ", stack_a.list[i++]);
	ft_printf("\nstack_b\n");
	i = len - stack_b.len;
	while (i < len)
		ft_printf("%i, ", stack_b.list[i++]);
	ft_printf("\n");
	ft_printf("count : %i\n\n", count);
}

int	push_swap(int *stack, int len, int count)
{
	t_stack	stack_a;
	t_stack	stack_b;

	stack_a.letter = 'a';
	stack_b.letter = 'b';
	stack_a.list = stack;
	stack_b.list = malloc((len + 1) * sizeof(int));
	if (stack_b.list == NULL)
		return (0);
	stack_a.len = len;
	stack_b.len = 0;
	if (check_sort(&stack_a, len, 0))
		return (count);
	if (stack_a.len == 5 || stack_a.len == 4)
		count += quintuplet(&stack_a, &stack_b, len, 0);
	else if (stack_a.len == 3)
		count += triplet(&stack_a, len, 0);
	else if (stack_a.len == 2)
		count += swap(&stack_a, len, 1);
	else
		count += chunk_sort(&stack_a, &stack_b, len, count);
	if (count == -1)
		return (-1);
	printf_all(stack_a, stack_b, len, count);
	free(stack_b.list);
	return (count);
}

//setopt shwordsplit
//unsetopt shwordsplit
	// ft_printf("len : %i\n", len);
	// ft_printf("________ORIGIN________\n");
	// printf_all(stack_a, stack_b, len, count);
	// ft_printf("______________________\n\n");
	// if (check_sort(&stack_a, len, 0))
	// 	ft_printf("\nSTACK IS SORTED !!!\n");