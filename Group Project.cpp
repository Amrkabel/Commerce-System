#include "Customers.h"
#include <string>

int main()
{
	deque<customer> list;
	deque<customer>* ptr = &list;

	string w = "Wuehrukhasd";

	string* x = &w;
	string* y = &w;
	string* z = &w;

	string change = "Change";
	string* changeptr = &change;

	newcustomer(ptr, x, y, z);
	customer* search = searchname(ptr, x);
	search->print();
	editname(search, changeptr);
	search->print();

	removeoldest(ptr);
}