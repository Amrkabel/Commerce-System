#pragma once
#include "Deque.h"
#include <string.h>

struct customer
{
	int id;
	string name;
	string email;
	string phone;
};

deque<customer>* newcustomer(deque<customer>* list, string name, string email, string phone)
{
	customer x;

	if (list->isEmpty())
	{
		x.id = 1;
		x.name = name;
		x.email = email;
		x.phone = phone;

		list->insertFront(x);
		return NULL;
	}

	else
	{
		//Definitions
		customer prev = list->getFront();

		x.id = prev.id + 1;
		x.name = name;
		x.email = email;
		x.phone = phone;

		list->insertFront(x);
		return list;
	}
}