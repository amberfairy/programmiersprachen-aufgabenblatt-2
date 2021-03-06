#ifndef VEC2_HPP
#define VEC2_HPP

//Vec2 data type def, Vec2 operator def
struct Vec2 {
	float x = 0.0f;						//2.2
	float y = 0.0f;

	Vec2& operator+=(Vec2 const& v);	// 2.3
	Vec2& operator-=(Vec2 const& v);
	Vec2& operator*=(float s);
	Vec2& operator/=(float s);
};

Vec2 operator+(Vec2 const& u, Vec2 const& v);		//2.4
Vec2 operator-(Vec2 const& u, Vec2 const& v);
Vec2 operator*(Vec2 const& v, float s);
Vec2 operator/(Vec2 const& v, float s);
Vec2 operator*(float s, Vec2 const& v);

#endif // VEC2_HPP