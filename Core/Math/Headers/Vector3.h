#pragma once

#include "Vector.h"

namespace Math
{
	template <typename T>
	struct VectorA<T, 3>
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
			T Axes[3];
		};

		VectorA(T d = 0)
			: X(d), Y(d), Z(d)
		{}

		VectorA(T x, T y, T z)
			:X(x), Y(y), Z(z)
		{}

		VectorA(VectorA<T, 3> const& v)
			: X(v.X), Y(v.Y), Z(v.Z)
		{}

		T Dot(VectorA<T, 3> const& v)
		{
			auto temp = v;
			temp * (*this);

			return (temp.X + temp.Y + temp.X);
		}

		VectorA<T, 3>& operator-(VectorA<T, 3> const& v)
		{
			X -= v.X;
			Y -= v.Y;
			Z -= v.Z;

			return *this;
		}

		VectorA<T, 3>& operator+(VectorA<T, 3> const& v)
		{
			X += v.X;
			Y += v.Y;
			Z += v.Z;

			return *this;
		}

		VectorA<T, 3>& operator*(T d)
		{
			X *= d;
			Y *= d;
			Z *= d;

			return *this;
		}

		VectorA<T, 3>& operator*(VectorA<T, 3> const& v)
		{
			X *= v.X;
			Y *= v.Y;
			Z *= v.Z;

			return *this;
		}

		VectorA<T, 3>& operator/(T d)
		{
			X /= d;
			Y /= d;
			Z /= d;

			return *this;
		}

		VectorA<T, 3>& operator/(VectorA<T, 3> const& v)
		{
			X /= v.X;
			Y /= v.Y;
			Z /= v.Z;

			return *this;
		}

		VectorA<T, 3>& operator=(T d)
		{
			X = d;
			Y = d;
			Z = d;

			return *this;
		}

		VectorA<T, 3>& operator=(VectorA<T, 3> const& v)
		{
			X = v.X;
			Y = v.Y;
			Z = v.Z;

			return *this;
		}

		bool operator==(VectorA<T, 3> const& v)
		{
			return (X == v.X && Y == v.Y && Z == v.Z);
		}

		T& operator[](int axis)
		{
			return Axes[axis];
		}
	};

/*	TYPE DEFS	*/
	template <typename T>
	using Vector3 = VectorA<T, 3>;

	using Float3 = Vector3<float>;
	using Int3 = Vector3<int>;
	using Uint3 = Vector3<uint>;
};
