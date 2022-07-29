#ifndef __DOUBLELINKEDLIST_HPP__
#define __DOUBLELINKEDLIST_HPP__

#include <iostream>
#include <string>

template <typename T> class Node {
public:
    Node(T i, std::string c, std::string n, std::string e, double p, int q) {
        id = i;
        category = c;
        name = n;
        expDate = e;
        price = p;
        quantity = q;
    }

    ~Node() {

    }

    void print() {
        std::cout << "--------------------------------" << std::endl;
        std::cout << "Category: " << category << std::endl;
        std::cout << "Name: " << name << std::endl;
        std::cout << "Expiry Date: " << expDate << std::endl;
        std::cout << "Price: " << price << std::endl;
        std::cout << "Quantity: " << quantity << std::endl;
        std::cout << "--------------------------------" << std::endl;
    }

    void changePrice(double p) {
        price = p;
    }

    void changeQuantity(int q) {
        quantity = q;
    }

    std::string getId() {
        return id;
    }

    std::string getCategory() {
        return category;
    }

    std::string getName() {
        return name;
    }

    std::string getExpDate() {
        return expDate;
    }

    double getPrice() {
        return price;
    }

    int getQuantity() {
        return quantity;
    }

    T id;
    class Node* next;
    class Node* prev;

    std::string category;
    std::string name;
    std::string expDate;
    double price;
    int quantity;
};

template <typename T> void printList(Node<T>** headRef, std::string c = "all") {
    Node<T>* tail = *headRef;

    while (tail->next != NULL) {
        tail = tail->next;
    }

    while (tail != *headRef) {
        if (tail->getCategory() == c || c == "all") {
            tail->print();
        }
        tail = tail->prev;
    }
    if (tail->getCategory() == c || c == "all") {
        tail->print();
    }
}

template <typename T> void printByPrice(Node<T>** headRef) {
    int last = 0;
    for (int i = 0; i < 100000; i++) {
        Node<T>* tail = *headRef;

        while (tail->next != NULL) {
            tail = tail->next;
        }

        while (tail != *headRef) {
            if (tail->getPrice() < i && tail->getPrice() > last) {
                tail->print();
            }
            tail = tail->prev;
        }
        if (tail->getPrice() < i && tail->getPrice() > last) {
            tail->print();
        }
        last = i;
    }
}

template <typename T> void printByQuantity(Node<T>** headRef) {
    for (int i = 0; i < 100000; i++) {
        Node<T>* tail = *headRef;

        while (tail->next != NULL) {
            tail = tail->next;
        }

        while (tail != *headRef) {
            if (tail->getQuantity() == i) {
                tail->print();
            }
            tail = tail->prev;
        }
        if (tail->getQuantity() == i) {
            tail->print();
        }
    }
}


template <typename T> void push(Node<T>** headRef, T id, std::string c, std::string n, std::string e, double p, int q) {
    Node<T>* newNode = new Node<T>(id, c, n, e, p, q);

    newNode->prev = NULL;

    newNode->next = (*headRef);

    if ((*headRef) != NULL) {
        (*headRef)->prev = newNode;
    }

    (*headRef) = newNode;
}

template <typename T> void deleteNode(Node<T>** headRef, Node<T>* del) {
    if (*headRef == NULL || del == NULL)
        return;

    if (*headRef == del)
        *headRef = del->next;

    if (del->next != NULL)
        del->next->prev = del->prev;

    if (del->prev != NULL)
        del->prev->next = del->next;

    free(del);
    return;
}

template <typename T> Node<T>* search(Node<T>** headRef, std::string n) {
    Node<T>* temp = *headRef;

    while (temp->name != n && temp->next != NULL) {
        temp = temp->next;
    }


    if (temp->name != n) {
        return NULL;
    }

    else {
        return temp;
    }
}


#endif