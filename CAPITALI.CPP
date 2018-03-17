#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
main()
{
 clrscr();
 char str[50], word[15];
 int i, k=0, m=0;

 cout<<"Enter a String\n";
 cin.getline(str,20);

 strcat(str," ");

 for(i=0;str[i]!='\0';i++)
  {
    if(str[i]!=' ')
    {
       word[k]=str[i];
       k++;
   }
    else
  {
    word[m]= toupper(word[m]);

     k=m;

	while(k<i)
      {
       cout<<word[k];
       k++;
     }

  while(m!=k)m++;
  cout<<str[i];
  }
 }
 getch();
}








