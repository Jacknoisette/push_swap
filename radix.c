/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 10:52:01 by jdhallen          #+#    #+#             */
/*   Updated: 2024/12/12 11:39:39 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	little_stack_sort(t_stack *stack_a, t_stack *stack_b, int len, int count)
{
	if (stack_a->len > 3)
		count += quintuplet(stack_a, stack_b, len, 0);
	else if (stack_a->len > 2)
		count += triplet(stack_a, len, 0);
	else if (stack_a->len > 1)
		count += swap(stack_a, len, 1);
	return (count);
}

int get_max_bits(t_stack *stack, int len)
{
	int max;
	int bits;

	bits = 0;
	max = stack->list[check_big(stack, len, 0)];
	if (max < 0)
	{
		max *= -1;
		bits += 1;
	}
	while (max > 0)
	{
		max >>= 1;
		bits++;
	}
	return (bits);
}

// // return 1 if rr is faster, 0 if r i faster
// int eco_rotate(t_stack *stack_a, t_stack *stack_b, int len, int count)
// {
//     int medium;
//     int add;
//     int numb;
//     int num;
//     int i;

//     i = 0;
//     add = 0;
//     numb = 0;
//     while (i < stack_a->len)
// 	{
//         num = stack_a->list[len - stack_a->len];
//         if (((num >> i) & 1) == 0)
//         {
//             add += i;
//             numb += 1;
//         }
//     }
//     medium = add / numb;
//     if (medium < stack_a->len / 2)
//         return (0);
//     return (medium)
// }

int radix_sort(t_stack *stack_a, t_stack *stack_b, int len, int count)
{
	int	max_bits;
	int	i;
	int	j;
	int	num;
	int stack_len;

	max_bits = get_max_bits(stack_a, len);
	i = 0;
	if (stack_a->len <= 5 && !check_sort(stack_a, len, 0))
		count += little_stack_sort(stack_a, stack_b, len, count);
	while (i < max_bits && !check_sort(stack_a, len, 0))
	{
		j = 0;
		stack_len = stack_a->len;
		while (j < stack_len)
		{
			num = stack_a->list[len - stack_a->len];
            if (((num >> i) & 1) == 0)
				count += push(stack_b, stack_a, len);	
			else
				count += rotate(stack_a, len, 1);
			j++;
		}
		printf_all(*stack_a, *stack_b, len, count);
		ft_printf("\n");
		while (stack_b->len > 0)
			count += push(stack_a, stack_b, len);
		i++;
    }
	ft_printf("max_bits : %i\n ", max_bits);
	for (int k = 1; k < len; k++)
	{
		if (stack_a->list[k] < stack_a->list[k - 1])
			ft_printf("%i ", stack_a->list[k]);
	}
	return (count);
}