#include "Exercise.h"
using namespace miit::algebra;
void miit::algebra::Exercise::task1()
{
    for (size_t i = 0; i < matrix.GetRows(); i++)
    {
        for (size_t j = 0; j < matrix.GetColumns(); j++)
        {
            if (matrix[i][j] % 3 == 0)
            {
                matrix[i][j] = 0;
            }
        }
    }
}

void miit::algebra::Exercise::task2()
{
    if (matrix.GetColumns() < 4)
    {
        throw std::out_of_range("Слишком мало столбцов");
    }

    for (size_t i = matrix.GetRows(); i > 0; )
    {

        --i;

        if (matrix[i][1] > matrix[i][matrix.GetColumns() - 2])
        {
            matrix.DeleteRow(i);
        }

    }
}

Matrix<int> miit::algebra::Exercise::GetMatrix()
{
    return matrix;
}
