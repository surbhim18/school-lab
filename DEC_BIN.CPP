#include<iostream.h>
#include<conio.h>
#include<math.h>
main()
{
 clrscr();
 int n,i,a[10];

 cout<<"Decimal to binary\n";
 cout<<"Enter a decimal no\n";
 cin>>n;

 i=0;
 while(n!=0)
 {
  a[i]=n%2;
  n=n/2;
  i++;
 }

 for(--i;i>=0;i--)
 cout<<a[i];

 getch();
}