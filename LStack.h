// LStack.h
/*******************************/
// Name: Connor Farrenden
// Course: SENG1120 - Assignment 2
// Student Number: c3374676
// Description: This is the header file for the stack class

//Include contents of LinkedList.h
#include "LinkedList.h"

//Include contents of Node.h
#include "Node.h"

// Macroguards
#ifndef LSTACK_H
#define LSTACK_H

template <typename value_type>
class LStack
{
    public:
        // Constructor
        // Precondition: None
        // Postcondition: Constructs stack with LinkedList data
        LStack();

        // Destructor
        // Precondition: None
        // Postcondition: Destructs stack by removing nodes from stack and thus removing memory from the heap when deleted
        ~LStack();

        // Main functions
        // Precondition: Stack for pushing data of value_type
        // Postcondition: This will add data to the top of stack
        void push(const value_type& top);

        // Precondition: None
        // Postcondition: Will remove the top element from the stack
        value_type pop();

        // Precondition: None
        // Postcondition: Returns true with string if list length is 0 (empty stack) or false if not
        bool isEmpty() const;

        // Precondition: 
        // Postcondition: Return the top element of the stack
        value_type peek() const;

        // Precondtion: None
        // Postcondition: Returns size of stack
        int size() const;
        
        // Precondition: None
        // Postcondition: Returns double, will loop through stack and add each charge for every existing data node correspondant to the type specified
        double totalIncome();

        // Precondition: None
        // Postcondition: Returns the amount (frequency) of the passed string type specified in the stack
        int count(const string number);
        
        // Precondition: Requires stack to remove from
        // Postcondition: Will loop through stack and remove specified licence
        void remove(const string licence_);

        // Member operators
        // Precondition: this LStack
        // Postcondition: Allows addition and assignment of stacks
        void operator +=(LStack<value_type>& stack);

        // Precondition: this LStack
        // Postcondition: Allows subtraction and assignment of stacks
        void operator -=(LStack<value_type>& stack);
    
    // Members that cannot be accessed outside LStack class.
    private:
        LinkedList<value_type> data;
};

// Non-member output operator
// Precondition: Stacks to print
// Postcondition: Allows printing of stacks
template <typename value_type>
std::ostream& operator << (std::ostream& out, LStack<value_type>& stack);

#include "LStack.hpp"

#endif