#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<ctype.h>
main()
{
 clrscr();
 char str[50];
 int i;

 cout<<"Enter a string\n";
 gets(str);

 str[0] = toupper(str[0]);

 for(i=0;str[i]!='\0';i++)
  {
   if(str[i]==' ')
    str[i+1] = toupper(str[i+1]);
   }

  puts(str);

  getch();
 }
