/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libvec.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rubennijhuis <rubennijhuis@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/13 16:38:43 by rubennijhui   #+#    #+#                 */
/*   Updated: 2022/07/07 17:11:30 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBVEC_H
# define LIBVEC_H

/* le epic vector compiler attribute */
/* the reason we use 4 components instead of 3 is because the vector attibrute
 * requires size to be a power of two.
 * access elements individually like an array, e.g. pos[1] for y value. 
 * the fourth element, "w", should always be 0 to prevent errors. */
typedef float	t_vec3f __attribute__ ((vector_size ((sizeof(float) * 4))));

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

// Assertion
int		vec3f_eq(const t_vec3f a, const t_vec3f b);

#endif
