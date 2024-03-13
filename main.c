#include "quadratic_equation_suitecases.h"
// #include "../quadratic_equation/lib_quadratic_equation.h"
#include "quadratic_equation/lib_quadratic_equation.h"

int main(void) {
  Suite *cases[] = {suite_s21_add(), NULL};

  for (Suite **current_testcase = cases; *current_testcase != NULL;
       current_testcase++) {
    run_testcase(*current_testcase);
  }
  return 0;
}

void run_testcase(Suite *testcase) {
  SRunner *sr = srunner_create(testcase);
  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);
  srunner_free(sr);
}
