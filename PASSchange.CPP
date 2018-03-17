#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
main()
{
 clrscr();
 int i;
 char pass[20]="surbhi",p[20];

  char ch[20],b;
do{

 cout<<"\nEnter password :\n";
 for(i=0;i<strlen(pass);i++)
 {
  ch[i] = getch();
  cout<<"*";
 }
  ch[i]= '\0';

  getch();

 if(strcmp(pass,ch)==0)
 { cout<<"\nCorrect password !!\n";

   cout<<"Change password\n";
   gets(p);


   strcpy(pass,p);
   cout<<"Pass changed\n";
 }
 else
  cout<<"\nPassword Incorrect !!!\nAccess Denied!!\n";

 cout<<"Enter ch: "; cin>>b;
 }while(b=='y');

  getch();
  getch();
 }
