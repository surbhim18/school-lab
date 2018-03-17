#include<iostream.h>
#include<conio.h>
main()
{
 clrscr();
 int max,min,i,r,c,j, a[10][10];

 cout<<"Enter rows and columns\n";
 cin>>r>>c;

 cout<<"Enter matrix\n";
 for(i=0;i<r;i++)
  for(j=0;j<c;j++)
   cin>>a[i][j];

 cout<<"Your matrix\n";
  for(i=0;i<r;i++)
 {
  for(j=0;j<c;j++)
  {
  cout<<a[i][j];
  cout<<"  ";
  }
  cout<<"\n";
 }
  for(i=0;i<r;i++)
 {
  max=a[i][0];
  min=a[i][0];
  for(j=0;j<c;j++)
  {
    if(a[i][j]>max)
    max=a[i][j];

    if(a[i][j]<min)
    min=a[i][j];

   }

  cout<<"Max of "<<i+1<<" row : "<<max<<" and min : "<<min<<endl;
 }

 getch();
}
