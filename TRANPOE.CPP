#include<iostream.h>
#include<conio.h>
main()
{
 clrscr();
 int i,j,r,c, a[6][6], b[6][6];
 cout<<"Enter row and column\n";
 cin>>r>>c;

 cout<<"Enter a matrix\n";
 for(i=0;i<r;i++)
  {
   for(j=0;j<c;j++)
    cin>>a[i][j];
  }

 cout<<"Your matrix is\n";
 for(i=0;i<r;i++)
  {
   for(j=0;j<c;j++)
    cout<<a[i][j]<<" ";

    cout<<"\n";
  }

  for(i=0;i<c;i++)
  {
   for(j=0;j<r;j++)
   b[i][j] = a[j][i];
  }

  cout<<"Transposed matrix is\n";

  for(i=0;i<r;i++)
  {
   for(j=0;j<c;j++)
   cout<<b[i][j]<<" ";

   cout<<"\n";
  }
 getch();
}

