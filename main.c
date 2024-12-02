/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdhallen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:51:27 by jdhallen          #+#    #+#             */
/*   Updated: 2024/11/18 16:51:29 by jdhallen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	int	*stack;
	int	i;
	int	j;
    long numb;
	int s;
	
	i = 1;
	j = 0;
	stack = malloc((argc - 1) * sizeof(int));
	while (i < argc - 1)
	{
		numb = ft_atol(argv[i]);
		ft_printf("%i\n", numb);
		i++;
		// return (ft_printf("Error\nNumber to big"), free(stack), 0);
		// return (ft_printf("Error\nWrong param type"), free(stack), 0);
	}
	//push_swap(stack);
	return (0);
}