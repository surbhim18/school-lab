#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
main()
{
 clrscr();
 char str[20]="PASSWORD";
 char a[20];
 int i=0,k=0,found=0;
 char ch;


 for(i=0;str[i]!='\0';i++)
    a[i]='*';

 a[i]='\0';

 for( ;k<4 && strcmpi(str,a)!=0; )
{
  found=0;

  cout<<"\nEnter alphabet: ";
  cin>>ch;

  for(i=0;str[i]!='\0';i++)
  {
     if(str[i]==ch)
     {
       a[i]=str[i];
       found=1;
     }
  }
 if(found==0)
 {
 k++;
 cout<<"WRONG GUESS!!\n";
}
 puts(a);
}

 if(k==4)
{ cout<<"\nGAME OVER!!!\n";
  puts(str);
}
 if(strcmpi(a,str)==0)
 cout<<"\nYOU WIN\n";

 getch();
 }