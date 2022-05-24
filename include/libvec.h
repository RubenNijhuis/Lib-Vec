/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libvec.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rubennijhuis <rubennijhuis@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/13 16:38:43 by rubennijhui   #+#    #+#                 */
/*   Updated: 2022/05/24 15:30:55 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBVEC_H
# define LIBVEC_H

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
typedef struct s_vec {
	void	*data;
	int32_t	length;
	int32_t	capacity;
	int32_t	elem_size;
}t_vec;
*/

t_vec3f	vec3f(float x, float y, float z);

float	vec3f_dot(const t_vec3f a, const t_vec3f b);
float	vec3f_length(const t_vec3f vec);
float	vec3f_len_sq(const t_vec3f vec);

t_vec3f	vec3f_sum(const t_vec3f a, const t_vec3f b);
t_vec3f	vec3f_subtract(const t_vec3f a, const t_vec3f b);

void	vec3f_normalize(t_vec3f *vec);
void	vec3f_translate(t_vec3f *vec, const t_vec3f b);
void	vec3f_multiply_scalar(t_vec3f *vec, const float scalar);

#endif
