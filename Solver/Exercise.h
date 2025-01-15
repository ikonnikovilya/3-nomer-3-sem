#pragma once
#include "Matrix.h"
#include "ExerciseVirtual.h"
namespace miit::algebra
{
	/*
	*@brief класс задание, наследник виртуального задания
	*/
	class Exercise :public miit::algebra::ExerciseVirtual
	{
	public:

		/*
		*@brief конструктор класса задание
		*@param rows - количество строк
		*@param columns - количество столбцов
		*@param generator - генератор
		*/
		Exercise(size_t rows, size_t columns, Generator& generator) : ExerciseVirtual(rows, columns, generator) {}

		/*
		*@brief заменяет каждый элемент кратный 3 на 0
		*/
		void task1() override;

		/*
		*@brief удаляет все строки, в которых второй элемент больше предпоследнего.
		*/
		void task2() override;

		/*
		*@brief геттер матрицы
		*@return матрица из задания
		*/
		Matrix<int> GetMatrix();

	};
}
