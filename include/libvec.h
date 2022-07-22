/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libvec.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rubennijhuis <rubennijhuis@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/13 16:38:43 by rubennijhui   #+#    #+#                 */
/*   Updated: 2022/07/22 18:38:27 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBVEC_H
# define LIBVEC_H

# include <stdbool.h>

/* le epic vector compiler attribute */
/* the reason we use 4 components instead of 3 is because the vector attibrute
 * requires size to be a power of two.
 * access elements individually like an array, e.g. pos[1] for y value. 
 * the fourth element, "w", should always be 0 to prevent errors. */
typedef float	t_vec3f __attribute__ ((vector_size ((sizeof(float) * 4))));

typedef enum e_rotation_type
{
	rotate_x,
	rotate_y,
	rotate_z
}	t_rotation_type;

t_vec3f	rotate(t_rotation_type rotation, t_vec3f dir, float angle);

// Create
t_vec3f	vec3f(float x, float y, float z);

// Arithmatic
float	vec3f_dot(const t_vec3f a, const t_vec3f b);
t_vec3f	vec3f_cross(t_vec3f a, t_vec3f b);
float	vec3f_length(const t_vec3f vec);
float	vec3f_len_sq(const t_vec3f vec);

t_vec3f	vec3f_sum(const t_vec3f a, const t_vec3f b);
t_vec3f	vec3f_subtract(const t_vec3f a, const t_vec3f b);

void	vec3f_normalize(t_vec3f *vec);
void	vec3f_translate(t_vec3f *vec, const t_vec3f b);
void	vec3f_multiply_scalar(t_vec3f *vec, const float scalar);

double	vec3f_get_angle(const t_vec3f a, const t_vec3f b);
double	vec3f_unit_get_angle(const t_vec3f a, const t_vec3f b);
t_vec3f	vec3f_rotate_axis(const t_vec3f v, const t_vec3f axis,
			const double angle);

void	vec3f_round(t_vec3f *v);

// Assertion
bool	vec3f_eq(const t_vec3f a, const t_vec3f b);
bool	vec3f_is_zero(const t_vec3f v);

#endif
