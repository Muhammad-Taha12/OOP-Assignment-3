/*
Name: Muhammad Taha
Roll No: 22I-0870
Section: D
Assignment - 3
*/

#ifndef PAGE_H_
#define PAGE_H_

class Page
{
	int LineNumber;
	Line* lines;
	public:
		Page(int size);
		Page(char* line);
		Page(Page& Pagey);
		int calculateLineNumber(char*);
		int getLineNumber();
		void setLineNumber();
		Page operator+(char* line);
		Page operator+=(char* line);
		Page operator+(Line& Line);
		Page operator+=(Line& Line);
		Page operator+(Page& Pagey);
		Page operator+=(Page& Pagey);
		Line& operator[](int fetch);
		~Page();
		friend ostream& operator<<(ostream& output, const Page& print);
};


#endif
