#include"LL.cpp"
#include<iostream>
using namespace std;
//#include"Book.h"
//#include"Dll.h"
int main() 
{
	int choice=0;
	
	Linklist<Book> dll;
	dll.readData("object.bin"); //linklist object
	do
	{
		cout<<"\n\t\t******************************* BOOK MANAGEMENT SYSTEM ***********************\n";
		cout<<"\n\t\t\t\t\t\t1.Display Book:";
		cout<<"\n\t\t\t\t\t\t2.Add Book:";
		cout<<"\n\t\t\t\t\t\t3.Search Book:";
		cout<<"\n\t\t\t\t\t\t4.Update Book:";
		cout<<"\n\t\t\t\t\t\t5.Delete Book:";
		cout<<"\n\t\t\t\t\t\t6.Sorting Book:";
		cout<<"\n\t\t\t\t\t\t7.Exit";
		
		
		cout<<"\n\t\tEnter Your Choice: ";
		cin>>choice;
		
		switch(choice)
		{
			case 1:
				{
					dll.display();	
					dll.writeData("object.bin");
					break;
				}
			case 2:
				{
					int pos;
					int bID;
					char bName[50], aName[50], cat[50];
					double price,rating;
					
					cout<<"\n\t\tEnter Book ID:";
					cin>>bID;
					
					fflush(stdin);
					cout<<"\t\tEnter Book Name:";
					gets(bName);
					
					cout<<"\t\tEnter Author Name:";
					gets(aName);
					
					cout<<"\t\tEnter Category:";
					gets(cat);
					
					fflush(stdin);
					cout<<"\t\tEnter Price:";
					cin>>price;
					
					cout<<"\t\tEnter Rating:";
					cin>>rating;
					
					Book b1(bID,bName,aName,cat,price,rating);
					//insert position
					cout<<"\n\t\tEnter the position:";
					cin>>pos;
					dll.AddBookByPos(b1,pos);
						
					break;
				}
			case 3:
				{
					cout<<"\n\t\t1.Book ID";
					cout<<"\n\t\t2.Book Name";
					cout<<"\n\n\t\tSearch Book By :";

					int choice1=0;
					cin>>choice1;
					
					if(choice1==1)
					{
						int bID;
						cout<<"\n\t\tEnter the Book Id which do you want to Search:";
						cin>>bID;
						Node<Book> * res =dll.SearchByBookId(bID);
					    if (res == NULL) 
						{
					        cout << "\n\t\tPlayer not found:\n";
					    } 
						else 
						{
					        res->getData().displayData();
					    }
						
						cout<<"\n\t\t--------------Data Updated Successfully-------------------\n\n";
							
						
					}
					else if(choice1==2)
					{
						char bName[50];
						fflush(stdin);
						cout<<"\nEnter the Book Name which do you want to Search:";
						gets(bName);
						Node<Book>* res=dll.SearchByBookName(bName);
						if (res == NULL) 
						{
					        cout << "\n\t\tPlayer not found\n";
					    } 
						else 
						{
					        res->getData().displayData();
				        }
						cout<<"\n\t\t---------Data Updated Successfully----------------\n";
							
					}
					else
						cout<<"\n\t\tInvalid choice. Please try again.\n";
					break;
				}
				
			case 4:
				{
					int b;
					cout << "\n\t\tEnter the Book id to Update Data: ";
                    cin >> b;
					dll.updateBook(b);
					
					
					break;
				}
			case 5:
				{
					int bID;
					cout << "\n\t\tEnter the Book id delete: ";
                    cin >> bID;
					dll.deleteBook(bID);
					
					break;			
				}
				
			case 6:
				{
					int ch=0;
					cout << "\n\t\tChoose what to Sort:";
			        cout << "\n\t\t1. Book Sort By Rating";
			        cout << "\n\t\t2. Book Sort By Price\n";
			        
			        cout << "\n\t\tEnter your choice: ";
			        cin >> ch;
			        if(ch==1)
			        {
			        	dll.sortByRating();
			        	
					}
					else if(ch==2)
					{
						dll.sortByPrice();
					}
					else
					{
						cout << "\n\t\tInvalid choice. Please try again.\n"; 
					}
					break;
				}
			case 7:
				{
					
					cout<<"\n\t\t\t!!!!!!!!!!!!!!!!! Exiting Program !!!!!!!!!!!\n";
					break;
				}
			/*case 9:
				{
            		dll.writeData("object.bin");
				}
				break;*/
			default:
				{
					cout<<"\n\t\t\t\tPlease enter valid Choice!!!\n";
				}
		}
	}while(choice!=7);
	return 0;
}