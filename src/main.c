/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rubennijhuis <rubennijhuis@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/13 16:38:00 by rubennijhui   #+#    #+#                 */
/*   Updated: 2022/04/29 19:31:30 by rnijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lib_vec.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

t_vec	create_vec(int values, unsigned int size)
{
	t_vec new_vec;
	set_values(new_vec, values, size);
	return (new_vec);
}

void	add_vec(t_vec *vec1, t_vec *vec2)
{
	unsigned int	i;

	i = 0;
	while (i < 3)
	{
		vec1->values[i] += vec2->values[i];
		i++;
	}
}

void	subtract_vec(t_vec *vec1, t_vec *vec2)
{
	unsigned int	i;

	i = 0;
	while (i < 3)
	{
		vec1->values[i] -= vec2->values[i];
		i++;
	}
}

void	print_vec(t_vec *vec)
{
	unsigned int	i;

	i = 0;
	while (i < 3)
	{
		printf("pos[%i] - val[%li]\n", i, vec->values[i]);
		i++;
	}
}
