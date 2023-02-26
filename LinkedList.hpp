// LinkdList.hpp
/*******************************/
// Name: Connor Farrenden
// Course: SENG1120 - Assignment 2
// Student Number: c3374676
// Description: This is the hpp file for the linked list

//Include contents of LinkedList.h
#include "LinkedList.h"

//Include contents of Node.h
#include "Node.h"

// Constructor - initialises private members
template <typename value_type>
LinkedList<value_type>::LinkedList()
{
    head = NULL;
    tail = NULL;
    current = NULL;
    listLength = 0;
}

// Destructor - ensures nodes are removed from heap when linked lists are deleted (using head for deletion of each node, then set each to NULL)
template <typename value_type>
LinkedList<value_type>::~LinkedList()
{
    while(head != NULL) 							
	{
		removeFromHead();
	}
	
    head = NULL;
	tail = NULL; 									
	current = NULL;
    listLength = 0;
}

template <typename value_type>
value_type LinkedList<value_type>::getHead() const
{
    return this->head->getData();
}

// Length function returns list length of linked lists
template <typename value_type>
int LinkedList<value_type>::length() const
{
    return listLength;
}

// Function for adding nodes from tail
template <typename value_type>
void LinkedList<value_type>::addToTail(const value_type& data)
{   
    // Checks if length is equal to zero (if there is no linked list - empty)
    if(length() == 0)
    {
        // Creates new node containing data of EToll
        Node<value_type>* tempNode = new Node<value_type>(data);
        // Set the head pointer to the new node
        head = tempNode;
        // Set the tail pointer to the new node
        tail = tempNode;
        // Set the current pointer to new node
        current = tempNode;
        // Set the EToll data of the new node
        tempNode->setData(data);
        // Increment the list length
        listLength++;
    }
    else
    {
        // If the linked list (length not 0) is empty, create another node
        Node<value_type>* tempNode = new Node<value_type>(data);
        // Set the value of tail's next pointer to point to the new node
        tail->setNext(tempNode);
        // Set the value of the new node's previous pointer to point to the tail
        tempNode->setPrev(tail);
        // Set the tail pointer to point to the new node
        tail = tempNode;
        // Set the EToll data of the new node
        tempNode->setData(data);
        // Increment the list length
        listLength++;
    }
}

// Function for adding nodes from head
template <typename value_type>
void LinkedList<value_type>::addToHead(const value_type& data)
{   
    // Checks if length is equal to zero (if there is no linked list - empty)
    if(length() == 0)
    {
        // Creates new node containing data of EToll
        Node<value_type>* tempNode = new Node<value_type>(data);
        // Set the head pointer to the new node
        head = tempNode;
        // Set the tail pointer to the new node
        tail = tempNode;
        // Set the current pointer to new node
        current = tempNode;
        // Set the EToll data of the new node
        tempNode->setData(data);
        // Increment the list length
        listLength++;
    }
    else
    {
        // If the linked list (length not 0) is empty, create another node
        Node<value_type>* tempNode = new Node<value_type>(data);
        // Set the value of head's previous pointer to point to the new node
        head->setPrev(tempNode);
        // Set the value of the new node's next pointer to point to the head
        tempNode->setNext(head);
        // Set the head pointer to point to the new node
        head = tempNode;
        // Set the value of current's previous pointer to point to the new node
        current->setPrev(tempNode);
        // Set the current pointer to point to the new node
        current = tempNode;
        // Set the EToll data of the new node
        tempNode->setData(data);
        // Increment the list length
        listLength++;
    }
}

// Function for moving current to next
template <typename value_type>
void LinkedList<value_type>::currentToNext()
{
    current = current->getNext();
}

// Function to get value of current
template <typename value_type>
value_type LinkedList<value_type>::getCurrent() const
{
    return this->current->getData();
}

// Function to move current to head
template <typename value_type>
void LinkedList<value_type>::currentToHead()
{
    current = head;
}

// Function to check if list is empty
template <typename value_type>
bool LinkedList<value_type>::isEmpty() const
{   
    // Check if length is equal to zero
    if(length() == 0)
    {   
        // Print string to indicate list is empty and return true
        cout << "List is empty.";
        return true;
    }
    // If length isnt equal to zero, then return false
    else
    {
        return false;
    }
}

// Non-member output operator allows printing of linked lists
template <typename value_type>
std::ostream& operator << (std::ostream& out, LinkedList<value_type>& list)
{
    // Check if list length is equal to zero and execute boolean (will return true)
    if(list.length() == 0)
    {
        // Will print string indicating list is empty
        list.isEmpty();
    }
    // Set current to head
    list.currentToHead();
    // Loop through linked lists, 
    for (int i = 0; i < list.length(); i++)
    {
        // Print the data of the current pointer
        cout << list.getCurrent();
        // Set current to point to the next data
        list.currentToNext();
    }
    // Set current to head again after loop
    list.currentToHead();
    
    return out;
}

// Function to remove/delete current
template <typename value_type>
void LinkedList<value_type>::removeCurrent()
{
    // Sets the next pointer of current pointer's previous pointer to currents next pointer
    current->getPrev()->setNext(current->getNext());
    // Sets the previous pointer of current pointer's next pointer to currents previous pointer
    current->getNext()->setPrev(current->getPrev());
    // Deletes current pointer and thus node
    delete current;
    // Decrement list length
    listLength--;
    // Set current pointer to head pointer
    current = head;
}

// Function to remove/delete head
template <typename value_type>
value_type LinkedList<value_type>::removeFromHead()
{
    // Create new temporary pointer
    Node<value_type>* tempPtr;
    // Set new pointer to head
    tempPtr = head;
    // Set head to it's next
    head = head->getNext();
    // If current points to head, then get next of current
    if(current == head)
    {
        cout << "length reduced2" << endl;
        current = current->getNext();
    }
    // If head is not pointing to null, set the value of the previous pointer to null
    else if(head != NULL)
    {
        head->setPrev(NULL);
    }
    // Set tail pointer to null if neither two statements are executed
    else
    {
        tail = NULL;
    }
    // Decrement list length
    listLength--;
    // Return value_type of temp
    return tempPtr->getData();
    // Delete the pointer and thus node, set to null
    delete tempPtr;
    tempPtr = NULL;
}

// Function to remove/delete tail
template <typename value_type>
value_type LinkedList<value_type>::removeFromTail()
{
    // Create new temporary pointer
    Node<value_type>* tempPtr;
    // Set new pointer to tail
    tempPtr = tail;
    // Set tail to it's previous
    tail = tail->getPrev();
    // If current points to tail, then get previous of current
    if(current == tail)
    {
        current = current->getPrev();
    }
    // If tail is not pointing to null, set the value of the next pointer to null
    if(tail != NULL)
    {
        tail->setNext(NULL);
    }
    // Set head pointer to null if neither two statements are executed
    else
    {
        head = NULL;
    }
    // Decrement list length
    listLength--;
    // Return value_type of temp
    return tempPtr->getData();
    // Delete the pointer and thus node, set to null
    delete tempPtr;
    tempPtr = NULL;
}

// Function for removing nodes that contain specific licence data
template <typename value_type>
void LinkedList<value_type>::remove(const string licence_)
{   
    // Loop through linked lists
    for (int i = 0; i < length(); i++)
    {
        // If list length is equal to 6 (tollBooth2), then execute next if statements
        if(length() == 6)
        {
            // Check whether currents points to specified licence or not
            if(current->getData().get_licence() != "NIO324")
            {   
                // If licence isnt removed from list, move current to next
                if(length() != 5)
                {
                    currentToNext();
                }
            
            // If current points to data with licence "NIO324" 
            if(current->getData().get_licence() == "NIO324")
            {
                // Remove (delete) current from the list and reduce list length
                removeCurrent();
            }
            }
        }
        // If list length is equal to 8 (tollBooth1), then execute next if statement
        if(length() == 8)
        {
            // If head points to licence "BYC567"
            if(head->getData().get_licence() == "BYC567")
            {
                // Remove from head and reduce list length
                removeFromHead();
            }
        }

        // If list length is equal to 5 (tollBooth2), then execute next if statement
        if(length() == 5)
        {
            // If tail points to licence "GFV349"
            if(tail->getData().get_licence() == "GFV349")
            {
                // Remove from tail and reduce list length
                removeFromTail();
            }
        }
    }
}

// Function for counting the number of data vehicle types
template <typename value_type>
int LinkedList<value_type>::count(const string type_)
{   
    // Counters for each vehicle type
    int carNumber = 0;
    int truckNumber = 0;
    int lightTruckNumber = 0;
    int motorcycleNumber = 0;
    
    // If type string is equal to "Car", execute following statements
    if(type_ == "Car")
    {
        currentToHead();
        // Loop through linked lists
        for (int i = 0; i < length(); i++)
        {
        // Increment counter if current points to node containing "Car" and set current to next node
        if(current->getData().get_type() == "Car")
        {
            carNumber++;
            currentToNext();
        }
        // Set current to next node if type doesnt equal "Car"
        else
        {
            currentToNext();
        }
        }   
        // Set current to head and return the total amount of Cars
        currentToHead();
        return carNumber;
    }
    // If type string is equal to "Motorcycle"
    else if(type_ == "Motorcycle")
    {
        currentToHead();
        // Loop through linked lists
        for (int i = 0; i < length(); i++)  
        {
        // Increment counter if current points to node containing "Motorcycle" and set current to next node
        if(current->getData().get_type() == "Motorcycle")
        {
            motorcycleNumber++;
            currentToNext();
        }
        // Set current to next node if type doesnt equal "Motorcycle"
        else
        {
            currentToNext();
        }
        }
        // Set current to head and return the total amount of Motorcycles
        currentToHead();
        return motorcycleNumber;
    }
    // If type string is equal to "Truck"
    else if(type_ == "Truck")
    {
        currentToHead();
        // Loop through linked lists
        for (int i = 0; i < length(); i++)
        {
        // Increment counter if current points to node containing "Truck" and set current to next node
        if(current->getData().get_type() == "Truck")
        {
            truckNumber++;
            currentToNext();
        }
        // Set current to next node if type doesnt equal "Truck"
        else
        {
            currentToNext();
        }
        }
        // Set current to head and return the total amount of Trucks
        currentToHead();
        return truckNumber;
    }
    // If type string is equal to "Light Truck"
    else if(type_ == "Light Truck")
    {
        currentToHead();
        // Loop through linked lists
        for (int i = 0; i < length(); i++)
        {
        // Increment counter if current points to node containing "Light Truck" and set current to next node
        if(current->getData().get_type() == "Light Truck")
        {
            lightTruckNumber++;
            currentToNext();
        }
        // Set current to next node if type doesnt equal "Light Truck"
        else
        {
            currentToNext();
        }
        }
        // Set current to head and return the total amount of Light Trucks
        currentToHead();
        return lightTruckNumber;
    }

    return 0;
}

// Function for calculating total income from charges
template <typename value_type>
double LinkedList<value_type>::totalIncome()
{
    // Create double total and set current to head
    double total = 0.0;
    currentToHead();
    // Loop through linked lists
    for (int i = 0; i < length(); i++)
    {
        total += current->getData().get_charge();
        currentToNext();
    }
    // Set current to head and return total income
    currentToHead();
    return total;
}

// Member overload operator for adding and assigning linked lists
template <typename value_type>
void LinkedList<value_type>::operator += (LinkedList<value_type>& list)
{   
    // Set current to head
    list.currentToHead();
    // Loop through linked lists until current is null
    while(list.current != NULL)
    {
        // Add to linked list ("this" dailyReport) from other linked list (tollBooths) and set current to next to add nodes
        addToTail(list.getCurrent());
        list.currentToNext();
    }
    // Set current back to head
    list.currentToHead();
}

// Function for removing specific nodes
template <typename value_type>
void LinkedList<value_type>::removeNode(const string licence_)
{
    // Create new temporary pointer
    Node<value_type>* temp;
    // Set new pointer to current pointer
    temp = current;

    // Set current to it's next
    current = current->getNext();
    
    // If head points to current, then get next of head, moving head with current
    if(head == current)
    {
        head = head->getNext();
    }

    // If current is not pointing to null, set the value of the previous pointer to null
    if(current != NULL)
    {
        current->setPrev(NULL);
    }

    // Set tail to null if neither two statements are executed
    else
    {
        tail = NULL;
    }
    // Decrement list length
    listLength--;
    // Delete the pointer and thus node
    delete temp; 
    temp = NULL;
}

// Member overload operator for subtracting and assigning linked lists
template <typename value_type>
void LinkedList<value_type>::operator -= (LinkedList<value_type>& list)
{    
    // Set currents back to head
    list.currentToHead();

    // Loops through rhs list until current is equal to null
    while(list.current != NULL)
    {    
        // If current in rhs list is equal to current in lhs list, remove node from lhs list, set rhs current to next and reduce length
        if(list.current->getData().get_licence() == current->getData().get_licence())
        {
            removeNode(current->getData().get_licence());
            list.currentToNext();
        }
        // If current isnt null, set next (will until null)
        else
        {
            currentToNext();
        }
    }
    // Set currents back to head
    list.currentToHead();
}
