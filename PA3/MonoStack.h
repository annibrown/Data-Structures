// Annika Brown
// 2428684
// annbrown@chapman.edu
// CPSC350-04
// PA3
// monostack class and methods

#ifndef MONO_STACK_H
#define MONO_STACK_H
#include <iostream>

template <typename T>
class MonoStack{
    public:
        MonoStack(); // default constuctor
        MonoStack(int iSize, char o); // overloaded constructor
        ~MonoStack();
        void push(T c); // add to the top
        T pop(); // remove from the top
        T peek(); // return the top without removing
        bool isFull();
        bool isEmpty();
        int size();

    private:
        T* stackArr;
        int count; // number of items currently in the stack
        int maxSize; // max number of things in the stack
        int top; // index of the current top of the stack
        char IorD;
};

// default constructor
template <typename T>
MonoStack<T>::MonoStack(){
    stackArr = new T[5];
    maxSize = 5;
    count = 0;
    top = -1;
    IorD = 'd';
}

// overload constructor
// @param int iSize, size of MonoStack
// @param char o, increasing or decreasing
template <typename T>
MonoStack<T>::MonoStack(int iSize, char o){
    stackArr = new T[iSize];
    maxSize = iSize;
    count = 0;
    top = -1;
    IorD = o;
}

// default destructor
template <typename T>
MonoStack<T>::~MonoStack(){
    std::cout << "deleting stackArr! " << std::endl;
     delete[] stackArr;
}

template <typename T>
bool MonoStack<T>::isFull(){
    return (count == maxSize);
}

template <typename T>
bool MonoStack<T>::isEmpty(){
    return (count == 0);
}

template <typename T>
int MonoStack<T>::size(){
    return count;
}

// push method
// @param T c, item c of type T
// @return void
template <typename T>
void MonoStack<T>::push(T c){
    if(isFull()){
        T* temp = new T[2*maxSize];
        for(int i = 0; i < maxSize; ++i){
            temp[i] = stackArr[i];
        }
        maxSize *= 2;
        delete[] stackArr;
        stackArr = temp;
    }
    while (true) {
        if (isEmpty()) {
            stackArr[++top] = c;
            ++count;
            break;
        }
        if (IorD == 'i' && c <= peek()) {
            if (isEmpty() != true) {
                pop();
            }
        } else if (IorD == 'd' && c >= peek()) {
            if (isEmpty() != true) {
                pop();
            }
        } else {
            stackArr[++top] = c;
            ++count;
            break;
        }
    }
    return;
}

template <typename T>
T MonoStack<T>::pop(){
    --count;
    return stackArr[top--];
}

template <typename T>
T MonoStack<T>::peek(){
    return stackArr[top];
}

#endif