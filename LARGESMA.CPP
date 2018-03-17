#include<iostream.h>
#include<conio.h>
main()
{
 clrscr();
 int i, max, n, a[20];

 cout<<"Enter the no. of elements to be compared\n";
 cin>>n;

 cout<<"Enter the elements\n";
  for(i=0;i<n;i++)
   cin>>a[i];

  int large( int [], int);
  max = large(a,n);

  cout<<"\nLagest no. is : "<<max;

  getch();
  }

  int large( int a[20], int n)
  {
   int i,max,min;
   max = a[0];
   min = a[0];

   for(i=1;i<n;i++)
    {
      if(a[i] > max)
	max=a[i];
      else if (a[i] < min)
       min = a[i];
    }

    cout<<"Smallest no. is "<<min;
    return max;
  }

