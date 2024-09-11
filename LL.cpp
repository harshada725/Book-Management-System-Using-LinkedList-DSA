#include"LL.h"
#include<fstream>
template <class H>
Linklist<H>::Linklist()
{
	start=NULL;
}

///////////////////////////////////////////////
template <class H>
void Linklist<H>::AddBookByPos(H data,int pos)
{
	//create a new node
	Node<H>* temp=new Node<H>(data);
	if(start==NULL)
	{
		start=temp;
		return;
	}
	else if(pos==1)
	{
		temp->setNext(start);
		start=temp;
		return;
	}
	//Empty list
	//Insert at the beginning
	if(pos==1 || pos==1)
	{
		temp->setNext(start);
		start=temp;
		return;
	}
	//we need to traverse
	Node<H> *p=start;
	int i=1;
	while(i<pos-1 && p->getNext()!=NULL)
	{
		p=p->getNext();
		i++;
	}
	//This will work for any position including (last)
	//Attach the new node first
	temp->setNext(p->getNext());
	p->setNext(temp);
}
/////////////////////////////////////////////////////////
template <class H>
void Linklist<H>::deleteBook(int bookId )
{
	if(start==NULL)
	{
		cout<<"\n\t\t Linked list id empty!!";
	}
	//Deleting First Node
	if(start->getData().getBookID()==bookId)
	{
		Node<H>* p=start; //created pointer p
		start=start->getNext();   //this will prevent from dangling pointer case and memory leak
		delete p;
		cout<<"\n\t\t Data delated suceesfuly";
		return;
	}
	//Checking for Single data present in List 
	if(start->getNext()==NULL)
	{
		cout<<"\n\t\t Book not found";
		return;
	}
	
	Node<H>* p = start;
	//int i=1;
	H bll =start->getNext()->getData();
	while(bll.getBookID() !=bookId && p->getNext()->getNext()!=NULL)
	{
		p=p->getNext();
	bll=p->getNext()->getData();
	
}
if(bll.getBookID()==bookId)
{
	Node<H> * q=p->getNext();
	p->setNext(q->getNext());
	delete q;
	cout<<"\n\t\t Data deletd suceesfully!!";
	return;
	}
	else{
		cout<<"\n\t\tBook not Found!!";
	}
   
}
//////////////////////////////////////////////////////
template <class H>
Node<H> * Linklist<H>::SearchByBookId(int bookID)
{
	Node<H>*p=start;
	//Node*res;
	while(p!=NULL)
	{
		if(p->getData().getBookID()==bookID)
		{
			return p;
		}
		p=p->getNext();
	}
	return NULL;
}
///////////////////////////////////////////////////
template <class H>
Node<H> * Linklist<H>::SearchByBookName(char* bookName)
{
	Node<H>*p=start;
	//Node*res;
	while(p!=NULL)
	{
		if(strcasecmp(p->getData().getBookName(),bookName)==0)
		{
			return p;
		}
		p=p->getNext();
	}
	return NULL;
}
//////////////////////////////////////////////////
template <class H>
void Linklist<H>::updateBook(int bookID)
{
	Node<H>  *p=SearchByBookId(bookID);
	if(p==NULL)
	{
		cout<<"\n\t\tBook not found!!";
		return;
	}
	else
	{
		int ch;
        cout << "\n\t\tChoose what to update:";
        cout << "\n\t\t1. Book Price";
        cout << "\n\t\t2. Book Rating\n";
        
        cout << "\n\t\tEnter your choice: ";
        cin >> ch;
        H b1=p->getData();
        if(ch==1)
        {
        	int cost;
            cout << "\n\t\tEnter new Book Price: ";
            cin >> cost;
            
            b1.setPrice(cost);
		}
		else if(ch==2)
		{
			int rate;
            cout << "\n\t\tEnter new Book Rating: ";
            cin >> rate;
            b1.setRating(rate);
		}
		else
		{
			cout << "\n\t\tInvalid choice. Please try again.\n";
			
		}
		p->setData(b1);
		cout<<"\n\t\tData Updated Successfully......";
	}
	
}
////////////////////////////////////////////////////////
template <class H>
void Linklist<H>::sortByRating()
{
	if(start==NULL)
	{
		cout<<"\nLinklist is empty!!";
		return;
	}
	else
	{
		for(Node<H>* p=start;p!=NULL;p=p->getNext())
		{
			for(Node <H>* q=p->getNext();q!=NULL;q=q->getNext())
			{
				if(p->getData().getRating()<q->getData().getRating())
				{
				    H temp=p->getData();
					p->setData(q->getData());
					q->setData(temp);	
				}	
			}
		}
	}
	cout<<"\n\t\tSuccessfully Sorted the Books by Rating!!!!";
	
}
//////////////////////////////////////////////////////
template <class H>
void Linklist<H>::sortByPrice()
{
	if(start==NULL)
	{
		cout<<"\nLinklist is empty!!";
		return;
	}
	else
	{
		for(Node<H>* p=start;p!=NULL;p=p->getNext())
		{
			for(Node<H> * q=p->getNext();q!=NULL;q=q->getNext())
			{
				if(p->getData().getPrice()<q->getData().getPrice())
				{
				    H temp=p->getData();
					p->setData(q->getData());
					q->setData(temp);	
				}	
			}
		}
	}
	cout<<"\n\t\tSuccessfully Sorted the Books by Price!!!!";
	
}

 ///////////////////////////////////////////////////
 template<class H>
 void Linklist<H>:: readData(char* fn)
 {
 	H data;
 	ifstream in(fn,ios_base::binary);
 	
 	while(in.read((char*)&data,sizeof(data)))
 	{
 		 AddBookByPos(data,1);
 		 
	 }
	 in.close();
 	
}
 /////////////////////////////////////////////////////

template<class H>
 void Linklist<H>::writeData(char* fn)
 {
 	ofstream out(fn,ios_base::binary);
 	Node<H>*p=start;
 	while(p!=NULL)
 	{
 		H data=p->getData();
 		out.write((char*)&data,sizeof(data));
 		p=p->getNext();
	}
 	out.close();
}
/////////////////////////////////////////////////////////

template <class H>
void Linklist<H>::display()
{
	if(start==NULL)
	{
		cout<<"\nNo nodes to print";
	}
	else
	{
		Node <H>* p=start;
		while(p!=NULL)
		{
			p->getData().displayData();
			p=p->getNext();
		}
	}
}
/////////////////////////////////////////////////