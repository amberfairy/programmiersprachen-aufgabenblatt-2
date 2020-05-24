#include "mat2.hpp"

Mat2& Mat2::operator*=(Mat2 const& m) {
	float var00 = e_00 * m.e_00 + e_01 * m.e_10;
	float var01 = e_00 * m.e_01 + e_01 * m.e_11;
	float var10 = e_10 * m.e_00 + e_11 * m.e_10;
	float var11 = e_10 * m.e_01 + e_11 * m.e_11;
	e_00 = var00; e_01 = var01; e_10 = var10;  e_11 = var11;
	return *this;
}
Mat2 operator*(Mat2 const& m1, Mat2 const& m2) {
	return Mat2({ m1.e_00 * m2.e_00 + m1.e_01 * m2.e_10, m1.e_00 * m2.e_01 + m1.e_01 * m2.e_11,
				  m1.e_10 * m2.e_00 + m1.e_11 * m2.e_10, m1.e_10 * m2.e_01 + m1.e_11 * m2.e_11 });
}
