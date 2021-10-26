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

#include "Queue.h"

Queue::Queue()
{   //initializes front and back pointers
    m_front = nullptr;
    m_back = nullptr;
}
void Queue::enqueue(std::string tempName)
{
    Node* tempNode = new Node(tempName);
    if (isEmpty())
    {   //if empty, front and back are set to the entry
        m_front = tempNode;
        m_back = tempNode;
    }
    else
    {   //if not empty, adds entry to back
        m_back->setNext(tempNode);
        m_back = tempNode;
    }
}
void Queue::dequeue()
{
    Node* tempNode = new Node("");
    if (isEmpty())
    {   //if empty, returns error message
        throw(std::runtime_error("Can not dequeue empty queue"));
    }
    else if (m_front == m_back)
    {   //if there is only one entry in queue
        m_front = nullptr;
        m_back = nullptr;
    }
    else
    {   //else removes front entry
        tempNode = m_front->getNext();
        m_front = tempNode;
    }
}
std::string Queue::peek_front() const
{
    if (isEmpty())
    {   //returns error message if empty
        throw(std::runtime_error("Can not peek empty queue"));
    }
    else
    {   //otherwise returns front value
        return m_front->getEntry();
    }
}
bool Queue::isEmpty() const
{
    if (m_front == nullptr && m_back == nullptr)
    {   //if both front and back are null pointers
        return true;
    }
    else
    {   //otherwise returns front
        return false;
    }
}
Queue::~Queue()
{   //destructor
    delete m_front;
    delete m_back;
}