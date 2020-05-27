#define CATCH_CONFIG_RUNNER
#define _USE_MATH_DEFINES
#include "circle.hpp"
#include <cmath>
Circle::Circle(float const& newrad_, Vec2 const& newcenter_, Color const& newcolCir_) {
	rad_ = newrad_;
	center_ = newcenter_;
	colCir_ = newcolCir_;
}

float const Circle::circumference(){
	return abs(2* M_PI * rad_);
}
