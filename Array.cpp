/*
Name: Muhammad Taha
Roll No: 22I-0870
Section: D
Assignment - 3
*/

#include "Array.h"

Array::Array()
{
	ArraySize = 0;
	array = new int[ArraySize];
}

Array::Array(int size)
{
	ArraySize = size;
	array = new int[ArraySize];
	for (int initialize = 0; initialize < ArraySize; initialize++)
	{
		array[initialize] = 0;
	}
}

Array::Array(int *arr, int size)
{
	ArraySize = size;
	array = new int[ArraySize];
	for (int copy = 0; copy < size; copy++)
	{
		array[copy] = arr[copy];
	}
}

Array::Array(const Array & Arr)
{
	ArraySize = Arr.ArraySize;
	array = new int[ArraySize];
	for (int copy = 0; copy < ArraySize; copy++)
	{
		array[copy] = Arr.array[copy];
	}
}

int Array::size()
{
	return ArraySize;
}

int& Array::operator[](int i)
{
	return array[i];
}

int& Array::operator[](int i)const
{
	return array[i];
}

const Array & Array::operator=(const Array& copyArray)
{
	Array Equal(array, ArraySize);
	return Equal;
}

Array Array::operator+(const Array& addArray)
{
	Array Add(ArraySize);
	for (int copy = 0; copy < ArraySize; copy++)
	{
		Add[copy] = addArray[copy] + array[copy];
	}
	return Add;
}

Array Array::operator-(const Array& subArray)
{
	Array Sub(ArraySize);
	for (int copy = 0; copy < ArraySize; copy++)
	{
		Sub[copy] = array[copy] - subArray[copy];
	}
	return Sub;
}

Array Array::operator++()
{
	for (int increment = 0; increment < ArraySize; increment++)
	{
		array[increment]++;
	}
	Array PreAdd(array, ArraySize);
	return PreAdd;
}
Array Array::operator++(int)
{
	Array PostAdd(array, ArraySize);
	for (int increment = 0; increment < ArraySize; increment++)
	{
		array[increment]++;
	}
	return PostAdd;
}
Array& Array::operator--(int)
{
	Array PostSub(array, ArraySize);
	for (int decrement = 0; decrement < ArraySize; decrement++)
	{
		array[decrement]--;
	}
	return PostSub;
}

bool Array::operator==(const Array& EqualEqual)const
{
	int counter = 0;
	for (int compare = 0; compare < ArraySize; compare++)
	{
		if (array[compare] == EqualEqual[compare])
		{
			counter++;
		}
	}
	if (counter == ArraySize)
	{
		return true;
	}
	return false;

}
bool Array::operator!()
{
	if (ArraySize <= 0)
	{
		return true;
	}
	return false;
}

void Array::operator+=(const Array& addArray)
{
	for (int copy = 0; copy < ArraySize; copy++)
	{
		array[copy] += addArray[copy];
	}
}

void Array::operator-=(const Array& subArray)
{
	for (int copy = 0; copy < ArraySize; copy++)
	{
		array[copy] -= subArray[copy];
	}
}
int Array::operator()(int idx, int val)
{
	if (array[idx] != val)
	{
		return -1;
	}
	else
	{
		for (int remove = idx; remove < ArraySize - 1; remove++)
		{
			array[remove] = array[remove + 1];
		}
		array[ArraySize - 1] = 0;
		return 1;
	}
}

Array::~Array()
{
	delete[] array;
	array = NULL;
}

ostream& operator<<(ostream& input, const Array& IArray)
{
	return input;
}

istream& operator>>(istream& output, Array& OArray)
{
	for (int cout = 0; cout < OArray.size(); cout++)
	{
		output >> OArray[cout];
	}
	return output;
}
