#pragma once

#include "Matrix.h"

namespace Math
{
	template <typename T>
	struct MatrixAxB<T, 2, 2>
	{
		union
		{
			struct
			{
				VectorA<T, 2> E1;
				VectorA<T, 2> E2;
			};
			VectorA<T, 2> Bases[2];
		};

		MatrixAxB(MatrixAxB<T, 2, 2> const& m)
			: E1(m.E1), E2(m.E2)
		{}

		MatrixAxB(VectorA<T, 2> const& e1, VectorA<T, 2> const& e2)
			: E1(e1), E2(e2)
		{}

		Matrix2x2(II i)
			: E1(T(i), T(0)), E2(T(0), T(i))
		{}

		VectorA<T, 2>& operator[](Basis basis)
		{
			return Bases[basis];
		}
	};

/*	TYPE DEFS	*/
	template <typename T>
	using Matrix2x2 = MatrixAxB<T, 2, 2>;

	using Float2x2 = Matrix2x2<float>;
	using Int2x2 = Matrix2x2<int>;
	using Uint2x2 = Matrix2x2<uint>;
};