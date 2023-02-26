// Node.h
/*******************************/
// Name: Connor Farrenden
// Course: SENG1120 - Assignment 2
// Student Number: c3374676
// Description: This is the header file for the Node class.

// Include contents of Node.h
#include "EToll.h"

// Macroguards
#ifndef NODE_H
#define NODE_H

// Template
template <typename value_type>

// Node class contains classes and definitions for Node.cpp implementation.
class Node
{   
    // Members that can be accessed outside Node class.
    public:
        // Constructor
        // Precondition: None
        // Postcondition: Node is created and passed data of value_type (EToll)
        Node(const value_type& data);

        // Destructor
        // Precondition: None
        // Postcondition: Removes all nodes from heap
        ~Node();

        // Setters
        // Precondition: None
        // Postcondition: Set the next pointer of node
        void setNext(Node* next);
        
        // Precondition: None
        // Postcondition: Sets the previous pointer of node
        void setPrev(Node* prev);

        // Precondition: Requires data to set
        // Postcondition: Sets data in node
        void setData(const value_type data);

        // Getters
        // Precondition: Requires next pointer value
        // Postcondition: Gets next pointer of node and returns value
        Node* getNext() const;

        // Precondition: Requires previous pointer value
        // Postcondition: Gets previous pointer of node and returns value
        Node* getPrev() const;

        // Precondition: Requires type data 
        // Postcondition: Returns data from pointer/node
        value_type getData() const;

    // Members that cannot be accessed outside Node class.
    private:
        value_type data;
        Node* next;
        Node* prev;
};

#include "Node.hpp"

#endif