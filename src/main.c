/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rubennijhuis <rubennijhuis@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/13 16:38:00 by rubennijhui   #+#    #+#                 */
/*   Updated: 2022/04/28 12:39:20 by rnijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lib_vec.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	set_values(t_vec *vec, long *values, unsigned int size)
{
	unsigned int		i;
	long	*new_values;
	
	new_values = malloc(sizeof(long) * size);
	if (!new_values)
		return ;
	i = 0;
	while (i < size)
	{
		new_values[i] = values[i];
		i++;
	}
	vec->values = new_values;
}

t_vec	*create_vec(long *values, unsigned int size)
{
	t_vec *new_vec;

	new_vec = malloc(sizeof(t_vec));
	if (!new_vec)
		return (NULL);
	new_vec->size = size;
	set_values(new_vec, values, size);
	return (new_vec);
}

void	add_vec(t_vec *vec1, t_vec *vec2)
{
	unsigned int	i;

	if (vec1->size != vec2->size)
		return ;
	i = 0;
	while (i < vec1->size)
	{
		vec1->values[i] += vec2->values[i];
		i++;
	}
}

void	subtract_vec(t_vec *vec1, t_vec *vec2)
{
	unsigned int	i;

	if (vec1->size != vec2->size)
		return ;
	i = 0;
	while (i < vec1->size)
	{
		vec1->values[i] -= vec2->values[i];
		i++;
	}
}

void	print_vec(t_vec *vec)
{
	unsigned int	i;

	i = 0;
	while (i < vec->size)
	{
		printf("pos[%i] - val[%li]\n", i, vec->values[i]);
		i++;
	}
}
