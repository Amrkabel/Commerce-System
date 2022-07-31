#include <iostream>
using namespace std;

#ifndef STACK_HPP
#define STACK_HPP

template <typename T>
class StkNode
{
public:
    T data;
    StkNode<T>* next;
    StkNode<T>* top;
    static void push(StkNode<T>** root, T data);
    static int isEmpty(StkNode<T>** root);
    static T peek(StkNode<T>** root);
    static void pop(StkNode<T>** root);
    static void disp(StkNode<T>** root);
};


#endif

template <typename T>
void StkNode<T>::push(StkNode<T>** root, T data)
{
    //create new node named temp
    StkNode<T>* temp = new StkNode();
    //stackoverflow condition check
    if (!temp)
    {
        cout << "Error Stack Overflow" << endl;
        EXIT_FAILURE;
    }
    //intialize data
    else
    {
        //push data into temp data field
        temp->data = data;
        temp->next = (*root);
        //make temp as top of stack
        (*root) = temp;
    }
}

template <typename T>
int StkNode<T>::isEmpty(StkNode<T>** root)
{
    return((*root) == NULL);
}

template <typename T>
T StkNode<T>::peek(StkNode<T>** root)
{
    //if stack is not empty return top element
    if (!isEmpty(root))
    {
        return (*root)->data;
    }
    //if empty return error code
    else
    {
        EXIT_FAILURE;
    }
}

template <typename T>
void StkNode<T>::pop(StkNode<T>** root)
{
    StkNode<T>* temp;
    //stackunderflow condition check and return error code
    if ((*root) == NULL)
    {
        cout << "Error Stack Underflow" << endl;
        EXIT_FAILURE;
    }
    else
    {
        temp = (*root);
        (*root) = (*root)->next;
        free(temp);
    }
}

template <typename T>
void StkNode<T>::disp(StkNode<T>** root)
{
    StkNode<T>* temp;

    if ((*root) == NULL)
    {
        cout << "Error Stack Underflow" << endl;
        EXIT_FAILURE;
    }
    else
    {
        temp = (*root);
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
    }
}