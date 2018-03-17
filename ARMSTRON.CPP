#include<iostream.h>
#include<conio.h>
#include<math.h>
main()
{
 clrscr();
 int k,n,i,no,sum,num;

 cout<<"Enter upper limit\n";
 cin>>k;

 for(i=1;i<=k;i++)
 {
  n=i;
  no=n;
  sum=0;

  while(n!=0)
  {
   num=n%10;
   n=n/10;
   sum+=pow(num,3);

  }

 if(sum==no)
  cout<<no<<endl;
 }

 getch();
}