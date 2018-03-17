#include<iostream.h>
#include<conio.h>
#include<string.h>
main()
{
 clrscr();
 int i;
 char pass[20] = "Surbhi";
 char ch[20];

 cout<<"Enter password :\n";
 for(i=0;i<6;i++)
 {
  ch[i] = getch();
  cout<<"*";
 }
  ch[i]= '\0';

  getch();

 if(strcmp(pass,ch)==0)
  cout<<"\nCorrect password !!\n";
 else
  cout<<"\nPassword Incorrect !!!\nAccess Denied!!\n";

  getch();
  getch();
 }