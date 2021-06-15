
#pragma once
#include<iostream>
using namespace std;
#include"Screen.h"
#include <SFML/Graphics.hpp>

// cirtual inheritance to overcome diamond problem
class Cellule : virtual public Screen {
protected:
	bool alive;
	
	float coord_x;
	float coord_y;
	// rect_shape is used to draw the cell
	sf::RectangleShape rect_shape;

	// define the cellule colors
	sf::Color neon = sf::Color(55, 55, 255);
	sf::Color blk = sf::Color(0, 0, 0);


	


public:

	// sell size defined
	// plan cells on the board using x y coordinates
	
	void generate_cell(float, float);

	// update status of the cell
	void cell_status(bool);



	// called when cell needs to be drawn
	sf::RectangleShape cellShape() {
		return rect_shape;
		}

	bool check_alive();
	bool intermediate_state = false;

	int alive_neighbours = 0;
	};

