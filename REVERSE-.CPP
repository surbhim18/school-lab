#include<iostream.h>
#include<conio.h>
#include<string.h>
main()
{
 clrscr();
 int n,len,i,k,j;
 char str[20][50],ch;
 cout<<"Enter the no. of strings\n";
 cin>>n;
 cout<<"Enter the strings\n";
  for(i=0; i<=n;i++)
    cin.getline(str[i],50);

  for(i=0; i<=n;i++)
  {
   len=strlen(str[i]);

   for(k=0,j=len-1;k<len/2;k++,j--)
     {
      ch= str[i][k];
      str[i][k]= str[i][j];
      str[i][j] =ch;
     }

     }

   for(i=0; i<=n;i++)
    {
     len=strlen(str[i]);
      cout.write(str[i],len);
	cout<<"\n";
     }


    getch();
   }



