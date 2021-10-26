/* -----------------------------------------------------------------------------
 *
 * File Name:  CeoOfElevator.h
 * Author: Derek Zhang 
 * Assignment:   EECS-268/269 Lab 4
 * Description:  This program will create a shape interface.
 * Date: 10/04/2021
 *
 ---------------------------------------------------------------------------- */
//Start your program.

#ifndef CEOOFELEVATOR_H
#define CEOOFELEVATOR_H
#include "Stack.h"
#include "Queue.h"

class CeoOfElevator
{   //executive class
    public: //public methods
    CeoOfElevator(std::string fileName);
    ~CeoOfElevator();
    /** Runs program
    * @pre None
    * @post Completes elevator simulator
    * @param None
    * @throw None
    **/
   void run();
    /** Adds an element to the queue
    * @pre None
    * @post entry is added to back of queue
    * @param name, the element to be added to the stack
    * @throw None
    **/
    void wait(std::string name);
    /** Moves up to 7 elements from the front of the queue
    * @pre None
    * @post 7 elements are moved from the front of the queue
    * @param none
    * @throw None
    **/
    void pick_up();
    /** Adds an element to the queue
    * @pre None
    * @post entry is added to back of queue
    * @param All elements being moved are deleted
    * @throw If it tries to delete greater number of elements than how many are being moved
    **/
    void drop_off(int dropped);
    /** Prints status of elements
    * @pre None
    * @post Status of elements is printed
    * @param None
    * @throw None
    **/
    void inspection();
    private:
    std::string fileName;
    std::string tempCommand;
    std::string tempName;
    Stack* inElevator;
    Queue* inLine;
    int tempInt;
};
#endif