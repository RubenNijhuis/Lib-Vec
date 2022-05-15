/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libvec.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rubennijhuis <rubennijhuis@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/13 16:38:43 by rubennijhui   #+#    #+#                 */
/*   Updated: 2022/05/15 23:31:12 by rubennijhui   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBVEC_H
# define LIBVEC_H

# include <stdlib.h>

// Token definitions
enum e_vec_type { vec_int, vec_float };
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
	int32_t	length;
	int32_t	capacity;
	int32_t	elem_size;
}	t_vec;

float	get_vec3f_len(t_vec3f vec);
void	multiply_vec3f(t_vec3f *vec, float scalar);

#endif