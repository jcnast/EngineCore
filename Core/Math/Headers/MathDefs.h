#include <cmath>

namespace Math
{
	template <typename int D>
	struct Dimension { operator int() { return D; } };
	using R1 = Dimension<1>;
	using R2 = Dimension<2>;
	using R3 = Dimension<3>;
	using R4 = Dimension<4>;

	template <typename int A>
	struct Axis { operator int() { return A; } };
	using X = Axis<0>;
	using Y = Axis<1>;
	using Z = Axis<2>;
	using W = Axis<3>;

	template <typename int B>
	struct Basis { operator int() { return B; } };
	using E1 = Basis<0>;
	using E2 = Basis<1>;
	using E3 = Basis<2>;
	using E4 = Basis<3>;

	struct II { operator int() { return 1; } };

	const double PI_D = 3.1415926535897;
	const float PI_F = 3.1415927f;
	const int PI_I = 3;
};