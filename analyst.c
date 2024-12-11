/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:52:06 by jdhallen          #+#    #+#             */
/*   Updated: 2024/11/18 16:52:07 by jdhallen         ###   ########.fr       */
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

int	little_stack_sort(t_stack *stack_a, t_stack *stack_b, int len, int count)
{
	ft_printf("_____LITTLE_SORT_____\n");
	if (stack_a->len > 3)
		count += quintuplet(stack_a, stack_b, len, 0);
	else if (stack_a->len > 2)
		count += triplet(stack_a, len, 0);
	else if (stack_a->len > 1)
		count += swap(stack_a, len, 1);
	ft_printf("_____________________\n");
	return (count);
}

int get_max_bits(t_stack *stack, int len)
{
	int max;
	int bits;

	max = stack->list[check_big(stack, len, 0)];
	bits = 0;
	while (max > 0)
	{
		max >>= 1;
		bits++;
	}
	return (bits);
}

int radix_sort(t_stack *stack_a, t_stack *stack_b, int len, int count)
{
	int	max_bits;
	int	i;
	int	j;
	int	num;

	max_bits = get_max_bits(stack_a, len);
	i = 0;
	if (stack_a->len <= 5 && !check_sort(stack_a, len, 0))
		count += little_stack_sort(stack_a, stack_b, len, count);
	while (i < max_bits && !check_sort(stack_a, len, 0))
	{
		j = 0;
		while (j < stack_a->len)
		{
			num = stack_a->list[len - stack_a->len];
            if (((num >> i) & 1) == 0)
				count += push(stack_b, stack_a, len);	
			else
				count += rotate(stack_a, len, 1);
			j++;
			printf_all(*stack_a, *stack_b, len, count);
		}
		if (stack_a->len <= 5)
			count += little_stack_sort(stack_a, stack_b, len, count);
		while (stack_b->len > 0)
			count += push(stack_a, stack_b, len);
		i++;
    }
	ft_printf("max_bits : %i\n ", max_bits);
	return (count);
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
	printf_all(stack_a, stack_b, len, count);
	free(stack_b.list);
	return (count);
}

