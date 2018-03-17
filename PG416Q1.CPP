#include<iostream.h>
#include<conio.h>
main()
{
 clrscr();
 int n,r,c,i,j,k=0, a[6][6], b[36];

 cout<<"Enter no. of rows and columns\n";
 cin>>r>>c;

 cout<<"Enter the array\n";
 for(i=0;i<r;i++)
  for(j=0;j<c;j++)
   cin>>a[i][j];

 cout<<"Your Matrix\n";
 for(i=0;i<r;i++)
 {
  for(j=0;j<c;j++)
   cout<<a[i][j]<<"  ";

  cout<<"\n";
 }


 for(i=0;i<r;i++)
 {
  for(j=0;j<c;j++)
  {
   b[k] = a[i][j];
   k++;
  }
 }

 n=r*c;

 cout<<"Your array\n";
 for(i=0;i<n;i++)
  cout<<b[i]<<"  ";

  getch();
 }

