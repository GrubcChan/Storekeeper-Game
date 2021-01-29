#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class Space
{
private:
	// Рамка
	RectangleShape rectangle_vertic_one;
	RectangleShape rectangle_vertic_two;
	RectangleShape rectangle_horiz_one;
	// Кран
	Sprite s_hend_gud;
	int cor_x = 12, cor_y = 60;
	Sprite s_cran;
	Texture t_cran;
	// Земля
	Sprite s_ground;
	Texture t_ground;
public:
	Space();
	RectangleShape get_rectangle_vertic_one();
	RectangleShape get_rectangle_vertic_two();
	RectangleShape get_rectangle_horiz_one();
	Sprite& get_s_ground();
	void set_t_ground(Texture* texture);
	Texture& get_t_ground();
	Sprite& get_s_cran();
	void set_t_cran(Texture* texture);
	Sprite& get_s_hend_gud();
	void set_t_hend_gud(Texture* texture);
	void move_hend_right()
	{
		s_hend_gud.setPosition((float)(cor_x++ % 1090),(float)cor_y);
	}
	void move_hend_rev()
	{
		cor_x = 12;
		s_hend_gud.setPosition((float)cor_x, (float)cor_y);
	}
};

