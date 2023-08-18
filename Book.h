/*
Name: Muhammad Taha
Roll No: 22I-0870
Section: D
Assignment - 3
*/

#ifndef BOOK_H_
#define BOOK_H_

class Book
{
	int pageNumber;
	Page* Pages;
	public:
		static int totalLines;
		Book(int size);
		Book(Page& Pagey);
		Book(Book& oldBook);
		Book operator+(Book& Book2);
		Book operator+=(Page& Pagey);
		Page& operator[](int fetch);
		~Book();
		friend ostream& operator<<(ostream& output, const Book& print);
};


#endif
