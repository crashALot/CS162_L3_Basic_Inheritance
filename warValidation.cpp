/********************************************************************* 
** Author:      Glenn Kiefer
** Date:        7/15/2018
** Description: This program contains the functions necessary to
*               validate each and every input in the War program. 
*********************************************************************/
#include "warValidation.hpp"
#include <string>
#include <iostream>
#include <cmath> // Used for pow function

/********************************************************************* 
** Description: int mainMenuValidate()
*               Ensures user input is limited to the integer values
*               1 or 2
*********************************************************************/
int mainMenuValidate()
{
    int go=1, length=0;
    std::string userIn;
    do
    {
        // http://www.cplusplus.com/forum/beginner/2624/
        // How to identify the Enter key when pressed alone 
        std::getline(std::cin, userIn);
        length=userIn.length();
        if (userIn[0]==' ' || length>1 || (userIn[0]!='1' && userIn[0]!='2'))
        {
            std::cout << "Please re-enter your choice as an integer 1 (Play a game) or 2 (Quit the game): " << std::endl;
        }
        else
        {
            // Work cited: https://stackoverflow.com/questions/5029840/convert-char-to-int-in-c-and-c
            go=0; // Signal variable exits while loop
            return((int)userIn[0]-'0'); // Converts char to int via ASCII code math
        }
    }
    while (go);
    return 0;
}

/********************************************************************* 
** Description: int playerValidate()
*               Ensures 
*********************************************************************/
int playerValidate()
{
    int go=1, length=0;
    std::string userIn;
    do
    {
        // http://www.cplusplus.com/forum/beginner/2624/
        // How to identify the Enter key when pressed alone 
        std::getline(std::cin, userIn);
        length=userIn.length();
        if (userIn[0]==' ' || length>1 || (userIn[0]!='1' && userIn[0]!='2'))
        {
            std::cout << "Please re-enter your choice as an integer 1 (for player 1) or 2 (for player 2): " << std::endl;
        }
        else
        {
            // Work cited: https://stackoverflow.com/questions/5029840/convert-char-to-int-in-c-and-c
            go=0; // Signal variable exits while loop
            return((int)userIn[0]-'0'); // Converts char to int via ASCII code math
        }
    }
    while (go);
    return 0;
}

/********************************************************************* 
** Description: int warInfoValidate()
*               Ensures user input is limited to the integer values
*               1 or 2. Slightly different output from playerValidate
*********************************************************************/
int warInfoValidate()
{
    int runTotal=0, go=1, length;
    do
    {
        std::string userIn;
        std::getline(std::cin, userIn);
        length=userIn.length();
        for (int i=0; i<length; i++)
        {
            if (isdigit(userIn[i]) && !(ispunct(userIn[i])) && !(isspace(userIn[i])))
            {
                // Work cited: https://stackoverflow.com/questions/5029840/convert-char-to-int-in-c-and-cs
                runTotal+=pow(10,length-1-i)*(userIn[i]-'0'); // Converts char back to int
                if ((i+1)==length)
                    go=0;
                if (!runTotal)
                {
                    std::cout << "Please enter a positive integer value (without spaces, commas, or periods) greater than 0: " << std::endl;
                    runTotal=0;
                    go=1;
                }
            }
            else
            {
                std::cout << "Please enter a positive integer value (without spaces, commas, or periods) greater than 0: " << std::endl;
                runTotal=0;
                break;
            }   
        }
    } while (go);
    return runTotal;
}

/********************************************************************* 
** Description: int dieInfoValidate()
*               Ensures die can only be positive integer
*********************************************************************/
int dieInfoValidate()
{
    int runTotal=0, go=1, length;
    do
    {
        std::string userIn;
        std::getline(std::cin, userIn);
        length=userIn.length();
        for (int i=0; i<length; i++)
        {
            if (isdigit(userIn[i]) && !(ispunct(userIn[i])) && !(isspace(userIn[i])))
            {
                // Work cited: https://stackoverflow.com/questions/5029840/convert-char-to-int-in-c-and-cs
                runTotal+=pow(10,length-1-i)*(userIn[i]-'0'); // Converts char back to int
                if ((i+1)==length && runTotal>1)
                    go=0;
                if (runTotal<2)
                {
                    std::cout << "Please enter a positive integer value (without spaces, commas, or periods) greater than 1: " << std::endl;
                    runTotal=0;
                    go=1;
                }
            }
            else
            {
                std::cout << "Please enter a positive integer value (without spaces, commas, or periods) greater than 1: " << std::endl;
                runTotal=0;
                break;
            }   
        }
    } while (go);
    return runTotal;
}