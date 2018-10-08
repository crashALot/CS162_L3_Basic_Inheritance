/********************************************************************* 
** Author:      Glenn Kiefer
** Date:        7/15/2018
** Description: Associated header file for warMenu.cpp. Contains the 
*               necessary member variables and methods to create
*               a warMenu class object.
*********************************************************************/
#ifndef GAME_HPP
#define GAME_HPP
#include "die.hpp"
#include "loadedDie.hpp"
#include "warValidation.hpp"

class game
{
private:

    int loadedPlayer, regularPlayer, numRounds;

public:  

    game();
    void gameInfo();
    void endOfRound(die*, loadedDie*); // Pass by referencach objecte
    void endOfGame(int);
    int quitMenu();
    ~game();

};

#endif