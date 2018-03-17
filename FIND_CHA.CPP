#include<iostream.h>
#include<conio.h>
main()
{
  clrscr();
  char str[50], ch;
  int pos;

  cout<<"Enter a string\n";
  cin.getline(str,50);

  cout<<"Enter the character to be found out\n";
  cin>>ch;

  int check(char [] , char);

  pos = check(str,ch);

  if(pos==0)
   cout<<"Character not found !!\n";
  else
   cout<<"Character found - "<<pos<<" position\n";

  getch();
}

 int check(char str[50], char ch)
 {
   int i, pos=0, flag=0;

   for(i=0;str[i]!='\0';i++)
    {
     if(str[i]==ch)
       {
	  flag =1;
	  pos=i+1;
	  break;
       }
    }
 if(flag==1)
  return pos;
 else
  return 0;
 }
