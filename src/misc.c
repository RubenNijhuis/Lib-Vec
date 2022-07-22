/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   misc.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jobvan-d <jobvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/22 16:14:23 by jobvan-d      #+#    #+#                 */
/*   Updated: 2022/07/22 18:38:54 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

#include <math.h> /* roundf */

/* returns true if vector v is more or less zero */
bool	vec3f_is_zero(const t_vec3f v)
{
	return (v[0] < __FLT_EPSILON__ && v[0] >= 0.0f
		&& v[1] < __FLT_EPSILON__ && v[1] >= 0.0f
		&& v[2] < __FLT_EPSILON__ && v[2] >= 0.0f);
}

/* rounds a vec3f. */
void	vec3f_round(t_vec3f *v)
{
	(*v)[0] = roundf((*v)[0]);
	(*v)[1] = roundf((*v)[1]);
	(*v)[2] = roundf((*v)[2]);
}
