#pragma once

#include "Vector.h"

namespace Math
{
	template <typename T>
	struct VectorA<T, 2>
	{
		union
		{
			struct
			{
				T X;
				T Y;
			};
			T Axes[2];
		};

		VectorA(T d = 0)
			: X(d), Y(d)
		{}

		VectorA(T x, T y)
			: X(x), Y(y)
		{}

		VectorA(VectorA<T, 2> const& v)
			: X(v.X), Y(v.Y)
		{}

		T Dot(VectorA<T, 2> const& v)
		{
			auto temp = v;
			temp * (*this);

			return (temp.X + temp.Y);
		}

		VectorA<T, 2>& operator-(VectorA<T, 2> const& v)
		{
			X -= v.X;
			Y -= v.Y;

			return *this;
		}

		VectorA<T, 2>& operator+(VectorA<T, 2> const& v)
		{
			X += v.X;
			Y += v.Y;

			return *this;
		}

		VectorA<T, 2>& operator*(T d)
		{
			X *= d;
			Y *= d;

			return *this;
		}

		VectorA<T, 2>& operator*(VectorA<T, 2> const& v)
		{
			X *= v.X;
			Y *= v.Y;

			return *this;
		}

		VectorA<T, 2>& operator/(T d)
		{
			X /= d;
			Y /= d;

			return *this;
		}

		VectorA<T, 2>& operator/(VectorA<T, 2> const& v)
		{
			X /= v.X;
			Y /= v.Y;

			return *this;
		}

		VectorA<T, 2>& operator=(T d)
		{
			X = d;
			Y = d;

			return *this;
		}

		VectorA<T, 2>& operator=(VectorA<T, 2> const& v)
		{
			X = v.X;
			Y = v.Y;

			return *this;
		}

		bool operator==(VectorA<T, 2> const& v)
		{
			return (X == v.X && Y == v.Y);
		}

		T& operator[](int axis)
		{
			return Axes[axis];
		}
	};

/*	TYPE DEFS	*/
	template <typename T>
	using Vector2 = VectorA<T, 2>;

	using Float2 = Vector2<float>;
	using Int2 = Vector2<int>;
	using Uint2 = Vector2<uint>;
};