/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkey_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <jdhallen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:05:10 by jdhallen          #+#    #+#             */
/*   Updated: 2024/12/16 16:25:12 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int shortcut_rot(t_stack *stack_a, t_chunk *chunks, int i)
{
    int j;
    int k;
    int stack_len;
    int middle;
    int numb;

    j = chunks->maxlen - stack_a->len;
    stack_len = stack_a->len;
    middle = 0;
    numb = 0;
    while (j < stack_len && chunks->found < chunks->chunks[i].len)
	{
		k = 0;
		while (k < chunks->chunks[i].len && 
			stack_a->list[j] !=  chunks->chunks[i].list[k])
			k++;
        if (stack_a->list[j] == chunks->chunks[i].list[k])
        {
            middle += j;
            numb += 1;
        }
        j++;
    }
    if (middle == 0 || numb == 0)
        return (0);
    return (middle /= numb, middle);
}
