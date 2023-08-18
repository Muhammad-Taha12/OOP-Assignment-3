/*
Name: Muhammad Taha
Roll No: 22I-0870
Section: D
Assignment - 3
*/

#include <iostream>
using namespace std;
#include "Line.h"

Line::Line(int size = 0)
{
	LineSize = size;
	Text = new char[LineSize + 1];
	Text[LineSize] = '\0';
}

Line::Line(char* line)
{
	LineSize = 0;
	while (line[LineSize] != '\0')
	{
		LineSize++;
	}
	Text = new char[LineSize + 1];
	Text[LineSize] = '\0';
	for (int copy = 0; line[copy] != '\0'; copy++)
	{
		Text[copy] = line[copy];
	}
}


Line::Line(Line& line)
{
	Line Temp(line.Text);
	*this = Temp;
}

Line Line::MoveLine()
{
	if (LineSize > 40)
	{
		Line newLine;
		newLine.LineSize = LineSize - 40;
		newLine.Text = new char[newLine.LineSize + 1];
		newLine.Text[newLine.LineSize] = '\0';
		int move = 40, copy = 0;
		while (Text[move] != '\0')
		{
			newLine.Text[copy] = Text[move];
			copy++;
			move++;
		}
		return newLine;
	}
	return *this;
}

Line Line::operator+=(char input)
{
	Line Temp(LineSize + 1);
	int thissize = 0;
	while(thissize < LineSize)
	{
		Temp.Text[thissize] = Text[thissize];
		thissize++;
	}
	Temp.Text[thissize] = input;
	Temp.Text[thissize + 1] = '\0';
	delete []Text;
	*this = Temp;
	return *this;
}

Line Line::operator+=(char* input)
{
	int size = 0;
	while (input[size] != '\0')
	{
		size++;
	}
	Line Temp(LineSize + size);
	size = 0;
	int thissize = 0;
	while(thissize < LineSize)
	{
		Temp.Text[thissize] = Text[thissize];
		thissize++;
	}
	while(thissize < Temp.LineSize)
	{
		Temp.Text[thissize] = input[size];
		size++;
		thissize++;
	}
	Temp.Text[thissize] = '\0';
	delete []Text;
	*this = Temp;
	return *this;
}

Line Line::operator-=(char input)
{
	Line Temp(LineSize - 1);
	int thissize = 0;
	while(thissize < Temp.LineSize)
	{
		Temp.Text[thissize] = Text[thissize];
		thissize++;
	}
	Temp.Text[thissize + 1] = '\0';
	delete []Text;
	*this = Temp;
	return *this;
}

Line Line::operator=(char* input)
{
	Line Temp(input);
	delete []Text;
	*this = Temp;
	return *this;
}

int Line::getSize()
{
	return LineSize;
}

char* Line::getText()
{
	return Text;
}

char Line::operator[](int fetch)
{
	return Text[fetch];
}

bool Line::operator!=(char letter)
{
	if (Text[0] == letter)
	{
		return false;
	}
	else
	{
		return true;
	}
}

Line::~Line()
{
	Text = NULL;
}

ostream& operator<<(ostream& output, const Line& show)
{
	output << show.Text;
	return output;
}
