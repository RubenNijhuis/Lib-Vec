/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rubennijhuis <rubennijhuis@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/25 22:42:56 by rubennijhui   #+#    #+#                 */
/*   Updated: 2022/07/22 18:38:00 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// Functions to compare original to real version
#include "libvec.h"
#include <stdbool.h>
#include <stdio.h>

#include <math.h>

// Testing lib
#include <criterion/criterion.h>

// TODO: write more tests

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

Test(vec3f_cross_test, passing)
{
	t_vec3f a = { 0, 0, 1, 0 };
	t_vec3f b = { 1, 0, 0, 0 };

	t_vec3f c = vec3f_cross(a, b);

	cr_expect(vec3f_eq(c, vec3f(0, 1, 0)), "invalid cross product");
}

Test(vec3f_get_angle_test, passing)
{
	t_vec3f a = vec3f(1, 0, 0);
	t_vec3f b = vec3f(0, 1, 0);

	double angle = vec3f_get_angle(a, b);
	cr_expect(angle == M_PI_2, "invalid angle");

	b = vec3f(1, 1, 0);

	angle = vec3f_get_angle(a, b);
	cr_expect(roundf(angle * 100000) == roundf(M_PI_4 * 100000), "invalid angle %f", angle);
}

Test(vec3f_rotate_axis_test, passing)
{
	t_vec3f axis = vec3f(0, 1, 0);
	t_vec3f v = vec3f(1, 0, 0);

	t_vec3f result = vec3f_rotate_axis(v, axis, M_PI_2);
	t_vec3f comp = vec3f(0, 0, -1.0f);

	// printf("%f, %f, %f\n",  result[0], result[1], result[2]);
	// printf("%f, %f, %f\n",  comp[0], comp[1], comp[2]);
	// printf("%d, %d, %d\n",  comp[0] == result[0], comp[1] == result[1], comp[2] == result[2]);

	// can't use vec3_eq because apparently result[0] isn't 0.0f. sigh.
	// but it's smaller than it's epsilon, so it's practically 0.
	cr_expect(result[0] < __FLT_EPSILON__ && result[1] < __FLT_EPSILON__ && result[2] == comp[2],
		"invalid rotation %f, %f, %f", result[0], result[1], result[2]);
}

Test(vec3f_round, passing)
{
	t_vec3f	v = vec3f(4.524, 0.2f, 5.9f);
	vec3f_round(&v);
	cr_assert(vec3f_eq(v, vec3f(5, 0, 6)), "invalid round");
}
