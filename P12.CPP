#include<fstream.h>
#include<conio.h>
#include<string.h>
#include<dos.h>
#include<stdio.h>
#include<process.h>


static int b=1;
static int t=1011;
int a,n;


class rail
{
  private:
	   int sno;
	   char name[50];
	   char address[100];
	   int phno;
	   char train[20];
	   int journey;
	   int tno;
	   int userno;

   public:
	   char* getname()
	    {
	      return name;
	    }
	  int getuserno()
	    {
	      return userno;

	  }

       void enter()
	{
	  sno=b;
	  cout<<"\nserial number is          : ";
	  cout<<sno;
	  cout<<"\nenter your name           : ";
	  gets(name);
      /*	  cout<<"\nenter your address        :";
	  gets(address);
	  cout<<"\nenter your contact number :";
	  cin>>phno;
	  cout<<"\nenter your train number   :";
	  gets(train);
	  cout<<"\nenter your journey date   :";
	  cin>>journey;
	  cout<<"\nyour ticket number is     :";
	  t=t+2;
	  cout<<t;
     */	  cout<<"enter your user number    :" ;
	  cin>>userno;
	  b++;


	 }



 void display()
   {

    cout<<"\n\nserial number                  : ";
    cout<<sno;
    cout<<"\nname                             :";
    puts(name);
/*    cout<<"address                          : ";
    puts(address);
    cout<<"contact number                   : ";
    cout<<phno;
    cout<<"\ntrain                            :";
    puts(train);
    cout<<"journey date                     : ";
    cout<<journey;
    cout<<"\nticket number                    :";
    cout<<t;
			 */
    cout<<"user number                      :";
    cout<<userno;
   }
  }r1;

  void search()
 {
  int found=0;
  char nam[20];
  rail r;

  ifstream fin("a",ios::out|ios::binary);

  cout<<"\nEnter name: ";
  gets(nam);

  while(fin)
  {
     fin.read((char*)&r,sizeof(r));

     if(strcmpi(r.getname(),nam)==0)
     {
       r.display();
       found=1;
       break;
     }
  }
  if(found==0)
  cout<<"Not found!!!!";
  fin.close();

 }
  void insert()
    {
       rail r;
       rail r1;


      ifstream fin("a",ios::in|ios::binary);
      ofstream fout("b",ios::out|ios::binary);
      char last='y';

      cout<<"enter the details whose record is to be inserted ";
      r1.enter();

      while(fin)
       {
	   fin.read((char*)&r,sizeof(r));
	   if(r1.getuserno()<=r.getuserno())
	      {
		 fout.write((char*)&r1,sizeof(r1));
		 fout.write((char*)&r,sizeof(r));
		 last='n';
		 break;
	      }
	 else
	   fout.write((char*)&r,sizeof(r));
      }
   if(last=='y')
   fout.write((char*)&r1,sizeof(r1));
   else if(!fin.eof());
   {
     while(fin)
       {
	  fin.read((char*)&r,sizeof(r));
	  fout.write((char*)&r,sizeof(r));
       }
   }
     fin.close();
     fout.close();
     remove("a");
     rename("b","a");
     fin.open("a",ios::in);
     cout<<"file now contains \n";
     while(fin)
      {
	fin.read((char*)&r,sizeof(r));
	if(fin.eof())
	break;
	r.display();
     }
     fin.close();
   }




   void delet()
   {  rail r;
      rail r1;

      int user;
      char found='f',confirm='n';

      ifstream fin("a",ios::in|ios::binary);
      ofstream fout("b",ios::out|ios::binary);
      cout<<"enter the user number that you want to delete \n ";
      cin>>user;

      while(fin)
	{
	   fin.read((char*)&r1,sizeof(r1));
	   if(r1.getuserno()==user)
	      {
		  r1.display();
		  found='t';
		  cout<<"\nAre you sure that you want to delete this record ? (y/n)";
		  cin>>confirm;
		  if(confirm=='n')
		  fout.write((char*)&r1,sizeof(r1));
	      }

	  else
	    fout.write((char*)&r1,sizeof(r1));
	}

      if(found=='f')
      cout<<"record not found ";
      fin.close();
      fout.close();
      remove("a");
      rename("b","a");
      fin.open("a",ios::in);
      cout<<"now the file contains \n ";

      while(fin)
      {
	fin.read((char*)&r,sizeof(r));
	if(fin.eof())
	break;
	r.display();
      }

	fin.close();

}

  void disp()
 {
    rail r;
    ifstream fin("a",ios::out|ios::binary);

    while(fin)
    {
      fin.read((char*)&r,sizeof(r));
       if(fin)
       r.display();
    }

   fin.close();
 }


void  main()
 {
     clrscr();

     gotoxy(30,10);
  cout<<"WELCOME TO INDIAN RAILWAYS...";
   clrscr();
     int i;
     char str[20]="savi",str1[20];
     cout<<"Enter the password \n";

     for(i=0;i<4;i++)
      {
	str1[i]=getch();
	cout<<"*";
      }
	 str1[i]='\0';
	if(strcmpi(str,str1)==0)
	cout<<"Password is correct \n";
	else
	exit(0);


  gotoxy(30,10);
  cout<<"WELCOME TO C++ PROJECT \n ";
  clrscr();
/*  gotoxy(30,10);
  cout<<"p";
  delay(1500);
  gotoxy(32,10);
  cout<<"r";
  delay(1500);
  gotoxy(34,10);
  cout<<"o";
  delay(1500) ;
  gotoxy(36,10);
  cout<<"c";
  delay(1500)  ;
  gotoxy(38,10);
  cout<<"e";
  delay(1500) ;
  gotoxy(40,10);
  cout<<"s";
  delay(1500);
  gotoxy(42,10);
  cout<<"s";
  delay(1500);
  gotoxy(44,10);
  cout<<"i";
  delay(1500);
  gotoxy(46,10);
  cout<<"n";
  delay(1500);
  gotoxy(48,10);
  cout<<"g";
  delay(2500);       */
  clrscr();

     rail r;
   int j;
   char ch;

 do{  cout<<"\n1. Ticket reservation\n";
   cout<<"2. Searching \n";
   cout<<"3. Cancellation \n";
   cout<<"4. Insertion \n\n";
   cout<<"Enter your choice : ";
   cin>>a;

   switch(a)
   {

     case 1:
		cout<<"Enter the no. of records \n";
	       cin>>n;

	       ofstream fout;
	       ifstream fin("a",ios::in|ios::binary);

	     if(fin)
	       fout.open("a",ios::out|ios::binary);
	     else
	       fout.open("a",ios::out|ios::binary);

	     fin.close();

	      for(j=0;j<n;j++)
	    {
	      r.enter();
	      fout.write((char*)&r,sizeof(r));

	    }

	    fout.close();
	    disp();
	    break;

    case 2: search();
	    break;
    case 3:delet();
	   disp();
	    break;
    case 4:insert();
	    disp();
	    break;

  }
  cout<<"\n\nDo you want to continue: ";
  cin>>ch;

 }while(ch=='y' || ch=='Y');


   getch();
 }

