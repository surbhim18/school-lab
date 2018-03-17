#include<iostream.h>
#include<conio.h>
main()
{
 clrscr();
 int i=0,j=0,k=0,l=0,h;
 static int m=0;

 for(  ;i<=40;i++)
 cout<<"*";

  for(  ;j<=11+m ;j++)
 cout<<"*\n";

 gotoxy(0,m+11);
 for(   ;k<40;k++)
 cout<<"*";

 gotoxy(0,m);
 for(  ;l<=11+m;l++)
{
   for(h=0;h<40;h++)
   {
     cout<<" ";
   }
   cout<<"*";
   cout<<"\n";

 }
 gotoxy(0,m);

 m=m+11;
 getch();
 }