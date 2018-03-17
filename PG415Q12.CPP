#include<iostream.h>
#include<conio.h>
main()
{
 clrscr();
 int m,n,i,j ,a[15],b[15],c[30];

 cout<<"Enter no. of elements in array 1 & 2\n";
 cin>>m>>n;

 cout<<"Enter array 1\n";
 for(i=0;i<m;i++)
  cin>>a[i];

 cout<<"Enter array 2\n";
 for(i=0;i<n;i++)
  cin>>b[i];

 for(i=0;i<m;i++)
  c[i] = a[i];

 for(j=0;j<n;j++)
  c[i+j]= b[j];

 cout<<"Your array is\n";
  for(i=0;i<m+n;i++)
   cout<<c[i]<<"\n";

  getch();
 }