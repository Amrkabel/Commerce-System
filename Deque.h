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
		node* newnode = new node<T>();
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
	deque()
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

	void insertFront(T data)
	{
		node<T>* newNode = node<T>::getnode(data);

		if (newNode == NULL)
			cout << "OverFlow\n";
		else
		{
			// If deque is empty
			if (front == NULL)
				rear = front = newNode;

			// Inserts node at the front end
			else
			{
				newNode->next = front;
				front->prev = newNode;
				front = newNode;
			}

			// Increments count of elements by 1
			Size++;
		}
	}

	void insertRear(T data)
	{
		node<T>* newNode = node<T>::getnode(data);

		if (newNode == NULL)
		{
			cout << "OverFlow\n";
		}

		else
		{
			// If deque is empty
			if (rear == NULL)
				front = rear = newNode;

			// Inserts node at the rear end
			else
			{
				newNode->prev = rear;
				rear->next = newNode;
				rear = newNode;
			}

			Size++;
		}
	}

	void deleteFront()
	{
		if (isEmpty())
		{
			cout << "UnderFlow\n";
		}

		else
		{
			node<T>* temp = front;
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
			node<T>* temp = rear;
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

	T getFront()
	{
		T x;
		if (isEmpty())
		{
			cout << "This list list is empty\n";
			return x;
		}

		return front->data;
	}

	T getRear()
	{
		T x;
		if (isEmpty())
		{
			cout << "This list list is empty\n";
			return x;
		}

		return rear->data;
	}

	void erase()
	{
		rear = NULL;
		while (front != NULL)
		{
			node* temp = front;
			front = front->next;
			free(temp);
		}
		Size = 0;
	}
};