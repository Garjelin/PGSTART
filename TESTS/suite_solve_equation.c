#include "quadratic_equation_suitecases.h"

START_TEST(quadratic_equation_1) {  // позитивный, простые числа
  EquationSolution sol = solve_equation(2, -1, -6);
  ck_assert_double_eq_tol(sol.root1, 2, 1e-15);
  ck_assert_double_eq_tol(sol.root2, -1.5, 1e-15);
  ck_assert_int_eq(sol.num_roots, 2);
}
END_TEST

START_TEST(quadratic_equation_2) {  // позитивный, простые числа
  EquationSolution sol = solve_equation(3, 4, 5);
  ck_assert_double_eq_tol(sol.root1, 0, 1e-15);
  ck_assert_double_eq_tol(sol.root2, 0, 1e-15);
  ck_assert_int_eq(sol.num_roots, 0);
}
END_TEST

START_TEST(quadratic_equation_3) {  // позитивный, все положительные
  EquationSolution sol = solve_equation(3, 10, 5);
  ck_assert_double_eq_tol(sol.root1, -0.6125741132772068, 1e-15);
  ck_assert_double_eq_tol(sol.root2, -2.720759220056127, 1e-15);
  ck_assert_int_eq(sol.num_roots, 2);
}
END_TEST

START_TEST(quadratic_equation_4) {
  EquationSolution sol =
      solve_equation(-3, -10, -5);  // позитивный, все отрицательные
  ck_assert_double_eq_tol(sol.root1, -2.720759220056127, 1e-15);
  ck_assert_double_eq_tol(sol.root2, -0.6125741132772068, 1e-15);
  ck_assert_int_eq(sol.num_roots, 2);
}
END_TEST

START_TEST(quadratic_equation_5) {  // позитивный, дробные
  EquationSolution sol =
      solve_equation(3.123456789012345, 10.123456789012345, 5.123456789012345);
  ck_assert_double_eq_tol(sol.root1, -0.6276399765926859, 1e-15);
  ck_assert_double_eq_tol(sol.root2, -2.6134667435721357, 1e-15);
  ck_assert_int_eq(sol.num_roots, 2);
}
END_TEST

START_TEST(quadratic_equation_6) {  // позитивный, очень маленькое число
  EquationSolution sol =
      solve_equation(0.000000000000003, 0.00000000000001, 0.000000000000005);
  ck_assert_double_eq_tol(sol.root1, -0.6125741132772069, 1e-15);
  ck_assert_double_eq_tol(sol.root2, -2.720759220056127, 1e-15);
  ck_assert_int_eq(sol.num_roots, 2);
}
END_TEST

START_TEST(quadratic_equation_7) {  // позитивный, очень большое число
  EquationSolution sol =
      solve_equation(2000000000001, -10000000000002, -60000000000003);
  ck_assert_double_eq_tol(sol.root1, 8.520797289393965, 1e-15);
  ck_assert_double_eq_tol(sol.root2, -3.5207972893954653, 1e-15);
  ck_assert_int_eq(sol.num_roots, 2);
}
END_TEST

START_TEST(quadratic_equation_8) {  // позитивный, a = 0
  EquationSolution sol = solve_equation(0, 5, 10);
  ck_assert_double_eq_tol(sol.root1, -2, 1e-15);
  ck_assert_double_eq_tol(sol.root2, 0, 1e-15);
  ck_assert_int_eq(sol.num_roots, 1);
}
END_TEST

START_TEST(quadratic_equation_9) {  // позитивный, b = 0
  EquationSolution sol = solve_equation(2, 0, -10);
  ck_assert_double_eq_tol(sol.root1, 2.23606797749979, 1e-15);
  ck_assert_double_eq_tol(sol.root2, -2.23606797749979, 1e-15);
  ck_assert_int_eq(sol.num_roots, 2);
}
END_TEST

START_TEST(quadratic_equation_10) {  // позитивный, c = 0
  EquationSolution sol = solve_equation(2, 5, 0);
  ck_assert_double_eq_tol(sol.root1, 0, 1e-15);
  ck_assert_double_eq_tol(sol.root2, -2.5, 1e-15);
  ck_assert_int_eq(sol.num_roots, 2);
}
END_TEST

START_TEST(quadratic_equation_11) {  // позитивный, a,b,c = 0
  EquationSolution sol = solve_equation(0, 0, 0);
  ck_assert_double_eq_tol(sol.root1, 0, 1e-15);
  ck_assert_double_eq_tol(sol.root2, 0, 1e-15);
  ck_assert_int_eq(sol.num_roots, 0);
}
END_TEST

START_TEST(quadratic_equation_12) {  // позитивный, D = 0
  EquationSolution sol = solve_equation(1, 2, 1);
  ck_assert_double_eq_tol(sol.root1, -1, 1e-15);
  ck_assert_double_eq_tol(sol.root2, 0, 1e-15);
  ck_assert_int_eq(sol.num_roots, 1);
}
END_TEST

START_TEST(quadratic_equation_13) {  // негативный, a = NAN
  EquationSolution sol = solve_equation(NAN, 1, 1);
  ck_assert_double_eq_tol(sol.root1, 0, 1e-15);
  ck_assert_double_eq_tol(sol.root2, 0, 1e-15);
  ck_assert_int_eq(sol.num_roots, 0);
}
END_TEST

START_TEST(quadratic_equation_14) {  // негативный, b = NAN
  EquationSolution sol = solve_equation(1, NAN, 1);
  ck_assert_double_eq_tol(sol.root1, 0, 1e-15);
  ck_assert_double_eq_tol(sol.root2, 0, 1e-15);
  ck_assert_int_eq(sol.num_roots, 0);
}
END_TEST

START_TEST(quadratic_equation_15) {  // негативный, c = NAN
  EquationSolution sol = solve_equation(1, 1, NAN);
  ck_assert_double_eq_tol(sol.root1, 0, 1e-15);
  ck_assert_double_eq_tol(sol.root2, 0, 1e-15);
  ck_assert_int_eq(sol.num_roots, 0);
}
END_TEST

START_TEST(quadratic_equation_16) {  // негативный, a = INFINITY
  EquationSolution sol = solve_equation(INFINITY, 1, 1);
  ck_assert_double_eq_tol(sol.root1, 0, 1e-15);
  ck_assert_double_eq_tol(sol.root2, 0, 1e-15);
  ck_assert_int_eq(sol.num_roots, 0);
}
END_TEST

START_TEST(quadratic_equation_17) {  // негативный, b = INFINITY
  EquationSolution sol = solve_equation(1, INFINITY, 1);
  ck_assert_double_eq_tol(sol.root1, 0, 1e-15);
  ck_assert_double_eq_tol(sol.root2, 0, 1e-15);
  ck_assert_int_eq(sol.num_roots, 0);
}
END_TEST

START_TEST(quadratic_equation_18) {  // негативный, c = INFINITY
  EquationSolution sol = solve_equation(1, 1, INFINITY);
  ck_assert_double_eq_tol(sol.root1, 0, 1e-15);
  ck_assert_double_eq_tol(sol.root2, 0, 1e-15);
  ck_assert_int_eq(sol.num_roots, 0);
}
END_TEST

Suite *suite_quadratic_equation(void) {
  Suite *s = suite_create("quadratic_equation");
  TCase *tc = tcase_create("quadratic_equation");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, quadratic_equation_1);
  tcase_add_test(tc, quadratic_equation_2);
  tcase_add_test(tc, quadratic_equation_3);
  tcase_add_test(tc, quadratic_equation_4);
  tcase_add_test(tc, quadratic_equation_5);
  tcase_add_test(tc, quadratic_equation_6);
  tcase_add_test(tc, quadratic_equation_7);
  tcase_add_test(tc, quadratic_equation_8);
  tcase_add_test(tc, quadratic_equation_9);
  tcase_add_test(tc, quadratic_equation_10);
  tcase_add_test(tc, quadratic_equation_11);
  tcase_add_test(tc, quadratic_equation_12);
  tcase_add_test(tc, quadratic_equation_13);
  tcase_add_test(tc, quadratic_equation_14);
  tcase_add_test(tc, quadratic_equation_15);
  tcase_add_test(tc, quadratic_equation_16);
  tcase_add_test(tc, quadratic_equation_17);
  tcase_add_test(tc, quadratic_equation_18);
  return s;
}
