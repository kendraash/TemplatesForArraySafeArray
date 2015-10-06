//
// Assignment  :  #3
// Class       :  CST 136
//
// Author      :  Kendra Ash 
//
// File        :  array.inc
//
//
// Description :  Member function declarations for the template.
//

#include "array.h"
#include <iostream>
#include <cstdlib>

using namespace std;

// Constructor Array, allocating memory 

template<class  ELEMENT_TYPE>
Array<ELEMENT_TYPE>::Array(int upper, int lower) : m_upper(upper), m_lower(lower), m_index(new ELEMENT_TYPE[numElements()])
{
	if (!m_index)
	{
		cout << "Error allocating memory" << endl;
		exit(EXIT_FAILURE);
	}
	
}
// Destructor
template<class  ELEMENT_TYPE>
Array<ELEMENT_TYPE>:: ~Array()
{
	if (m_refCounter.onlyInstance())
		delete[] m_index;
}
// Set function that takes index and sets it to the specified value
template<class  ELEMENT_TYPE>
void Array<ELEMENT_TYPE>::set(const int &index, ELEMENT_TYPE value)
{
	m_index[realIndex(index)] = value;

}
template<class  ELEMENT_TYPE>
ELEMENT_TYPE Array<ELEMENT_TYPE>::get(int index) const
{
	return m_index[realIndex(index)]; // returns the value stored in the array m_index at that index

}
template<class  ELEMENT_TYPE>
int Array<ELEMENT_TYPE>::lowerBound() const
{
	return m_lower;
}
template<class  ELEMENT_TYPE>
int Array<ELEMENT_TYPE>::upperBound()const
{	
	return m_upper; 
}
template<class  ELEMENT_TYPE>
int Array<ELEMENT_TYPE>::size() const
{
	// number of elements times the number of bytes for the ELEMENT_TYPE  
	return sizeof(ELEMENT_TYPE)*numElements();
}
template<class  ELEMENT_TYPE>
ELEMENT_TYPE& Array<ELEMENT_TYPE>::at(int index) 
{
	return m_index[index];
}
// ------------------------------------ SafeArray -------------------------------------------
// Allocating memory
template<class    ELEMENT_TYPE>
SafeArray<ELEMENT_TYPE>::SafeArray(int upper, int lower) : Array(upper, lower)
{
}

// Set function that includes bound checking
template<class  ELEMENT_TYPE>
void SafeArray<ELEMENT_TYPE>::set(const int &index, ELEMENT_TYPE value)
{
	m_checkRange(index);
	Array::set(index, value);

}
// Get function that includes bound checking 
template<class  ELEMENT_TYPE>
ELEMENT_TYPE SafeArray<ELEMENT_TYPE>::get(int index) const
{
	m_checkRange(index);
	
	return Array::get(index);
}
