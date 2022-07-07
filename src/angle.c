/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   angle.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jobvan-d <jobvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/07 17:00:22 by jobvan-d      #+#    #+#                 */
/*   Updated: 2022/07/07 17:20:20 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

#include <math.h>

/* returns the angle between vectors a and b */
double	vec3f_get_angle(const t_vec3f a, const t_vec3f b)
{
	double	cos_angle;
	double	len;

	len = vec3f_length(a) * vec3f_length(b);
	if (len == 0.0)
	{
		return (0.0);
	}
	cos_angle = (double)vec3f_dot(a, b) / len;
	return (acos(cos_angle));
}

/* returns the angle between unit vectors a and b.
 * WARNING: USE ONLY IF YOU'RE 100% SURE THEY ARE UNIT ANGLES.
 * basically the same as vec3f_get_angle, but since we know the length is one,
 * we can get rid of the very expensive length operation. */
double	vec3f_unit_get_angle(const t_vec3f a, const t_vec3f b)
{
	double	cos_angle;

	cos_angle = (double)vec3f_dot(a, b);
	return (acos(cos_angle));
}
