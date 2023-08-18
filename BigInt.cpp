/*
Name: Muhammad Taha
Roll No: 22I-0870
Section: D
Assignment - 3
*/

#include <iostream>
#include "BigInt.h"
using namespace std;

BigInt::BigInt(int val = 0)
{
	BigSize = 0;
	int temp = val;
	if (val == 0)
	{
		BigSize++;
	}
	while (temp != 0)
	{
		BigSize++;
		temp /= 10;
	}
	Big = new char[BigSize + 1];
	for (int init = 0; init < BigSize; init++)
	{
		Big[init] = '0';
	}
	Big[BigSize] = '\0';
	for (int Zero = BigSize - 1; Zero >= 0; Zero--)
	{
		Big[Zero] = char((val % 10) + 48);
		val /= 10;
	}
}

BigInt::BigInt(const BigInt& copy)
{
	BigSize = copy.BigSize;
	Big = new char[BigSize + 1];
	Big[BigSize] = '\0';
	for (int same = 0; same < BigSize + 1; same++)
	{
		Big[same] = copy.Big[same];
	}
}

BigInt::BigInt(const string& text)
{
	BigSize = 0;
	while (text[BigSize] != '\0')
	{
		BigSize++;
	}
	Big = new char[BigSize + 1];
	Big[BigSize] = '\0';;
	for (int copy = 0; copy < BigSize; copy++)
	{
		Big[copy] = text[copy];
	}
}

BigInt BigInt::operator+(const BigInt& val) const
{
	BigInt Add;
	BigInt rhs = val;
	if (Big[0] == '-' && rhs.Big[0] != '-')
	{
		BigInt Temp;
		Temp.BigSize = BigSize - 1;
		Temp.Big = new char[BigSize];
		Temp.Big[BigSize - 1] = '\0';
		for (int copy = 1; copy < BigSize; copy++)
		{
			Temp.Big[copy - 1] = Big[copy];
		}
		Temp.Big[BigSize - 1] = Big[BigSize];
		delete [] Big;
		Add = val - Temp;
		return Add;
	}
	else if (Big[0] != '-' && rhs.Big[0] == '-')
	{
		BigInt Temp;
		Temp.BigSize = rhs.BigSize - 1;
		Temp.Big = new char[rhs.BigSize];
		Temp.Big[rhs.BigSize - 1] = '\0';
		for (int copy = 1; copy < rhs.BigSize; copy++)
		{
			Temp.Big[copy - 1] = rhs.Big[copy];
		}
		Temp.Big[rhs.BigSize - 1] = rhs.Big[rhs.BigSize];
		delete [] rhs.Big;
		Add -= Temp;
		return Add;
	}
	else if (Big[0] == '-' && rhs.Big[0] == '-')
	{
		BigInt Temp;
		Temp.BigSize = BigSize - 1;
		Temp.Big = new char[BigSize];
		Temp.Big[BigSize - 1] = '\0';
		for (int copy = 1; copy < BigSize; copy++)
		{
			Temp.Big[copy - 1] = Big[copy];
		}
		Temp.Big[BigSize - 1] = Big[BigSize];
		BigInt Temp2;
		Temp2.BigSize = rhs.BigSize - 1;
		Temp2.Big = new char[rhs.BigSize];
		Temp2.Big[rhs.BigSize - 1] = '\0';
		for (int copy = 1; copy < rhs.BigSize; copy++)
		{
			Temp2.Big[copy - 1] = rhs.Big[copy];
		}
		Temp2.Big[rhs.BigSize - 1] = rhs.Big[rhs.BigSize];
		delete [] Big;
		delete [] rhs.Big;
		Add = Temp + Temp2;
		BigInt Temp3;
		Temp3.BigSize = Add + 2;
		Temp3.Big = new char[Add.BigSize + 2];
		Temp3.Big[BigSize + 1] = '\0';
		for (int copy = 1; copy < Add.BigSize + 1; copy++)
		{
			Temp3.Big[copy] = Add.Big[copy - 1];
		}
		Temp3.Big[Add.BigSize + 1] = Add.Big[Add.BigSize];
		Temp3.Big[0] = '-';
		delete [] Big;
		Add = Temp3;
		return Add;
	}
	int carry = 0;
	if (BigSize > val.BigSize)
	{
		Add.BigSize = BigSize;
	}
	else
	{
		Add.BigSize = val.BigSize;
	}
	(string)Add = new char[Add.BigSize + 1];
	Add.Big[Add.BigSize] = '\0';
	int size1 = val.BigSize - 1;
	int size2 = BigSize - 1;
	int newsize = Add.BigSize - 1;
	while (newsize >= 0)
	{
		if (size1 >= 0 && size2 >= 0)
		{
			Add.Big[newsize] = val.Big[size1] + Big[size2] + carry - 48;
		}
		else if (size1 >= 0)
		{
			Add.Big[newsize] = val.Big[size1] + carry;
		}
		else if (size2 >= 0)
		{
			Add.Big[newsize] = Big[size2] + carry;
		}
		else
		{
			Add.Big[newsize] = carry;
		}
		if (Add.Big[newsize] > 57)
		{
			carry = 1;
			Add.Big[newsize] -= 10;
		}
		else
		{
			carry = 0;
		}
		newsize--;
		size1--;
		size2--;
	}
	if (carry == 1)
	{
		BigInt Temp;
		Temp.BigSize = Add.BigSize + 2;
		Temp.Big = new char[Add.BigSize + 2];
		Temp.Big[Add.BigSize + 1] = '\0';
		for (int copy = 1; copy < Add.BigSize + 1; copy++)
		{
			Temp.Big[copy] = Add.Big[copy - 1];
		}
		Temp.Big[Add.BigSize + 1] = Add.Big[Add.BigSize];
		Temp.Big[0] = '1';
		delete [] Add.Big;
		Add = Temp;
	}
	return Add;
}

BigInt BigInt::operator+(int val) const
{
	BigInt Add;
	BigInt rhs(val);
	if (Big[0] == '-' && rhs.Big[0] != '-')
	{
		BigInt Temp;
		Temp.BigSize = BigSize - 1;
		Temp.Big = new char[BigSize];
		Temp.Big[BigSize - 1] = '\0';
		for (int copy = 1; copy < BigSize; copy++)
		{
			Temp.Big[copy - 1] = Big[copy];
		}
		Temp.Big[BigSize - 1] = Big[BigSize];
		delete [] Big;
		Add = val - Temp;
		return Add;
	}
	else if (Big[0] != '-' && rhs.Big[0] == '-')
	{
		BigInt Temp;
		Temp.BigSize = rhs.BigSize - 1;
		Temp.Big = new char[rhs.BigSize];
		Temp.Big[rhs.BigSize - 1] = '\0';
		for (int copy = 1; copy < rhs.BigSize; copy++)
		{
			Temp.Big[copy - 1] = rhs.Big[copy];
		}
		Temp.Big[rhs.BigSize - 1] = rhs.Big[rhs.BigSize];
		delete [] rhs.Big;
		Add -= Temp;
		return Add;
	}
	else if (Big[0] == '-' && rhs.Big[0] == '-')
	{
		BigInt Temp;
		Temp.BigSize = BigSize - 1;
		Temp.Big = new char[BigSize];
		Temp.Big[BigSize - 1] = '\0';
		for (int copy = 1; copy < BigSize; copy++)
		{
			Temp.Big[copy - 1] = Big[copy];
		}
		Temp.Big[BigSize - 1] = Big[BigSize];
		BigInt Temp2;
		Temp2.BigSize = rhs.BigSize - 1;
		Temp2.Big = new char[rhs.BigSize];
		Temp2.Big[rhs.BigSize - 1] = '\0';
		for (int copy = 1; copy < rhs.BigSize; copy++)
		{
			Temp2.Big[copy - 1] = rhs.Big[copy];
		}
		Temp2.Big[rhs.BigSize - 1] = rhs.Big[rhs.BigSize];
		delete [] Big;
		delete [] rhs.Big;
		Add = Temp + Temp2;
		BigInt Temp3;
		Temp3.BigSize = Add + 2;
		Temp3.Big = new char[Add.BigSize + 2];
		Temp3.Big[BigSize + 1] = '\0';
		for (int copy = 1; copy < Add.BigSize + 1; copy++)
		{
			Temp3.Big[copy] = Add.Big[copy - 1];
		}
		Temp3.Big[Add.BigSize + 1] = Add.Big[Add.BigSize];
		Temp3.Big[0] = '-';
		delete [] Big;
		Add = Temp3;
		return Add;
	}
	int carry = 0;
	if (BigSize > rhs.BigSize)
	{
		Add.BigSize = BigSize;
	}
	else
	{
		Add.BigSize = rhs.BigSize;
	}
	(string)Add = new char[Add.BigSize + 1];
	Add.Big[Add.BigSize] = '\0';
	int size1 = rhs.BigSize - 1;
	int size2 = BigSize - 1;
	int newsize = Add.BigSize - 1;
	while (newsize >= 0)
	{
		if (size1 >= 0 && size2 >= 0)
		{
			Add.Big[newsize] = rhs.Big[size1] + Big[size2] + carry - 48;
		}
		else if (size1 >= 0)
		{
			Add.Big[newsize] = rhs.Big[size1] + carry;
		}
		else if (size2 >= 0)
		{
			Add.Big[newsize] = Big[size2] + carry;
		}
		else
		{
			Add.Big[newsize] = carry;
		}
		if (Add.Big[newsize] > 57)
		{
			carry = 1;
			Add.Big[newsize] -= 10;
		}
		else
		{
			carry = 0;
		}
		newsize--;
		size1--;
		size2--;
	}
	if (carry == 1)
	{
		BigInt Temp;
		Temp.BigSize = Add.BigSize + 1;
		Temp.Big = new char[Add.BigSize + 1];
		Temp.Big[Add.BigSize + 1] = '\0';
		for (int copy = 1; copy < Add.BigSize; copy++)
		{
			Temp.Big[copy] = Add.Big[copy - 1];
		}
		Temp.Big[Add.BigSize] = Add.Big[Add.BigSize - 1];
		Temp.Big[0] = '1';
		delete [] Add.Big;
		Add = Temp;
	}
	return Add;
}

BigInt BigInt::operator-(const BigInt& val) const
{
	BigInt Sub;
	int carry = 0;
	if (BigSize > val.BigSize)
	{
		Sub.BigSize = BigSize;
	}
	else
	{
		Sub.BigSize = val.BigSize;
	}
	(string)Sub = new char[Sub.BigSize + 1];
	Sub.Big[Sub.BigSize] = '\0';
	int size1 = val.BigSize - 1;
	int size2 = BigSize - 1;
	int newsize = Sub.BigSize - 1;
	if (size1 > size2 || ((size1 == size2) && (val.Big[0] > Big[0])))
	{
		while (newsize >= 0)
		{
			if (size1 >= 0 && size2 >= 0)
			{
				if (val.Big[size1] >= Big[size2] + carry)
				{
					Sub.Big[newsize] = val.Big[size1] - Big[size2] - carry + 48;
					carry = 0;
				}
				else
				{
					Sub.Big[newsize] = val.Big[size1] - Big[size2] - carry + 10 + 48;
					carry = 1;
				}
			}
			else if (size1 >= 0)
			{
				if (val.Big[size1] == '0' && carry == 1)
				{
					Sub.Big[newsize] = val.Big[size1] - carry + 10;
					carry = 1;
				}
				else
				{
					Sub.Big[newsize] = val.Big[size1] - carry;
					carry = 0;
				}
			}
			else if (size2 >= 0)
			{
				if (Big[size2] == '0' && carry == 1)
				{
					Sub.Big[newsize] = Big[size2] - carry + 10;
					carry = 1;
				}
				else
				{
					Sub.Big[newsize] = Big[size2] - carry;
					carry = 0;
				}
			}
			newsize--;
			size1--;
			size2--;
		}
		while (Sub.Big[0] == '0' && Sub.Big[1] != '\0')
		{
			BigInt Temp;
			Temp.BigSize = Sub.BigSize - 1;
			Temp.Big = new char[Sub.BigSize];
			Temp.Big[Sub.BigSize - 1] = '\0';
			for (int copy = 1; copy < Sub.BigSize; copy++)
			{
				Temp.Big[copy - 1] = Sub.Big[copy];
			}
			Temp.Big[Sub.BigSize - 1] = Sub.Big[Sub.BigSize];
			delete [] Sub.Big;
			Sub = Temp;
		}
		BigInt Temp;
		Temp.BigSize = Sub.BigSize + 2;
		Temp.Big = new char[Sub.BigSize + 2];
		Temp.Big[Sub.BigSize + 1] = '\0';
		for (int copy = 1; copy < Sub.BigSize + 1; copy++)
		{
			Temp.Big[copy] = Sub.Big[copy - 1];
		}
		Temp.Big[Sub.BigSize + 1] = Sub.Big[Sub.BigSize];
		Temp.Big[0] = '-';
		delete [] Sub.Big;
		Sub = Temp;
	}
	else
	{
		while (newsize >= 0)
		{
			if (size1 >= 0 && size2 >= 0)
			{
				if (Big[size2] >= val.Big[size1] + carry)
				{
					Sub.Big[newsize] = Big[size2] - val.Big[size1] - carry + 48;
					carry = 0;
				}
				else
				{
					Sub.Big[newsize] = Big[size2] - val.Big[size1] - carry + 10 + 48;
					carry = 1;
				}
			}
			else if (size1 >= 0)
			{
				if (val.Big[size1] == '0' && carry == 1)
				{
					Sub.Big[newsize] = val.Big[size1] - carry + 10;
					carry = 1;
				}
				else
				{
					Sub.Big[newsize] = val.Big[size1] - carry;
					carry = 0;
				}
			}
			else if (size2 >= 0)
			{
				if (Big[size2] == '0' && carry == 1)
				{
					Sub.Big[newsize] = Big[size2] - carry + 10;
					carry = 1;
				}
				else
				{
					Sub.Big[newsize] = Big[size2] - carry;
					carry = 0;
				}
			}
			newsize--;
			size1--;
			size2--;
		}
		while (Sub.Big[0] == '0' && Sub.Big[1] != '\0')
		{
			BigInt Temp;
			Temp.BigSize = Sub.BigSize - 1;
			Temp.Big = new char[Sub.BigSize];
			Temp.Big[Sub.BigSize - 1] = '\0';
			for (int copy = 1; copy < Sub.BigSize; copy++)
			{
				Temp.Big[copy - 1] = Sub.Big[copy];
			}
			Temp.Big[Sub.BigSize - 1] = Sub.Big[Sub.BigSize];
			delete [] Sub.Big;
			Sub = Temp;
		}
	}
	return Sub;
}

BigInt BigInt::operator-(int val) const
{
	BigInt Sub;
	BigInt rhs(val);
	int carry = 0;
	if (BigSize > rhs.BigSize)
	{
		Sub.BigSize = BigSize;
	}
	else
	{
		Sub.BigSize = rhs.BigSize;
	}
	(string)Sub = new char[Sub.BigSize + 1];
	Sub.Big[Sub.BigSize] = '\0';
	int size1 = rhs.BigSize - 1;
	int size2 = BigSize - 1;
	int newsize = Sub.BigSize - 1;
	if (size1 > size2 || ((size1 == size2) && (rhs.Big[0] > Big[0])))
	{
		while (newsize >= 0)
		{
			if (size1 >= 0 && size2 >= 0)
			{
				if (rhs.Big[size1] >= Big[size2] + carry)
				{
					Sub.Big[newsize] = rhs.Big[size1] - Big[size2] - carry + 48;
					carry = 0;
				}
				else
				{
					Sub.Big[newsize] = rhs.Big[size1] - Big[size2] - carry + 10 + 48;
					carry = 1;
				}
			}
			else if (size1 >= 0)
			{
				if (rhs.Big[size1] == '0' && carry == 1)
				{
					Sub.Big[newsize] = rhs.Big[size1] - carry + 10;
					carry = 1;
				}
				else
				{
					Sub.Big[newsize] = rhs.Big[size1] - carry;
					carry = 0;
				}
			}
			else if (size2 >= 0)
			{
				if (Big[size2] == '0' && carry == 1)
				{
					Sub.Big[newsize] = Big[size2] - carry + 10;
					carry = 1;
				}
				else
				{
					Sub.Big[newsize] = Big[size2] - carry;
					carry = 0;
				}
			}
			newsize--;
			size1--;
			size2--;
		}
		while (Sub.Big[0] == '0' && Sub.Big[1] != '\0')
		{
			BigInt Temp;
			Temp.BigSize = Sub.BigSize - 1;
			Temp.Big = new char[Sub.BigSize];
			Temp.Big[Sub.BigSize - 1] = '\0';
			for (int copy = 1; copy < Sub.BigSize; copy++)
			{
				Temp.Big[copy - 1] = Sub.Big[copy];
			}
			Temp.Big[Sub.BigSize - 1] = Sub.Big[Sub.BigSize];
			delete [] Sub.Big;
			Sub = Temp;
		}
		BigInt Temp;
		Temp.BigSize = Sub.BigSize + 2;
		Temp.Big = new char[Sub.BigSize + 2];
		Temp.Big[Sub.BigSize + 1] = '\0';
		for (int copy = 1; copy < Sub.BigSize + 1; copy++)
		{
			Temp.Big[copy] = Sub.Big[copy - 1];
		}
		Temp.Big[Sub.BigSize + 1] = Sub.Big[Sub.BigSize];
		Temp.Big[0] = '-';
		delete [] Sub.Big;
		Sub = Temp;
	}
	else
	{
		while (newsize >= 0)
		{
			if (size1 >= 0 && size2 >= 0)
			{
				if (Big[size2] >= rhs.Big[size1] + carry)
				{
					Sub.Big[newsize] = Big[size2] - rhs.Big[size1] - carry + 48;
					carry = 0;
				}
				else
				{
					Sub.Big[newsize] = Big[size2] - rhs.Big[size1] - carry + 10 + 48;
					carry = 1;
				}
			}
			else if (size1 >= 0)
			{
				if (rhs.Big[size1] == '0' && carry == 1)
				{
					Sub.Big[newsize] = rhs.Big[size1] - carry + 10;
					carry = 1;
				}
				else
				{
					Sub.Big[newsize] = rhs.Big[size1] - carry;
					carry = 0;
				}
			}
			else if (size2 >= 0)
			{
				if (Big[size2] == '0' && carry == 1)
				{
					Sub.Big[newsize] = Big[size2] - carry + 10;
					carry = 1;
				}
				else
				{
					Sub.Big[newsize] = Big[size2] - carry;
					carry = 0;
				}
			}
			newsize--;
			size1--;
			size2--;
		}
		while (Sub.Big[0] == '0' && Sub.Big[1] != '\0')
		{
			BigInt Temp;
			Temp.BigSize = Sub.BigSize - 1;
			Temp.Big = new char[Sub.BigSize];
			Temp.Big[Sub.BigSize - 1] = '\0';
			for (int copy = 1; copy < Sub.BigSize; copy++)
			{
				Temp.Big[copy - 1] = Sub.Big[copy];
			}
			Temp.Big[Sub.BigSize - 1] = Sub.Big[Sub.BigSize];
			delete [] Sub.Big;
			Sub = Temp;
		}
	}
	return Sub;
}

BigInt BigInt::operator*(const BigInt& val) const
{
	BigInt Mult;
	BigInt rhs = val;
	int neg1 = 0, neg2 = 0;
	if (Big[0] == '-' && rhs.Big[0] != '-')
	{
		neg1 = 1;
	}
	if (Big[0] != '-' && rhs.Big[0] == '-')
	{
		neg2 = 1;
	}
	if (Big[0] == '-' && rhs.Big[0] == '-')
	{
		neg1 = 1;
		neg2 = 1;
	}
	Mult.BigSize = BigSize + rhs.BigSize - 1;
	Mult.Big = new char[Mult.BigSize + 1];
	for (int init = 0; init < Mult.BigSize; init++)
	{
		 Mult.Big[init] = 0;
	}
	Mult.Big[Mult.BigSize] = '\0';
	int overflow = 0;
	int size1 = BigSize;
	int size2 = rhs.BigSize;
	int carry = 0;
	for (int prod = size1 - 1; prod >= neg1; prod--)
	{
		for (int uct = size2 - 1; uct >= neg2; uct--)
		{
			if (Mult.Big[uct + prod] >= 48 && Mult.Big[uct + prod] <= 57)
			{
				Mult.Big[uct + prod] -= 48;
			}
			if (((rhs.Big[uct] - 48) * (Big[prod] - 48)) + carry + 48 > 127)
			{
				int temp = (rhs.Big[uct] - 48) * (Big[prod] - 48) + carry + 48 - 57;
				int temp2 = temp;
				carry = 0;
				while (temp > 0)
				{
					carry++;
					temp -= 10;
				}
				Mult.Big[uct + prod] += temp2 - (carry * 10) + 57;
			}
			else if (((rhs.Big[uct] - 48) * (Big[prod] - 48)) + carry + 48 + (int)Mult.Big[uct + prod] > 127)
			{
				int temp = (rhs.Big[uct] - 48) * (Big[prod] - 48) + carry + 48 - 57 + (int)Mult.Big[uct + prod];
				int temp2 = temp;
				carry = 0;
				while (temp > 0)
				{
					carry++;
					temp -= 10;
				}
				Mult.Big[uct + prod] = temp2 - (carry * 10) + 57;
			}
			else
			{
				Mult.Big[uct + prod] += (rhs.Big[uct] - 48) * (Big[prod] - 48) + carry + 48;
				carry = 0;
				if (Mult.Big[uct + prod] > 57)
				{
					int temp = Mult.Big[uct + prod] - 57;
					while (temp > 0)
					{
						carry++;
						temp -= 10;
					}
					Mult.Big[uct + prod] -= (carry * 10);
				}
			}
		}
		if (carry != 0 && prod > neg1)
		{
			Mult.Big[neg2 + prod - 1] += carry;
			carry = 0;
		}
	}
	if (carry != 0)
	{
		BigInt Temp;
		Temp.BigSize = Mult.BigSize + 2;
		Temp.Big = new char[Mult.BigSize + 2];
		Temp.Big[Mult.BigSize + 1] = '\0';
		for (int copy = 1; copy < Mult.BigSize + 1; copy++)
		{
			Temp.Big[copy] = Mult.Big[copy - 1];
		}
		Temp.Big[Mult.BigSize + 1] = Mult.Big[Mult.BigSize];
		Temp.Big[neg1 + neg2] = carry + 48;
		delete [] Mult.Big;
		Mult = Temp;
	}
	if ((neg1 == 1 && neg2 == 0) || (neg1 == 0 && neg2 == 1))
	{
		BigInt Temp;
		Temp.BigSize = Mult.BigSize - 1;
		Temp.Big = new char[Mult.BigSize];
		Temp.Big[Mult.BigSize - 1] = '\0';
		for (int copy = 1; copy < Mult.BigSize; copy++)
		{
			Temp.Big[copy - 1] = Mult.Big[copy];
		}
		Temp.Big[Mult.BigSize - 1] = Mult.Big[Mult.BigSize];
		delete [] Mult.Big;
		Mult = Temp;
		Mult.Big[0] = '-';
	}
	else if (neg1 == 1 && neg2 == 1)
	{
		BigInt Temp;
		Temp.BigSize = Mult.BigSize - 1;
		Temp.Big = new char[Mult.BigSize];
		Temp.Big[Mult.BigSize - 1] = '\0';
		for (int copy = 1; copy < Mult.BigSize; copy++)
		{
			Temp.Big[copy - 1] = Mult.Big[copy];
		}
		Temp.Big[Mult.BigSize - 1] = Mult.Big[Mult.BigSize];
		delete [] Mult.Big;
		Mult = Temp;
		Temp.BigSize = Mult.BigSize - 1;
		Temp.Big = new char[Mult.BigSize];
		Temp.Big[Mult.BigSize - 1] = '\0';
		for (int copy = 1; copy < Mult.BigSize; copy++)
		{
			Temp.Big[copy - 1] = Mult.Big[copy];
		}
		Temp.Big[Mult.BigSize - 1] = Mult.Big[Mult.BigSize];
		delete [] Mult.Big;
		Mult = Temp;
	}
	while (Mult.Big[0] == '0' && Mult.Big[1] != '\0')
	{
		BigInt Temp;
		Temp.BigSize = Mult.BigSize - 1;
		Temp.Big = new char[Mult.BigSize];
		Temp.Big[Mult.BigSize - 1] = '\0';
		for (int copy = 1; copy < Mult.BigSize; copy++)
		{
			Temp.Big[copy - 1] = Mult.Big[copy];
		}
		Temp.Big[Mult.BigSize - 1] = Mult.Big[Mult.BigSize];
		delete [] Mult.Big;
		Mult = Temp;
	}
	return Mult;
}

BigInt BigInt::operator+=(const BigInt& rhs)
{
	*this = *this + rhs;
	return *this;
}

BigInt BigInt::operator-=(const BigInt& rhs)
{
	*this = *this - rhs;
	return *this;
}

BigInt BigInt::operator*=(const BigInt& rhs)
{

	*this = *this * rhs;
	return *this;
}

bool BigInt::operator==(const BigInt& val) const
{
	int counter = 0;
	if (BigSize == val.BigSize)
	{
		for (int compare = 0; compare < BigSize; compare++)
		{
			if (Big[compare] == val.Big[compare])
			{
				counter++;
			}
		}
		if (counter == BigSize)
		{
			return true;
		}
	}
	return false;
}

bool BigInt::operator==(const char* val) const
{
	int counter = 0, valSize = 0;
	while (val[valSize] != '\0')
	{
		valSize++;
	}
	if (BigSize == valSize)
	{
		for (int compare = 0; compare < BigSize; compare++)
		{
			if (Big[compare] == val[compare])
			{
				counter++;
			}
		}
		if (counter == BigSize)
		{
			return true;
		}
	}
	return false;
}

bool BigInt::operator!=(const BigInt& val) const
{
	int counter = 0;
	if (BigSize == val.BigSize)
	{
		for (int compare = 0; compare < BigSize; compare++)
		{
			if (Big[compare] == val.Big[compare])
			{
				counter++;
			}
		}
		if (counter == BigSize)
		{
			return false;
		}
	}
	return true;
}

bool BigInt::operator<(const BigInt& val) const
{
	int compare = 0;
	if (BigSize == val.BigSize)
	{
		while (Big[compare] < val.Big[compare])
		{
			compare++;
		}
		if (compare == BigSize)
		{
			return true;
		}
		return false;
	}
	else if (BigSize > val.BigSize)
	{
		return false;
	}
	return true;
}

bool BigInt::operator<=(const BigInt& val) const
{
	int compare = 0;
	if (BigSize == val.BigSize)
	{
		while (Big[compare] <= val.Big[compare])
		{
			compare++;
		}
		if (compare == BigSize)
		{
			return true;
		}
		return false;
	}
	else if (BigSize > val.BigSize)
	{
		return false;
	}
	return true;
}

bool BigInt::operator>(const BigInt& val) const
{
	int compare = 0;
	if (BigSize == val.BigSize)
	{
		while (Big[compare] > val.Big[compare])
		{
			compare++;
		}
		if (compare == BigSize)
		{
			return true;
		}
		return false;
	}
	else if (BigSize < val.BigSize)
	{
		return false;
	}
	return true;
}

bool BigInt::operator>=(const BigInt& val) const
{
	int compare = 0;
	if (BigSize == val.BigSize)
	{
		while (Big[compare] >= val.Big[compare])
		{
			compare++;
		}
		if (compare == BigSize)
		{
			return true;
		}
		return false;
	}
	else if (BigSize < val.BigSize)
	{
		return false;
	}
	return true;
}

BigInt& BigInt::operator++()
{
	*this = *this + 1;
	return *this;
}

BigInt BigInt::operator++(int)
{
	BigInt temp(*this);
	*this = *this + 1;
	return temp;
}

BigInt& BigInt::operator--()
{
	*this = *this - 1;
	return *this;
}

BigInt BigInt::operator--(int)
{
	BigInt temp(*this);
	*this = *this - 1;
	return temp;
}

BigInt::operator string()
{
	return Big;
}

BigInt::operator int()
{
	return BigSize;
}

ostream& operator<<(ostream& output, const BigInt& val)
{
	for (int cout = 0; cout < val.BigSize; cout++)
	{
		output << val.Big[cout];
	}
	output << endl;
	return output;
}

istream& operator>>(istream& input, BigInt& val)
{
	int size = 0;
	char* temp = new char[1000];
	input >> temp;
	while (temp[size] != '\0')
	{
		size++;
	}
	val.BigSize = size;
	val.Big = new char[val.BigSize + 1];
	for (int cin = 0; cin < (int)val; cin++)
	{
		val.Big[cin] = temp[cin];
	}
	val.Big[val.BigSize] = '\0';
	delete []temp;
	return input;
}

BigInt::~BigInt()
{
	Big = NULL;
}
