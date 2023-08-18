/*
Name: Muhammad Taha
Roll No: 22I-0870
Section: D
Assignment - 3
*/

#ifndef LINE_H_
#define LINE_H_

class Line
{
	int LineSize;
	char* Text;
	public:
		Line(int size);
		Line(char* line);
		Line(Line& line);
		Line MoveLine();
		Line operator+=(char);
		Line operator+=(char*);
		Line operator-=(char);
		Line operator=(char*);
		bool operator!=(char);
		char operator[](int fetch);
		int getSize();
		char* getText();
		~Line();
		friend ostream& operator<<(ostream& output, const Line& show);
};

#endif
