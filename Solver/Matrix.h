#pragma once
#include <iostream>
#include <vector>
#include <sstream>
#include "RandomGenerator.h"
#include "IStreamGenerator.h"

namespace miit::algebra
{
	template<typename T> class Matrix;

	/*
	* @brief Оператор "<<" для класса Matrix.
	*/
	template<typename T>
	std::ostream& operator<<(std::ostream& os, const Matrix<T>& matrix);

	/*
	* @brief Класс матрица.
	*/
	template<typename T>
	class Matrix
	{
	private:
		/*
		* @brief Вектор векторов Матрица.
		*/
		std::vector<std::vector<T>> matrix;

		/*
		* @brief Строки.
		*/
		size_t rows;

		/*
		* @brief Столбцы.
		*/
		size_t columns;
	public:
		/*
		* @brief Консртуктор.
		*/
		Matrix() = default;

		/*
		* @brief Конструктор.
		* @param Rows количество строк.
		* @param Columns количество столбцов.
		*/
		Matrix(size_t Rows, size_t Columns);

		/*
		* @brief Консртуктор копирования.
		*/
		Matrix(const Matrix& other) = default;

		/*
		* @brief Консртуктор копирования перемещением.
		*/
		Matrix(Matrix&& other) noexcept = default;

		/*
		* @brief Оператор копирования.
		*/
		Matrix& operator = (const Matrix& other) = default;
		/*
		* @brief Оператор копирования перемещением.
		*/
		Matrix& operator = (Matrix&& other) noexcept = default;

		/*
		* @brief Оператор доступа к строке.
		* @param index индекс строки.
		* @return Ссылку на вектор строки матрицы.
		*/
		std::vector<T>& operator [](size_t index);

		/*
		* @brief Оператор доступа к строке.
		* @param index индекс строки.
		* @return Ссылку на вектор строки матрицы.
		*/
		const std::vector<T>& operator [](size_t index) const;

		/*
		* @brief Метод заполения матрицы значениями.
		* @param generator генератор.
		*/
		void Fill(Generator& generator);

		/*
		* @brief Метод получения колличества строк.
		* @return Колличество строк матрицы.
		*/
		size_t GetRows();

		/*
		* @brief Метод получения колличества столбцов.
		* @return Колличество столбцов матрицы.
		*/
		size_t GetColumns();

		/*
		* @brief Метод сериализации в строку ToString().
		* @return Возвращает строковое представление матрицы.
		*/
		std::string ToString() const;

		/*
		* @brief Метод удаления строки матрицы.
		* @param delete_row строка, которую нужно удалить.
		*/
		void DeleteRow(size_t delete_row);
	};
}
template<typename T>
inline miit::algebra::Matrix<T>::Matrix(size_t Rows, size_t Columns) :rows{ Rows }, columns{ Columns }
{
	matrix.assign(Rows, std::vector<T>(Columns));
}

template<typename T>
inline std::vector<T>& miit::algebra::Matrix<T>::operator[](size_t index)
{
	if (index >= rows)
	{
		throw std::out_of_range("Некорректный индекс");
	}
	return matrix[index];
}

template<typename T>
inline void miit::algebra::Matrix<T>::Fill(miit::algebra::Generator& generator)
{
	for (size_t i = 0;i < rows;i++)
	{
		for (size_t j = 0; j < columns; j++)
		{
			matrix[i][j] = generator.generate();
		}
	}
}

template<typename T>
inline size_t miit::algebra::Matrix<T>::GetRows()
{
	return rows;
}

template<typename T>
inline size_t miit::algebra::Matrix<T>::GetColumns()
{
	return columns;
}

template<typename T>
inline const std::vector<T>& miit::algebra::Matrix<T>::operator[](size_t index) const
{
	if (index >= rows)
	{
		throw std::out_of_range("Некорректный индекс");
	}
	return Matrix[index];
}

template<typename T>
inline std::string miit::algebra::Matrix<T>::ToString() const
{
	std::stringstream buffer{};
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < columns; j++)
		{
			buffer << matrix[i][j] << " ";
		}
		buffer << std::endl;
	}
	return buffer.str();
}

template<typename T>
inline void miit::algebra::Matrix<T>::DeleteRow(size_t delete_row)
{
	if (delete_row >= rows)
	{
		throw std::out_of_range("Выход за границы допустимых значений");
	}
	matrix.erase(matrix.begin() + delete_row);
	--rows;
}

template<typename T>
std::ostream& miit::algebra::operator<<(std::ostream& os, const Matrix<T>& matrix)
{
	os << matrix.ToString();
	return os;
}