#include "MyStack.h"
#include <iostream>
#include <stdexcept>

// Double data method
template <class Object>
void MyStack<Object>::doubleData(){
	Object * _new = new Object[capacity * 2];
	
	for(auto i (0); i < capacity; ++i)
		_new[i] = data[i];

	capacity *= 2;
	delete data;

	data = _new;
}

// Push method
template <class Object>
void MyStack<Object>::push(const Object & x){
	data[topIndex] = x;
	++topIndex;

	if(topIndex == capacity)
		doubleData();
}

//	Pop method
template <class Object>
const Object & MyStack<Object>::pop( ){
	if(topIndex == 0)
		throw std::runtime_error("The stack is empty!");
	else
		return data[topIndex--];
}

// topIndex method
template <class Object>
const Object & MyStack<Object>::top( ) const{
	if(topIndex == 0)
		throw std::runtime_error("The stack is empty!");
	else
		return data[topIndex - 1];
}

//	Empty method
template <class Object>
bool MyStack<Object>::empty( ) const{
	return !topIndex;
}

//	Clear method
template <class Object>
void MyStack<Object>::clear( ){
	topIndex = 0;
}

