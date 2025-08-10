#include <iostream>
using namespace std;
class Book
{
public:
string bookId;
string title;
string author;

public:
void setBook(string bId, string t, string a)
{
bookId=bId;
title=t;
author=a;
}
void displayBook()
{
cout<<"Boook Id "<< bookId<< "Title"<< title << "Author"<< author<< endl;
}
}
class Fiction
{

}
