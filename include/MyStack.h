#ifndef _MY_STACK_
#define _MY_STACK_

#include "AbsStack.h"

template <class Object>
class MyStack : public AbsStack <Object>{

	private:
		static const int DEFAULT_CAPACITY = 50;
		
		int topIndex;
		int capacity;
		Object * data;

		void doubleData();
	public:
		MyStack() : 
			AbsStack < Object >(),
			topIndex { 0 }, 
			capacity { DEFAULT_CAPACITY },
			data { new Object[capacity] }{};

		~MyStack(){
			delete [] data;
			topIndex = 0;
			capacity = DEFAULT_CAPACITY;
		}
		void push(const Object & x);
		const Object & pop( );
 		const Object & top( ) const;

		bool empty( ) const;
  		void clear( );
};

#include "../src/MyStack.inl"
#endif
