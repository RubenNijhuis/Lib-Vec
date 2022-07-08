/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   angle.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jobvan-d <jobvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/07 17:00:22 by jobvan-d      #+#    #+#                 */
/*   Updated: 2022/07/08 14:16:49 by jobvan-d      ########   odam.nl         */
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

/* rotates vector v around axis axis with angle. AXIS MUST BE A UNIT VECTOR.
 * you must see as the v as a point on a wheel and the axis as an axle.
 * source: https://www.youtube.com/watch?v=OKr0YCj0BW4 */
t_vec3f	vec3f_rotate_axis(const t_vec3f v, const t_vec3f axis,
	const double angle)
{
	t_vec3f		d;
	t_vec3f		r;
	t_vec3f		r_new;

	d = vec3f_dot(axis, v) * axis;
	r = v - d;
	r_new = r * (float)cos(angle) + vec3f_cross(axis, r) * (float)sin(angle);
	return (d + r_new);
}
