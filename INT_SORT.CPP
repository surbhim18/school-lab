#include<iostream.h>
#include<conio.h>
#include<string.h>
main()
{
 int a[15],i,j,n,temp;
 clrscr();

 cout<<"Enter the no. of elements\n";
 cin>>n;

 cout<<"Enter the array\n";
  for(i=0;i<n;i++)
   cin>>a[i];

  for(i=0;i<n-1;i++)
   {
    for(j=0;j<n-i-1;j++)
     {
      if(a[j]>a[j+1])
       {
	temp= a[j];
	a[j] = a[j+1];
	a[j+1]= temp;
	}
      }
    }
   cout<<"The sorted array is\n";
    for(i=0;i<n;i++)
     cout<<a[i]<<"\n";

  getch();
 }