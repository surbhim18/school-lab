#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>

struct emp
{
  int id;
  char name[20];
  int sal;

  emp* next;
}*front,*rear,*save,*temp,*e1;

 emp* create()
{
  int r,m;
  char n[20];
  e1= new emp;
  cout<<"\nId: ";
  cin>>r;
  cout<<"Name: ";
  gets(n);
  cout<<"Salary: ";
  cin>>m;

  e1->id=r;
  strcpy(e1->name,n);
  e1->sal=m;

  e1->next=NULL;
  return e1;
}

 void insert(emp* e1)
{
  if(rear==NULL)
  front=rear=e1;
  else
  {
    rear->next=e1;
    rear=e1;
  }
}

 void remove()
{
 cout<<"\nEle is being popped...\n";
 if(front==NULL)
 cout<<"Ouch..Underflow!!\n";
 else
  {
    temp=front;
    front=front->next;
    delete temp;

  }
}

 void disp(emp* temp)
{
  cout<<"\nQueue is:";
  if(temp==NULL)
  cout<<" EMPTY!!\n";

  while(temp!=NULL)
  {
    cout<<"\n\nId: "<<temp->id;
    cout<<"\nName: ";
    puts(temp->name);
    cout<<"Sal: "<<temp->sal;;

    temp=temp->next;
  }
}

  main()
{
  clrscr();
  char ch;
  int a;

  cout<<"1.Insert\n";
  cout<<"2.Delete\n";
  cout<<"3.Display\n";

do{ cout<<"\nEnter choice: ";
    cin>>a;

    switch(a)
    {
      case 1:
	      e1=create();
	      insert(e1);
	      break;


      case 2:
	     disp(front);
	     remove();

	     break;

      case 3:
	     disp(front);
	     break;

  }

  cout<<"\nWant to continue: ";
  cin>>ch;

}while(ch=='y'||ch=='Y');

 getch();
}

