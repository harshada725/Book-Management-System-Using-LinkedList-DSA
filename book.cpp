#include"book.h"

////////////////////////////////////////////////
Book :: Book()
{
	this->bookID=0;
    strcpy(this->bookName,"Not Given");
    strcpy(this->authorName,"Not Given");
    strcpy(this->category,"Not Given");
    this->price=0;
    this->rating=0;
}
////////////////////////////////////////////////
Book :: Book(int bid,const char* nm,const char* authornm,const char* cater,double p,double r)
{
	this->bookID=bid;
    strcpy(this->bookName,nm);
    strcpy(this->authorName,authornm);
    strcpy(this->category,cater);
    this->price=p;
    this->rating=r;	
}
////////////////////////////////////////////////
void Book :: setBookID(int bid)
{
	this->bookID=bid;
}
int Book :: getBookID()
{
	return this->bookID;
}
/////////////////////////////////
void Book :: setBookName(const char* nm)
{
	strcpy(this->bookName,nm);
}
const char* Book :: getBookName()
{
	return this->bookName;
}
/////////////////////////////////
void Book :: setAuthorName(const char* authornm)
{
	strcpy(this->authorName,authornm);
}
const char* Book :: getAuthorName()
{
	return this->authorName;
}
/////////////////////////////////
void Book :: setCategory(const char* cater)
{
	strcpy(this->category,cater);
}
const char* Book :: getCategory()
{
	return this->category;
}
//////////////////////////////////
void Book :: setPrice(double p)
{
	this->price=p;
}
double Book :: getPrice()
{
	return this->price;
}
////////////////////////////////////
void Book :: setRating(double r)
{
	this->rating=r;
}
double Book :: getRating()
{
	return this->rating;
}
////////////////////////////////////////////////
void Book :: displayData()
{
	cout<<"\n\t\tBOOK Id:"<<this->getBookID();
	cout<<"\n\t\tBook Name:"<<this->getBookName();
	cout<<"\n\t\tBook Author Name:"<<this->getAuthorName();
	cout<<"\n\t\tBook caterogy:"<<this->getCategory();
	cout<<"\n\t\tBook Price:"<<this->getPrice();
	cout<<"\n\t\tBook Rating:"<<this->getRating();	
	cout<<"\n\n\t-----------------------------------------------------------------------\n";
}
////////////////////////////////////////////////

