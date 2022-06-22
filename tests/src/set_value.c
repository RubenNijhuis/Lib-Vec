/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_value.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rubennijhuis <rubennijhuis@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/25 22:42:56 by rubennijhui   #+#    #+#                 */
/*   Updated: 2022/06/22 17:18:04 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// Functions to compare original to real version
#include "libvec.h"
#include <stdbool.h>
#include <stdio.h>

// Testing lib
#include <criterion/criterion.h>

// TODO: write more tests

// void	print_vec(const t_vec3f v)
// {
// 	printf("(%f, %f, %f, %f)\n", v[0], v[1], v[2], v[3]);
// }

Test(vec3f_constructor, passing)
{
	t_vec3f test_vec = vec3f(2, 2, 2);

	cr_expect(test_vec[0] == 2.0f, "Expected new x value to be 2");
	cr_expect(test_vec[1] == 2.0f, "Expected new y value to be 2");
	cr_expect(test_vec[2] == 2.0f, "Expected new z value to be 2");
	cr_expect(test_vec[3] == 0.0f, "Expected new z value to be 0");
	cr_expect(vec3f_eq(test_vec, (t_vec3f){ 2, 2, 2, 0 }), "expected vecs to be equal");
}

Test(vec3f_mutliply_scalar, passing)
{
	t_vec3f test_vec = vec3f(2, 2, 2);

	float scalar = 3;
	vec3f_multiply_scalar(&test_vec, scalar);
	cr_expect(vec3f_eq(test_vec, vec3f(6, 6, 6)), "expected vec to be (6, 6, 6)");
}

// TODO: tests two thinks at once, should just test one instead
Test(normalize_vector, passing)
{
	t_vec3f test_vec = { 2, 3, 4, 0.0f };

	vec3f_normalize(&test_vec);

	cr_expect(vec3f_length(test_vec) == 1.0f, "Expected the vector length to be 1");
}

Test(vec3f_dot_test, passing)
{
	t_vec3f a = { 1, 4, 5, 0 };
	t_vec3f b = { 0, 2, 5, 0 };

	cr_expect(vec3f_dot(a, b) == 0 + 8 + 25, "invalid dot product");
}
