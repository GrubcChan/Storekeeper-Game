#pragma once
#include "Box.h"
#include "vector"
#include "Space.h"
using namespace sf;

class Boxes_all
{
private:
	std::vector<std::vector<Box>> boxes;
	std::vector<int> cotd_pusk = { 12,110, 208, 306,404,502,600,698,796,894,992,1090 };
	float delay = 0.0000001;
public:
	Boxes_all();
	void push_box(const Box& new_box, const int index, const int index_j);
	std::vector<Box>& get_index_box_line(const int index);
	Box& get_box(const int index_line, const int index_cor);
	int get_cotd_pusk(const int index);
	void check_stop(const int index_i, const int index_j, std::vector<int>& count);
	bool mov_tic_timer(float& time, int index_i, int index_j,std::vector<int>& count);
	bool check_line_all(const int index_i, int index_j, std::vector<int>& count);
	bool deleat_line(int index_i, int index_j,std::vector<int>& count);
};

