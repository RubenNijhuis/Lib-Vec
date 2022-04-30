/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libvec.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rubennijhuis <rubennijhuis@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/13 16:38:43 by rubennijhui   #+#    #+#                 */
/*   Updated: 2022/04/30 14:49:32 by rubennijhui   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBVEC_H
# define LIBVEC_H

/*
	Vector made of unions
	Meant to be used for positions,
	orientations and colors
	x,y,z || r,g,b
*/
typedef struct s_vec3i {
	union {
		int	x;
		int	r;
	};
	union {
		int	y;
		int	g;
	};
	union {
		int	z;
		int	b;
	};
}	t_vec3i;

/*
	vec with size for 3 floats
*/
typedef struct s_vec3f {
	float	x;
	float	y;
	float	z;
}	t_vec3f;

/*
	General vector with "unlimited" size 
	and reallocation when adding more elements
*/
typedef struct s_vec {
	void	*data;
	int		length;
	int		capacity;
	int		elem_size;
}	t_vec;

#endif