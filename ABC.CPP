#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<process.h>
main()
{
 clrscr();
 char str[50], str1[25];
 int i,j,first,found=0;

 if(strlen(str1)>=strlen(str))
 {
  cout<<"not possible";
  exit(0);
 }

 cout<<"Enter string: ";
 gets(str);
 cout<<"Enter substring: ";
 gets(str1);


 for(i=0;str[i]!='\0';i++)
 {
   if(str[i]==str1[0])
   { first=i;
     break;
   }
 }

  for(j=0;str[j]!='\0';i++,j++)
  {
    if(str[i]!=str1[j])
      {
       found=1;
       break;
      }
  }

  if(found==1)
  cout<<"found at "<<first;
  else
  cout<<"not found";

  getch();
 }