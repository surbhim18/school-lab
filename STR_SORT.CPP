#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
main()
{
 clrscr();
 char str[50][20], temp[20];
 int i,j,n;

 cout<<"Enter no. of strings\n";
 cin>>n;

 cout<<"Enter the strings\n";
  for(i=0;i<n+1;i++)
   gets(str[i]);

 for(i=0;i<n-1;i++)
  {
   for(j=0;j<n-i-1;j++)
    {
     if(strcmp(str[j],str[j+1])>0)
      {
       strcpy(temp,str[j]);
       strcpy(str[j],str[j+1]);
       strcpy(str[j+1],temp);
      }
     }
   }

  cout<<"Sorted strings are\n";
   for(i=0;i<n+1;i++)
    puts(str[i]);

   getch();
  }