#include<iostream.h>
#include<conio.h>
void box();
main()
{
 clrscr();
 box();
 cout<<" Name: Surbhi"<<endl;
 cout<<" Class: 11-C\n";
 cout<<" school is cool!!";

 box();
 cout<<"you are good\n";
 getch();
 }
void box()
{

 int i=1, x=1;
 static int j=1,y=1;

 for( ;i<=50;i++)
 {
  gotoxy(i,j);
  cout<<"*";
}
  for( ;y<=20;y++)
{ gotoxy(x+50,y);
  cout<<"*";
 }

  for( ;i>=1;i--)
 {  gotoxy(i,j+20);
  cout<<"*";
 }

  for( ;y>=2;y--)
{
  gotoxy(x,y);
  cout<<"*";
 }


 j=j+40;
 y=y+40;

 }
