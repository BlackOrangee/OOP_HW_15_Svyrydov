// Part 1
// Create a stack that includes methods for adding (push) and removing (pop) elements. 
// Implement a method called "top" that returns the top element of the stack without removing it.
// 
// Part 2
// Develop a program that simulates the "Undo" and "Redo" functions in a text editor.
// Use two stacks : one for storing user actionsand another for storing undone actions.
// Users can perform actions like adding text, deleting text, etc., 
// and the program should allow them to undoand redo these actions.
//

#include <iostream>
#include "Node.h"

using namespace std;

int main()
{
	// Create a new stack using a linked list and push elements onto it
	Node* stack = new Node("k");
	push(stack, "c");
	push(stack, "a");
	push(stack, "b");
	push(stack, "d");
	push(stack, "e");
	push(stack, "e");
	push(stack, "f");

	// Display the stack elements
	cout << "Stack: ";
	display(stack);

	// Pop an element from the stack and display the updated stack
	cout << "\n\nPop: " << pop(stack);
	cout << "\nStack: ";
	display(stack);

	// Get the top element of the stack without removing it and display the stack
	cout << "\n\nTop: " << top(stack);
	cout << "\nStack: ";
	display(stack);

	// Create a new stack (stack2) for checking balanced braces
	Node* stack2 = nullptr;
	push(stack2, "[");
	push(stack2, "{");
	push(stack2, "}");
	push(stack2, "]");
	push(stack2, "(");
	push(stack2, "[");
	push(stack2, "[");
	push(stack2, "]");
	push(stack2, "]");
	push(stack2, ")");

	// Check if the braces are balanced in the stack2 and display it
	cout << "\n\nBraces Balanced: ";
	if (braces(stack2))
	{
		cout << "yes";
	}
	else
	{
		cout << "no";
	}
	cout << "\nBraces Stack: ";
	display(stack2);

	// Create a new list for text operations and a memory stack
	Node* list = new Node();
	Node* mem = new Node();

	// Add text "Hello" to the list
	push(list, "Hello");
	cout << "\n\nAdd 'Hello':\n" << "Top Element: " << top(list) << endl;

	// Delete text from the list and display the updated list
	deleteText(list, mem);
	cout << "\nDelete:\n" << "Top Element: " << top(list) << endl;

	// Undo the last action (restore deleted text) and display the updated list
	undo(list, mem);
	cout << "\nUndo:\n" << "Top Element: " << top(list) << endl;

	// Redo the last undone action (re-delete the text) and display the updated list
	redo(list, mem);
	cout << "\nRedo:\n" << "Top Element: " << top(list) << endl;

	// Push a new element "Darkness" to the list and display the updated list
	push(list, "Darkness");
	cout << "\nPush 'Darkness':\n" << "Top Element: " << top(list) << endl;

	// Undo the last action (remove "Darkness") and display the updated list
	undo(list, mem);
	cout << "\nUndo:\n" << "Top Element: " << top(list) << endl;

	// Redo the last undone action (re-add "Darkness") and display the updated list
	redo(list, mem);
	cout << "\nRedo:\n" << "Top Element: " << top(list) << endl;


}