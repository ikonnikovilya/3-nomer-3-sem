#include <iostream>
#include "..\Solver\Matrix.h"
#include "..\Solver\Exercise.h"
using namespace miit::algebra;
int main()
{
	miit::algebra::RandomGenerator gen(0, 9);
	Exercise matrix(4, 4, gen);
	std::cout << matrix.GetMatrix();
	matrix.task2();
	std::cout << std::endl << matrix.GetMatrix();
	return 0;
}