#include<iostream.h>
#include<conio.h>
main()
{
 clrscr();
 char str[80];
 int i, word=0;

 cout<<"Enter a string\n";
 cin.getline(str,80);

 for(i=0;str[i]!='\0';i++)
  {
   if(str[i]==' ')
   {
    word++;

    while(str[i++]==' ');
   }
  }

  cout<<"No. of words: "<<++word;

  getch();
 }
