#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
main()
{
 clrscr();
 char str[80], temp;
 int i,j,len;

 cout<<"Enter a string\n";
 cin.getline(str,80);

 len = strlen(str);

 for(i=0,j= len-1;i<len/2 ; i++,j--)
 {
   temp = str[i];
   str[i] = str[j];
   str[j] = temp;
 }

 cout<<"Your string is : ";
 puts(str);

 getch();
}