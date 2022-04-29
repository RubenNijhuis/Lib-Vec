/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lib_vec.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rubennijhuis <rubennijhuis@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/13 16:38:43 by rubennijhui   #+#    #+#                 */
/*   Updated: 2022/04/29 19:31:42 by rnijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_VEC_H
# define LIB_VEC_H

typedef struct s_vec
{
	int			values[3];
}t_vec;

t_vec	create_vec(int values, unsigned int size);
void	add_vec(t_vec *vec1, t_vec *vec2);
void	subtract_vec(t_vec *vec1, t_vec *vec2);
void	print_vec(t_vec *vec);

#endif