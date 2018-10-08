/********************************************************************* 
** Author:      Glenn Kiefer
** Date:        7/15/2018
** Description: This program contains the functions necessary to create
*               a warMenu class object. This object contains the 
*               necessary functions to play a game of War in its 
*               entirety.
*********************************************************************/
#include <iostream>
#include <iomanip>
#include "game.hpp"

/********************************************************************* 
** Description: game:warMenu()
*               Outputs default intro menu to consol. User can select
*               to play game or quite program
*********************************************************************/
game::game()
{
    int userChoice;
    std::cout << "****************** Welcome to War! ******************" << std::endl;
    std::cout << "Would you like to: " << std::endl;
    std::cout << "Play a game (1) or Quit the game (2)? " << std::endl;
    userChoice=mainMenuValidate();
    if (userChoice==1)
    {
        gameInfo();
    }
    else
    {
        quitMenu();
    }
}

/********************************************************************* 
** Description: void game::gameInfo()
*               Requests userinput to configure game before start.
*               Calls die and loadedDie object creation. Maintains
*               loop per user specificed number of rounds. Determines 
*               victor and calls end of game menu when completed.
*********************************************************************/
void game::gameInfo()
{
    int numSidesLoaded, numSidesRegular, victor;
    std::cout << "Please enter how many rounds of War you'd like to play: " << std::endl;
    numRounds=warInfoValidate();
    std::cout << "Which player will hold the loaded die?" << std::endl;
    loadedPlayer=playerValidate();
    std::cout << "How many sides will the regular die have?" << std::endl;
    numSidesRegular=dieInfoValidate();
    std::cout << "How many sides will the loaded die have?" << std::endl;
    numSidesLoaded=dieInfoValidate();
    die regularDie(numSidesRegular);
    loadedDie cheapDie(numSidesLoaded);
    
   while (numRounds>0)
    {
        regularDie.rollDice();
        cheapDie.rollDiceLoaded();
        
        if (regularDie.getRollTotal()>cheapDie.getRollTotal())
            regularDie.setRunningTotal();
        if (regularDie.getRollTotal()<cheapDie.getRollTotal())
            cheapDie.setRunningTotal();
            
        endOfRound(&regularDie, &cheapDie);
        numRounds--;
    }
    
    if (regularDie.getRunTotal()>cheapDie.getRunTotal())
        victor=1;
    else if (regularDie.getRunTotal()<cheapDie.getRunTotal())
        victor=2;
    else
        victor=3;
        
    endOfGame(victor);
}

/********************************************************************* 
** Description: void game::endOfRound(die* regDice, loadedDie* cheapDice)
*               Using generated die and loadedDie objects as arguments,
*               creates descriptive output summarizing each round of 
*               War.
*********************************************************************/
void game::endOfRound(die* regDice, loadedDie* cheapDice)
{
    if (loadedPlayer==1)
        regularPlayer=2;
    else
        regularPlayer=1;
  
    std::cout << std::endl << std::right << std::setw(35) << std::setfill ('*')  << " There remains " << numRounds << " battles of War! " << std::left << std::setw(15) << '*' << std::endl;
    std::cout << std::setw(55) << std::setfill ('~') << std::endl;
    std::cout << std::right << std::setw(37) << std::setfill(' ') << "Player 1" << std::setw(15) << std::setfill(' ') << "Player 2"  << std::endl;
    std::cout << std::right << std::setw(37) << std::setfill(' ') << "--------" << std::setw(15) << std::setfill(' ') << "--------"  << std::endl;
    std::cout << std::left << std::setw(20) << "Using loaded dice: ";
    if (loadedPlayer==1)
    {
        std::cout << std::right << std::setw(14) << std::setfill(' ') << "Yes" ;
            std::cout << std::right << std::setw(14) << std::setfill(' ') << "No" << std::left << std::endl;
        std::cout << std::setw(20) << "Number of sides on dice: " ;
        std::cout << std::right << std::setw(8) << std::setfill(' ') << cheapDice->getNumSides() << std::left;
            std::cout << std::right << std::setw(14) << std::setfill(' ') << regDice->getNumSides() << std::left << std::endl;
        std::cout << std::setw(20) << "Rolled this round:" ;
        std::cout << std::right << std::setw(13) << std::setfill(' ') << cheapDice->getRollTotal() ;
            std::cout << std::right << std::setw(14) << std::setfill(' ') << regDice->getRollTotal() << std::left << std::endl;
        std::cout << std::setw(20) << "Has a cumulative score of: " ;
        std::cout << std::right << std::setw(6) << std::setfill(' ') << cheapDice->getRunTotal() ;
            std::cout << std::right << std::setw(14) << std::setfill(' ') << regDice->getRunTotal() << std::left << std::endl;
    }
    else
    {
        std::cout << std::right << std::setw(14) << std::setfill(' ') << "No" ;
            std::cout << std::right << std::setw(14) << std::setfill(' ') << "Yes" << std::left << std::endl;
        std::cout << std::setw(20) << "Number of sides on dice: " ;
        std::cout << std::right << std::setw(8) << std::setfill(' ') << regDice->getNumSides() << std::left;
            std::cout << std::right << std::setw(14) << std::setfill(' ') << cheapDice->getNumSides() << std::left << std::endl;
        std::cout << std::setw(20) << "Rolled this round:" ;
        std::cout << std::right << std::setw(13) << std::setfill(' ') << regDice->getRollTotal() ;
            std::cout << std::right << std::setw(14) << std::setfill(' ') << cheapDice->getRollTotal() << std::left << std::endl;
        std::cout << std::setw(20) << "Has a cumulative score of: " ;
        std::cout << std::right << std::setw(6) << std::setfill(' ') << regDice->getRunTotal() ;
            std::cout << std::right << std::setw(14) << std::setfill(' ') << cheapDice->getRunTotal() << std::left << std::endl;
    }
}

/********************************************************************* 
** Description: void game::endOfGame(int theWinner)
*               Outputs winning message based on player with highest 
*               score. Prompts user to play another game or quit.
*********************************************************************/
void game::endOfGame(int theWinner)
{
    std::cout << std::right << std::endl << std::setw(56) << "-----------------------------------" ;
    std::cout << std::right << std::endl << std::setw(56) << std::endl << "You've reached the end of the game!" << std::endl;
    std::cout << std::right << std::endl << std::setw(56) << "-----------------------------------" << std::endl << std::endl;
    switch (theWinner)
    {
        case 1:
            std::cout << std::right << std::endl << std::setw(64) << "**************************************************" << std::endl;
            std::cout << std::right << std::endl << std::setw(23) << "* Player " << regularPlayer << " with the regular die has won the game *" << std::endl;
            std::cout << std::right << std::endl << std::setw(64) << "**************************************************" << std::endl;
            break;
        
        case 2:
            std::cout << std::right << std::endl << std::setw(63) << "*************************************************" << std::endl;
            std::cout << std::right << std::endl << std::setw(23) << "* Player " << loadedPlayer << " with the loaded die has won the game *" << std::endl;
            std::cout << std::right << std::endl << std::setw(63) << "*************************************************" << std::endl;
            break;
        
        case 3:
            std::cout << std::right << std::endl << std::setw(50) << "***********************" << std::endl;
            std::cout << std::right << std::endl << std::setw(50) << "* The game is a draw! *" << std::endl;
            std::cout << std::right << std::endl << std::setw(50) << "***********************" << std::endl;
            break;
    }
    
    int userChoice;
    std::cout << std::endl << "Would you like to play another game (1) or quit (2)?" << std::endl;
    userChoice=mainMenuValidate();
    if (userChoice==1)
        gameInfo();
    else
        quitMenu();   
}

/********************************************************************* 
** Description: int game::quitMenu()
*               Simple exit message and terminating return when user
*               requests.
*********************************************************************/
int game::quitMenu()
{
    std::cout << "Thank you for playing! See you again soon!" << std::endl;
    return 0;
}

/********************************************************************* 
** Description: warMenu::~warMenu()
*               warMenu destructor
*********************************************************************/
game::~game()
{
}