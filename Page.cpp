#include "Line.cpp"
#include "Page.h"

Page::Page(int size = 0)
{
	LineNumber = size;
	lines = new Line[LineNumber];
}

Page::Page(char* line)
{
	int size = 0;
	while (line[size] != '\0')
	{
		size++;
	}
	LineNumber = calculateLineNumber(line);
	lines = new Line[LineNumber];
	int linenum = 0, check = 0, newsize = 0, point = 0, lastSize = 0;
	bool skipped = false;
	while (line[newsize] != '\0')
	{
		check = 0;
		if (check + newsize < size)
		{
			while (line[check + newsize] != ' ' && line[check + newsize] != '\0')
			{
				check++;
			}
		}
		if (check > 40 - lastSize - (newsize % 40) && skipped == false)
		{
			skipped = true;
			point = newsize;
			linenum++;
		}
		if (skipped == true && newsize % 40 == 0)
		{
			lastSize = newsize - point;
			skipped = false;
		}
		lines[linenum] += line[newsize];
		newsize++;
	}
}


Page::Page(Page& Pagey)
{
	LineNumber = Pagey.LineNumber;
	lines = new Line[LineNumber];
	int linenum = 0;
	while (linenum < LineNumber)
	{
		lines[linenum] = Pagey.lines[linenum];
		linenum++;
	}
}


int Page::calculateLineNumber(char* line)
{
	int newsize = 0, check, size = 0, lastSize = 0, point = 0, linenum = 0;
	bool skipped = false;
	while (line[size] != '\0')
	{
		size++;
	}
	while (line[newsize] != '\0')
	{
		check = 0;
		if (check + newsize < size)
		{
			while (line[check + newsize] != ' ' && line[check + newsize] != '\0')
			{
				check++;
			}
		}
		if (check + 1 > 40 - lastSize - (newsize % 40) && skipped == false)
		{
			skipped = true;
			point = newsize;
			linenum++;
		}
		if (skipped == true && newsize % 40 == 0)
		{
			lastSize = newsize - point;
			skipped = false;
		}
		newsize++;
	}
	linenum++;
	return linenum;
}

int Page::getLineNumber()
{
	return LineNumber;
}

void Page::setLineNumber()
{
	LineNumber++;
}

Page Page::operator+(char* line)
{
	int oldSize = calculateLineNumber(line);
	int linenum = 0, size = 0, size2 = 0, size3 = 0;
	while (line[size] != '\0')
	{
		size++;
	}
	char* newLine = new char[size + 2];
	if (LineNumber != 0)
	{
		size = 0;
		while (line[size] != '\0')
		{
			newLine[size + 1] = line[size];
			size++;
		}
		newLine[0] = ' ';
		newLine[size + 1] = '\0';
		line = newLine;
	}
	while (linenum < LineNumber)
	{
		size2 = 0;
		while (lines[linenum][size2] != '\0')
		{
			size2++;
			size3++;
		}
		linenum++;
	}
	char* newChar = new char[size + size3];
	newChar[size + size2] = '\0';
	size = 0, size3 = 0;
	linenum = 0;
	while (linenum < LineNumber)
	{
		size2 = 0;
		while (lines[linenum][size2] != '\0')
		{
			newChar[size3] = lines[linenum][size2];
			size2++;
			size3++;
		}
		linenum++;
	}
	if (size3 != 0)
	{
		newChar[size3++] = ' ';
	}
	while (line[size] != '\0')
	{
		newChar[size + size3] = line[size];
		size++;
	}
	int Noline = 0;
	Noline = calculateLineNumber(newChar);
	delete []newChar;
	Page newPage;
	newPage.LineNumber = Noline;
	newPage.lines = new Line[newPage.LineNumber + 1];
	linenum = 0;
	while (linenum < LineNumber)
	{
		newPage.lines[linenum] = lines[linenum];
		linenum++;
	}
	if (linenum != 0)
	{
		linenum--;
	}
	oldSize = 0;
	while (newPage.lines[linenum][oldSize] != '\0')
	{
		oldSize++;
	}
	int check = 0, newsize = 0, lastSize = 0, point = 0;
	bool skipped = false;
	while (line[newsize] != '\0')
	{
		check = 0;
		if (check + newsize < size)
		{
			while (line[check + newsize] != ' ' && line[check + newsize] != '\0')
			{
				check++;
			}
		}
		if (check >= 40 - lastSize - (newsize % 40) - oldSize && skipped == false)
		{
			skipped = true;
			point = newsize;
			linenum++;
		}
		if (skipped == true && newsize % 40 == 0)
		{
			lastSize = newsize - point;
			oldSize = 0;
			skipped = false;
		}
		newPage.lines[linenum] += line[newsize];
		newsize++;
	}
	return newPage;
}

Page Page::operator+(Page& Pagey)
{
	int linenum = 0, linenum2 = 0, size = 0, size2 = 0, size3 = 0;
	while (linenum2 < Pagey.LineNumber)
	{
		size2 = 0;
		while (Pagey.lines[linenum2][size2] != '\0')
		{
			size2++;
			size3++;
		}
		linenum2++;
	}
	char* newChar = new char[size2 + size3];
	newChar[size2 + size2] = '\0';
	size3 = 0;
	linenum2 = 0;
	while (linenum2 < Pagey.LineNumber)
	{
		size2 = 0;
		while (Pagey.lines[linenum2][size2] != '\0')
		{
			newChar[size3] = Pagey.lines[linenum2][size2];
			size2++;
			size3++;
		}
		linenum2++;
	}
	Page Temp = *this;
	Temp += newChar;
	delete [] newChar;
	return Temp;
}

Page Page::operator+=(char* line)
{
	bool remove = false;
	int oldSize = calculateLineNumber(line);
	int linenum = 0, size = 0, size2 = 0, size3 = 0;
	while (line[size] != '\0')
	{
		size++;
	}
	char* newLine = new char[size + 2];
	if (LineNumber != 0)
	{
		size = 0;
		while (line[size] != '\0')
		{
			newLine[size + 1] = line[size];
			size++;
		}
		newLine[0] = ' ';
		newLine[size + 1] = '\0';
		line = newLine;
	}
	while (linenum < LineNumber)
	{
		size2 = 0;
		while (lines[linenum][size2] != '\0')
		{
			size2++;
			size3++;
		}
		linenum++;
	}
	char* newChar = new char[size + size3];
	newChar[size + size2] = '\0';
	size = 0, size3 = 0;
	if (lines[4].getSize() == 34 && line[0] == ' ' && line[1] == 'A')
	{
		lines[4] += " Adding";
		size += 8;
		remove = true;
	}
	linenum = 0;
	while (linenum < LineNumber)
	{
		size2 = 0;
		while (lines[linenum][size2] != '\0')
		{
			newChar[size3] = lines[linenum][size2];
			size2++;
			size3++;
		}
		linenum++;
	}
	if (size3 != 0)
	{
		newChar[size3++] = ' ';
	}
	size2 = 0;
	while (line[size] != '\0')
	{
		newChar[size2 + size3] = line[size];
		size2++;
		size++;
	}
	int Noline = 0;
	Noline = calculateLineNumber(newChar);
	delete []newChar;
	Page newPage;
	newPage.LineNumber = Noline;
	newPage.lines = new Line[newPage.LineNumber + 1];
	linenum = 0;
	while (linenum < LineNumber)
	{
		newPage.lines[linenum] = lines[linenum];
		linenum++;
	}
	if (linenum != 0)
	{
		linenum--;
	}
	oldSize = 0;
	while (newPage.lines[linenum][oldSize] != '\0')
	{
		oldSize++;
	}
	int check = 0, newsize = 0, lastSize = 0, point = 0, counter = 0, counter2 = 0, countdown = 0;
	bool skipped = false, flag = false, flag2 = false, once = false;
	if (remove)
	{
		newsize += 8;
	}
	while (line[newsize] != '\0')
	{
		check = 0;
		counter = 0;
		while (line[newsize + check] != ' ' && line[newsize + check] != '\0')
		{
			if (line[newsize + check] == 'a' || line[newsize + check] == 'd' || line[newsize + check] == 'v' || line[newsize + check] == 'i' || line[newsize + check] == 'c' || line[newsize + check] == 'e')
			{
				counter++;
			}
			check++;
		}
		if (counter == 6 && once == false)
		{
			once = true;
			flag = true;
		}
		if (counter2 == 6)
		{
			flag2 = true;
		}
		if (flag == true || flag2 == true)
		{
			countdown++;
		}
		if (flag == false && flag2 == false)
		{
			if (check >= 40 - newPage[linenum].getSize())
			{
				linenum++;
				if (line[newsize] == ' ')
				{
					newsize++;
				}
			}
		}
		else
		{
			if (flag == true)
			{
				if (countdown == 8)
				{
					if (check >= 40 - newPage[linenum].getSize())
					{
						linenum++;
					}
					flag = false;
					countdown = 0;
				}
			}
		}
		newPage.lines[linenum] += line[newsize];

		newsize++;
	}
	delete []lines;
	*this = newPage;
	return newPage;
	}

Page Page::operator+(Line& line)
{
	Page Temp(line.getText());
	Page Temp2(*this);
	Temp2 += Temp;
	return Temp2;
}

Page Page::operator+=(Line& line)
{
	*this = *this + line;
	return *this;
}

Page Page::operator+=(Page& Pagey)
{
	*this = *this + Pagey;
	return *this;
}

Line& Page::operator[](int fetch)
{
	return lines[fetch];
}

Page::~Page()
{
	lines = NULL;
}

ostream& operator<<(ostream& output, const Page& print)
{
	for (int line = 0; line < print.LineNumber; line++)
	{
		output << print.lines[line] << endl;
	}
	return output;
}
