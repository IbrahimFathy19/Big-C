#ifndef MATRIX1_H
#define MATRIX1_H

#include <iostream>
#include <cassert>
#include <vector>


/**
   This class describes a row in a matrix.
*/
class Matrix; // Forward definition
class MatrixRow
{
public:
   /**
      Remembers a row for a given matrix.
      @param m a pointer to the matrix
      @param s the size of the row
   */
   MatrixRow(Matrix* m, int s);

   /**
      Accesses a row element.
      @param j the column index
      @return a reference to the element with the given index
   */
   double& operator[](int j);

private:
   Matrix* mat;
   int i;
};

/**
   This class describes a row in a constant matrix.
*/
class ConstMatrixRow
{
public:
   /**
      Constructs a row with a given start and size.
      @param m a pointer to the matrix
      @param s the size of the row
   */
   ConstMatrixRow(const Matrix* m, int s);

   /**
      Accesses a row element.
      @param j the column index
      @return a reference to the element with the given index
   */
   double operator[](int j) const;

private:
   const Matrix* mat;
   int i;
};

/**
   This class describes a 3 x 3 matrix.
*/
class Matrix
{
public:
   /**
      Constructs a matrix filled with zero elements.
   */
   Matrix();

   /**
      Accesses a matrix element.
      @param i the row index
      @param j the column index
      @return a reference to the element with the given indexes
   */
   double& operator()(int i, int j);

   /**
      Accesses a matrix element.
      @param i the row index
      @param j the column index
      @return the element with the given indexes
   */
   double operator()(int i, int j) const;

   /**
      Accesses a matrix row.
      @param i the row index
      @return the row with the given index
   */
   MatrixRow operator[](int i);   

   /**
      Accesses a matrix row.
      @param i the row index
      @return the row with the given index
   */
   ConstMatrixRow operator[](int i) const;

   /**
      Computes the matrix sum.
      @param right another matrix
      @return the updated matrix
   */
   Matrix& operator+=(const Matrix& right);

	/**
		Computes the matrix difference.
		@param right another matrix
		@return the updated matrix
	*/
	Matrix& operator-=(const Matrix& right);

   static const int ROWS = 3;
   static const int COLUMNS = 3;

private:
   double elements[ROWS * COLUMNS];
};

/**
   Computes the matrix sum.
   @param right another matrix
   @return the sum of two matrices
*/
   Matrix operator+(const Matrix& left, const Matrix& right);

/**
	Computes the matrix difference.
	@param right another matrix
	@return the difference of two matrices
*/
	Matrix operator-(const Matrix& left, const Matrix& right);

/**
	Computes the negation of the matrix
	@param matrix to be negated
	@return negated matrix
*/
	Matrix operator-(const Matrix& value);

/**
   Computes the matrix product.
   @param right another matrix
   @return the product of two matrices
*/
   Matrix operator*(const Matrix& left, const Matrix& right);

/**
	Computes the matrix-vector product.
	Number of Columns of the matrix must be equal to the number of rows of the vector
	@param right vector treated as column vector
	@return the product of matrix and vector
*/
Matrix operator*(const Matrix& left, const std::vector<double>& right);

/**
	Computes the matrix-vector product.
	Number of Columns of the matrix must be equal to the number of rows of the vector
	@param left vector treated as column vector
	@return the product of matrix and vector
*/
Matrix operator*(const std::vector<double>& left, const Matrix& right);

/**
   Computes the scalar product of a scalar value and a matrix.
   @param left a scalar value
   @param right a matrix
   @return the product of the given value and the given matrix
*/
Matrix operator*(double left, const Matrix& right);

/**
   Computes the scalar product of a matrix and a scalar value.
   @param right a scalar value
   @return the product of this matrix and the given value
*/
Matrix operator*(const Matrix& left, double right);

/**
   Prints a matrix to an output stream.
   @param left an output stream
   @param right a matrix
   @return the given output stream
*/
std::ostream& operator<<(std::ostream& left, const Matrix& right);

/**
	Inputs a matrix to an input stream.
	@param left an input stream
	@param right a matrix
	@return the given input stream
*/
std::istream& operator>>(std::istream& left, Matrix& right);

inline double& Matrix::operator()(int i, int j)
{
   assert(0 <= i && i < ROWS && 0 <= j && j < COLUMNS);
   return elements[i * COLUMNS + j];
}

inline double Matrix::operator()(int i, int j) const
{
   assert(0 <= i && i < ROWS && 0 <= j && j < COLUMNS);
   return elements[i * COLUMNS + j];
}
   
inline MatrixRow Matrix::operator[](int i) 
{
   return MatrixRow(this, i);
}   

inline ConstMatrixRow Matrix::operator[](int i) const
{
   return ConstMatrixRow(this, i);
}   
   
inline MatrixRow::MatrixRow(Matrix* m, int s) : mat(m), i(s) { }
   
inline double& MatrixRow::operator[](int j)
{
   return (*mat)(i,j);
}   

inline ConstMatrixRow::ConstMatrixRow(const Matrix* m, int s) 
   : mat(m), i(s) { }

inline double ConstMatrixRow::operator[](int j) const
{
   return (*mat)(i, j);
}   

inline Matrix operator*(double left, const Matrix& right)
{
   return right * left;
}

#endif
