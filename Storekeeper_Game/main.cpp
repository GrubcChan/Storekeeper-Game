#include <SFML/Graphics.hpp>
#include "Space.h"
#include "Box.h"
#include "vector"
#include "time.h"
#include "ResourceHolder.h"
#include "Boxes_all.h"
using namespace sf;

int main()
{
	auto getGlobalTextureHolder = getGlobalResourceHolder<sf::Texture, std::string>;

	//�������������:
	sf::Texture* BoxTexture = getGlobalTextureHolder().loadFromFile("C:\\Users\\grubo\\source\\repos\\Storekeeper_Game\\Debug\\Box2.png","box");
	sf::Texture* GroundTexture = getGlobalTextureHolder().loadFromFile("C:\\Users\\grubo\\source\\repos\\Storekeeper_Game\\Debug\\grage2.png", "ground");
	sf::Texture* CranTexture = getGlobalTextureHolder().loadFromFile("C:\\Users\\grubo\\source\\repos\\Storekeeper_Game\\Debug\\Cran2.png", "�ran");
	sf::Texture* HendGadTexture = getGlobalTextureHolder().loadFromFile("C:\\Users\\grubo\\source\\repos\\Storekeeper_Game\\Debug\\hendGad2.png", "hend");
	if (BoxTexture == nullptr) {
		//������ ��� ��������, ���� ���-�� ������
	}
	//���� ������ ���, �� ����� �������� � tankTexture.
	srand(time(0));

	// ������, �������, ����������, �������� ������� ����� ����������
	RenderWindow window(VideoMode(1200, 741), "Storekeeper Game");
	Space space;
	GroundTexture = getGlobalTextureHolder().getResource("ground");
	CranTexture = getGlobalTextureHolder().getResource("�ran");
	HendGadTexture = getGlobalTextureHolder().getResource("hend");
	space.set_t_ground(GroundTexture);
	space.set_t_cran(CranTexture);
	space.set_t_hend_gud(HendGadTexture);
	Boxes_all boxes;
	// ���������� ��� ������� � ��������
	float timer = 0, delay = 0.01, delay_pusk = 5.5;
	int timer_2 = 0;
	// ���� (������)
	Clock clock;
	int dx = 0;
	bool deleat_line = false;
	// ������� ���� ����������. �����������, ���� ������� ����
	//int pusk = rand() % 12;
	BoxTexture = getGlobalTextureHolder().getResource("box");
	if (BoxTexture == nullptr) {
		//������, ��������, �������� �� ���������.
	}
	int pusk = rand() % 12;
	Box box(boxes.get_cotd_pusk(pusk), BoxTexture);
	std::vector<int> count = {0,0,0,0,0,0,0,0,0,0,0,0};
	boxes.push_box(box, pusk, count[pusk]++);
	while (window.isOpen())
	{

		// �������� �����, ��������� � ������ �������, � ������������ ��� � �������
		float time = clock.getElapsedTime().asSeconds();
		clock.restart();
		timer += time;
		//timer_2 += time;
		// ������������ ������� ������� � �����
		Event event;
		while (window.pollEvent(event))
		{
			// ������������ ����� �� �������� � ����� ������� ����?
			if (event.type == Event::Closed)
				// ����� ��������� ���
				window.close();
			// ���� �� ������ ������� �� ����������?
			if (event.type == Event::KeyPressed)
				// ��� ������ � ������� �����?
				// if (event.key.code == Keyboard::Up) rotate = true;
				// ��� ����� ������� �����?
			if (event.key.code == Keyboard::Left) dx = -4;
			// ��� ������� ������?
			else if (event.key.code == Keyboard::Right) dx = 8;
		}
		if (deleat_line) {

			while (true) {
				pusk = rand() % 12;
				if (count[pusk] <= 4)break;
				int i = 0;
				for (; i < 12; ++i) {
					if (count[i] <= 4) break;
				}
				if (i == 11)break;

			}

			box.set_cord_x_pusk(boxes.get_cotd_pusk(pusk));
			boxes.push_box(box, pusk, count[pusk]++);
			deleat_line = false;

		}
		else {
			if (boxes.get_box(pusk, count[pusk] - 1).get_finish())
			{
				while (true) {
					pusk = rand() % 12;
					if (count[pusk] <= 4)break;
					int i = 0;
					for (; i < 12; ++i) {
						if (count[i] <= 4) break;
					}
					if (i == 11)break;

				}

				box.set_cord_x_pusk(boxes.get_cotd_pusk(pusk));
				boxes.push_box(box, pusk, count[pusk]++);
			}
		}

		deleat_line = boxes.mov_tic_timer(timer, pusk, count[pusk] - 1, count);
		
		dx = 0;
		// ������ ���� ����
		RectangleShape faon((Vector2f(1200.f, 741.f)));
		faon.move(0.f, 0.f);
		faon.setFillColor(Color(150,150,150,35));
		window.clear(Color(105,105,105,200));
		window.draw(space.get_rectangle_vertic_one());
		window.draw(space.get_rectangle_vertic_two());
		window.draw(space.get_rectangle_horiz_one());
		window.draw(space.get_s_cran());
		window.draw(space.get_s_ground());
		window.draw(space.get_s_hend_gud());
		Sprite sprite;
		if (!deleat_line) {
			sprite = *boxes.get_box(pusk, count[pusk] - 1).get_box();
			window.draw(sprite);
		}
			for (size_t i = 0; i < 12; ++i) {
				for (size_t j = 0; j < count[i]; ++j) {
					if (boxes.get_box(i, j).get_finish()) {
						//if (i == pusk && j == count[pusk] - 1) continue;
						sprite = *boxes.get_box(i, j).get_box();
						window.draw(sprite);
					}
				}
			}
			window.draw(faon);
		// ��������� ����	
		window.display();
	}

	return 0;
}