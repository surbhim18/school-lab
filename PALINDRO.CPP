#include<iostream.h>
#include<conio.h>
#include<string.h>
main()
{
 clrscr();
 char str[20];
 int i,j,len,flag=0;

 cout<<"Enter a string\n";
 cin.getline(str,20);

 len= strlen(str);

 for(i=0,j=len-1;i<len/2;i++,j--)
  {
   if(str[i]!=str[j])
    {
     flag = 1;
     break;
    }
  }
  if(flag==1)
   cout<<"It is not  a palindrome ";
   else
   cout<<"It is a palindrome.";

   getch();
  }