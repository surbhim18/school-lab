#include<iostream.h>
#include<conio.h>
main()
{
 clrscr();
 static int i,j;
 static int y=1;

// gotoxy(10,2);
 //cout<<"Surbhi!!\n";

 for( ;i<=50;i++)
 {
  gotoxy(i,y);
  cout<<"*";
 }
  for(  ;j<=20;j++)
 {
  gotoxy(i,j);
  cout<<"*";
 }

 for( ;i>=1;i--)
 {
  gotoxy(i,j);
  cout<<"*";
 }

 for(  ;j>=y;j--)
 {
   gotoxy(i,j);
   cout<<"*";
 }

  y=y+40;

 getch();
}
