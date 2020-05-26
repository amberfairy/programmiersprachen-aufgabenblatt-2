#ifndef CIRCLE_HPP //#TODO irgendwie nicht verzweifeln :) oder so...
#define CIRCLE_HPP
#include "vec2.hpp"
#include "color.hpp"
#include "mat2.hpp"		

class Circle {
private:
	float rad_ = 1.0f;
	Vec2 center_ = { 0.0f , 0.0f };
	Color colCir_ = { 0.0f , 1.0f , 0.0f };;

public:
	//...so irgendwie?
	Circle(float const& newrad_, Vec2 const& newcenter_, Color const& newcolCir_);

	float circumference();



	/*
	float radius()const;				//???????????? sind das unnötige getter/setter? oder nicht
	void center(Vec2 const& ctr);		//??????????? notwenig? und heh? weh? meh? fml...
	void color(Color const& col);		//??????????????
	*/
};

#endif