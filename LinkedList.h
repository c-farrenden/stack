// LinkdList.h
/*******************************/
// Name: Connor Farrenden
// Course: SENG1120 - Assignment 2
// Student Number: c3374676
// Description: This is the header file for the linked list class

// Include contents of Node.h
#include "Node.h"

// Macroguards
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

// Template
template <typename value_type>

class LinkedList
{   
    // Members that can be accessed outside LinkedList class.
    public:
        // Constructor
        // Precondition: None
        // Postcondition: Constructs and initialises linked list and its private members
        LinkedList();

        // Destructor
        // Precondition: None
        // Postcondition: Destructs linked list, setting pointers to null, removing memory from the heap when deleted
        ~LinkedList();

        // Main functions
        // Precondition: None
        // Postcondition: A new node is added to the head of the Linked List
        void addToHead(const value_type& data);

        // Precondition: None
        // Postcondition: A new node is added to the tail of the Linked List
        void addToTail(const value_type& data);

        // Precondtion: None
        // Postcondition: Returns the number of nodes in each linked list
        int length() const;

        // Precondition: Requires current and head pointers
        // Postcondition: Moves current pointer to head pointer
        void currentToHead();

        // Precondition: Requires linked list to remove from
        // Postcondition: Will loop through lists and remove specified licences if linked list is a specified length 
        void remove(const string licence_);

        // Precondition: Requires current pointer
        // Postcondition: Moves current pointer to the next node in linked list (or NULL)
        void currentToNext();

        // Precondition: Requires a node (current pointer)
        // Postcondition: Will remove/delete current and sets the next pointer of current pointer's previous pointer to currents next pointer and sets the 
        // previous pointer of current pointer's next pointer to currents previous pointer and resets current back to head after deletion 
        void removeCurrent();

        // Precondition: Requires a node (head pointer)
        // Postcondition: Will create a temporary pointer to head and move head to the next node, removing the node previously pointed to by head
        //void removeFromHead();
        value_type removeFromHead();

        // Precondition: Requires a node (tail pointer)
        // Postcondition: Will create a temporary pointer to tail and move tail to the previous node, removing the node previously pointed to by tail
        value_type removeFromTail();

        // Precondition: Requires pointers/nodes
        // Postcondition: Will remove/delete node and move current to next along with head if it equals current and set previous to NULL, else tail to NULL
        void removeNode(const string licence_);

        // Precondition: Requires current
        // Postcondition: Will return the value of current's data
        value_type getCurrent() const;

        // Precondition: Requires head
        // Postcondition: Will return the value of head
        value_type getHead() const;

        // Precondition: None
        // Postcondition: Returns true with string if list length is 0 (empty linked list) or false if not
        bool isEmpty() const;

        // Precondition: None
        // Postcondition: Returns the amount (frequency) of the passed string type specified in the linked list
        int count(const string number);

        // Precondition: None
        // Postcondition: Returns double, will loop through linked lists and add each charge for every existing data node
        double totalIncome();
        
        // Member operators
        // Precondition: this LinkedList
        // Postcondition: Allows addition and assignment of linked lists
        void operator +=(LinkedList<value_type>& list);

        // Precondition: this LinkedList
        // Postcondition: Allows subtraction and assignment of linked lists
        void operator -=(LinkedList<value_type>& list);

    // Members that cannot be accessed outside LinkedList class.
    private:
        Node<value_type>* head;
        Node<value_type>* tail;
        Node<value_type>* current;
        int listLength;
};

// Non-member output operator
// Precondition: Linked lists to print
// Postcondition: Allows printing of linked lists
template <typename value_type>
std::ostream& operator << (std::ostream& out, LinkedList<value_type>& list);

#include "LinkedList.hpp"

#endif