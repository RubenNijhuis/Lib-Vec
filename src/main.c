/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rubennijhuis <rubennijhuis@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/13 16:38:00 by rubennijhui   #+#    #+#                 */
/*   Updated: 2022/06/22 17:19:00 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

#include <math.h> /* sqrt */

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

/* vec += b */
void	vec3f_translate(t_vec3f *vec, const t_vec3f b)
{
	*vec += b;
}

void	vec3f_multiply_scalar(t_vec3f *vec, const float scalar)
{
	*vec *= scalar;
}

/* returns true if vectors a and b are equal */
int	vec3f_eq(const t_vec3f a, const t_vec3f b)
{
	return (a[0] == b[0]
		&& a[1] == b[1]
		&& a[2] == b[2]
		&& a[3] == b[3]);
}
