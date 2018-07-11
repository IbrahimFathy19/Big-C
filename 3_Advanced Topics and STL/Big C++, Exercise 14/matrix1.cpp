#include <iomanip>
#include "matrix1.h"

Matrix::Matrix()
{
   for (int i = 0; i < ROWS; i++)
      for (int j = 0; j < COLUMNS; j++)
         (*this)(i, j) = 0;
}
   
Matrix& Matrix::operator+=(const Matrix& right)
{
   for (int i = 0; i < ROWS; i++)
      for (int j = 0; j < COLUMNS; j++)
         (*this)(i, j) += right(i, j);
   return *this;
}

Matrix & Matrix::operator-=(const Matrix & right)
{
	for (int i = 0; i < ROWS; i++)
		for (int j = 0; j < COLUMNS; j++)
			(*this)(i, j) -= right(i, j);
	return *this;
}

Matrix operator+(const Matrix& left, const Matrix& right)
{
   Matrix result = left;
   result += right;
   return result;
}

Matrix operator-(const Matrix & left, const Matrix & right)
{
	/**
	Matrix result = left;
	result -= right;
	return result;
	*/

	Matrix result = left;
	result = left + -right;
	return result;
}

Matrix operator-(const Matrix & value)
{
	return Matrix(value * -1);
}
   
Matrix operator*(const Matrix& left, const Matrix& right)
{
   Matrix result;
   for (int i = 0; i < Matrix::ROWS; i++)
      for (int j = 0; j < Matrix::COLUMNS; j++)
         for (int k = 0; k < Matrix::COLUMNS; k++)         
            result(i, j) += left(i, k) * right(k, j); 
   return result;
}

Matrix operator*(const Matrix & left, const std::vector<double>& right)
{
	Matrix result;
	for (int i = 0; i < Matrix::ROWS; i++)
		for (int j = 0; j < Matrix::COLUMNS; j++)
				result(i, j) = left(i, j) * right[j];
	return result;
}

Matrix operator*(const std::vector<double>& left, const Matrix & right)
{
	Matrix result;
	for (int i = 0; i < Matrix::ROWS; i++)
		for (int j = 0; j < Matrix::COLUMNS; j++)
			result(i, j) = right(i, j) * left[j];
	return result;
}
   
Matrix operator*(const Matrix& left, double right)
{
   Matrix result;
   for (int i = 0; i < Matrix::ROWS; i++)
      for (int j = 0; j < Matrix::COLUMNS; j++)
         result(i, j) = left(i, j) * right; 
   return result;
}
   
std::ostream& operator<<(std::ostream& left, const Matrix& right)
{
   const int WIDTH = 10;
   for (int i = 0; i < Matrix::ROWS; i++)
   {
      for (int j = 0; j < Matrix::COLUMNS; j++)
         left << std::setw(WIDTH) << right(i, j);
      left << "\n";
   }
   return left;
}

std::istream & operator>>(std::istream & left, Matrix & right)
{
	for (int i = 0; i < Matrix::ROWS; i++)
		for (int j = 0; j < Matrix::COLUMNS; j++)
			left >> right(i, j);

	return left;
}

