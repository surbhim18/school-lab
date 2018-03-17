#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<process.h>
main()
{
  clrscr();
  int i,j;
  char str[50],str1[50];

  cout<<"Enter a string with only A,B,C: ";
  gets(str);


  for(i=0;str[i]!='\0';i++)
  {
    if(str[i]!='A' || str[i]!='B' || str[i]!='C')
    exit(0);
  }

   j=0;
   for(i=0;str[i]!='\0';i++)
  {
    if((str[i]=='A' && str[i+1]=='B')||  (str[i]=='B' && str[i+1]=='A'))
     str1[j++]='C';
    else  if((str[i]=='B' && str[i+1]=='C') ||(str[i]=='C' && str[i+1]=='B'))
     str1[j++]='A';
    else  if((str[i]=='A' && str[i+1]=='C') || (str[i]=='C' && str[i+1]=='A'))
     str1[j++]='B';
  }

    str1[j]='\0';


  cout<<"\n";
  puts(str1);
  cout<<"\nShortest length : "<<strlen(str1);

  getch();
 }