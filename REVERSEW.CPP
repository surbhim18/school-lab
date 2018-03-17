#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
main()
{
 clrscr();
 int l,i,k=0;
 char str[80], word[80];

 cout<<"Enter a string (max. 80 chars)\n";
 cin.getline(str,80);

 strcat(str," ");

 for(i=0;str[i]!='\0';i++)
  {
    if(str[i]!=' ')
     {
      word[k]= str[i];
      k++;
     }

  else
   {
    while(k>0)
     {
      cout<<word[--k];
     }
    cout<<str[i];
   }
 }
 getch();
}