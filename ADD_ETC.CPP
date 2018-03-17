#include<conio.h>
#include<process.h>
#include<iostream.h>
main()
{
  clrscr();
  int a,b,res;
  char ch;

  cout<<"Enter two no.s\n";
  cin>>a>>b;

  cout<<"Enter an operation(+,-,*,/,%)\n";
  cin>>ch;

  int calc(int, int, char);
  res = calc(a,b,ch);

  cout<<a<<" "<<ch<<" "<<b<<" = "<<res;
  getch();
  }

  int calc(int a, int b, char ch)
  {
   int res;
   switch(ch)
   {
    case '+' : res = a+b;
     break;
    case '-' : res = a-b;
     break;
    case '*': res= a*b;
     break;
    case '/': res = a/b;
     break;
    case '%': res = a%b;
     break;
    default :
    { cout<<"Not a valid character\n";
     exit(0);
     }
   }
   return res;
  }
