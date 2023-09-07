#pragma once

#include <iostream>
using namespace std;

class Node
{
public:
	string value;  // The value stored in the node
	Node* next;   // Pointer to the next node in the linked list

	// Constructors for creating Node objects
	Node();
	Node(string);
};

// Function to push a new element onto the stack represented by a linked list
void push(Node*&, string);

// Function to get the value at the top of the stack (linked list)
string top(Node*);

// Function to pop and remove the top element from the stack (linked list)
string pop(Node*&);

// Function to display the elements in the linked list
void display(Node*);

// Function to check if opening and closing braces are balanced in the linked list
bool braces(Node*);

// Function to clean and remove all elements from a linked list
void clean(Node*&);

// Function to delete text by moving it from one linked list to another
void deleteText(Node*&, Node*&);

// Function to undo the last action by moving text from one linked list back to another
void undo(Node*&, Node*&);

// Function to redo the last undone action by moving text from one linked list to another
void redo(Node*&, Node*&);

