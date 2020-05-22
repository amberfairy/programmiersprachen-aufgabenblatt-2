#include "vec2.hpp"

Vec2& Vec2::operator+=(Vec2 const& v) {
	return Vec2{ x + x,y + y };
}
Vec2& Vec2::operator-=(Vec2 const& v) {
	return Vec2{ x - x, y - y };
}
Vec2& Vec2::operator*=(float s){
	return Vec2{x * s, y * s};
}
Vec2& Vec2::operator/=(float s) {
	return Vec2{x / s, y / s};
}
