
//
// Assignment  :  #3
// Class       :  CST 136
//
// Author      :  Kendra Ash 
//
// File        :  array.h
//
//
// Description :  Declarations for the Array and SafeArray Templates.
//

#ifndef  array_H

#define  array_H


#include "refCounter.h"

/*
Constraints for the Type datatype for the Array<> template class:
- The Array function can only be created with integer arguments for lower and upper bounds. 
-The set and get function must alway be passed integer index arguments. 

-The at function also must be passed index of type int. 
*/
template<class ELEMENT_TYPE>
class Array
{
	public :
		Array(int upper, int lower=0);
		~Array();
		void set(const int &index, ELEMENT_TYPE value);
		ELEMENT_TYPE get(int index) const;
		int lowerBound() const;
		int upperBound() const;
		int size() const;
		int numElements() const
		{
			return abs(upperBound() - lowerBound()) + 1;
		}
		
		ELEMENT_TYPE &at(int index);


	private :
		const int m_upper;
		const int m_lower; 
		ELEMENT_TYPE *m_index; // pointer to the data 

		int  realIndex(int  index)  const 
		{
			return  index - m_lower; 
		}

		RefCounter m_refCounter;

};
// ------------------------------------ SafeArray -------------------------------------------
/*
Constraints for the Type datatype for the Array<> template class:
- The SafeArray function can only be created with integer arguments for lower and upper bounds.
-The set and get function must always be passed integer index arguments and be less than upper bound and lower then lower bound. 
*/
template<class ELEMENT_TYPE>
class SafeArray : Array<ELEMENT_TYPE>
{
	public:
		SafeArray(int upper, int lower = 0);
		void set(const int &index, ELEMENT_TYPE value);
		ELEMENT_TYPE get(int index) const;

	private:

	 void  m_checkRange(int index) const 
		{
			if (index < lowerBound() || index > upperBound())
			{
				cout << "Index out of range " << endl;
				exit(EXIT_FAILURE);
			}
		}
};

#include "array.inc"

#endif