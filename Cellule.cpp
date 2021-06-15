#include "Cellule.h"


bool Cellule::check_alive() {
	return alive;
	}


void Cellule::generate_cell(float coordinate_x, float coordinate_y) {


	coord_x = coordinate_x;
	coord_y = coordinate_y;
	// assign the colors 
	if (alive)
		rect_shape.setFillColor(neon);
	else
		rect_shape.setFillColor(blk);


	// vector 2f is a class
	// mathematical vector with 2 coordinates
	// rectangle shape given 2 coordinates

	rect_shape = sf::RectangleShape(sf::Vector2f(11, 11));


	// default position is 0 0 
	// overwrite previous position
	rect_shape.setPosition(coordinate_x, coordinate_y);

	



	// the border of each cell is set 
	rect_shape.setOutlineThickness(1);
	if (alive) {
		rect_shape.setOutlineColor(neon);
		}
	else
		rect_shape.setOutlineColor(blk);
	}

// set the state to active
// give appropriate color
void Cellule::cell_status(bool status) {
	alive = status;

	if (alive) {
		// set color too active
		rect_shape.setFillColor(neon);

		}
	else
		// set color too inactive
		rect_shape.setFillColor(blk);
	}


