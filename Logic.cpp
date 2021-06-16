#include"Logic.h"
#include"Gun.h" 

void Logic::render_all() {
	// background color after first initialization
	// clear garbage
	window.clear(sf::Color(0, 0, 0));

	
	circle.setPosition((float)gun.get_x(), (float)gun.get_y());

	

	if (!paused) {
		predict_next();

		}

	

	check_events();

	render_cells();


	//window.display();


	}

// weighted randomness
// randomly generate cells 
void Logic::print_board() {
	// loop through 
	for (int i = 0; i < col_length; i++) {
		for (int j = 0; j < row_height; j++) {

			// create a cell give its 
			// position and  

			int random_int = rand() % 7;
			int arr_rand[] = { 0,0,0,0,0,0,1 };

			// iterate through each cell and randomly set dead alive
			cells[i][j].generate_cell(11 * i, 11 * j);
			cells[i][j].cell_status(arr_rand[random_int]);
			if (j == 0)
				cells[i][j].cell_status(0);
			}
		}
	}





// boiler plate sfml to load the text
void Logic::load_text() {

	// check for errors
	if (!font.loadFromFile("Menlo.ttf"))
		{
		cout << "Font could not be loaded" << endl;
		}



	// set font properties
	text.setFont(font);
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::Magenta);
	text.setStyle(sf::Text::Bold | sf::Text::Italic);

	}


// window created
// player gun blip made
// text loaded
void Logic::load_visual_elements() {
	load_text();
	circle.setRadius(5);
	circle.setPointCount(100);
	window.create(sf::VideoMode(screen_width, screen_height), "My Window", sf::Style::Titlebar | sf::Style::None | sf::Style::Close);
	circle.setFillColor(sf::Color::Red);

	}

// the rules to calculate next frame
void Logic::predict_next() {

	// count alive neigbors
	// first traverse through the column then row
	for (int i = 0; i < col_length; i++) {

		for (int j = 0; j < row_height; j++) {

			// firstly assume the cell has no alive neighbour
			cells[i][j].alive_neighbours = 0;

			//  iterate horizontal
			for (int x = -1; x <= 1; x++) {
				// iterate vertical
				for (int y = -1; y <= 1; y++) {
					// if the cell is not on the left or right boundary
					if (i + x >= 0 && i + x < col_length)
						// if the cell is not on the top or bottom boundary
						if (j + y >= 0 && j + y < row_height)
							// if it is not the cell itself
							if (!(x == 0 && y == 0))
								// if the neighbour cell is alive
								if (cells[i + x][j + y].check_alive())
									// increment the neighbours of i j cell
									cells[i][j].alive_neighbours++;

					}

				}
			}
		}

	// set temp alive
	// traverse though grid
	for (int i = 0; i < col_length; i++) {
		for (int j = 0; j < row_height; j++) {

			// if cell alive 
			// the cell has either 2 or 3 neighbours it stays alive
			if (cells[i][j].check_alive()) {
				if (cells[i][j].alive_neighbours == 3 || cells[i][j].alive_neighbours == 2) {
					cells[i][j].intermediate_state = true;
					}

				// otherwise kill cell
				else {
					cells[i][j].intermediate_state = false;
					}
				}
			// to bring a cell to life, it must have 3 neighbours
			else {

				if (cells[i][j].alive_neighbours == 3) {
					cells[i][j].intermediate_state = true;
					}

				else {
					cells[i][j].intermediate_state = false;
					}
				}
			}
		}

	// set alive
	// activate_cell using intermediate state
	activate_cell();

	}

// draw the cells and player gun
void Logic::render_cells() {
	// equal to column length and width
	for (int i = 0; i < col_length; i++) {
		for (int j = 0; j < row_height; j++) {
			// draw functions takes in rect_shape and draws
			window.draw(cells[i][j].cellShape());
			window.draw(circle);



			}
		}


	}

void Logic::check_events() {


	// Patterns according to keys pressed
	// from A S D F G H J

	// vertical lines
	if (modeAKey.key_pressed()) {
		paused = true;
		for (int i = 0; i < col_length; i++) {
			for (int j = 0; j < row_height; j++) {
				if (i == 0 || i == col_length - 1)
					cells[i][j].cell_status(true);
				else
					cells[i][j].cell_status(false);
				}
			}
		}

	// square
	if (modeSKey.key_pressed()) {
		paused = true;

		for (int i = 0; i < col_length; i++) {
			for (int j = 0; j < row_height; j++) {
				if (i == 0 || i == col_length - 1 || j == 0 || j == row_height - 1)
					cells[i][j].cell_status(true);
				else
					cells[i][j].cell_status(false);
				}
			}
		}

	// diagnol
	if (modeDKey.key_pressed()) {
		paused = true;

		for (int i = 0; i < col_length; i++) {
			for (int j = 0; j < row_height; j++) {
				if (i + j == col_length - 1 || i == j)
					cells[i][j].cell_status(true);
				else
					cells[i][j].cell_status(false);
				}
			}
		}

	// diagnol and square
	if (modeFKey.key_pressed()) {
		paused = true;

		for (int i = 0; i < col_length; i++) {
			for (int j = 0; j < row_height; j++) {
				if (i + j == col_length - 1 || i == j || i == 0 || i == col_length - 1 || j == 0 || j == row_height - 1)
					cells[i][j].cell_status(true);
				else
					cells[i][j].cell_status(false);
				}
			}
		}

	// Parallel lines
	if (modeGKey.key_pressed()) {
		paused = true;

		for (int i = 0; i < col_length; i++) {
			for (int j = 0; j < row_height; j++) {
				if (i % 2)
					cells[i][j].cell_status(true);
				else
					cells[i][j].cell_status(false);
				}
			}
		}

	// Parallel lines
	if (modeHKey.key_pressed()) {
		paused = true;

		for (int i = 0; i < col_length; i++) {
			for (int j = 0; j < row_height; j++) {
				if (j % 2)
					cells[i][j].cell_status(true);
				else
					cells[i][j].cell_status(false);
				}
			}
		}
	// Glider Gun
	if (modeJKey.key_pressed()) {
		paused = true;

		for (int i = 0; i < col_length; i++)
			for (int j = 0; j < row_height; j++)
				cells[i][j].cell_status(false);
		cells[37][6].cell_status(true);
		cells[38][6].cell_status(true);
		cells[38][5].cell_status(true);
		cells[37][5].cell_status(true);
		cells[27][9].cell_status(true);
		cells[27][8].cell_status(true);
		cells[27][3].cell_status(true);
		cells[27][4].cell_status(true);
		cells[25][8].cell_status(true);
		cells[25][4].cell_status(true);
		cells[24][7].cell_status(true);
		cells[24][6].cell_status(true);
		cells[24][5].cell_status(true);
		cells[23][5].cell_status(true);
		cells[23][6].cell_status(true);
		cells[23][7].cell_status(true);
		cells[20][8].cell_status(true);
		cells[17][8].cell_status(true);
		cells[18][6].cell_status(true);
		cells[19][7].cell_status(true);
		cells[19][8].cell_status(true);
		cells[19][9].cell_status(true);
		cells[18][10].cell_status(true);
		cells[16][11].cell_status(true);
		cells[15][11].cell_status(true);
		cells[14][10].cell_status(true);
		cells[16][5].cell_status(true);
		cells[15][5].cell_status(true);
		cells[14][6].cell_status(true);
		cells[13][9].cell_status(true);
		cells[13][7].cell_status(true);
		cells[13][8].cell_status(true);
		cells[3][8].cell_status(true);
		cells[4][8].cell_status(true);
		cells[4][7].cell_status(true);
		cells[3][7].cell_status(true);

		}

	// controls to move the gun blip
	if (upKey.key_pressed()) {
		gun.set_y(gun.get_y() - 15);
		}
	if (downKey.key_pressed()) {
		gun.set_y(gun.get_y() + 15);
		}
	if (rightKey.key_pressed()) {
		gun.set_x(gun.get_x() + 15);
		}
	if (leftKey.key_pressed()) {
		gun.set_x(gun.get_x() - 15);
		}
	if (fireRight.key_pressed()) {
		generate_bullet_right(gun.get_x() / 10, gun.get_y() / 11);
		}
	if (fireLeft.key_pressed()) {
		generate_bullet_left(gun.get_x() / 12, gun.get_y() / 11);
		}





	// wipes screen
	// If reset key pressed
	if (backspace.key_pressed()) {
		for (int i = 0; i < col_length; i++) {
			for (int j = 0; j < row_height; j++) {
				cells[i][j].cell_status(false);
				}
			}
		print_board();


		cout << "Random Grid Generated" << endl;
		}

	// if clear key pressed
	// all cells are deactivated
	if (keypress_clear.key_pressed()) {
		for (int i = 0; i < col_length; i++) {
			for (int j = 0; j < row_height; j++) {
				cells[i][j].cell_status(false);
				}
			}

		cout << "All cells deactivated" << endl;
		}

	// detect cell clicks
// mouse button pressed
	if (leftMouseButton.sense_click()) {
		for (int j = 0; j < row_height; j++) {
			for (int i = 0; i < col_length; i++) {
				// check if the mouse click is contained inside the cell
				// get position is relative (0,0) position so we add the size of cell
				if (sf::Mouse::getPosition(window).x >= cells[i][j].cellShape().getPosition().x
					&& sf::Mouse::getPosition(window).x <= cells[i][j].cellShape().getPosition().x + cells[i][j].cellShape().getSize().x
					&& sf::Mouse::getPosition(window).y >= cells[i][j].cellShape().getPosition().y
					&& sf::Mouse::getPosition(window).y <= cells[i][j].cellShape().getPosition().y + cells[i][j].cellShape().getSize().y) {

					// we activate the cell if it was inactive
					// if it was active we deactivate it
					if (cells[i][j].check_alive())
						cells[i][j].cell_status(false);
					else
						cells[i][j].cell_status(true);


					window.draw(cells[i][j].cellShape());
					}
				}
			}
		}


	// if pause key pressed
	// pause game
	// if escape key pressed
	// close the window
	Screen::sense_pause();
	Screen::sense_exit();

	}

// cell is given state
// according to rules
void Logic::activate_cell() {
	for (int i = 0; i < col_length; i++) {
		for (int j = 0; j < row_height; j++) {
			cells[i][j].cell_status(cells[i][j].intermediate_state);
			}
		}

	}


// generate the cell patter which fires bullet to right
void Logic::generate_bullet_right(int x_pos, int y_pos)
	{

	cells[x_pos][y_pos - 1].cell_status(true);
	cells[x_pos + 1][y_pos - 2].cell_status(true);
	//cells[x_pos + 1][y_pos - 2].cell_status(true);
	cells[x_pos + 2][y_pos - 2].cell_status(true);
	cells[x_pos + 3][y_pos - 2].cell_status(true);
	cells[x_pos + 4][y_pos - 2].cell_status(true);
	cells[x_pos + 5][y_pos - 2].cell_status(true);
	cells[x_pos + 6][y_pos - 2].cell_status(true);
	cells[x_pos + 6][y_pos - 1].cell_status(true);
	cells[x_pos + 6][y_pos].cell_status(true);
	cells[x_pos + 5][y_pos + 1].cell_status(true);
	cells[x_pos][y_pos + 1].cell_status(true);
	cells[x_pos + 2][y_pos + 2].cell_status(true);
	cells[x_pos + 3][y_pos + 2].cell_status(true);



	cout << "Bullet Fired!!" << endl;


	}

// fires bullet to left
void Logic::generate_bullet_left(int x_pos, int y_pos) {

	cells[x_pos][y_pos - 1].cell_status(true);
	cells[x_pos][y_pos + 1].cell_status(true);
	cells[x_pos - 1][y_pos - 2].cell_status(true);
	cells[x_pos - 2][y_pos - 2].cell_status(true);
	cells[x_pos - 3][y_pos - 2].cell_status(true);
	cells[x_pos - 4][y_pos - 2].cell_status(true);
	cells[x_pos - 5][y_pos - 2].cell_status(true);
	cells[x_pos - 6][y_pos - 2].cell_status(true);
	cells[x_pos - 6][y_pos - 1].cell_status(true);
	cells[x_pos - 6][y_pos].cell_status(true);
	cells[x_pos - 5][y_pos + 1].cell_status(true);
	cells[x_pos - 2][y_pos + 2].cell_status(true);
	cells[x_pos - 3][y_pos + 2].cell_status(true);

	cout << "Bullet Fired!!" << endl;
	
	}


void Logic::move_gun(int x, int y) {
	gun.set_x(x);
	gun.set_y(y);


	}
