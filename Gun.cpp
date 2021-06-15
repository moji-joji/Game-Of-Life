#include"Gun.h"


// the getters and setters
int Gun::get_x() {
    return x_coordinate;
    }


int Gun::get_y() {
    return y_coordinate;
    }

// Check bounds and then update position
void Gun::set_x(int pos) {
    if (pos < 0)
        this->x_coordinate = 0;
    else if(pos > 725)
        this->x_coordinate = 725;
    else
    this->x_coordinate = pos;
    }
// Check bounds and then update position

void Gun::set_y(int pos) {
    if (pos < 0)
        this->y_coordinate = 0;
    else if(pos > 725)
        this->y_coordinate = 725;
    else
    this->y_coordinate = pos;
    }

// initially the gun is centeres on the board
Gun::Gun() {
    x_coordinate = 355;
    y_coordinate = 355;
    }