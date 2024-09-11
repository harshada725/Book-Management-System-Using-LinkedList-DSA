#include"node.h"
template <class H>
Node<H>::Node(H d)
{
	data=d;
	next=NULL;
	
}
///////////////////////////////////
template <class H>
void Node<H>::setData(H d)
{
	data=d;
}
template <class H>
void Node<H>::setNext(Node *nt)
{
	next=nt;
}

/////////////////////////////////////
template <class H>
H Node<H>::getData()
{
	return data;
}
template <class H>
Node<H> *Node<H>::getNext()
{
	return next;
}

