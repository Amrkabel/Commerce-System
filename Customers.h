#pragma once
#include "Deque.h"
#include <string.h>
#include "Stack.h"

struct customer
{
	int id = 0;
	string* name;
	string* email;
	string* phone;

	void print()
	{
			cout << "---------------------------" << endl;
			cout << id << endl;
			cout << *name << endl;
			cout << *email << endl;
			cout << *phone << endl;
			cout << "---------------------------" << endl;
	}
};

deque<customer>* newcustomer(deque<customer>* list, string* name, string* email, string* phone)
{
	customer* x = new customer;

	if (list->isEmpty())
	{
		x->id = 1;
		x->name = name;
		x->email = email;
		x->phone = phone;

		list->insertFront(*x);
		return NULL;
	}

	else
	{
		//Definitions
		customer prev = list->getFront();

		x->id = prev.id + 1;
		x->name = name;
		x->email = email;
		x->phone = phone;

		list->insertFront(*x);
		return list;
	}
}

void removeoldest(deque<customer>* list)
{
	if (list->isEmpty())
	{
		cout << "There are no customers!\n";
	}

	else
	{
		list->deleteRear();
	}
}

void removenewest(deque<customer>* list)
{
	if (list->isEmpty())
	{
		cout << "There are no customers!\n";
	}

	else
	{
		list->deleteFront();
	}
}

customer* searchid(deque<customer>* list, int id)
{
	StkNode<customer>* stack = NULL;
	customer* answer = NULL;

	if (list->isEmpty())
	{
		cout << "There are no customers!\n";
		return NULL;
	}

	else
	{
		if (id > (list->getFront().id / 2))
		{
			while (!(list->isEmpty()) and (list->getFront().id != id))
			{
				StkNode<customer>::push(&stack, list->getFront());
				list->deleteFront();
			}

			if (list->getFront().id == id)
			{
				customer temp = list->getFront();
				answer = &(temp);
			}

			while (!StkNode<customer>::isEmpty(&stack))
			{
				list->insertFront(StkNode<customer>::peek(&stack));
				StkNode<customer>::pop(&stack);
			}

			return answer;
		}

		else
		{
			while (!(list->isEmpty()) and (list->getRear().id != id))
			{
				StkNode<customer>::push(&stack, list->getRear());
				list->deleteFront();
			}

			if (list->getRear().id == id)
			{
				customer temp = list->getRear();
				answer = &(temp);
			}

			while (!StkNode<customer>::isEmpty(&stack))
			{
				list->insertRear(StkNode<customer>::peek(&stack));
				StkNode<customer>::pop(&stack);
			}

			return answer;
		}
	}
}

customer* searchname(deque<customer>* list, string* name)
{
	StkNode<customer>* stack = NULL;
	customer* answer = NULL;

	if (list->isEmpty())
	{
		cout << "There are no customers!\n";
		return NULL;
	}

	else
	{
		while (!(list->isEmpty()) && (list->getFront().name != name))
		{
			StkNode<customer>::push(&stack, list->getFront());
			list->deleteFront();
		}

		if (list->getFront().name == name)
		{
			customer temp = list->getFront();
			answer = &temp;
		}

		while (!StkNode<customer>::isEmpty(&stack))
		{
			list->insertFront(StkNode<customer>::peek(&stack));
			StkNode<customer>::pop(&stack);
		}

		return answer;
	}
}

customer* searchemail(deque<customer>* list, string* email)
{
	StkNode<customer>* stack = NULL;
	customer* answer = NULL;

	if (list->isEmpty())
	{
		cout << "There are no customers!\n";
		return NULL;
	}

	else
	{
		while (!(list->isEmpty()) and (list->getFront().email != email))
		{
			StkNode<customer>::push(&stack, list->getFront());
			list->deleteFront();
		}

		if (list->getFront().name == email)
		{
			customer temp = list->getFront();
			answer = &(temp);
		}

		while (!StkNode<customer>::isEmpty(&stack))
		{
			list->insertFront(StkNode<customer>::peek(&stack));
			StkNode<customer>::pop(&stack);
		}

		return answer;
	}
}

customer* searchphone(deque<customer>* list, string* phone)
{
	StkNode<customer>* stack = NULL;
	customer* answer = NULL;

	if (list->isEmpty())
	{
		cout << "There are no customers!\n";
		return NULL;
	}

	else
	{
		while (!(list->isEmpty()) and (list->getFront().email != phone))
		{
			StkNode<customer>::push(&stack, list->getFront());
			list->deleteFront();
		}

		if (list->getFront().name == phone)
		{
			customer temp = list->getFront();
			answer = &(temp);
		}

		while (!StkNode<customer>::isEmpty(&stack))
		{
			list->insertFront(StkNode<customer>::peek(&stack));
			StkNode<customer>::pop(&stack);
		}

		return answer;
	}
}

void editid(customer* person, int id)
{
	person->id = id;
}

void editname(customer* person, string* name)
{
	person->name = name;
}

void editemail(customer* person, string* email)
{
	person->email = email;
}

void editphone(customer* person, string* phone)
{
	person->phone = phone;
}