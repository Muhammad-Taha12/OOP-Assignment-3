#include "Page.cpp"
#include "Book.h"

int Book::totalLines = 0;

Book::Book(int size = 0)
{
	pageNumber = size;
	Pages = new Page[pageNumber];
}

Book::Book(Page& Pagey)
{
	pageNumber = 1;
	Pages = new Page[pageNumber];
	Pages[0] = Pagey;
}

Book::Book(Book& oldBook)
{
	pageNumber = oldBook.pageNumber;
	Pages = new Page[pageNumber];
	int pagenum = 0;
	while (pagenum < pageNumber)
	{
		Pages[pagenum] = oldBook.Pages[pagenum];
		pagenum++;
	}
}

Book Book::operator+(Book& Book2)
{
	Book Temp(pageNumber + Book2.pageNumber);
	int pagenum = 0;
	while (pagenum < pageNumber)
	{
		Temp += Pages[pagenum];
		pagenum++;
	}
	pagenum = 0;
	while (pagenum < Book2.pageNumber)
	{
		Temp += Book2.Pages[pagenum];
		pagenum++;
	}
	return Temp;
}

Book Book::operator+=(Page& Pagey)
{
	int startLines = totalLines;
	totalLines += Pagey.getLineNumber();
	int pagenum = 0;
	if (totalLines > 20)
	{
		int linenum = 0, linenum2 = 0, size = 0, size2 = 0, size3 = 0;
		size3 = 0;
		while (linenum2 <= 20 - startLines)
		{
			size2 = 0;
			while (Pagey[linenum2][size2] != '\0')
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
		while (linenum2 <= 20 - startLines)
		{
			size2 = 0;
			while (Pagey[linenum2][size2] != '\0')
			{
				newChar[size3] = Pagey[linenum2][size2];
				size2++;
				size3++;
			}
			linenum2++;
		}
		newChar[size3 - 1] = '\0';
		Pages[pagenum] += newChar;
		delete []newChar;
		size = 0;
		char* oldChar;
		while (Pages[pagenum][19][size] != '\0')
		{
			size++;
		}
		int lastSize = 40 - Pages[pagenum][19].getSize();
		newChar = new char[lastSize];
		newChar[lastSize] = '\0';
		size3 = 0;
		while (lastSize > 0)
		{
			size2 = 0;
			while (Pagey[linenum2][size2] != '\0')
			{
				newChar[size3] = Pagey[linenum2][size2];

				lastSize--;
				size2++;
				size3++;
				if (Pagey[linenum2][size2] == ' ')
				{
					size = 1;
					while (Pagey[linenum2][size + size2] != '\0' && Pagey[linenum2][size + size2] != ' ')
					{
						size++;
					}
					if (size > lastSize)
					{
						break;
					}
				}
				if (lastSize == 0)
				{
					break;
				}
			}
			if (size > lastSize)
			{
				break;
			}
			linenum2++;
		}
		Pages[pagenum] += newChar;
		delete []newChar;
		newChar = new char[40 - size2];
		pagenum++;
		size3 = 0;
		if (Pagey[linenum2][size2] == ' ')
		{
			size2++;
		}
		while (Pagey[linenum2][size2] != '\0')
		{
			newChar[size3] = Pagey[linenum2][size2];
			size3++;
			size2++;
		}
		linenum2++;
		while (linenum2 <= Pagey.getLineNumber())
		{
			size2 = 0;
			while (Pagey[linenum2][size2] != '\0')
			{
				newChar[size3] = Pagey[linenum2][size2];
				size2++;
				size3++;
			}
			linenum2++;
		}
		newChar[size3] = '\0';
		Pages[pagenum] += newChar;
		totalLines -= 20;
	}
	else
	{
		Pages[pagenum] += Pagey;
	}
	return *this;
}

Page& Book::operator[](int fetch)
{
	return Pages[fetch];
}

Book::~Book()
{
	delete []Pages;
	Pages = NULL;
}

ostream& operator<<(ostream& output, const Book& print)
{
	for (int page = 0; page < print.pageNumber; page++)
	{
		output << "---------------Page " << page + 1 << "---------------" << endl << print.Pages[page];
	}
	return output;
}

int main()
{
	Page p, p2, p3, p4;
	p += "I think having someone in your life to look up to is one of the most important things. We all admire people like Linus Torvalds and Bill Gates but trying to make them your role models can be demotivating. Bill Gates began coding at age 13 and formed his first venture at age 17.";
	p2 += "Having a local hero or mentor is more helpful. Because you're both living in the same community, there's a greater chance there won't be such a large gap to discourage you. A local mentor probably started coding around the age you did and was unlikely to start a big venture.";
	p3 += "First, because their stories seemed like fantasy to me, and second, I couldn't reach them. I chose my mentors and role models to be those near my reach. Choosing a role model doesn't mean you just want to get to where they are and stop. Success is step by step.";
	p4 += "You probably can't get one-on-one advice from someone like Bill Gates. You can get the advice they're giving to the public at conferences, which is great, too. I always follow smart people.";
	Book b(3);
	b += p2;
	b += p;

	
	b += p3;
	b[2] += p4;
	/*
	b[2][2] = "I am editing this line using subscripts.";
	b[2] += "Adding this text to existing line of page number 3 and overflowed text must go to next line";
	Line l("Adding a new line to an existing page.");
	Line l2("This is line 2.");
	b[1] += l;
	b[1] += l2;
	b[1] += l;*/
	cout << b;
	return 0;
}

