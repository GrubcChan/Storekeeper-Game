#include "Boxes_all.h"

Boxes_all::Boxes_all()
{
	boxes = std::vector<std::vector<Box>>(12, std::vector<Box>(5));
}

void Boxes_all::push_box(const Box& new_box, const int index_i,const int index_j)
{
	boxes[index_i][index_j] = new_box;

}

std::vector<Box>& Boxes_all::get_index_box_line(const int index)
{
	return boxes[index];
}

Box& Boxes_all::get_box(const int index_line, const int index_cor)
{
	return get_index_box_line(index_line)[index_cor];
}

int Boxes_all::get_cotd_pusk(const int index)
{
	return cotd_pusk[index];
}

void Boxes_all::check_stop(const int index_i,const int index_j, std::vector<int>& count)
{
	for (size_t i = 0; i < 12; ++i) {
		for (size_t j = 0; j < count[i]; ++j)
			if (get_box(index_i, index_j).get_cor_y() == get_box(i, j).get_cor_y() - 96) {
				if (get_box(index_i, index_j).get_cor_x() >= get_box(i, j).get_cor_x() - 96 &&
					get_box(index_i, index_j).get_cor_x() <= get_box(i, j).get_cor_x() + 96) {

					get_box(index_i, index_j).set_finish(true);
					//boxes[index_i][index_j].set_in_the_space(true);
				}
			}
	}
}

bool Boxes_all::mov_tic_timer(float& time, int index_i, int index_j, std::vector<int>& count)
{
	if (get_box(index_i, index_j).get_cor_x() < get_cotd_pusk(index_i)) {
		get_box(index_i, index_j).move_box_right();
	}
	else {
		if (time > delay)
					{
			boxes[index_i][ index_j].move_box_down();
			time = 0;
		}
	}
	check_stop(index_i, index_j, count);
	return check_line_all(index_i, index_j, count);
}

bool Boxes_all::check_line_all(const int index_i, int index_j, std::vector<int>& count)
{
	int i = 0;
	for (; i < 12; ++i) {
		

		if (boxes[i][0].get_finish() && count[i] != 0) {
			
			continue;
			
		}
		else break;
	}
	if (i == 12) {
		return deleat_line(index_i, index_j, count);
	}
	else return false;
}

bool Boxes_all::deleat_line(int index_i, int index_j, std::vector<int>& count)
{
	for (int i = 0; i < 12; ++i) {
		//boxes[i].erase(boxes[i].begin() + 0);
		int j = 0;
		count[i]--;
		for (; j < count[i]-1; ++j) {
			boxes[i][j] = boxes[i][j + 1];
			boxes[i][j].set_cor_y_del_line(boxes[i][j].get_cor_y() + 96);
		}
	}
	return true;
}

