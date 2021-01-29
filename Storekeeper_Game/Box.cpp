#include "Box.h"


Box::Box()
{
	edge = 0;
	cor_x = 0;
	cor_y = 0;
	cord_x_pusk = 0;
}

Box::Box(int pusk, const Texture* texture)
{
	sprite.setTexture(*texture);
	edge = 98;
	cor_x = 12;
	cor_y = 140;
	cord_x_pusk = pusk;
	sprite.setPosition((float)cor_x, (float)cor_y);

}
void Box::move_box_down()
{
	if (check()) sprite.setPosition((float)cor_x, (float)cor_y++);
}
void Box::move_box_right()
{
	if (check()) sprite.setPosition((float)cor_x++, (float)cor_y);
}
void Box::move_box_left()
{
	if (check()) sprite.setPosition((float)cor_x--, (float)cor_y);
}
bool Box::check()
{
	if (cor_y > 592 || cor_x > 1090) {

		finish = true;
		return false;
	}
	else return true;
}

Sprite* Box::get_box() { return &sprite; }
Texture Box::get_Texture()
{
	return texture;
}
bool Box::get_in_the_space()
{
	return in_the_space;
}
void Box::set_in_the_space(bool b)
{
	in_the_space = b;
}
int Box::get_cord_x_pusk()
{
	return cord_x_pusk;
}
void Box::set_cord_x_pusk(int pusk)
{
	cord_x_pusk = pusk;

}
void Box::setTexture(Texture* tex)
{
	sprite.setTexture(*tex);
}
bool Box::get_finish()
{
	return finish;
}
void Box::set_finish(const bool b)
{
	finish = b;

}
void Box::set_edge(const double c_edge) { edge = c_edge; }
double Box::get_edge() { return edge; }
void Box::set_cor_x(const int c_cor_x) {
	if (c_cor_x < 1090 && c_cor_x >= 12) {
		cor_x = c_cor_x;
		sprite.setPosition((float)cor_x, (float)cor_y);
	}
}
int Box::get_cor_x() { return cor_x; }
void Box::set_cor_y(const int c_cor_y) { 
	if (c_cor_y < 592 && c_cor_y >= 12) {
		cor_y = c_cor_y;
		sprite.setPosition((float)cor_x, (float)cor_y);
	}
}
int Box::get_cor_y() { return cor_y; }
void Box::set_cor_y_del_line(const int c_cor_y) {
	
		cor_y = c_cor_y;
		sprite.setPosition((float)cor_x, (float)cor_y);
}