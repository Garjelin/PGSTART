#include "lib_quadratic_equation.h"

EquationSolution solve_equation(double a, double b, double c) {
  EquationSolution solution = {0, 0, 0};
  if (isinf(a) || isinf(b) || isinf(c)) {
    return solution;
  }

  if (a == 0)
    solution = linear_equation(
        b, c, solution);  // (a == 0) -> linear equation: bx + c = 0
  else
    solution = discriminant_solution(a, b, c, solution);

  return solution;
}

EquationSolution linear_equation(double b, double c,
                                 EquationSolution solution) {
  if (b != 0) {
    solution.root1 = -c / b;
    solution.num_roots = 1;
  }
  return solution;
}

EquationSolution discriminant_solution(double a, double b, double c,
                                       EquationSolution solution) {
  double discriminant = b * b - 4 * a * c;
  if (discriminant > 0) {
    solution.root1 = (-b + sqrt(discriminant)) / (2 * a);
    solution.root2 = (-b - sqrt(discriminant)) / (2 * a);
    solution.num_roots = 2;
  } else if (discriminant == 0) {
    solution.root1 = -b / (2 * a);
    solution.num_roots = 1;
  }
  // (discriminant < 0) -> num_roots = 0
  return solution;
}