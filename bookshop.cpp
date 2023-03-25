/* 

A book shop that maintains the inventory of books that are being sold at shop the list includes
details such as title, author, publisher, price and available stock.
 
 We have to create a c++ program which will have class called book and member functions for
 1.ADD
 2.UPDATE/MODIFY
 3.SEARCH
 4.PURCHASE
 5.NUMBER OF SUCCESSFUL AND UNSUCCESSFUL TRANSACITONS


Basic library management system. The program provides options for adding a book, updating book 
details, searching for a book, purchasing a book, displaying all books, displaying successful 
transactions, and removing a book from the library.
 */
 
 
 
 #include<iostream>
 #include<string.h>
 using namespace std;


 /*
This class defines the Book object and its attributes like book ID, price, author name, title,
publication, and stock. The constructor function is used to allocate memory for author, title
and publication using the 'new' operator.
 */
 class Book
 {
    int book_id,price;
    static int trans;
    char *author,*title,*publ;  //(publ=publication)
    int stock;
    public:
        book()
        {
        author = new char[30];
        title = new char[30];
        publ = new char[30];
        }

        /*This function is used to add a new book to the library. It takes input from the user
        for the book's details like title, author, publication, price, and stock.*/

        void add()
        {
        cout<<"Enter the details of the book\n";
        cout<<" Title of book:\t";
        cin>>title;
        cout<<"Author :\t";
        cin>>author;
        cout<<"Publication :\t";
        cin>>publ;
        cout<<"Price :\t";
        cin>>price;
        cout<<"Stock:\t";
        cin>>stock;
        }


        /*This function displays the details of the book like title, author, publication, price, and stock.*/
        
        void display()
        {
        cout<<"BOOK :\t"<<title<<"\nAuthored by\t"<<author<<"\nPublished by\t"<<publ<<"\nhaving cost:\t"<<price;
        cout<<"Stock:\t"<<stock;
        }

        /*This function is used to update the book's details. It takes input from the user for the book ID that 
        needs to be updated and then checks if the book ID exists in the library. If it exists, the user can 
        update the book's price. If not, it displays a message that the book is not found.*/

        void update(Book b[])
        {
        int i,flag=0;
        int id,price;
        int n=25; // where n is total number of books avialable
        cout<<"Enter the book ID that you want to update";
        cin>>book_id;
            for(i=0;i<n;i++)
            {
                if(id==b[i].book_id)
                {
                    cout<<"Book Found\n";
                    cout<<"Add the new cost\n";
                    cin>>price;
                    cout<<"Reocord updated successfully\n";
                    flag=0;
                }
                else
                    flag=1;
            }
        if(flag=1)
        {
            cout<<"Book not found\n";
        }
        }


          /*
          This function searches for a book by its ID from an array of Book objects. It takes an array of Book objects as a parameter and returns nothing. Here's how it works:

            It prompts the user to enter the book ID to be searched.
            It then iterates over the array of Book objects and checks if the book ID entered by the user matches with the book ID of any book in the array.
            If a match is found, it displays the details of that book by calling the display function of the Book class.
            If no match is found, it displays a message that the book was not found.
          */
          void search(Book b[])
          {
          int i,flag=0;
          int id;
          int n=25;
          cout<<"Enter the book id to b searched\n";
          cin>>id;
            for(i=0;i<n;i++)
            {
                if(id==b[i].book_id)
                {
                    cout<<"Book found\n";
                    b[i].display();
                    flag=0;
                }
                else
                flag=1;
            }
            
            if(flag=1)
            {
            cout<<"BOok not found\n";
            }
        }     
             
        /*
        This function is used to purchase a book. It takes an array of Book objects as a parameter and returns nothing. 
        Here's how it works:

        It prompts the user to enter the book ID of the book to be purchased.
        It then iterates over the array of Book objects and checks if the book ID entered by the 
        user matches with the book ID of any book in the array.
        If a match is found, it displays a message that the book is available and prompts the user to 
        confirm the purchase by entering 'y' or 'Y'.
        If the user confirms the purchase, it deducts one from the stock of the book and increments the 
        transaction counter by calling the static transactions function of the Book class. 
        It also displays a message that the purchase was successful.
        If the user does not confirm the purchase, it displays a message that the purchase was cancelled.
        If no match is found, it displays a message that the book is not available.
        */
        void purchase(Book b[])
        {
            int i,flag=0;
            int id,n=25;
            char ans;
            int trans;
            cout<<"Enter the book ID:\t";
            cin>>id;
                for(i=0;i<n;i++)
                {
                    if(b[i].book_id==id)
                    {
                        cout<<"Book is available\n";
                        cout<<"Would you like to purchase it\n";
                        cin>>ans;
                        if(ans =='y' || ans == 'Y')
                        {
                            cout<<"Book price :\t"<<b[i].price;
                            trans++;
                            stock--;
                            cout<<"Purchase successful\n";
                            flag=0;
                        }
                        else
                        {
                            cout<<"better Next time\n";
                    
                        }
                    }         
                    else
                    {
                        flag=1;
                    }
                }
            if(flag=1)
            {
            cout<<"book not available \n";
            }
        
        }

        /*
        This function is used to delete a book from the array of Book objects. 
        It takes an array of Book objects as a parameter and returns nothing. Here's how it works:

        It prompts the user to enter the book ID of the book to be deleted.
        It then iterates over the array of Book objects and checks if the book ID entered by the 
        user matches with the book ID of any book in the array.
        If a match is found, it deletes the memory allocated to the character arrays for storing 
        the book's title, author, and publication using the delete operator. It also sets the stock 
        of the book to -1 to indicate that it has been deleted. It displays a message that the 
        book was found and deleted.
        If no match is found, it displays a message that the book was not found.
        */             
        void deleterecord(Book b[])
        {
            int i,n=25;
            int flag=0,id;
            cout<<"Enter the book ID that you want to delete\n";
            cin>>id;
                for(i=0;i<n;i++)
                {
                    if(b[i].book_id==id)
                    {
                        cout<<"book found\n";
                        delete b[i].title;
                        delete b[i].author;
                        delete b[i].publ;
                        b[i].stock =-1;
                        flag=1;
                        break;
                    }
                    else
                        flag=0;
                }
                
                if(flag=0)
                {
                    cout<<"Book not found";
                }
        }

        /*
        static member function of the Book class. It is used to display the total number 
        of successful transactions. It does not take any input parameters and does not 
        modify any class variables.

        The function simply prints the value of the static trans variable, which is 
        incremented each time a successful purchase is made by calling the purchase function. 
        Therefore, the transactions function shows the total number of successful purchases 
        made by calling the purchase function throughout the program's execution.
        */
        static void transactions()
        {
            int trans;
            cout<<"\n Successful transactions are = "<<trans;
        }
    };
    
    


    /*
    The main function starts by creating an array of Book objects named B with a size of 25. 
    It then initializes some variables such as i and ch which will be used in a do-while loop 
    that runs until the user chooses to exit.

    Within the loop, the user is prompted to enter a choice of operation they would like to 
    perform from a menu of options. The program then uses a switch statement to execute the 
    corresponding function based on the user's input.

    If the user chooses option 1, the add() function is called on the Book object at index i 
    of the B array, which prompts the user to input details of a new book and adds it to the array. 
    The index i is then incremented to point to the next available slot in the array.

    If the user chooses option 2, the display() function is called on the Book object at index i,
     which displays details of the book at that index.

    If the user chooses option 3, the update() function is called on the Book object at index i, 
    passing in the entire B array as an argument. This function searches for a book with a 
    matching ID entered by the user, and updates its price.

    If the user chooses option 4, the search() function is called on the Book object at index i, 
    passing in the entire B array as an argument. This function searches for a book with a matching 
    ID entered by the user, displays its details, and allows the user to purchase it.

    If the user chooses option 5, the purchase() function is called on the Book object at index i, 
    passing in the entire B array as an argument. This function allows the user to purchase a book 
    with a matching ID entered by the user, reducing the stock of that book by 1.

    If the user chooses option 6, the transactions() function is called on the Book object at index i, 
    which displays the total number of successful transactions.

    If the user chooses option 7, the deleterecord() function is called on the Book object at index i, 
    passing in the entire B array as an argument. This function searches for a book with a matching ID 
    entered by the user, and removes it from the array by setting its stock to -1.

    After each operation, the user is prompted to enter a choice of whether to continue or exit the program. 
    If the user chooses to exit, the loop terminates and the main function returns 0, indicating successful program termination.
    
    */
    int main() {
	Book B[25];
	int i, ch,c = 1 ;

	i = 0;

	do {

		cout<<"\n1.Add a book\n2.Update a book record\n3.Search a book\n4.Purchase a book\n5.Display all book\n6.Diplay transactions\n7.Remove book\nEnter what do you want to do?";
		cin>>ch;

		switch(ch) {
			case 1:
				B[i].add();
				i++;
				break;
      case 2:
        B[i].display();
        i++;
        break;
			case 3:
				B[i].update(B);
				break;
			case 4:
				B[i].search(B);
				break;
			case 5:
				B[i].purchase(B);
				break;
			case 6:
				B[i].transactions();
				break;
			case 7:
				B[i].deleterecord(B);
				break;
			default:
				cout<<"\nSorry, you entered wrong choice \n Please try again";
		}

		cout<<"\n Do you want to continue?\n1.Yes 2.No";
		cin>>c;

	} while(c==1);

	return 0;
}