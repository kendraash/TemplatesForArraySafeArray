#include  <iostream>
#include  <cstdlib>
#include  "array.h"
#include <string>
#include  <math.h>

	//
	// CST 136 - Assignment #2 (test program)
	//
	// Michael Hoffman
	//
	//
	// File: test.cpp
	//
	// Test program for the Array and SafeArray classes.
	//


using  namespace  std;


	//
	// Test valid limits for an Array object with a
	// lower index of zero.
	//
	static void  zeroBasedArrayTest()
	{
		Array<float>  data(5);

		data.set(0, 10.5);
		data.set(3, 20.4);
		data.set(5, 30.3);

		cout << std::endl
			<< "Test1 - "
			<< data.get(0) << ' '
			<< data.get(3) << ' '
			<< data.get(5) << ' '
			<< std::endl;
	}


	//
	// Test valid limits for an Array object with a
	// non-zero, positve lower index.
	//
	static void  positiveBasedArrayTest()
	{
		Array<float>  data(10, 5);

		data.set(5, -10);
		data.set(8, 22);
		data.set(10, 9);

		cout << std::endl
			<< "Test2 - "
			<< data.get(5) << ' '
			<< data.get(8) << ' '
			<< data.get(10) << ' '
			<< std::endl;
	}


	//
	// Test valid limits for an Array object with a
	// non-zero, negative lower index.
	//
	static void  negativeBasedArrayTest()
	{
		Array<float>  data(3, -2);

		data.set(-2, 78);
		data.set(0, -30);
		data.set(3, -8);

		cout << std::endl
			<< "Test3 - "
			<< data.get(-2) << ' '
			<< data.get(0) << ' '
			<< data.get(3) << ' '
			<< std::endl;
	}


	//
	// Display array settings and contents.
	//
	static void  displayArray(const Array<float>  &a, const char  *prompt)
	{
		cout << prompt << ":"
			<< "  L: " << a.lowerBound()
			<< "  U: " << a.upperBound()
			<< "  N: " << a.numElements()
			<< "  S: " << a.size()
			<< endl << "    Contents: ";

		for (int idx = a.lowerBound(); idx <= a.upperBound(); ++idx)
			cout << a.get(idx) << ' ';

		cout << endl;
	}


	//
	// Test the copy constructor for the Array class.
	//
	static void  cctorTest()
	{
		cout << std::endl << "Test 4" << std::endl;

		const int  lower = 7;
		const int  upper = 16;

		Array<float>  data(upper, lower);

		int  idx;

		for (idx = lower; idx <= upper; ++idx)
			data.set(idx, (idx*2));

		displayArray(data, "  Original");

		Array<float>  copy1(data);
		Array<float>  copy2(data);

		cout << endl;
		displayArray(copy1, "  Copy 1");

		cout << endl;
		displayArray(copy2, "  Copy 2");

		cout << std::endl;
	}


	//
	// Test valid limits for a SafeArray object with a
	// non-zero, positive lower index.
	//
	static void  positiveBasedSafeArrayTest()
	{
		SafeArray<float>  data(10, 5);

		data.set(5, -10.3);
		data.set(8, 22.4);
		data.set(10, 9.5);

		cout << "Test5 - "
			<< data.get(5) << ' '
			<< data.get(8) << ' '
			<< data.get(10) << ' '
			<< std::endl;
	}


	//
	// Test for an index limits violation for a
	// SafeArray object.
	//
	static void  safeArrayViolationTest()
	{
		SafeArray<float>  data(10, 5);

		data.set(5, -10.3);
		data.set(8, 22.4);
		data.set(10, 9.5);

		cout << std::endl
			<< "Test6 - "
			<< data.get(5) << ' '
			<< data.get(8) << ' '
			<< std::endl;


		cout << "  Should terminate now!"
			<< std::endl << "  ";

		cout << data.get(11) << std::endl;
	}
	void checkAt()
	{
		Array<float> values(10);
		Array<string> s(6);
		s.at(1) = "Hello ";
		s.at(2) = " world ";
		s.at(3) =  "hi";
		s.at(4) = " kendra ";
		s.at(5) = "!!";

		for (int i = 0; i <= 10; i++)
		{
			values.at(i) = i*3.14;
			cout << "Value in position "<<i<< " of array Values: " << values.at(i) << endl;	
		}
		for (int i = 0; i <= 6; i++)
		{
			cout << s.at(i);
			Array<string> copyS(s);

			cout <<" "<< copyS.at(i)<<endl;
		}
	}
	//
	// main() program
	//
	int  main()
	{
		SafeArray<double> Array(5, 10);

		
		// Testing at function 
		checkAt();

		/*class point{};
		SafeArray<point> data(38, 31);

		data.at(38) = point(8);*/
		
		// Zero-based Array
		zeroBasedArrayTest();


		// Non-zero positive based array
		positiveBasedArrayTest();

		// Non-zero negative based array
		negativeBasedArrayTest();

		// CCTOR
		cctorTest();

		// Non-zero positive safe array
		positiveBasedSafeArrayTest();

		// Violate safe array bounds
		safeArrayViolationTest();

		cout << "If you see this output, something's wrong"
			<< std::endl;
		return 0;
	
	}

