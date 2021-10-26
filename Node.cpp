/* -----------------------------------------------------------------------------
 *
 * File Name:  Node.cpp
 * Author: Derek Zhang 
 * Assignment:   EECS-268/269 Lab 4
 * Description:  This program will create an elevator simulator.
 * Date: 10/04/2021
 *
 ---------------------------------------------------------------------------- */
//Start your program.

#include "Node.h"
#include <string>

Node::Node(std::string entry)
{   //sets node entry to intialized value
    m_entry = entry;
    m_next = nullptr;
}
std::string Node::getEntry() const
{   //returns entry of node
    return m_entry;
}
void Node::setEntry(std::string entry)
{   //sets node entry to new entry
    m_entry = entry;
}
Node* Node::getNext() const
{   //returns pointer to next node
    return m_next;
}
void Node::setNext(Node* next)
{   //sets pointer to next node
    m_next = next;
}
Node::~Node()
{
    delete m_next;
}