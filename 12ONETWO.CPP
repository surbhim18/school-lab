#include<iostream.h>
#include<conio.h>
#include<string.h>
main()
{
 clrscr();
 char str[20][20]={ "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven","twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };

 char str1[10][20]= { "twenty" , "thirty", "forty", "fifty", "sixty", "seventy", "eighty","ninety"};

 int n,a;

 cout<<"Enter a no. : ";
 cin>>n;


 if(n>=1000 && n<=9999)
 {
   a=n/1000;
   n=n%1000;

   cout<<str[a-1];
   cout<<" thousand ";
 }

 if(n>=100 && n<=999)
 {
    a=n/100;
    n=n%100;

    cout<<str[a-1];
    cout<<" hundred ";
 }


 if(n>=20 && n<=99)
 {
    a=n/10;
    n=n%10;

    cout<<str1[a-2];
    cout<<" ";
 }

 if(n>=1 && n<=19)
 {
    a=n;

    cout<<str[a-1];
 }


 getch();

 }



