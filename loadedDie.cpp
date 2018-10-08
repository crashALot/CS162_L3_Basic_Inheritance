/********************************************************************* 
** Author:      Glenn Kiefer
** Date:        7/15/2018
** Description: This program contains the functions necessary to create
*               a loadedDie class object. This die will roll a randomly 
*               distributed number as determined by its number of sides.
*               However, the loadedDie will tend to skew towards higher
*               values, as determined by a weighted function. The loadedDie
*               inherits its structure from the base die class.
*********************************************************************/
#include "loadedDie.hpp"
#include <ctime>
#include <cstdlib>

/********************************************************************* 
** Description: loadedDie::loadedDie() : die()
*               Default constructor for loadedDie, derived from die
*               base class
*********************************************************************/
loadedDie::loadedDie() : die()
{
}

/********************************************************************* 
** Description: loadedDie::loadedDie(int numSidesIn) : die(numSidesIn)
*               Default constructor for loadedDie, derived from die
*               base class. Initialized with user inputted number of
*               sides
*********************************************************************/
loadedDie::loadedDie(int numSidesIn) : die(numSidesIn)
{
}

/********************************************************************* 
** Description: void loadedDie::rollDiceLoaded()
*               Calculates a weighted roll for the loadedDie object.
*********************************************************************/
void loadedDie::rollDiceLoaded()
{
    int loadedRoll;
    rollDice();
    loadedRoll=getRollTotal()+((getNumSides()-getRollTotal())*(((double)rand()/(double)RAND_MAX)));
    setRollTotal(loadedRoll);
}

/********************************************************************* 
** Description: loadedDie::~loadedDie()
*               Destructor for loadedDie class.s
*********************************************************************/
loadedDie::~loadedDie()
{
}