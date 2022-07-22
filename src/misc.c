/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   misc.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jobvan-d <jobvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/22 16:14:23 by jobvan-d      #+#    #+#                 */
/*   Updated: 2022/07/22 16:17:15 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libvec.h"

bool	vec3f_is_zero(const t_vec3f v)
{
	return (v[0] < __FLT_EPSILON__ && v[0] >= 0.0f
		&& v[1] < __FLT_EPSILON__ && v[1] >= 0.0f
		&& v[2] < __FLT_EPSILON__ && v[2] >= 0.0f);
}
