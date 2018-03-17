#include<iostream.h>
#include<conio.h>
main()
{
 int a[100], no=0,i,n, ele ,j=0, b[100];
 clrscr();

 cout<<"Enter no. of elements\n";
 cin>>n;

 cout<<"Enter an array\n";
  for(i=0;i<n;i++)
   cin>>a[i];

 cout<<"Enter element\n";
 cin>>ele;

 for(i=0;i<n;i++)
  {
   if(a[i]==ele)
    no++;
   }

 for(i=0;i<n;i++)
 {
  if(a[i]!=ele)
  {
   b[j+no]=a[i];
    j++;
  }
}
 for(i=0;i<no;i++)
  b[i] = 0;

 cout<<"Output : \n";
 for(i=0;i<n;i++)
  cout<<b[i]<<"  ";

 getch();
}
