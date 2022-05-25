/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rubennijhuis <rubennijhuis@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/13 16:38:00 by rubennijhui   #+#    #+#                 */
/*   Updated: 2022/05/25 15:25:02 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

#include <math.h> /* sqrt */

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

/* returns the dot product of vec */
/* there is probably some crazy intrinsic builtin which makes this faster,
 * but I am not aware of that */
float	vec3f_len_sq(const t_vec3f vec)
{
	const t_vec3f	sq = vec * vec;

	return (sq[0] + sq[1] + sq[2]);
}

/* Returns the dot product of two vectors */
float	vec3f_dot(const t_vec3f a, const t_vec3f b)
{
	const t_vec3f	product = a * b;

	return (product[0] + product[1] + product[2]);
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
	return (a + b);
}

t_vec3f	vec3f_subtract(const t_vec3f a, const t_vec3f b)
{
	return (a - b);
}

/* normalizes vector vec */
void	vec3f_normalize(t_vec3f *vec)
{
	const float	invlen = 1.0f / vec3f_length(*vec);

	*vec *= invlen;
}

/* vec += b */
void	vec3f_translate(t_vec3f *vec, const t_vec3f b)
{
	*vec += b;
}

void	vec3f_multiply_scalar(t_vec3f *vec, const float scalar)
{
	*vec *= scalar;
}

int	vec_eq(const t_vec3f a, const t_vec3f b)
{
	return (a[0] == b[0]
		&& a[1] == b[1]
		&& a[2] == b[2]
		&& a[3] == b[3]);
}
