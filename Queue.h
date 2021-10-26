/* -----------------------------------------------------------------------------
 *
 * File Name:  Queue.h
 * Author: Derek Zhang 
 * Assignment:   EECS-268/269 Lab 4
 * Description:  This program will create an elevator simulator.
 * Date: 10/04/2021
 *
 ---------------------------------------------------------------------------- */
//Start your program.

#ifndef QUEUE_H
#define QUEUE_H
#include "QueueInterface.h"
#include "Node.h"

class Queue : public QueueInterface<std::string>
{   //Queue class
    private:
    Node* m_front;
    Node* m_back;
    public:
    Queue();
    ~Queue();
    /** Adds entry to back of queue
       * @pre None
       * @post Adds entry to back of queue
       * @param entry, to be added to back
       * @throw None
       **/
    void enqueue(std::string tempName);
    /** Removes entry from front of queue
       * @pre Queue is not empty
       * @post Removes entry from front of queue
       * @param none
       * @throw tries to remove an entry when empty
       **/
    void dequeue();
    /** Gets entry of node
       * @pre Node is not empty
       * @post Returns entry of node
       * @param none
       * @throw If peek is attempted on an empty queue
       **/
    std::string peek_front() const;
    /** Returns if queue is empty
       * @pre None
       * @post Returns if queue is empty
       * @param none
       * @throw none
       **/
    bool isEmpty() const;
};
#endif