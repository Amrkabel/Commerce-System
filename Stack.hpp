#ifndef STACK_HPP
#define STACK_HPP

template <typename T>
class StkNode
{
public:
    T data;
    StkNode<T>* next;
    StkNode<T>* top;
    void push(StkNode<T>** root,T data);
    int isEmpty(StkNode<T>** root);
    T peek(StkNode<T>** root);
    void pop(StkNode<T>** root);
    void disp(StkNode<T>** root);
};


#endif
