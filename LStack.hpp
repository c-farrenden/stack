// LStack.hpp
/*******************************/
// Name: Connor Farrenden
// Course: SENG1120 - Assignment 2
// Student Number: c3374676
// Description: This is the hpp file for the stack

//Include contents of LinkedList.h
#include "LinkedList.h"

//Include contents of LStack.h
#include "LStack.h"

// Constructor - initialises private members (LinkedList)
template <typename value_type>
LStack<value_type>::LStack()
{       
    data = LinkedList<value_type>();
}

// Loops stack and pops off each node till null (empty stack)
template <typename value_type>
LStack<value_type>::~LStack()
{
    while(size() != 0)
    {
        pop();
    }
}

// Adds data to the top of stack using addToHead()
template <typename value_type>
void LStack<value_type>::push(const value_type& top)
{
    data.addToHead(top);
}

// Returns data from the top of stack using getHead()
template <typename value_type>
value_type LStack<value_type>::peek() const
{
    return data.getHead();
}

// Removes and returns data from the top of stack with removeFromHead()
template <typename value_type>
value_type LStack<value_type>::pop()
{
    return data.removeFromHead();
}

// Returns length of stack, determinant of LL size
template <typename value_type>
int LStack<value_type>::size() const
{
    return data.length();
}

// Non-member output operator allows printing of stacks
template <typename value_type>
std::ostream& operator << (std::ostream& out, LStack<value_type>& stack) 
{
    // Creates a copy of stack (temp stack)
    LStack<value_type> tempStack = stack;
    // Check if stack is empty
    if(stack.size() == 0)
    {
        // Will print string indicating list is empty
        stack.isEmpty();
    }
    // Loops through stack, printing and then removing data from the top of temporary stack
    for (int i = 0; i < stack.size(); i++)
    {
        cout << tempStack.peek();
        tempStack.pop();
    }
    
    return out;
}

// Checks if stack is empty
template <typename value_type>
bool LStack<value_type>::isEmpty() const
{   
    // Check if length is equal to zero
    if(size() == 0)
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

// Function for removing nodes from stack that contain specific licence data
template <typename value_type>
void LStack<value_type>::remove(const string licence_)
{
    // Check if stack is empty
    if(size() == 0)
    {
        isEmpty();
    }
    // Create empty temp stack
    LStack<value_type> tempStack;
    // Check length of stack
    if(size() == 6)
    {
        // Loop until specified licence is found
        while(peek().get_licence() != "NIO324")
        {
            // Remove from top of stack and assign to temp variable
            value_type temp = pop();
            // Push the data of temp variable to temp stack
            tempStack.push(temp);
        }
        // If specificed licence is found, remove it from the stack
        if(peek().get_licence() == "NIO324")
        {
            // Remove from stack
            pop();
        }
        // Loop until stack has all added nodes back (length reduced by 1)
        while(size() != 5)
        {
            // Create temp variable to store value removed from temp stack
            value_type temp = tempStack.pop();
            // Push the temp value back onto the main stack
            push(temp);
        }

        return;
    }
    // Check length of stack
    else if(size() == 5)
    {
        // Loop until specified licence is found
        while(peek().get_licence() != "GFV349")
        {
            // Remove from top of stack and assign to temp variable
            value_type temp = pop();
            // Push the data of temp variable to temp stack
            tempStack.push(temp);
        }
        // If specificed licence is found, remove it from the stack
        if(peek().get_licence() == "GFV349")
        {
            // Remove from stack
            pop();
        }
        // Loop until stack has all added nodes back (length reduced by 1)
        while(size() != 4)
        {
            // Create temp variable to store value removed from temp stack
            value_type temp = tempStack.pop();
            // Push the temp value back onto the main stack
            push(temp);
        }

        return;
    }
    // Check length of stack
    else if(size() == 8)
    {
        // Loop until specified licence is found
        while(peek().get_licence() != "BYC567")
        {
            // create temp value to store removed node from main stack
            value_type temp = pop();
            // push the temp node onto the temp stack
            tempStack.push(temp);
        }

        if(peek().get_licence() == "BYC567")
        {
            // pop off main stack (remove it)
            pop();
        }
        // loop to add back to the main stack (what was removed)
        while(size() != 7)
        {
            // create temp value to store value removed from temp stack
            value_type temp = tempStack.pop();
            // push the temp value onto the main stack
            push(temp);
        }       

        return;
    }
}

// Member overload operator for adding and assigning stacks
template <typename value_type>
void LStack<value_type>::operator +=(LStack<value_type>& stack)
{
    // Create temp stack copy of stack
    LStack<value_type> tempStack = stack;
    // Loop until temp stack is empty
    while(tempStack.size() != 0)
    {
        // Add each node from temp stack to stack (LHS to RHS)
        push(tempStack.pop());
    }
}

// Member overload operator for subtracting and assigning stacks
template <typename value_type>
void LStack<value_type>::operator -=(LStack<value_type>& stack)
{
    // Create temp stack copy of stack
    LStack<value_type> tempStack = stack;
    // Loop through stack until its empty
    while(size() != 0)
    {
        // If RHS stack is equal to LHS in (licence determinant), remove node from LHS stack
        if(tempStack.peek().get_licence() == peek().get_licence())
        {
            tempStack.pop();
        }
        // If not equal, remove from stack to get next node and check
        else
        {
            pop();
        }
    }
}

// Calculates total income from charges
template <typename value_type>
double LStack<value_type>::totalIncome()
{
    // Iniatilise total
    double total = 0.0;
    // Create empty temp stack
    LStack<value_type> tempStack;
    // Loop through stack until empty
    while(size() != 0)
    {
        // Create temp variable to store each removed node from stack
        value_type temp = pop();
        // Push temp value onto temp stack
        tempStack.push(temp);
    }
    // Check if stack is empty
    if(size() == 0)
    {
        // Loop until temp stack is empty
        while(tempStack.size() != 0)
        {
            // Add the charge value from node in temp stack to total
            total += tempStack.peek().get_charge();
            // Store each removed node from temp stack to temp variable
            value_type temp = tempStack.pop();
            // Add the node back onto the stack
            push(temp);
        }
    }
    // Return total income from charges
    return total;
}

// Counts the number of vehicle types
template <typename value_type>
int LStack<value_type>::count(const string type_)
{
    // Initialises counters for each type
    int carNumber = 0;
    int truckNumber = 0;
    int lightTruckNumber = 0;
    int motorcycleNumber = 0;
    // Create empty stack
    LStack<value_type> tempStack;
    // Check if type is equal to "Car"
    if(type_ == "Car")
    {
        // Loops through stack until its empty
        while(size() != 0)
        {
            // Remove from stack and assign to temp variable
            value_type temp = pop();
            // Pushes the temp node onto the temp stack
            tempStack.push(temp);
        }
        // Check if stack is empty
        if(size() == 0)
        {
            // Loop through temp stack until its empty
            while(tempStack.size() != 0)
            {
                // Check if data of stack is of type "Car"
                if(tempStack.peek().get_type() == "Car")
                {
                    // Increment car counter
                    carNumber++;
                    // Remove from temp stack and assign to temp variable
                    value_type temp = tempStack.pop();
                    // Pushes node back onto main stack
                    push(temp);
                }
                else
                {
                    // Remove from temp stack and assign to temp variable
                    value_type temp = tempStack.pop();
                    // Push back onto main stack
                    push(temp);
                }
            }
        }
        // Return number of cars
        return carNumber;
    }
    // Check if type is equal to "Motorcycle"
    else if(type_ == "Motorcycle")
    {   
        // Loops through stack until its empty
        while(size() != 0)
        {
            // Remove from stack and assign to temp variable
            value_type temp = pop();
            // Pushes the temp node onto the temp stack
            tempStack.push(temp);
        }
        // Check if stack is empty
        if(size() == 0)
        {
            // Loop through temp stack until its empty
            while(tempStack.size() != 0)
            {
                // Check if data of stack is of type "Motorcycle"
                if(tempStack.peek().get_type() == "Motorcycle")
                {
                    // Increment motorcycle counter
                    motorcycleNumber++;
                    // Remove from temp stack and assign to temp variable
                    value_type temp = tempStack.pop();
                    // Pushes node back onto main stack
                    push(temp);
                }
                else
                {
                    // Remove from temp stack and assign to temp variable
                    value_type temp = tempStack.pop();
                    // Push back onto main stack
                    push(temp);
                }
            }
        }
        // Return number of motorcycles
        return motorcycleNumber;
    }
    // Check if type is equal to "Light Truck"
    else if(type_ == "Light Truck")
    {
        // Loops through stack until its empty
        while(size() != 0)
        {
            // Remove from stack and assign to temp variable
            value_type temp = pop();
            // Pushes the temp node onto the temp stack
            tempStack.push(temp);
        }
        // Check if stack is empty
        if(size() == 0)
        {
            // Loop through temp stack until its empty
            while(tempStack.size() != 0)
            {
                // Check if data of stack is of type "Light Truck"
                if(tempStack.peek().get_type() == "Light Truck")
                {
                    // Increment light truck counter
                    lightTruckNumber++;
                    // Remove from temp stack and assign to temp variable
                    value_type temp = tempStack.pop();
                    // Pushes node back onto main stack
                    push(temp);
                }
                else
                {
                    // Remove from temp stack and assign to temp variable
                    value_type temp = tempStack.pop();
                    // Push back onto main stack
                    push(temp);
                }
            }
        }
        // Return number of light trucks
        return lightTruckNumber;
    }
    // Check if type is equal to "Truck"
    else if(type_ == "Truck")
    {
        // Check if stack is empty
        while(size() != 0)
        {
            // Remove from stack and assign to temp variable
            value_type temp = pop();
            // Pushes the temp node onto the temp stack
            tempStack.push(temp);
        }
        // Check if stack is empty
        if(size() == 0)
        {
            // Loop through temp stack until its empty
            while(tempStack.size() != 0)
            {
                // Check if data of stack is of type "Truck"
                if(tempStack.peek().get_type() == "Truck")
                {
                    // Increment truck counter
                    truckNumber++;
                    // Remove from temp stack and assign to temp variable
                    value_type temp = tempStack.pop();
                    // Pushes node back onto main stack
                    push(temp);
                }
                else
                {
                    // Remove from temp stack and assign to temp variable
                    value_type temp = tempStack.pop();
                    // Push back onto main stack
                    push(temp);
                }
            }
        }
        // Return number of trucks
        return truckNumber;
    } 

    return 0;
}