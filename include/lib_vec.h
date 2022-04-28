/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lib_vec.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rubennijhuis <rubennijhuis@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/13 16:38:43 by rubennijhui   #+#    #+#                 */
/*   Updated: 2022/04/28 12:41:02 by rnijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_VEC_H
# define LIB_VEC_H

typedef struct s_vec
{
	long			*values;
	unsigned int	size;
}t_vec;

void	set_values(t_vec *vec, long *values, unsigned int size);
t_vec	*create_vec(long *values, unsigned int size);
void	add_vec(t_vec *vec1, t_vec *vec2);
void	subtract_vec(t_vec *vec1, t_vec *vec2);
void	print_vec(t_vec *vec);

#endif