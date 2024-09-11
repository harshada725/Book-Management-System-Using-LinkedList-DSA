//#include"node.h"
#include"node.cpp"
template <class H>
class Linklist
{
	Node<H> * start;
	public:
		Linklist();
		//functions
		void AddBookByPos(H,int);  //here H is datatype book
		void deleteBook(int);
		Node<H> * SearchByBookId(int);
		Node<H> * SearchByBookName(char *);
		void updateBook(int);
		void sortByRating();
		void sortByPrice();
		void display();
		void readData(char*);
		void writeData(char*);
};