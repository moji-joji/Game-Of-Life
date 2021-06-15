#pragma once
#include<iostream>
using namespace std;
#include<SFML\Graphics.hpp>
#include"Controls.h"

// virtual inheritance
class Screen : virtual public Key, virtual public Mouse {
protected:

    // make objects to store pause and escape 
    bool terminate = false;
    Key pauseKey = Key(sf::Keyboard::Pause);
    Key escapeKey = Key(sf::Keyboard::Escape);

    // initially the game is paused
    bool paused = true;

public:

    
    void print_welcome();
    void sense_pause();
    void sense_exit();
    
    };


