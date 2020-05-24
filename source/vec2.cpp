#include "vec2.hpp"
#include <iostream>

Vec2& Vec2::operator+=(Vec2 const& v) {
	x += v.x; y += v.y;
	return *this;
}
Vec2& Vec2::operator-=(Vec2 const& v) {
	x -= v.x; y -= v.y;
	return *this;
}
Vec2& Vec2::operator*=(float s){
	x *= s; y *= s;
	return *this;
}
Vec2& Vec2::operator/=(float s) {
	if (s == 0) {
		std::cout << "Der Divisor darf nicht Null sein! (Aufg 2.3)\n";
		return *this;
	}
	else {
		x /= s; y /= s;
		return *this;
	}
}
Vec2 operator+(Vec2 const& u, Vec2 const& v) {
	return Vec2(u) += Vec2(v);
}
Vec2 operator-(Vec2 const& u, Vec2 const& v) {
	return Vec2(u) -= Vec2(v);
}
Vec2 operator*(Vec2 const& v, float s) {
	return Vec2(v) *= s;
}
Vec2 operator/(Vec2 const& v, float s) {
	if (s == 0) {
		std::cout << "Der Divisor darf nicht 0 sein! (Aufg 2.4)\n";
		return Vec2(v);
	}
	else {
		return Vec2(v) /= s;
	}
}
Vec2 operator*(float s, Vec2 const& v) {;
return Vec2({ s*v.x,s*v.y});
}
