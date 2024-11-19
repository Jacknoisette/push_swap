/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:51:50 by jdhallen          #+#    #+#             */
/*   Updated: 2024/11/18 16:51:52 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_bint *list_a, t_bint *list_b, int mod, int intlen)
{
	int i;
	t_bint temp;

	if (mod == 1 || mod == 3)
	{
		i = intlen - 1;
		temp = list_a[intlen - 1];
        while (i > 0)
        {
			list_a[i] = list_a[i - 1];
			i--;
        }
        list_a[0] = temp;
	}
	if (mod == 2 || mod == 3)
	{
		i = intlen - 1;
		temp = list_b[intlen - 1];
        while (i > 0)
        {
			list_b[i] = list_b[i - 1];
			i--;
        }
        list_b[0] = temp;
	}
}
