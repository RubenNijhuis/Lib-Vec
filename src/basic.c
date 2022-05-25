/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   basic.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rnijhuis <rnijhuis@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/25 19:35:16 by rnijhuis      #+#    #+#                 */
/*   Updated: 2022/05/25 19:38:15 by rnijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"
#include <math.h>

/* returns a vec3f with the position (x, y, z) */
t_vec3f	vec3f(float x, float y, float z)
{
	const t_vec3f	pos = {
		x,
		y,
		z,
		0.0f
	};

	return (pos);
}

/* returns the magnitude/length of a vector. */
float	vec3f_length(const t_vec3f vec)
{
	return (sqrt(vec3f_len_sq(vec)));
}

/* normalizes vector vec */
void	vec3f_normalize(t_vec3f *vec)
{
	const float	invlen = 1.0f / vec3f_length(*vec);

	*vec *= invlen;
}

/* sum up two vectors.
 * TODO: is removing the const on a, doing the operation on a, and returning
 * a faster? Or pass by pointers? */
t_vec3f	vec3f_sum(const t_vec3f a, const t_vec3f b)
{
	return (a + b);
}

t_vec3f	vec3f_subtract(const t_vec3f a, const t_vec3f b)
{
	return (a - b);
}
