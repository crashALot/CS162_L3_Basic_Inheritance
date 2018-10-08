/********************************************************************* 
** Author:      Glenn Kiefer
** Date:        7/15/2018
** Description: Associated header file for die.cpp. Contains the 
*               necessary member variables and methods to create
*               a die class object.
*********************************************************************/
#ifndef DIE_HPP
#define DIE_HPP

class die
{
private:

    int numSides, rollTotal, runTotal;

public:
    
    die();
    die(int);
    void rollDice();
    void setNumSides(int);
    void setRollTotal(int);
    void setRunningTotal();
    int getNumSides();
    int getRollTotal();
    int getRunTotal();
    ~die();
    
};

#endif