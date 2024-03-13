// tests/test_quadratic_equation.c

// #include "../quadratic_equation/lib_quadratic_equation.h"
#include "quadratic_equation/lib_quadratic_equation.h"
#include "quadratic_equation_suitecases.h"

// #include <stdio.h>
// #include <assert.h>

// void test_solve_equation() {
//     EquationSolution sol;

//     // Тест 1: два корня
//     sol = solve_equation(1, -3, 2);
//     ck_assert_double_eq(sol.num_roots == 2);
//     printf("Test 1 passed\n");

//     // Тест 2: один корень
//     sol = solve_equation(1, -2, 1);
//     assert(sol.num_roots == 1);
//     printf("Test 2 passed\n");

//     // Тест 3: нет корней
//     sol = solve_equation(1, 0, 1);
//     assert(sol.num_roots == 0);
//     printf("Test 3 passed\n");

//     // Тест 4: линейное уравнение
//     sol = solve_equation(0, 2, -4);
//     assert(sol.num_roots == 1);
//     printf("Test 4 passed\n");
// }

// int main() {
//     test_solve_equation();
//     printf("All tests passed.\n");
//     return 0;
// }

START_TEST(div_9) {
    EquationSolution sol = solve_equation(1, -3, 2);
    ck_assert_int_eq(sol.num_roots, 2);

}
END_TEST

Suite *suite_s21_add(void) {
    Suite *s = suite_create("add");
    TCase *tc = tcase_create("add");

    suite_add_tcase(s, tc);
    tcase_add_test(tc, div_9);
    return s;
}

