#pragma once

#include "Matrix.h"

namespace Math
{
	template <typename T>
	struct MatrixAxB<T, 4, 4>
	{
		union
		{
			struct
			{
				union
				{
					struct
					{
						union
						{
							struct
							{
								VectorA<T, 4> E1;
								VectorA<T, 4> E2;
							};
							VectorA<T, 4> E1E2[2];
						};
						VectorA<T, 4> E3
					};
					VectorA<T, 4> E1E2E3[3]
				};
				VectorA<T, 4> E4;
			};
			VectorA<T, 4> Bases[4];
		};

		MatrixAxB(MatrixAxB<T, 4, 4> const& m)
			: E1(m.E1), E2(m.E2), E3(m.E3), E4(m.E4)
		{}

		MatrixAxB(VectorA<T, 4> const& e1, VectorA<T, 4> const& e2, VectorA<T, 4> const& e3, VectorA<T, 4> const& e4)
			: E1(e1), E2(e2), E3(e3), E4(e4)
		{}

		MatrixAxB(II i)
			: E1(T(i), T(0), T(0), T(0)), E2(T(0), T(i), T(0), T(0)), E3(T(0), T(0), T(i), T(0)), E4(T(0), T(0), T(0), T(i))
		{}

		VectorA<T, 4>& operator[](Basis basis)
		{
			return Bases[basis];
		}
	};

	/*	TYPE DEFS	*/
	template <typename T>
	using Matrix4x4 = MatrixAxB<T, 4, 4>;

	using Float4x4 = Matrix4x4<float>;
	using Int4x4 = Matrix4x4<int>;
	using Uint4x4 = Matrix4x4<uint>;
};
