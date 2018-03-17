#include<iostream.h>
#include<conio.h>
main()
{
 clrscr();
 int no,n, a[20][3],i=0,j=0,m;

 for(i=0;i<20;i++)
  for(j=0;j<3;j++)
   a[i][j]=0;

 cout<<"Enter a no.to convert from octal to binary\n";
  cin>>n;

  i=0;
  while(n!=0)
 {
   no=n%10;
   n= n/10;

   j=0;
   while(no!=0)
   {
     a[i][j] = no%2;
     no= no/2;

     j++;
   }
 i++;
  }
  i--;
   cout<<"Binary form is\n";
  for( ; i>=0;i--)
   for(j=2;j>=0;j--)
    cout<<a[i][j];

   getch();
  }