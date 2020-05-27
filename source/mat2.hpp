#ifndef MAT2_HPP
#define MAT2_HPP
#include "vec2.hpp"
#include <array>
						//2.5
struct Mat2 {
	// e_00  e_10
	// e_10  e_11
	float e_00 = 1.0f;
	float e_01 = 0.0f;
	float e_10 = 0.0f;
	float e_11 = 1.0f;

	float det() const;

	Mat2& operator*=(Mat2 const& m);
};

Mat2 operator*(Mat2 const& m1, Mat2 const& m2);
Mat2 operator*(float s, Mat2 const& m);

						//2.6
Vec2 operator*(Mat2 const& m, Vec2 const& v);

Mat2 inverse(Mat2 const& m);
Mat2 transpose(Mat2 const& m);
Mat2 make_rotation_mat2(float phi);

#endif // MAT2_HPP