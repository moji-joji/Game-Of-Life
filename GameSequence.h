#pragma once
#include"Logic.h"
#include"Cellule.h"
#include"Controls.h"
#include"Screen.h"

// inherits
class GameSequence : public Logic, public Cellule{
public:
    
    // constructor 
    GameSequence();

    // main game loop
    void simulate();

    // calculate game stats
    void display_stats();
    };