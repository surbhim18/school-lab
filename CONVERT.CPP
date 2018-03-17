#include<iostream.h>
#include<conio.h>
#include<string.h>

void digit(int a[], int s)
{
  static int b=1;

 if(b==3 && a[1]==1)
 {
  switch(s)
  {
   case 1: cout<<" eleven ";
   break;
   case 2: cout<<" twelve ";
   break;
   case 3: cout<<" thirteen ";
   break;
   case 4: cout<<" fourteen ";
   break;
   case 5: cout<<" fifteen ";
   break;
   case 6: cout<<" sixteen ";
   break;
   case 7: cout<<" seventeen ";
   break;
   case 8: cout<<" eighteen ";
   break;
   case 9: cout<<" nineteen ";
   break;
  }
 }

  if(b==2)
 {

   switch(s)
   {
    case 1: cout<<"";
    break;
    case 2: cout<<" twenty ";
    break;
    case 3: cout<<" thirty ";
    break;
    case 4: cout<<" forty ";
    break;
    case 5: cout<<" fifty ";
    break;
    case 6: cout<<" sixty ";
    break;
    case 7: cout<<" seventy ";
    break;
    case 8: cout<<" eighty ";
    break;
    case 9: cout<<" ninety ";
    break;
   }

 }

 else if(b==1 || b==3 && a[1]!=1)
 {
  switch(s)
  {
   case 1: cout<<" one ";
   break;
   case 2: cout<<" two ";
   break;
   case 3: cout<<" three ";
   break;
   case 4: cout<<" four ";
   break;
   case 5: cout<<" five ";
   break;
   case 6: cout<<" six ";
   break;
   case 7: cout<<" seven ";
   break;
   case 8: cout<<" eight ";
   break;
   case 9: cout<<" nine ";
   break;
  }
 }

  if(b==1)
  cout<<" hundred ";

  b++;

 }



 main()
{
  clrscr();
  int n,i,a[5];

  cout<<"Enter a 3 digit no. : ";
  cin>>n;

  for(i=0;n!=0;i++)
   {
     a[i]=n%10;
     n=n/10;
   }

  for(--i;i>=0;i--)
   digit(a,a[i]);


  getch();
}


