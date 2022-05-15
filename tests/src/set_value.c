/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_value.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rubennijhuis <rubennijhuis@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/25 22:42:56 by rubennijhui   #+#    #+#                 */
/*   Updated: 2022/05/15 23:30:53 by rubennijhui   ########   odam.nl         */
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

Test(multiply_vec3f, passing) {
	t_vec3f test_vec;

	test_vec.x = 2;
	test_vec.y = 2;
	test_vec.z = 2;

	float scalar = 3;
	multiply_vec3f(&test_vec, scalar);
	cr_expect(test_vec.x == 6.0f, "Expected the new value to be 6");
}

Test(normalize_vector, passing) {
	t_vec3f test_vec;

	test_vec.x = 2;
	test_vec.y = 3;
	test_vec.z = 4;

	float inv_vec_len = 1 / get_vec3f_len(test_vec);
	multiply_vec3f(&test_vec, inv_vec_len);

	cr_expect(get_vec3f_len(test_vec) == 1.0f, "Expected the vector length to be 1");
}
