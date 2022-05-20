/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_value.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rubennijhuis <rubennijhuis@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/25 22:42:56 by rubennijhui   #+#    #+#                 */
/*   Updated: 2022/05/20 19:26:16 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// Lib to be tested

// Functions to compare original to real version
#include "libvec.h"
#include <string.h>
#include <stdio.h>

// Testing lib
#include <criterion/criterion.h>

// 	t_vec *main_vec;
// 	long values[3] = {1, 1, 1};
// 	main_vec = create_vec(values, 3);

// 	t_vec *secondary_vec;
// 	long values2[3] = {2, 2, 2};
// 	secondary_vec = create_vec(values2, 3);
	
// 	add_vec(main_vec, secondary_vec);
// 	cr_expect(main_vec->values[0] == 3, "Expected the new value to be 3");
// }

// Test(subtract, basic) {
// 	t_vec *main_vec;
// 	long values[3] = {1, 1, 1};
// 	main_vec = create_vec(values, 3);

// 	t_vec *secondary_vec;
// 	long values2[3] = {2, 2, 2};
// 	secondary_vec = create_vec(values2, 3);
	
// 	subtract_vec(main_vec, secondary_vec);
// 	cr_expect(main_vec->values[0] == -1, "Expected the new value to be -1");
// }

// Test(vec3f_len, passing) {
// 	t_vec3f test_vec;

// 	test_vec.x = 1;
// 	test_vec.y = 2;
// 	test_vec.z = 3;

// 	printf("\n--- Vec3flen test\nVec3f length:\n%f\n---\n\n", get_vec3f_len(test_vec));
// 	cr_expect(get_vec3f_len(test_vec) == 3.741657, "Expected the vec length to be the sqrt of [1,2,3]");
// }

// TODO: write more tests

Test(vec3f_mutliply_scalar, passing) {
	t_vec3f test_vec;

	test_vec.x = 2;
	test_vec.y = 2;
	test_vec.z = 2;

	float scalar = 3;
	vec3f_multiply_scalar(&test_vec, scalar);
	cr_expect(test_vec.x == 6.0f, "Expected new x value to be 6");
	cr_expect(test_vec.y == 6.0f, "Expected new y value to be 6");
	cr_expect(test_vec.z == 6.0f, "Expected new z value to be 6");
}

// TODO: tests two thinks at once, should just test one instead
Test(normalize_vector, passing) {
	t_vec3f test_vec;

	test_vec.x = 2;
	test_vec.y = 3;
	test_vec.z = 4;

	vec3f_normalize(&test_vec);

	cr_expect(vec3f_length(test_vec) == 1.0f, "Expected the vector length to be 1");
}
