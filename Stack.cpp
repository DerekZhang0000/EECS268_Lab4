/* -----------------------------------------------------------------------------
 *
 * File Name:  Stack.cpp
 * Author: Derek Zhang 
 * Assignment:   EECS-268/269 Lab 4
 * Description:  This program will create an elevator simulator.
 * Date: 10/04/2021
 *
 ---------------------------------------------------------------------------- */
//Start your program.

#include "Stack.h"
#include <iostream>
#include <stdexcept>

Stack::Stack()
{   //initializes stack
    m_top = nullptr;
    length = 0;
}
void Stack::push(std::string entry)
{   //Adds to top of stack
    Node* tempPtr = new Node(entry);    //creates a temporary pointer
    if (isEmpty())
    {   //if stack is empty
        m_top = tempPtr;    //tempPtr becomes the top pointer
        length++;   //adds to length
    }
    else
    {   //if stack is not empty
        tempPtr->setNext(m_top);
        m_top = tempPtr;
        length++;   //adds to length
    }
}
void Stack::pop()
{   //Removes the top of stack
    if (isEmpty())
    {   //if top is null pointer
        throw(std::runtime_error("Can not pop an empty stack"));
    }
    else
    {   //sets top to next node
        Node* tempPtr = new Node("");
        tempPtr = m_top->getNext();
        m_top = tempPtr;
        length--;
    }
}
std::string Stack::peek() const
{   //Looks at top of stack
    if (isEmpty())
    {   //if top is null pointer
        throw(std::runtime_error("Can not peek an empty stack"));
    }
    else
    {   //sets gets entry of top
        return m_top->getEntry();
    }
}
bool Stack::isEmpty() const
{   //Checks if stack is empty
    if (m_top == nullptr)
    {   //if stack is empty
        return true;
    }
    else
    {   //if stack is not empty
        return false;
    }
}
bool Stack::isFull() const
{   //checks if stack has 7 elements
    if (length == 7)
    {   //if stack is full
        return true;
    }
    else
    {   //otherwise false
        return false;
    }
}
Stack::~Stack()
{   //destructor
    delete m_top;
}