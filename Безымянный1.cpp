// TASK 11

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct image {
	int mx;
	int my;
	int* points;

	void showimage() {
		for (int i = 0; i < my; i++) {
			for (int j = 0; j < mx; j++) {
				cout << points[(i * mx) + j];
			}
			cout << endl;
		}
	}

	void createlmage(int tmx, int tmy) {
		mx = tmx;
		my = tmy;
		points = new int[tmy * tmx];
		for (int i = 0; i < tmy * tmx; i++) {
			points[i] = 1;
		}
	}



	void setPointImage(int x, int y, int color) {
		points[(y - 1) * mx + x - 1] = color;
	}

	void getPointImage(int x, int y) {
		points[(y - 1) * my + x - 1];
	}

	void saveToPnmFile(const string filename)
	{
		fstream out;
		out.open(filename, fstream::out);
		out << "P1" << endl;
		out << mx << " " << my << endl;

		for (int i = 0; i < mx; i++)
		{
			for (int j = 0; j < my; j++)
			{
				out << points[i * my + j] << " ";
			}
			out << endl;
		}

		out.close();
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	image img;
	int mx, my, x, y, color;
	cout << "??????? ?????? ???????? ?? x: ";
	cin >> mx;
	cout << "??????? ?????? ???????? ?? y: ";
	cin >> my;
	img.createlmage(mx, my);
	img.showimage();
	cout << "??????? ?????????? ????? ?? x ? ?? y, ??????? ?????? ????????: " << endl;
	cin >> x;
	cin >> y;
	cout << "??????? ??? ????? ??????????? ?????: ";
	cin >> color;
	img.setPointImage(x, y, color);
	img.showimage();
	img.saveToPnmFile("fount");
}

// TASK 12

#include <SFML/Graphics.hpp>

using namespace sf;


int main()
{
	RenderWindow window(VideoMode(400, 400), "12");
	RectangleShape pr;
	pr.setSize(Vector2f(20, 30));
	pr.setFillColor(Color::Green);
	pr.setPosition(0, 0);
	int i = 20;
	int k = 0;
	bool m = 1;
	while (window.isOpen())
	{
		Event ev;
		while (window.pollEvent(ev))
		{
			if (ev.type == Event::Closed)
				window.close();

			if (ev.type == Event::MouseButtonPressed) {
				k = 1;
			}

			else if (ev.key.code == Mouse::Right)
				k = 0;
		}
		window.clear(Color::White);
		if (k == 1) {
			if (i == 200) m = 0;
			if (i == 20) m = 1;
			if (m == 1) i = i + 10;
			if (m == 0) i = i - 10;
			pr.setSize(Vector2f(20, i));
		}
		window.draw(pr);
		sleep(sf::milliseconds(50));
		window.display();
	}

	return 0;
}
