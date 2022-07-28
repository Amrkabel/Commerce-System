#include <iostream>
using namespace std;
#pragma once
template <class T>
struct node
{
	T data;
	node* next;
	node* prev;

	static node* getnode(T newdata)
	{
		node* newnode = (node*)malloc(sizeof(node));
		newnode->data = newdata;
		newnode->prev = NULL;
		newnode->next = NULL;
		return newnode;

	}
};

template <class T>
class deque
{
private:
	node<T>* front;
	node<T>* rear;
	int Size;

public:
	void DeQue()
	{
		front = rear = NULL;
		Size = 0;
	}

	//Checks if the queue is empty
	bool isEmpty()
	{
		return (front == NULL);
	}

	//Checks the size
	int size()
	{
		return Size;
	}

	void insertFront(int data)
	{
		node* newNode<T> = getnode(data);

		if (newNode == NULL)
		{
			cout << "OverFlow\n";
		}

		else
		{
			newNode->next = front;
			front->prev = newNode;
			front = newNode;
		}
		Size++;
	}

	void insertRear(int data)
	{
		node* newNode = getnode(data);

		if (newNode == NULL)
		{
			cout << "OverFlow\n";
		}

		else
		{
			newNode->prev = rear;
			rear->next = newNode;
			rear = newNode;
		}
		Size++;
	}

	void deleteFront()
	{
		if (isEmpty())
		{
			cout << "UnderFlow\n";
		}

		else
		{
			node* temp = front;
			front = front->next;
			if (front == NULL)
			{
				rear = NULL;
			}

			else
			{
				front->prev = NULL;
			}

			free(temp);
			Size--;
		}
	}

	void deleteRear()
	{
		if (isEmpty())
		{
			cout << "UnderFlow\n";
		}

		else
		{
			node* temp = rear;
			rear = rear->prev;

			if (rear == NULL)
			{
				front = NULL;
			}

			else
			{
				rear->next = NULL;
			}
			free(temp);
			Size--;
		}
	}

	int getFront()
	{
		if (isEmpty())
		{
			return -1;
		}

		return front->data;
	}

	int getRear()
	{
		if (isEmpty())
		{
			return -1;
		}

		return rear->data;
	}
};