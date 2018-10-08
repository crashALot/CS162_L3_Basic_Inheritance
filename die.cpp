/********************************************************************* 
** Author:      Glenn Kiefer
** Date:        7/15/2018
** Description: This program contains the functions necessary to create
*               a die class object. This die will roll a randomly 
*               distributed number as determined by its number of sides.
*               This class has a derived class in the form of a 
*               loaded die.
*********************************************************************/
#include <cstdlib>
#include <ctime>
#include "die.hpp"

/********************************************************************* 
** Description: die::die()
*               Default constructor for die class objects. 
*********************************************************************/
die::die()
{
    numSides=6;
    rollTotal=0;
    runTotal=0;
    srand(time(NULL));
}

/********************************************************************* 
** Description: die::die(int numSidesStart)
*               Default constructor for loadedDie class objects. User
*               inputted number of sides initializes numSides member
*               variable.
*********************************************************************/
die::die(int numSidesStart)
{
    numSides=numSidesStart;
    rollTotal=0;
    runTotal=0;
    srand(time(NULL));
}

/********************************************************************* 
** Description: void die::rollDice()
*               Creates randomly generated dice roll.
*********************************************************************/
void die::rollDice()
{
    rollTotal=(((double)rand()/(double)RAND_MAX)*getNumSides())+1;
}

/********************************************************************* 
** Description: Set and Get functions
*               Used to retrieve and set specific member variables
*               within class objects.
*********************************************************************/
void die::setNumSides(int numberOfSides)
{
    numSides=numberOfSides;
}

void die::setRunningTotal()
{
    runTotal=runTotal+1;
}

void die::setRollTotal(int rollTotalIn)
{
    rollTotal=rollTotalIn;
}

int die::getNumSides()
{
    return numSides;
}

int die::getRollTotal()
{
    return rollTotal;
}

int die::getRunTotal()
{
    return runTotal;
}

/********************************************************************* 
** Description: die::~die()
*               die class destructor.
*********************************************************************/
die::~die()
{
}