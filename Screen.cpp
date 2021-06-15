#include"Screen.h"

// The inital game message is printed on console

void Screen::print_welcome() {
    cout << "Use the mouse button to plant cells" << endl;
    cout << "Press 'A' 'S' 'D' 'F' 'G' 'H' 'J' for various patterns" << endl;
    cout << "Press 'Z' or 'X' to shoot ripple bullets" << endl;
    cout << "Move the gun with arrow keys" <<endl<< endl;
    cout << "Press R to generate random" << endl;
    cout << "Press BackSpace to clear grid" << endl;
    cout << "Press Pause  to pause and resume" << endl;
    cout << "Press Escape to exit" << endl;
    cout << endl << endl;
    cout << "Press Enter to Start" << endl;
    getchar();
    }

// detects for pause button pressed or not
void Screen::sense_pause() {
    if (pauseKey.key_pressed()) {
        if (paused)
            {
            paused = false;
            cout << "Game resumed" << endl;
            }
        else
            {
            paused = true;
            cout << "Game paused" << endl;
            }

        }

    }

// exits if escape key is pressed
void Screen::sense_exit() {
    if (escapeKey.key_pressed()) {
        terminate = true;
        cout << "Sequence Terminated" << endl;
        }
    }


