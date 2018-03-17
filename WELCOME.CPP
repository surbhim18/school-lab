#include<iostream.h>
#include<dos.h>
#include<conio.h>
#include<iomanip.h>
main()

{
 void welc();
clrscr();
 clrscr();
 char  str[]="            ****** WELCOME TO CRIMINAL RECORDS FILE ******";
 cout<<str;
 welc();

getch();
}
 void welc()
 {
   int i;
   cout<<endl<<endl;
   char str1[]="LOADING.......";

   for(i=0;str1[i]!='\0';i++)
   {
     delay(500);
     cout<<str1[i];
   }

 }