#ifndef RECT_HPP
#define RECT_HPP
#include "mat2.hpp"
#include "vec2.hpp"
#include "color.hpp"

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
		//was weiß ich... das haben wir noch nie gemacht. ich kann das alles eh nicht..
	}




	float const circumference();

	//get/set nicht machen! unnötig? was für konstruktoren sollte man denn machen? bereits kreis/rect erstellen? ich will nicht mehr...
};
#endif