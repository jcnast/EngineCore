#pragma once

#include "Matrix.h"


// Invert
/*
MatrixXxX<T, vT, V> Invert()
{

}
*/

// Determinant
/*
T Determinant()
{
T det = 0;

if (Matrix.Dimensions() == 2)
{
det = (Matrix[0][0] * Matrix[1][1]) - (Matrix[1][0] * Matrix[0][1]);
}
else
{
for (int i = 0; i < Matrix.Dimensions(); i++)
{
det += Matrix[0][i] * SubMatrix(1, Matrix.Dimensions());
}
}
}
*/
// left multiply (for vectors too)

// right multiply (for vectors too)

// Multiply vectors (return matrix)