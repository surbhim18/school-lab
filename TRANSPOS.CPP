#include<iostream.h>
#include<conio.h>
main()
{
 clrscr();
 int a[7][7], b[7][7],i,j,r,c;

 cout<<"Enter no. of rows and columns\n";
 cin>>r>>c;

 cout<<"Enter matrix\n";
  for(i=0;i<r;i++)
  {
    for(j=0;j<c;j++)
    cin>>a[i][j];
  }
  cout<<"Your Matrix\n";
    for(i=0;i<r;i++)
  {
    for(j=0;j<c;j++)
    cout<<a[i][j]<<" ";

    cout<<"\n";
  }

  cout<<"Transposed Matrix\n";

    for(i=0;i<r;i++)
  {
    for(j=0;j<c;j++)
    b[j][i] = a[i][j];
  }

  for(i=0;i<c;i++)
   {
    for(j=0;j<r;j++)
     cout<<b[i][j]<<" ";

    cout<<"\n";

   }

  getch();
 }