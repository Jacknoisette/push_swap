/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:51:57 by jdhallen          #+#    #+#             */
/*   Updated: 2024/11/18 16:51:58 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int **list_a, int **list_b, int mod)
{
	int temp;

	if (mod == 1 || mod == 3)
	{
		temp = *list_a[0];
		*list_a[0] = *list_a[1];
		*list_a[1] = temp;
	}
	if (mod == 2 || mod == 3)
	{
		temp = *list_b[0];
		*list_b[0] = *list_b[1];
		*list_b[1] = temp;
	}
	return ;
}
