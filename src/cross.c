/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cross.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jobvan-d <jobvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/22 17:09:11 by jobvan-d      #+#    #+#                 */
/*   Updated: 2022/06/22 17:16:08 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

/* returns the cross product of vectors a and b. */
t_vec3f	vec3f_cross(t_vec3f a, t_vec3f b)
{
	const t_vec3f	ret = {
		a[1] * b[2] - a[2] * b[1],
		a[2] * b[0] - a[0] * b[2],
		a[0] * b[1] - a[1] * b[0],
		0
	};

	return (ret);
}
