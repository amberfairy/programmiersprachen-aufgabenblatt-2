#define CATCH_CONFIG_RUNNER
#define _USE_MATH_DEFINES
#include "circle.hpp"
#include "circle.hpp"
#include <cmath>
Circle::Circle(float const& newrad_, Vec2 const& newcenter_, Color const& newcolCir_) {
	rad_ = newrad_;
	center_ = newcenter_;
	colCir_ = newcolCir_;
}

float Circle::circumference(){
	return abs(2* M_PI * rad_);
}


/*
void Circle::Circle(Point2D const& cen, float rad, ColorRGB const& col) {
}
void Circle::radius(float rad) {		// unnötig?wichtig?keine ahnung?
	rad_ = rad;
}
*/