/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rubennijhuis <rubennijhuis@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/13 16:38:00 by rubennijhui   #+#    #+#                 */
/*   Updated: 2022/05/24 15:37:02 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

#include <math.h> /* sqrt */

/* returns a vec3f with the position (x, y, z) */
t_vec3f	vec3f(float x, float y, float z)
{
	t_vec3f	pos;

	pos.x = x;
	pos.y = y;
	pos.z = z;
	return (pos);
}

/* returns the dot product of vec */
float	vec3f_len_sq(const t_vec3f vec)
{
	return (vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
}

/* Returns the dot product of two vectors */
float	vec3f_dot(const t_vec3f a, const t_vec3f b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

/* returns the magnitude/length of a vector. */
float	vec3f_length(const t_vec3f vec)
{
	return (sqrt(vec3f_len_sq(vec)));
}

/* sum up two vectors.
 * TODO: is removing the const on a, doing the operation on a, and returning
 * a faster? Or pass by pointers? */
t_vec3f	vec3f_sum(const t_vec3f a, const t_vec3f b)
{
	t_vec3f	vec;

	vec.x = a.x + b.x;
	vec.y = a.y + b.y;
	vec.z = a.z + b.z;
	return (vec);
}

t_vec3f	vec3f_subtract(const t_vec3f a, const t_vec3f b)
{
	t_vec3f	vec;

	vec.x = a.x - b.x;
	vec.y = a.y - b.y;
	vec.z = a.z - b.z;
	return (vec);
}

/* normalizes vector vec */
void	vec3f_normalize(t_vec3f *vec)
{
	const float	invlen = 1.0f / vec3f_length(*vec);

	vec->x *= invlen;
	vec->y *= invlen;
	vec->z *= invlen;
}

/* vec += b */
void	vec3f_translate(t_vec3f *vec, const t_vec3f b)
{
	vec->x += b.x;
	vec->y += b.y;
	vec->z += b.z;
}

void	vec3f_multiply_scalar(t_vec3f *vec, const float scalar)
{
	vec->x *= scalar;
	vec->y *= scalar;
	vec->z *= scalar;
}
