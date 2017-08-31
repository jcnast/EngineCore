#pragma once

#include "../../Headers/CoreDefs.h"
#include "MathDefs.h"

template <typename T>
struct Quaternion
{
	T W;
	T X;
	T Y;
	T Z;

	Quaternion(II i)
		: W(i), X(0), Y(0), Z(0)
	{}

	Quaternion(T w, T x, T y, T z)
		: W(w), X(x), Y(y), Z(z)
	{}

	Quaternion(Quaternion const& q)
		: W(q.W), X(q.X), Y(q.Y), Z(q.Z)
	{}

	// from euler angles
	Quaternion(T x, T y, T z)
	{
		T cosX = cos(x * 0.5f);
		T sinX = sin(x * 0.5f);

		T cosY = cos(y * 0.5f);
		T sinY = sin(y * 0.5f);

		T cosZ = cos(z * 0.5f);
		T sinZ = cos(z * 0.5f);

		W = (cosX * cosY * cosZ) + (sinX * sinY * sinZ);
		X = (cosX * sinY * cosZ) + (sinX * cosY * sinZ);
		Y = (sinY * cosY * cosZ) + (cosX * sinY * sinZ);
		Z = (cosX * cosY * sinZ) + (sinX * sinY * cosZ);
	}

	Quaternion(Quaternion<T> const& q)
		: W(q.W), X(q.X), Y(q.Y), Z(q.Z)
	{}

	T EulerAngle(Axis axis)
	{
		switch (axis)
		{
			case Axis::X:
			{
				T sinX = T(2) * (W * X + Y * Z);
				T cosX = T(1) - T(2) * (X * X + Y * Y);

				return atan2(sinX, cosX);
				break;
			}
			case Axis::Y:
			{
				T sinY = T(2) * (W * Y - X * Z);
				if (fabs(sinY) >= T(1))
				{
					return copysign(T(PI_F) / T(2), sinY);
				}
				else
				{
					return asin(sinY);
				}
				break;
			}
			case Axis::Z:
			{
				T sinZ = T(2) * (W *Z + X * Y);
				T cosZ = T(1) - T(2) * Y *Y +Z * Z);
				return atan2(sinZ, cosZ);

				break;
			}
			default:
				return T(0);
		}
	}

	// from rotation matrix
	/*
	Quaternion(Matrix3x3<T> m)
	{

	}
	*/
};