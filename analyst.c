/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:52:06 by jdhallen          #+#    #+#             */
/*   Updated: 2024/12/12 11:43:34 by jdhallen         ###   ########.fr       */
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

int	push_swap(int *stack, int len)
{
	t_stack stack_a;
	t_stack stack_b;
	int	count;
	
	count = 0;
	stack_a.letter = 'a';
	stack_b.letter = 'b';
	stack_a.list = stack;
	ft_printf("len : %i\n", len);
	stack_b.list = malloc((len + 1) * sizeof(int));
	if (stack_b.list == NULL)
		return (0);
	stack_a.len = len;
	stack_b.len = 0;
	ft_printf("________ORIGIN________\n");
	printf_all(stack_a, stack_b, len, count);
	ft_printf("_____________________\n\n");
	// count += push(&stack_b, &stack_a, len);
	// count += push(&stack_b, &stack_a, len);
	// count += triplet(&stack_a, len, 0);
	// count += quintuplet(&stack_a, &stack_b, len, 0);
	count += radix_sort(&stack_a, &stack_b, len, count);
	// for (int i = 500; i > 0; i--)
	// 	ft_printf("%i ", i);
	printf_all(stack_a, stack_b, len, count);
	free(stack_b.list);
	return (count);
}

