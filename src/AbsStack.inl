#include "AbsStack.h"
#include <iostream>
#include <stdexcept>

// Double data method
template <class Object>
void MyStack<Object>::doubleData(){
	Object * _new = new Object[capacity * 2];
	
	for(auto i (0); i < capacity; ++i)
		_new = data[i];

	capacity *= 2;
	delete data;

	data = _new;
}

// Push method
template <class Object>
void MyStack<Object>::push(const Object & x){
	data[top] = x;
	++top;

	if(top == capacity)
		doubleData();
}

//	Pop method
typename <class Object>
const MyStack<Object>::Object & pop( ){
	if(top == 0)
		throw std::runtime_error("The stack is empty!");
	else
		return data[top--];
}

// Top method
typename <class Object>
const MyStack<Object>::Object & top( ) const{
	if(top == 0)
		throw std::runtime_error("The stack is empty!");
	else
		return data[top - 1];
}

//	Empty method
typename <class Object>
bool MyStack<Object>::empty( ) const{
	return !top;
}

//	Clear method
typename <class Object>
void MyStack<Object>::clear( ){
	top = 0;
}



