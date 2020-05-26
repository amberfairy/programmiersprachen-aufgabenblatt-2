#include "rect.hpp"

float const Rect::circumference() {
	float lena;
	float lenb;
	if (max_.x > min_.x) {
		lena = abs(max_.x - min_.x);
	}
	else {
		lena = abs(min_.x - max_.x);
	}
	if (max_.y - min_.x) {
		lenb = abs(max_.y - min_.y);
	}
	else {
		lenb = abs(min_.y - max_.y);
	}
	
	return 2 * lena + 2 * lenb;
}