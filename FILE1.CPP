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
   clrscr();
   student s;
   ofstream fout("a");
   char ch='y';

   int n,i,roll;

   fout.seekp(0);
   while(ch=='y')
   {
     s.enter();
     fout.write((char*)&s,sizeof(s));

     cout<<"Ch = ";
     cin>>ch;
   }

   fout.close();


   ifstream fin("a");
   fin.seekg(0);


   while(fin)
   {
     fin.read((char*)&s,sizeof(s));
     s.display();

   }


   fin.close();

   getch();

   }


