#ifndef QUADRATIC_EQUATION_H
#define QUADRATIC_EQUATION_H

#include <math.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    double root1;
    double root2;
    int num_roots;
} EquationSolution;

EquationSolution solve_equation(double a, double b, double c);
EquationSolution linear_equation(double b, double c, EquationSolution solution);
EquationSolution discriminant_solution(double a, double b, double c, EquationSolution solution);

#ifdef __cplusplus
}
#endif

#endif // QUADRATIC_EQUATION_H
