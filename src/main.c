/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rubennijhuis <rubennijhuis@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/13 16:38:00 by rubennijhui   #+#    #+#                 */
/*   Updated: 2022/05/15 13:49:32 by rubennijhui   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"
#include <math.h>
#include <stdint.h>
#include <stdlib.h>

float	get_vec3f_len(t_vec3f vec)
{
	float	vec_len;
	float	x;
	float	y;
	float	z;

	x = vec.x;
	y = vec.y;
	z = vec.z;
	vec_len = sqrt((x * x) + (y * y) + (z * z));
	return (vec_len);
}

t_vec3f	*make_vec3f_from_sum(t_vec3f *vec_primary, t_vec3f *vec_secondary)
{
	t_vec3f	*new_vec;

	new_vec = malloc(1 * sizeof(t_vec3f));
	if (new_vec == NULL)
		return (NULL);
	new_vec->x = (vec_primary->x + vec_secondary->x);
	new_vec->x = (vec_primary->y + vec_secondary->y);
	new_vec->x = (vec_primary->z + vec_secondary->z);
	return (new_vec);
}

void	multiply_vec3f(t_vec3f *vec, float scalar)
{
	vec->x *= scalar;
	vec->y *= scalar;
	vec->z *= scalar;
}
