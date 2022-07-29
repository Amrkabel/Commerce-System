#include "UserInterface.hpp"

void clearScreen() {
	system("cls");
}

void wait() {
	system("pause");
}

void mainMenu() {
	Node<int>* head = NULL;
	Node<int>* temp = NULL;

	int id = 0;

	std::string category;
	std::string name;
	std::string date;
	double price;
	int quantity;

	while (true) {
		clearScreen();

		std::cout << "Main Menu" << std::endl << "------------------------------------------------------------------" << std::endl;
		std::cout << "1 -> Add Entry" << std::endl << "2 -> Remove Entry" << std::endl << "3 -> Modify Entry" << std::endl << "4 -> Sort Database" << std::endl << "5 -> Print Database" << std::endl << "6 -> Save to .JSON" << std::endl << "7 -> Load from .JSON" << std::endl << "8 -> Exit" << std::endl << ">> ";

		int in;
		std::cin >> in;

		switch (in) {
		default:
			clearScreen();

		case 1:
			clearScreen();

			std::cout << "Add Entry" << std::endl << "------------------------------------------------------------------" << std::endl;
			std::cout << "Please input the required fields below:" << std::endl;

			std::cout << "Category: ";
			std::cin >> category;

			std::cout << "Name: ";
			std::cin >> name;

			std::cout << "Date: ";
			std::cin >> date;

			std::cout << "Price: ";
			std::cin >> price;

			std::cout << "Quantity: ";
			std::cin >> quantity;

			push<int>(&head, id, category, name, date, price, quantity);

			id++;

			wait();

			break;

		case 2:
			clearScreen();

			std::cout << "Remove Entry" << std::endl << "------------------------------------------------------------------" << std::endl;
			std::cout << "Please enter the name of the entry to remove from the database:\n\n>>";
			std::cin >> name;

			temp = search(&head, name);
			deleteNode(&head, temp);

			wait();

			break;

		case 3:
			clearScreen();

			std::cout << "Modify Entry" << std::endl << "------------------------------------------------------------------" << std::endl;
			std::cout << "Please enter the name of the entry you would like to modify\n\n>> ";
			std::cin >> name;
			std::cout << "Which attribute of " << name << " would you like to modify\n1 - Price\n2 - Quantity\n\n>> ";
			int x;
			std::cin >> x;

			temp = search(&head, name);

			if (x == 1) {
				std::cout << "Enter new price:\n\n>> ";
				double y;
				std::cin >> y;
				temp->changePrice(y);
			}

			else if (x == 2) {
				std::cout << "Enter new quantity:\n\n>> ";
				int y;
				std::cin >> y;
				temp->changeQuantity(y);
			}

			wait();

			break;

		case 4:
			clearScreen();

			std::cout << "Sort" << std::endl << "------------------------------------------------------------------" << std::endl;
			std::cout << "Dpo you wish to sort by Category, Price, or Quantity?\n1 - Category\n2 - Price\n3 - Quantity\n\n>> ";
			int choice;
			std::cin >> choice;
			switch (choice) {
			default:
				break;
			case 1:
				std::cout << "Printing by Category" << std::endl;
				std::cout << "Please input a category to sort by:\n>> ";
				std::cin >> category;

				printList<int>(&head, category);
				break;

			case 2:
				std::cout << "Printing by Price" << std::endl;
				printByPrice(&head);
				break;

			case 3:
				std::cout << "Printing by Quantity" << std::endl;
				printByQuantity(&head);
				break;

			}

			wait();

			break;

		case 5:
			clearScreen();

			std::cout << "Print Database" << std::endl << "------------------------------------------------------------------" << std::endl;

			printList<int>(&head);

			wait();

			break;

		case 6:
			break;

		case 7:
			break;

		case 8:
			clearScreen();

			return;
		}
	}
}
