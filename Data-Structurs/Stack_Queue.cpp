#include <iostream>

void main()
{
	printf("Mustafa \n");
}

class Node
{
	int Data;
	Node* next;
	friend class Stack;
	friend class Queue;
};
class Stack
{
private:

	Node* head;
	int n;

public:
	
	Stack()
	{
		head = NULL;
		n = 0;
	}

	void push(int Added_Data)
	{
		n++;
		Node* new_node = new Node;

		new_node->Data = Added_Data;
		new_node->next = head;

		head = new_node;
	}
	int pop()
	{
		n--;

		Node* pointer = head;
		int temp = pointer->Data;

		head = head->next;
		delete pointer;

		return temp;
	}
	bool isEmpty()
	{
		if (n == 0)
			return true;
		return false;
	}
	int Size()
	{
		return n;
	}
};

class Queue
{
private:

	Node * head;
	int n;

public:

	Queue()
	{
		head = NULL;
		n = 0;
	}
	void push(int Added_Data)
	{
		n++;
		Node* new_node = new Node;

		new_node->Data = Added_Data;
		new_node->next = head;
		
		head = new_node;
	}
	int pop()
	{
		n--;

		Node* pointer = head;
		int temp = pointer->Data;

		head = head->next;
		delete pointer;

		return temp;
	}
	bool isEmpty()
	{
		if (n == 0)
			return true;
		return false;
	}
	int Size()
	{
		return n;
	}
};

