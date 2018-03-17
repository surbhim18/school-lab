#include<iostream.h>
#include<conio.h>
main()
{
 clrscr();
 int n,i=0,a[10];

 cout<<"Enter a no. to convert from decimal to binary\n";
 cin>>n;

 while(n!=0)
  {
    a[i]=n%2;
    n=n/2;

    i++;
  }

  cout<<"Binary form is\n";
  for(--i;i>=0;i--)
   cout<<a[i];

  getch();
 }



