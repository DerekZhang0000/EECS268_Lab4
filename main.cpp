/* -----------------------------------------------------------------------------
 *
 * File Name:  main.cpp
 * Author: Derek Zhang 
 * Assignment:   EECS-268/269 Lab 4
 * Description:  This program will create an elevator simulator.
 * Date: 10/04/2021
 *
 ---------------------------------------------------------------------------- */
//Start your program.

#include <iostream>
#include <fstream>
#include "CeoOfElevator.h"

int main(int argc, char** argv)
{   //takes input from command line
    std::ifstream inFile;
    std::string fileName = "";
    if (argc > 1)
    {   //if there is more than 1 argument
        fileName = argv[1]; //second argument is the file name
        inFile.open(fileName);  //attempts to open file
        CeoOfElevator ceo(fileName);
        ceo.run();  //runs CeoOfElevator
    }
    if (!inFile.is_open())
    {   //error if file could not be opened
        std::cout << "Error: File could not be opened.\n";
    }
}