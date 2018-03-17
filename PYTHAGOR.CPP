#include<iostream.h>
#include<conio.h>
#include<math.h>
main()
{
 clrscr();
 int i,j,k,n;

 cout<<"Enter upper limit\n";
 cin>>n;

 for(i=1;i<=n-2;i++)
 {
  for(j=i+1; j<=n-1;j++)
  {
   for(k=j+1; k<=n; k++)
    {
      if(pow(k,2)==pow(j,2)+pow(i,2))
       cout<<i<<" "<<j<<" "<<k<<endl;
    }
   }
 }
 getch();
}
