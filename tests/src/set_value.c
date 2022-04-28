/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_value.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rubennijhuis <rubennijhuis@student.coda      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/25 22:42:56 by rubennijhui   #+#    #+#                 */
/*   Updated: 2022/04/28 22:07:53 by rnijhuis      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// Lib to be tested

// Functions to compare original to real version
#include "lib_vec.h"
#include <string.h>
#include <stdio.h>

// Testing lib
#include <criterion/criterion.h>

Test(addition, basic) {
	t_vec *main_vec;
	long values[3] = {1, 1, 1};
	main_vec = create_vec(values, 3);

	t_vec *secondary_vec;
	long values2[3] = {2, 2, 2};
	secondary_vec = create_vec(values2, 3);
	
	add_vec(main_vec, secondary_vec);
	cr_expect(main_vec->values[0] == 3, "Expected the new value to be 3");
}

Test(subtract, basic) {
	t_vec *main_vec;
	long values[3] = {1, 1, 1};
	main_vec = create_vec(values, 3);

	t_vec *secondary_vec;
	long values2[3] = {2, 2, 2};
	secondary_vec = create_vec(values2, 3);
	
	subtract_vec(main_vec, secondary_vec);
	cr_expect(main_vec->values[0] == -1, "Expected the new value to be -1");
}
