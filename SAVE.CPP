clrscr();
 static int i=1, j=1, x=1, y=1;

 for( ;i<=80;i++)
 {
  gotoxy(i,j);
  cout<<"_";
  gotoxy(i,j+20);
  cout<<"_";
 }

 for( ;y<=20;y++)
 {
  gotoxy(x,y);
  cout<<"_";
  gotoxy(x+79,y);
  cout<<"_";
 }

 getch();
}
#include<iostream.h>
#include<conio.h>
void box();
main()
{
 int a[3][5],i,j;
 for(i=0;i<2;i++)
  {
   cout<<"Record of "<<i+1<<"student\n";
    for(j=0;j<5;j++)
     {
      cin>>a[i][j];
      }
   }

 for(i=0;i<2;i++)
  {
   box();
   cout<<"Record of "<<i+1<<"student\n";
    for(j=0;j<5;j++)
     {
     cout<<a[i][j]<<"\n";
      }
   }

 getch();
}

 void box()
{