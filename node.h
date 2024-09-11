#include<iostream>
#include"book.h"

using namespace std;
template <class H>
class Node
{
	H data;
	Node *next;
	public:
		Node(H);
		void setData(H);
		void setNext(Node*);
		H getData();
		Node *getNext();
};