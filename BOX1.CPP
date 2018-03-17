#include<iostream.h>
#include<conio.h>
main()
{
 clrscr();
 static int i=1, j=1, x=1, y=1;

 for( ;y<=20;y++)
 {
  gotoxy(x,y);
  cout<<"_";
  gotoxy(x+79,y);
  cout<<"_";
 }

  for( ;i<=80;i++)
 {
   gotoxy(i,j+20);
  cout<<"_";
  gotoxy(i,j);
  cout<<"_";

 }

 cout<<"  ";
 getch();
}
