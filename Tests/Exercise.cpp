?#include "pch.h"
#include "CppUnitTest.h"
#include "..\Solver\Exercise.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace miit::algebra;

namespace ExerciseTest
{
	TEST_CLASS(ExerciseTest)
	{
	public:

		TEST_METHOD(Task1_ValidData_Success)
		{
			RandomGenerator gen(-9, 9);
			Exercise matrix(3, 3, gen);
			Exercise matrixcopy = matrix;
			matrix.task1();
			for (size_t i = 0; i < matrixcopy.GetRows(); i++)
			{
				for (size_t j = 0; j < matrixcopy.GetColumns(); j++)
				{
					if (matrixcopy[i][j] % 3 == 0)
					{
						Assert::IsTrue(matrixcopy[i][j] == matrix[i][j]);
					}
				}
			}
		}

		TEST_METHOD(Task2_ValidData_Success)
		{
			RandomGenerator gen(-9, 9);
			Exercise matrix(3, 4, gen);
			matrix.task2();
			if (matrix.GetMatrix().GetRows() != 0)
			{
				for (size_t i = 0; i < matrix.GetMatrix().GetRows(); ++i)
				{
					Assert::IsTrue(matrix.GetMatrix()[i][1] < matrix.GetMatrix()[i][2]);
				}
			}
		}
	};
}