/* -----------------------------------------------------------------------------
 *
 * File Name:  Node.h
 * Author: Derek Zhang 
 * Assignment:   EECS-268/269 Lab 4
 * Description:  This program will create an elevator simulator.
 * Date: 10/04/2021
 *
 ---------------------------------------------------------------------------- */
//Start your program.

#ifndef NODE_H
#define NODE_H
#include <string>

class Node
{
	private:
	std::string m_entry;
	Node* m_next;
	public:
	Node(std::string entry);
       ~Node();
	/** Gets entry of node
       * @pre None
       * @post Returns entry of node
       * @param a
       * @throw None
       **/
	std::string getEntry() const;
	/** Sets entry of node
       * @pre None
       * @post Changes the entry of the node to a new entry
       * @param a character
       * @throw None
       **/
	void setEntry(std::string entry);
	/** Returns pointer to next node
       * @pre None
       * @post Returns pointer of next node
       * @param None
       * @throw None
       **/
	Node* getNext() const;
	/** Sets pointer to next node
       * @pre None
       * @post Sets pointer of next node to a new pointer
       * @param None
       * @throw None
       **/
	void setNext(Node* next);

};
#endif