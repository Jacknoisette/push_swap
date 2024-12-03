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

void	printf_all(t_stack stack_a, t_stack stack_b, int len)
{
	int	i;

	i = len - stack_a.len;
	ft_printf("stack_a\n");
	while (i < len)
		ft_printf("%i, ", stack_a.list[i++]);
	ft_printf("\nstack_b\n");
	i = len - stack_b.len;
	while (i < len)
		ft_printf("%i, ", stack_b.list[i++]);
	ft_printf("\n");
}

int	push_swap(int *stack, int len)
{
	t_stack stack_a;
	t_stack stack_b;

	stack_a.list = stack;
	stack_b.list = malloc((len) * sizeof(int));
	stack_a.len = len;
	stack_b.len = 0;
	ft_printf("origin\n");
	printf_all(stack_a, stack_b, len);
	ft_printf("\npb * 2\n");
	push(&stack_b, &stack_a, len);
	push(&stack_b, &stack_a, len);
	printf_all(stack_a, stack_b, len);
	ft_printf("\nrr\n");
	rreverse_rotate(&stack_a, &stack_b, len);
	printf_all(stack_a, stack_b, len);
	ft_printf("\nsa\n");
	swap(&stack_a, len);
	printf_all(stack_a, stack_b, len);
	free(stack_b.list);
    return (0);
}

