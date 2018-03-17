#include<iostream.h>
#include<conio.h>
main()
{
 clrscr();
 static int i=1, j=1, x=1, y=1;

 for( ;i<=80;i++)
 {
  gotoxy(i,j);
  cout<<"*";
  gotoxy(i,j+20);
  cout<<"*";
 }

 for( ;y<=20;y++)
 {
  gotoxy(x,y);
  cout<<"*";
  gotoxy(x+79,y);
  cout<<"*";
 }

 getch();
}
