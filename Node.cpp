#include "Node.h"

// Constructor for an empty stack node
Node::Node()
{
	value = "";
	next = nullptr;
}

// Constructor for a stack node with a given value
Node::Node(string value)
{
	this->value = value;
	next = nullptr;
}

// Function to push a value onto the stack
void push(Node*& head, string value)
{
	// Create a new node with the given value
	Node* n = new Node(value);

	// If the stack is empty, make the new node the head
	if (head == nullptr)
	{
		head = n;
		return;
	}

	// Set the new node's 'next' pointer to the current head
	n->next = head;

	// Update the head to point to the new node
	head = n;
}

// Function to get the value at the top of the stack without removing it
string top(Node* head)
{
	// Return the value of the head node
	return head->value;
}

// Function to pop (remove) the value at the top of the stack
string pop(Node*& head)
{
	// Get the value of the head node
	string value = head->value;

	// Update the head to point to the next node (removing the current head)
	head = head->next;

	// Return the removed value
	return value;
}

// Function to display the contents of the stack
void display(Node* head)
{
	Node* slider = head;

	// Traverse the stack and print each value
	while (slider != nullptr)
	{
		cout << slider->value << " ";
		slider = slider->next;
	}
}

// Function to check if the braces in the linked list are balanced
bool braces(Node* head)
{
	// Initialize counters for each type of brace
	int counter_1 = 0; // Counter for '('
	int counter_2 = 0; // Counter for '['
	int counter_3 = 0; // Counter for '{'

	// Traverse the linked list
	while (head != nullptr)
	{
		// Check if the current node contains an opening brace '('
		if (head->value == "(")
		{
			counter_1++;
		}

		// Check if the current node contains an opening brace '['
		if (head->value == "[")
		{
			counter_2++;
		}

		// Check if the current node contains an opening brace '{'
		if (head->value == "{")
		{
			counter_3++;
		}

		// If any of the counters is greater than 0, it means there's an opening brace
		if (counter_1 > 0 || counter_2 > 0 || counter_3 > 0)
		{
			return false; // Braces are not balanced, return false
		}

		// Check if the current node contains a closing brace ')'
		if (head->value == ")")
		{
			--counter_1;
		}

		// Check if the current node contains a closing brace ']'
		if (head->value == "]")
		{
			--counter_2;
		}

		// Check if the current node contains a closing brace '}'
		if (head->value == "}")
		{
			--counter_3;
		}

		// Move to the next node in the linked list
		head = head->next;
	}

	// If any of the counters is not zero, it means there are unmatched braces
	if (counter_1 != 0 || counter_2 != 0 || counter_3 != 0)
	{
		return false; // Braces are not balanced, return false
	}

	// If all opening braces have matching closing braces, return true (braces are balanced)
	return true;
}

// Function to delete text from 'head1' and push it onto 'head2'
void deleteText(Node*& head1, Node*& head2)
{
	// Pop the top element from 'head1' and push it onto 'head2'
	push(head2, pop(head1));
}

// Function to undo the last action by moving text from 'head2' back to 'head1'
void undo(Node*& head1, Node*& head2)
{
	// Pop the top element from 'head2' and push it back onto 'head1'
	push(head1, pop(head2));

	// Clean 'head2' by removing all its elements
	clean(head2);
}

// Function to redo the last undone action by moving text from 'head1' to 'head2'
void redo(Node*& head1, Node*& head2)
{
	// Pop the top element from 'head1' and push it onto 'head2'
	push(head2, pop(head1));

	// Clean 'head2' by removing all its elements
	clean(head2);
}

// Function to clean a linked list by removing all its elements
void clean(Node*& head)
{
	// Traverse the linked list and remove all elements
	while (head != nullptr)
	{
		head = head->next;
	}

	// Create a new empty node as the head of the linked list
	head = new Node();
}
