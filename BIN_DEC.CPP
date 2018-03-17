#include<iostream.h>
#include<conio.h>
#include<math.h>
main()
{
 clrscr();
 int i,sum=0,s,num;
 long int n;

 cout<<"Enter a binary number\n";
 cin>>n;

  i=0;
  while(n!=0)
 {
   num=n%10;
   s= num* pow(2,i);
   n=n/10;
   sum+=s;
   i++;
 }

 cout<<"Decimal no : "<<sum;

 getch();
}
