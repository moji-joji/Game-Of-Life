#include"GameSequence.h"
#include"Screen.h"
#include"Gun.h"
#include<string>
#include<string.h>




GameSequence::GameSequence() { }


void GameSequence::simulate() {

    // set the colors name
    sf::RectangleShape rect_shape;
    sf::Color neon = sf::Color(55, 255, 255);
    sf::Color blk = sf::Color(0, 0, 0);


    // random seed given
    unsigned int seed;
    unsigned int init;
    seed = (unsigned)time(NULL);

    // console message given
    print_welcome();

    // Draw the window using given titles
    load_visual_elements();
    print_board();
    // draws rectangles	
    render_cells();






    // Game loop
    // Specify events
    // event.type senses Event
    // window_loop
    while (window.isOpen()) {
        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed)
                window.close();
            if (terminate)
                window.close();

            }

        // everything displayed on screen
        render_all();
        // fps and cell count 
        display_stats();

        }
    }

// calculate and display population
// also calculate and display fps
void GameSequence::display_stats() {

    // first population is 0
    int population = 0;
    string message = "Alive Cells: ";

    // we loop and count each alive cell
    for (int i = 0; i < col_length; i++)
        for (int j = 0; j < row_height; j++)
            if (cells[i][j].check_alive())
                population++;
    string count = to_string(population);

    // place text on screen
    window.draw(text);

    //  calculate fps



    float last_time = 0;

    float current_time = clock.restart().asSeconds();
    float fps = 1.f / (current_time - last_time);
    last_time = current_time;
    if (paused)
        fps = 0;

    // display all data
    text.setString(message + count + "\t\t\t\t\t\t FPS: " + to_string((int)fps));
    window.display();

    }
