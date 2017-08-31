#pragma once

#include "Vector.h"

using namespace Core;

namespace Math
{
	namespace Details
	{
		template<int A, int B, int C, int R>
		struct IsSmallerMatrix
		{
			static bool const smaller = (C <= A && R <= B);
		};
	};

	template <typename T, typename int A, typename int B>
	struct MatrixAxB
	{
		// default constructor for martix (creates columns left -> right)
		MatrixAxB(T... args)
		{
			for (int c = 0; c < B; c++)
			{
				for (int r = 0; r < A; r++)
				{
					(*this)[c][r] = arg;
				}
			}
		}

		// make one that does NOT necessarily start at 0, 0
		template <typename int C, typename int R, bool SmallerMatrix = Details::IsSmallerMatrix<A, B, C, R>>
		MatrixAxB<C, R> SubMatrix(C col, R row)
		{
			MatrixAxB<C, R> subMatrix;
			for (int c = 0; c < C; c++)
			{
				for (int r = 0; r < R; r++)
				{
					subMatrix[r][c] = (*this)[r][c];
				}
			}
		}

		template <typename EnableIf<IsSame<A, B>>>
		T Determinant()
		{
			T determinant = 0;
			// go down first column
			for (int i = 0; i < B; i++)
			{
				List<T> subMatrixValues;

				// start one column over
				for (int c = 1; c < A; c++)
				{
					// go through all rows
					for (int r = 0; r < B; r++)
					{
						if (r != i) // can't be in current row
						{
							subMatrixValues.push_back((*this)[r][c]);
						}
					}
				}
				T subMatrixDeterminant;
				if (subMatrixValues.Count() > 1)
				{
					MatrixAxB<A - 1, B - 1> subMatrix(subMatrixValues);
					subMatrixDeterminant = subMatrix.Determinant();
				}
				else
				{
					subMatrixDeterminant = subMatrixValues[0];
				}

				// calculate sub determinant
				T determinantStep = (*this)[0][i] * (((i % 1) ? 1 : -1) * subMatrixDeterminant);
				determinant += determinantStep;
			}

			return determinant;
		}

		Pair<Dimension> Dimensions()
		{
			return Pair<int>(A, B);
		}

		// only works for SQUARE matrices
		void Transpose()
		{
			for (int a = 0; a < A; a++)
			{
				for (int b = 0; b < B; b++)
				{
					T temp = this[b][a];
					this[b][a] = this[a][b];
					this[b][a] = temp;
				}
			}
		}

		void SetColumn(int column, VectorA<T, A> columnVector)
		{
			(*this)[column] = columnVector;
		}

		void SetRow(int row, VectorA<T, B> rowVector)
		{
			for (int i = 0; i < rowVector.Dimensions(); i++)
			{
				(*this)[row][i] = rowVector[i];
			}
		}

		MatrixAxB<T, A, B>& operator-=(T d)
		{
			return (this = this - d);
		}

		MatrixAxB<T, A, B>& operator-=(MatrixAxB<T, A, B> const& v)
		{
			return (this = this - v);
		}

		MatrixAxB<T, A, B>& operator+=(T d)
		{
			return (this = this + d);
		}

		MatrixAxB<T, A, B>& operator+=(MatrixAxB<T, A, B> const& v)
		{
			return (this = this + v);
		}

		MatrixAxB<T, A, B>& operator*=(T d)
		{
			return (this = this * d);
		}

		MatrixAxB<T, A, B>& operator*=(MatrixAxB<T, A, B> const& v)
		{
			return (this = this * v);
		}

		MatrixAxB<T, A, B>& operator/=(T d)
		{
			return (this = this / d);
		}

		MatrixAxB<T, A, B>& operator/=(MatrixAxB<T, A, B> const& v)
		{
			return (this = this / v);
		}
	};
};