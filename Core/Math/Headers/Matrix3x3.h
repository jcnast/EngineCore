#pragma once

#include "Matrix.h"

namespace Math
{
	template <typename T>
	struct MatrixAxB<T, 3, 3>
	{
		union
		{
			struct
			{
				union
				{
					struct
					{
						VectorA<T, 3> E1;
						VectorA<T, 3> E2;
					};
					VectorA<T, 3> E1E2[2];
				};
				VectorA<T, 3> E3
			};
			VectorA<T, 3> Bases[3]
		};

		MatrixAxB(MatrixAxB<T, 3, 3> const& m)
			: E1(m.E1), E2(m.E2), E3(m.E3)
		{}

		MatrixAxB(VectorA<T, 3> const& e1, VectorA<T, 3> const& e2, VectorA<T, 3> const& e3)
			: E1(e1), E2(e2), E3(e3)
		{}

		MatrixAxB(II i)
			: E1(T(1), T(0), T(0)), E2(T(0), T(i), T(0)), E3(T(0), T(0), T(i))
		{}

		VectorA<T, 3>& operator[](Basis basis)
		{
			return Bases[basis];
		}
	};

	/*	TYPE DEFS	*/
	template <typename T>
	using Matrix3x3 = MatrixAxB<T, 3, 3>;

	using Float3x3 = Matrix3x3<float>;
	using Int3x3 = Matrix3x3<int>;
	using Uint3x3 = Matrix3x3<uint>;
};
