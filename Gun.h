#pragma once

// the gun is moved and shoots a rippler

class Gun {

private:
    // location in pixels
    int x_coordinate;
    int y_coordinate;
public:
    // constructor getter and setters
    Gun();
    void set_x(int);
    void set_y(int);
    int get_x();
    int get_y();

    };