/*
Name: Muhammad Taha
Roll No: 22I-0870
Section: D
Assignment - 3
*/

#ifndef ARRAY_H_
#define ARRAY_H_
#include<iostream>
using namespace std;


class Array
{
	int* array;
	int ArraySize;
	// think about the private data members...
	public:
		// provide definitions of following functions...
		Array(); // a default constructor
		Array(int size); // a parameterized constructor initializing an Array of predefined size
		Array(int *arr, int size); // initializes the Array with an existing Array
		Array(const Array &); // copy constructor
		int size();
		int& operator[](int i); //returns the integer at index after checking the out of range error
		int& operator[](int i)const;
		const Array & operator=(const Array&); //copy the array
		Array operator+(const Array&); //adds two Array
		Array operator-(const Array&); //subtracts two Array
		Array operator++(); //adds one to each element of Array
		Array operator++(int); //adds one to each element of Array
		Array& operator--(int); //subtracts one from each element of array
		bool operator==(const Array&)const; //returns true if two arrays are same
		bool operator!(); // returns true if the Array is empty
		void operator+=(const Array&); //adds two Array
		void operator-=(const Array&); //subtracts two Array
		int operator()(int idx, int val); /* erases the value val at idx. Returns 1 for a successful //deletion and
		-1 if idx does not exists or is invalid. Shift the elements after idx to the left.*/
		~Array(); // destructor...
};

ostream& operator<<(ostream& input, const Array&); //Inputs the Array
istream& operator>>(istream& ouput, Array&); //Outputs the Array

#endif
