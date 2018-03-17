//program: reverse triangle

#include<iostream.h>
#include<conio.h>
main()
 {
  clrscr();
  int n,i,j;
  cout<<"enter the no. of rows\n";
  cin>>n;

  for(i=n;i>=1;i--)
   {
    for(j=1;j<=n-i;j++)
     cout<<" ";

    for(j=1;j<=i;j++)
     cout<<"*";

    for(j=1;j<=i-1;j++)
     cout<<"*";

   cout<<"\n";
   }
 getch();
 }
