/* -----------------------------------------------------------------------------
 *
 * File Name:  CeoOfElevator.cpp
 * Author: Derek Zhang 
 * Assignment:   EECS-268/269 Lab 4
 * Description:  This program will create an elevator simulator.
 * Date: 10/04/2021
 *
 ---------------------------------------------------------------------------- */
//Start your program.

#include "CeoOfElevator.h"
#include "Stack.h"
#include "Queue.h"
#include "Node.h"
#include <iostream>
#include <fstream>
#include <string>
std::ifstream inFile;
std::string tempCommand;
std::string tempName;
int tempInt;
Stack* inElevator;
Queue* inLine;

CeoOfElevator::CeoOfElevator(std::string fileName)
{   //opens file
    inFile.open(fileName);
    inElevator = new Stack();
    inLine = new Queue();
}
void CeoOfElevator::run()
{   //runs main functions of program
    while (!inFile.eof())   //runs until end of file
    {
        inFile >> tempCommand;
        if (tempCommand == "WAIT")
        {  //if wait command is read
            inFile >> tempName;
            wait(tempName);
        }
        else if (tempCommand == "PICK_UP")
        {   //if pick up command is read
            try
            {
                pick_up();
            }
            catch(std::runtime_error& e)
            {
                std::cout << e.what() << "\n";
            }
        }
        else if (tempCommand == "DROP_OFF")
        {   //if drop off command is read
            inFile >> tempInt;
            try
            {
                drop_off(tempInt);
            }
            catch(std::runtime_error& e)
            {
                std::cout << e.what() << "\n";
            }
        }
        else if (tempCommand == "INSPECTION")
        {   //if inspection command is read
            inspection();
        }
    }
    std::cout << "END OF FILE\n";
}
void CeoOfElevator::wait(std::string tempName)
{   //wait method
    std::cout << "WAIT " << tempName << "\n";
    inLine->enqueue(tempName);
}
void CeoOfElevator::pick_up()
{   //pick up method
    std::cout << "PICK UP\n";
    if (!(inLine->isEmpty()))
    {   //if line is not empty
        while (!(inElevator->isFull()) && !(inLine->isEmpty()))
        {   //until elevator fills up or line becomes empty
            std::cout << "Picked up " << inLine->peek_front() << "\n";
            inElevator->push(inLine->peek_front()); //adds front of line to elevator
            inLine->dequeue();  //removes front of line
        }
    }
    else
    {   //error if tries to pick up from empty line
        throw(std::runtime_error("No one in line to pick up"));
    }
}
void CeoOfElevator::drop_off(int dropped)
{   //drop off method
    std::cout << "DROP OFF " << dropped << "\n";
    for (int x = 0; x < dropped; x++)
    {   
        if (inElevator->isEmpty())
        { //error message if attempted drop off from empty elevator
            throw(std::runtime_error("No one in elevator to drop off"));
        }
        else
        {   //drops off last person on elevator
            std::cout << "Dropped off " << inElevator->peek() << "\n";
            inElevator->pop();
        }
    }
}
void CeoOfElevator::inspection()
{   //inspection method
    std::cout << "INSPECTION\n";
    std::cout << "Elevator status:\n";
    if (inElevator->isEmpty())
    {   //if elevator is empty
        std::cout << "The elevator is empty\n";
        std::cout << "There is no one in the elevator\n";
    }
    else
    {   //if someone is in elevator
        std::cout << "The elevator is not empty\n";
        std::cout << inElevator->peek() << " will be next off the elevator\n";
    }
    if (inLine->isEmpty())
    {   //if line is empty
        std::cout << "There is no one waiting in line\n";
    }
    else
    {   //if someone is in line
        std::cout << inLine->peek_front() << " will be next on the elevator\n";
    }
}
CeoOfElevator::~CeoOfElevator()
{   //deconstructor
    inFile.close();
}