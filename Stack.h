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

#ifndef STACK_H
#define STACK_H
#include "StackInterface.h"
#include "Node.h"


class Stack : public StackInterface<std::string> 
{
	private:
	Node* m_top;
       int length;
	public:
	Stack();
       ~Stack();
	void push(std::string entry);
       /** Removes top of stack
       * @pre Stack is non-empty
       * @post Top element is removed from the stack
       * @param None
       * @throw std::runtime_error if pop attempted on empty stack
       **/
	void pop();
       /** Looks at top of stack
       * @pre Stack is non-empty
       * @post Top element is returned
       * @param None
       * @throw std::runtime_error if peek attempted on empty stack
       **/
	std::string peek() const; //should peek throw an exception?
       /** Checks if stack is empty
       * @pre None
       * @post Returns whether or not the stack is empty
       * @param None
       * @throw None
       * */
	bool isEmpty() const;
       /** Checks if stack length is equal or less than 7
       * @pre None
       * @post Returns true or false based on above
       * @param None
       * @throw None
       * */
       bool isFull() const;
};
#endif