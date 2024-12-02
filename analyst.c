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


// int	commander(t_bint **list_a, t_bint **list_b, int intlen)
// {

// }


int	push_swap(int *stack)
{
	t_bint *list_a;
    t_bint *list_b;
	int numb;
	int len;
	int	ind;

	len = intlen(stack);
	list_a = build_bint(stack, len, 0);
	list_b = build_bint(stack, len, 1);
   
	stack = build_int(stack, list_a, len);
    return (numb);
}
