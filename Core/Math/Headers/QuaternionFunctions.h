#pragma once

#include "Quaternion.h"

#include "Vector3.h"

#include "../../Debugging/Headers/Declarations.h"

namespace Math
{
	// from rotation matrix
	/*
	Quaternion(Matrix3x3<T> m)
	{

	}
	*/

	// get rotation matrix

	// rotate vector
	template <typename T>
	Vector3<T> RotateVectorBy(Vector3<T> const& v, Quaternion<T> const& q)
	{
		// conjugate of q
		auto qC = q.Inverse();
		qC *= v;
		qC *= q;

		// at this point qC.W == 0
		VERIFY(Within(qC.W, T(0.0f), T(0.001f)));
		return Vector3<T>(qC.X, qC.Y, qC.Z);
	}

	// several rotations (applied first to last)
	template <typename T, typename Ts...>
	Vector3<T> RotateVectorBy(Vector3<T> const& v, Quaternion<T> const& firstQ, Ts ... restQs)
	{
		auto rotatedVector = RotateVectorBy(v, firstQ);
		return RotateVectorBy(rotatedVector, restQs...);
	}

	// undo rotation
	template <typename T>
	Vector3<T> UndoRotationBy(Vector3<T> const& v, Quaternion<T> const& q)
	{
		return RotateVectorBy(v, q.Inverse());
	}

	// undo several rotations (applied first to last)
	// NOTE: order of RotateVectorBy needs to be opposite this on to undo applied rotations
	template <typename T, typename Ts...>
	Vector3<T> UndoRotationBy(Vector3<T> const& v, Quaternion<T> const& firstQ, Ts ... restQs)
	{
		auto rotatedVector = UndoRotationBy(v, firstQ);
		return UndoRotationBy(rotatedVector, restQs...);
	}

#if DEBUG
	template <typename T>
	String QuaternionString(Quaternion<T> const& q)
	{
		String quaternionInfo;

		quaternionInfo += "(";
		for (auto i = 0; i < 4; i++)
		{
			quaternionInfo += q[i];

			if (i != 3)
			{
				quaternionInfo += ", ";
			}
		}
		quaternionInfo += ")";

		return quaternionInfo;
	}
#endif
};