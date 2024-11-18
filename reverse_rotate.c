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

void	reverse_rotate(int *list_a, int *list_b, int mod, int intlen)
{
	int i;
	int temp;

	if (mod == 1 || mod == 3)
	{
		i = 0;
		temp = list_a[intlen - 1];
        while (i < intlen - 1)
        {
            list_a[i] = list_a[i - 1];
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
            list_b[i] = list_b[i - 1];
			i++;
        }
        list_b[intlen - 1] = temp;
	}
}

int main(void)
{
	int	list_a[] = {4,6,1,3,9,2};
	int	list_b[] = {0,0,0,0,0,0};
	int	i;

	reverse_rotate(list_a, list_b, 3, 6);
	i = 0;
	while (i++ < 6)
		printf("%i  %i\n", list_a[i - 1], list_b[i - 1]);
	printf("a  b \n");
	return (0);
}