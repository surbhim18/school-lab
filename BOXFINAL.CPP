#include<iostream.h>
#include<conio.h>
main()
{
 clrscr();
 static int m=0;
 int i,j,k,l;

 for(i=0;i<40;i++)
  cout<<"*";

 for(j=0;j<11;j++)
 {
  gotoxy(i,j);
  cout<<"*";
  }

  getch();
 }
