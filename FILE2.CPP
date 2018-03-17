//insertion
#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>

 class student
{
  char name[20];
  int rno;

  public:
  void enter();
  void display();
  int getrno();
};

 void student:: enter()
 {
  cout<<"\nName : ";
  gets(name);
  cout<<"R.no. : ";
  cin>>rno;
 }

  void student:: display()
 {
  cout<<"\n";
  cout<<"Name : ";
  puts(name);
  cout<<"R.no. : ";
  cout<<rno;
 }

  int student:: getrno()
  {
    return rno;
  }

 main()
{
  student s1;
  ifstream fin("a",ios::in);
  ofstream fout("temp");


  cout<<"Enter new record : ";
  s1.enter();