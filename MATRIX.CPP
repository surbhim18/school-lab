#include<iostream.h>
#include<conio.h>
#include<process.h>
main()
{
 int a[10][10], i,j,n,ch,sum=0;
 clrscr();

 cout<<"Enter dimensions for matrix\n";
 cin>>n;

 cout<<"Enter a matrix\n";
  for(i=0;i<n;i++)
  {
   for(j=0;j<n;j++)
    cin>>a[i][j];
   }

 cout<<"Your matrix is\n";
    for(i=0;i<n;i++)
  {
   for(j=0;j<n;j++)
    cout<<a[i][j]<<" ";
    cout<<"\n";
   }

  cout<<"MENU\n";
  cout<<"Display and sum :\n";
  cout<<"1. Upper triangular\n";
  cout<<"2. Lower triangular\n";
  cout<<"3. Diagonals\n";
  cout<<"Enter your choice\n";
  cin>>ch;


  switch(ch)
  {
   case 1:
 {
  sum=0;
  for(i=0;i<n;i++)
  {
   for(j=0;j<n;j++)
    {
     if(i<=j)
     {
       cout<<a[i][j]<<" ";
       sum+=a[i][j];
     }
     else
     cout<<"  ";
    }
    cout<<"\n";
   }
 } break;

 case 2:
 {
   sum=0;
    for(i=0;i<n;i++)
  {
   for(j=0;j<n;j++)
    {
     if(i>=j)
    {
     cout<<a[i][j]<<" ";
     sum+=a[i][j];
    }
     else
     cout<<"  ";
    }
    cout<<"\n";
   }
 }  break;

 case 3:
 {
  sum=0;
    for(i=0;i<n;i++)
  {
   for(j=0;j<n;j++)
    {
     if(i==j || i+j==n-1)
    {
     cout<<a[i][j]<<" ";
     sum+=a[i][j];
    }
     else
     cout<<"  ";
    }
    cout<<"\n";
   }
 } break;

 default: { cout<<"Enter a valid choice\n";
	   exit(0);
	   }
 }

 cout<<"Sum is "<<sum;
 getch();
}