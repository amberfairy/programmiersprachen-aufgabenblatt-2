#include "mat2.hpp"
#include "vec2.hpp"
#include <iostream>

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
///*
Vec2 operator*(Mat2 const& m, Vec2 const& v){
	return Vec2({ m.e_00 * v.x + m.e_01 * v.y , m.e_10 * v.x + m.e_11 * v.y });
}
//*/
Mat2 operator*(float s, Mat2 const& m){
	return Mat2({ s * m.e_00 , s * m.e_01 , s * m.e_10 , s * m.e_11 });
}

float Mat2::det() const{
	return e_00 * e_11 - e_10 * e_01;
}

Mat2 inverse(Mat2 const& m){
	if (m.det() == 0) {
		std::cout << "Die Inverse kann nur bestimmt werde, wenn die Determinante != 0 ist!";
		return Mat2(m);
	}
	else {
		return Mat2(1 / (m.det())* Mat2({ m.e_11, -m.e_01, -m.e_10, m.e_00 }));
	}
}

Mat2 transpose(Mat2 const& m){
	return Mat2({ m.e_00 , m.e_10 , m.e_01 , m.e_11 });
}

Mat2 make_rotation_mat2(float phi){
	return Mat2();
}
