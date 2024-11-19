/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:51:45 by jdhallen          #+#    #+#             */
/*   Updated: 2024/11/18 16:51:46 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_bint *list_a, t_bint *list_b, int mod, int intlen)
{
	int i;
	t_bint temp;

	if (mod == 1 || mod == 3)
	{
		i = 0;
		temp = list_a[0];
        while (i < intlen - 1)
        {
            list_a[i] = list_a[i + 1];
			i++;
        }
        list_a[intlen - 1] = temp;
	}
	if (mod == 2 || mod == 3)
	{
		i = 0;
		temp = list_b[0];
        while (i < intlen - 1)
        {
            list_b[i] = list_b[i + 1];
			i++;
        }
        list_b[intlen - 1] = temp;
	}
}

