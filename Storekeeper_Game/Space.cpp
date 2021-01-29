#include "Space.h"

Space::Space()
{
	rectangle_vertic_one = RectangleShape(Vector2f(12.f, 741.f));
	rectangle_vertic_two = RectangleShape(Vector2f(12.f, 741.f));
	rectangle_horiz_one = RectangleShape(Vector2f(1176.f, 12.f));
	//rectangle_cran = RectangleShape(Vector2f(1177.f, 30.f));
	//s_ground.setPosition(1177.f, 51.f);

	rectangle_vertic_one.move(0.f, 0.f);
	rectangle_vertic_two.move(1188.f, 0.f);
	rectangle_horiz_one.move(12.f, 0.f);
	s_cran.setPosition(12.f, 12.f);
	s_ground.setPosition(12.f, 690.f);
	s_hend_gud.setPosition(12.f, 60.f);

	rectangle_vertic_one.setFillColor(Color::Black);
	rectangle_vertic_two.setFillColor(Color::Black);
	rectangle_horiz_one.setFillColor(Color::Black);
}

RectangleShape Space::get_rectangle_vertic_one()
{
	return rectangle_vertic_one;
}

RectangleShape Space::get_rectangle_vertic_two()
{
	return rectangle_vertic_two;
}

RectangleShape Space::get_rectangle_horiz_one()
{
	return rectangle_horiz_one;
}

Sprite& Space::get_s_ground()
{
	return s_ground;
}

void Space::set_t_ground(Texture* texture)
{
	s_ground.setTexture(*texture);
}

Texture& Space::get_t_ground()
{
	return t_ground;
}

Sprite& Space::get_s_cran()
{
	return s_cran;
}

void Space::set_t_cran(Texture* texture)
{
	s_cran.setTexture(*texture);
}

Sprite& Space::get_s_hend_gud()
{
	return s_hend_gud;
}

void Space::set_t_hend_gud(Texture* texture)
{
	s_hend_gud.setTexture(*texture);
}




