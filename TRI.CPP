#include<iostream.h>
#include<conio.h>
main()
{
 clrscr();
 int i,j,n;

 cout<<"Enter no. of rows\n";
 cin>>n;

 for(i=0;i<n;i++)
  {
   for(j=0;j<n;j++)
    {
      if(i+j==n-1 || i+j>=n )
       cout<<"*";
      else
       cout<<" ";
    }
   cout<<"\n";
  }
 getch();
}