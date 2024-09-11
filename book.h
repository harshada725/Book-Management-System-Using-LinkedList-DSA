#include<iostream>
using namespace std;
class Book
{
	int bookID;
    char bookName[50];
    char authorName[50];	
    char category[50];
    double price;
    double rating;
    public:
    	
    	Book();
    	Book(int,const char*,const char*,const char*,double,double);
    	void setBookID(int);
    	int getBookID();
    	void setBookName(const char*);
    	const char* getBookName();
		void setAuthorName(const char*);
    	const char* getAuthorName();
		void setCategory(const char*);
    	const char* getCategory();
		void setPrice(double);
    	double getPrice();
		void setRating(double);
    	double getRating();
    	void displayData(); 		
};