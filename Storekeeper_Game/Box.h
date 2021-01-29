#pragma once
#include <SFML/Graphics.hpp>
#include "ResourceHolder.h"

using namespace sf;
class Box
{
private:
	Texture texture;
	Sprite sprite;
	double edge;
	int cor_x;
	int cor_y;
	int cord_x_pusk;
	bool finish = false;
	bool in_the_space = false;
public:
	Box();
	Box(int pusk, const Texture* texture);
	void move_box_down();
	void move_box_right();
	void move_box_left();
	bool check();

	Sprite* get_box();
	Texture get_Texture();

	bool get_in_the_space();
	void set_in_the_space(bool b);
	int get_cord_x_pusk();
	void set_cord_x_pusk(int pusk);
	void setTexture(Texture* tex);
	bool get_finish();
	void set_cor_y_del_line(const int c_cor_y);
	void set_finish(const bool b);
	void set_edge(const double c_edge);
	double get_edge();
	void set_cor_x(const int c_cor_x);
	int get_cor_x();
	void set_cor_y(const int c_cor_y);
	int get_cor_y();
};

