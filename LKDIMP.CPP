#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>

struct stu
{
  int rno;
  char name[20];
  int marks;

  stu* next;
}*top,*save,*temp,*s1;

 stu* create()
{
  int r,m;
  char n[20];
  s1= new stu;
  cout<<"\nRno: ";
  cin>>r;
  cout<<"Name: ";
  gets(n);
  cout<<"Marks: ";
  cin>>m;

  s1->rno=r;
  strcpy(s1->name,n);
  s1->marks=m;

  s1->next=NULL;
  return s1;
}

 void push(stu* s1)
{
  if(top==NULL)
  top=s1;
  else
  {
    save=top;
    top=s1;

    s1->next=save;
  }
}

 void pop()
{
 cout<<"\nEle is being popped...\n";
 if(top==NULL)
 cout<<"Underflow\n";
 else
  {
    temp=top;
    top=top->next;
    delete temp;
  }
}

 void disp(stu* temp)
{
  cout<<"\nStack is:";
  if(temp==NULL)
  cout<<" EMPTY!!\n";

  while(temp!=NULL)
  {
    cout<<"\n\nRno: "<<temp->rno;
    cout<<"\nName: ";
    puts(temp->name);
    cout<<"Marks: "<<temp->marks;

    temp=temp->next;
  }
}

  main()
{
  clrscr();
  char ch;
  int a;

  cout<<"1.Push\n";
  cout<<"2.Pop\n";
  cout<<"3.Display\n";

do{ cout<<"\nEnter choice: ";
    cin>>a;

    switch(a)
    {
      case 1:
	      s1=create();
	      push(s1);
	      break;


      case 2:
	     disp(top);
	     pop();

	     break;

      case 3:
	     disp(top);
	     break;

  }

  cout<<"\nWant to continue: ";
  cin>>ch;

}while(ch=='y'||ch=='Y');

 getch();
}

