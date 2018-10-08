/********************************************************************* 
** Author:      Glenn Kiefer
** Date:        7/15/2018
** Description: Associated header file for loadedDie.cpp. Contains the 
*               necessary member variables and methods to create
*               a loadedDie class object.
*********************************************************************/
#ifndef LOADEDDIE_HPP
#define LOADEDDIE_HPP
#include "die.hpp"

class loadedDie : public die
{
private:

public:
    
    loadedDie();
    loadedDie(int);
    void rollDiceLoaded();
    ~loadedDie();
    
};

#endif