
#pragma once
#include<iostream>
using namespace std;
#include"Controls.h"
#include"Cellule.h"
#include"Gun.h"
#include<SFML/Audio.hpp>
#include"Screen.h"

class Logic : virtual public Screen, virtual public Gun {
protected:

	int screen_width = 737;
	int screen_height = 737;

	int col_length = 67;
	int row_height = 67;

	
	Gun gun;
	// define all keys  forvarious events
	Key backspace = Key(sf::Keyboard::R);
	Key modeAKey = Key(sf::Keyboard::A);
	Key modeSKey = Key(sf::Keyboard::S);
	Key modeDKey = Key(sf::Keyboard::D);
	Key modeFKey = Key(sf::Keyboard::F);
	Key modeGKey = Key(sf::Keyboard::G);
	Key modeHKey = Key(sf::Keyboard::H);
	Key modeJKey = Key(sf::Keyboard::J);
	Key upKey = Key(sf::Keyboard::Up);
	Key downKey = Key(sf::Keyboard::Down);
	Key leftKey = Key(sf::Keyboard::Left);
	Key rightKey = Key(sf::Keyboard::Right);
	Key fireRight = Key(sf::Keyboard::X);
	Key fireLeft = Key(sf::Keyboard::Z);


	// Mouse class made, enum Left
	Mouse rightMouseButton = Mouse(sf::Mouse::Right);
	Mouse leftMouseButton = Mouse(sf::Mouse::Left);

	// store kepresses
	Key keypress_clear = Key(sf::Keyboard::BackSpace);


	// generate_cell the main window
	sf::RenderWindow window;
	sf::Event event;
	sf::Clock clock;
	sf::Text text;
	sf::Font font;
	sf::CircleShape circle;



	// create 68 x 68 cells array
	Cellule cells[68][68];


	// draw the tiles
	void print_board();

	// display everything
	void render_all();

	// these three functions control the blip
	void generate_bullet_left(int, int);
	void generate_bullet_right(int, int);

	// load the window and text
	void load_visual_elements();
	void load_text();
	void move_gun(int, int);

	// apply game rules
	// find next frame setup
	void predict_next();

	// look for inputs
	void check_events();
	
	//
	void activate_cell();

	//draw the cells
	void render_cells();

	};

