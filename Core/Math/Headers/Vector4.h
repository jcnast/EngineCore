#pragma once

#include "Vector.h"

namespace Math
{
	template <typename T>
	struct VectorA<T, 4>
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
								T X;
								T Y;
							};
							VectorA<T, 2> XY[2];
						};
						T Z;
					};
					VectorA<T, 3> XYZ[3];
				};
				T W;
			};
			T Axes[4];
		};

		VectorA(T d = 0)
			: X(d), Y(d), Z(d), W(d)
		{}

		VectorA(T x, T y, T z, T w)
			: X(x), Y(y), Z(z), W(w)
		{}

		VectorA(VectorA<T, 4>& v)
			: X(v.X), Y(v.Y), Z(v.Z), W(v.W)
		{}

		T Dot(VectorA<T, 4> const& v)
		{
			auto temp = v;
			temp * (*this);

			return (temp.X + temp.Y + temp.Z + temp.W);
		}

		VectorA<T, 4>& operator-(VectorA<T, 4> const& v)
		{
			X -= v.X;
			Y -= v.Y;
			Z -= v.Z;
			W -= v.W;

			return *this;
		}

		VectorA<T, 4>& operator+(VectorA<T, 4> const& v)
		{
			X += v.X;
			Y += v.Y;
			Z += v.Z;
			W += v.W;

			return *this;
		}

		VectorA<T, 4>& operator*(T d)
		{
			X *= d;
			Y *= d;
			Z *= d;
			W *= d;

			return *this;
		}

		VectorA<T, 4>& operator*(VectorA<T, 4> const& v)
		{
			X *= v.X;
			Y *= v.Y;
			Z *= v.Z;
			W *= v.W;

			return *this;
		}

		VectorA<T, 4>& operator/(T d)
		{
			X /= d;
			Y /= d;
			Z /= d;
			W /= d;

			return *this;
		}

		VectorA<T, 4>& operator/(VectorA<T, 4> const& v)
		{
			X /= v.X;
			Y /= v.Y;
			Z /= v.Z;
			W /= v.W;

			return *this;
		}

		VectorA<T, 4>& operator=(T d)
		{
			X = d;
			Y = d;
			Z = d;
			W = d;

			return *this;
		}

		VectorA<T, 4>& operator=(VectorA<T, 4> const& v)
		{
			X = v.X;
			Y = v.Y;
			Z = v.Z;
			W = v.W;

			return *this;
		}

		bool operator==(VectorA<T, 4> const& v)
		{
			return (X == v.X && Y == v.Y && Z == v.Z && W == v.W);
		}

		T& operator[](int axis)
		{
			return Axes[axis];
		}
	};

/*	TYPE DEFS	*/
	template <typename T>
	using Vector4 = VectorA<T, 4>;

	using Float4 = Vector4<float>;
	using Int4 = Vector4<int>;
	using Uint4 = Vector4<uint>;
};
