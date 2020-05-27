#ifndef RECT_HPP
#define RECT_HPP
#include "color.hpp"
#include "mat2.hpp"
#include "vec2.hpp"


class Rect {
private:
	Vec2 min_ = { 0.0f , 0.0f }; //links unten
	Vec2 max_ = { 0.0f , 0.0f }; //rechts oben
	Color rgb_ = { 1.0f , 0.0f , 0.0f };

public:

	Rect::Rect(Vec2 const& newmin_ , Vec2 const& newmax_ , Color const& newrgb_){
		rgb_ = newrgb_;
		min_ = newmin_;
		max_ = newmax_;
	}

	float const circumference();         //const, da umfang eines dazugehörigen vierecks immer abhängig vom viereck selber ist
	                                     //außerdem elem. datentyp
	};
#endif