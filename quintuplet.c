/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quintuplet.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:23:25 by jdhallen          #+#    #+#             */
/*   Updated: 2024/12/02 17:23:27 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int quintuplet(t_stack *stack_a, t_stack *stack_b, int len, int count)
{
    while (stack_a->len > 3)
    {
         // Trouve la plus petite valeur
        if (check_little(stack_a, len, 0) == 0)
            count += push(stack_b, stack_a, len);
        else
            count += rotate(stack_a, len);
    }
    count += triplet(stack_a, len, 0);
    while (stack_b->len > 0)
        count += push(stack_a, stack_b, len);
    return (count);
}
