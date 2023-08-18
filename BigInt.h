/*
Name: Muhammad Taha
Roll No: 22I-0870
Section: D
Assignment - 3
*/

#ifndef BIGINT_H_
#define BIGINT_H_

class BigInt
{
	char *Big;
	int BigSize;
	//think about the private data members
	public:
		BigInt(int val);
		BigInt(const string& text);
		BigInt(const BigInt& copy); // copy constructor
		// Binary Operators
		// Arithmetic Operators
		BigInt operator+(const BigInt& val) const;
		BigInt operator+(int val) const;
		BigInt operator-(const BigInt& val) const;
		BigInt operator-(int val) const;
		BigInt operator*(const BigInt& val) const;
		// Compound Assignment Operators
		BigInt operator+=(const BigInt& rhs);
		BigInt operator-=(const BigInt& rhs);
		BigInt operator*=(const BigInt& rhs);
		// Logical Operators
		bool operator==(const BigInt& val) const;
		bool operator==(const char* val) const;
		bool operator!=(const BigInt& val) const;
		bool operator<(const BigInt& val) const;
		bool operator<=(const BigInt& val) const;
		bool operator>(const BigInt& val) const;
		bool operator>=(const BigInt& val) const;
		// Unary Operators
		BigInt& operator++(); // Pre-increment Operator
		BigInt operator++(int); // Post-increment Operator
		BigInt& operator--(); // Pre-decrement Operator
		BigInt operator--( int ); // Post-decrement Operator

		//Conversion Operator
		operator string(); // return value of the BigInt as string
		operator int(); // return the number of digits in big Integer

		friend ostream& operator<<(ostream& output, const BigInt& val); // outputs the BigInt
		friend istream& operator>>(istream& input, BigInt& val); // inputs the BigInt

		~BigInt(); // destructor
};




#endif
