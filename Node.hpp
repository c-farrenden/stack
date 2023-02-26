// Node.hpp
/*******************************/
// Name: Connor Farrenden
// Course: SENG1120 - Assignment 2
// Student Number: c3374676
// Description: This is the hpp file for Node.

// Include contents of Node.h
#include "Node.h"

// Constructor - initialises private members
template <typename value_type>
Node<value_type>::Node(const value_type& data)
{
    this->data = data;
    next = NULL;
    prev = NULL;
}

// Destructor - not necessarily required for node
template <typename value_type>
Node<value_type>::~Node()
{
    next = NULL;
    prev = NULL;
}

// Get the EToll data stored in the node
template <typename value_type>
value_type Node<value_type>::getData() const
{
    return data;
}

// Set the next node
template <typename value_type>
void Node<value_type>::setNext(Node* next)
{
    this->next = next;
}

// Set the previous node
template <typename value_type>
void Node<value_type>::setPrev(Node* prev)
{
    this->prev = prev;
}

// Set the EToll data in the node
template <typename value_type>
void Node<value_type>::setData(const value_type data)
{
    this->data = data;
}

// Get the previous node
template <typename value_type>
Node<value_type>* Node<value_type>::getPrev() const
{
    return prev;
}

// Get the next node
template <typename value_type>
Node<value_type>* Node<value_type>::getNext() const
{
    return next;
}

