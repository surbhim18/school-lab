#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<process.h>
#include<stdio.h>

struct cri
{
 char name[20];
 int age;
 char crime[20];
 char date[15];
 char add[250];
 char punish[20];
 char inch[20];
}c[100];

int n;
void enter( cri[]);
void pass();
void sedisp(cri[], int);
void sodisp(cri[]);
void box();
void insert(cri[]);
void delet(cri[]);
void sename(cri[]);
void secrime(cri[]);
void seinch(cri[]);
void seage(cri[]);
void sortn(cri[]);
void sorta(cri[]);
void modadd(cri[]);
void modver(cri[]);

void pass()
{
 clrscr();
 int i;
 char pass[20] = "surbhi";
 char ch[20];

 cout<<"Enter password :\n";
 for(i=0;i<6;i++)
 {
  ch[i] = getch();
  cout<<"*";
 }
  ch[i]= '\0';

  getch();

 if(strcmp(pass,ch)==0);
 else
 { cout<<"\nAccess Denied!!\n";
   exit(0);
 }

 cout<<"\n";
}


void enter(cri c[100])
{
 int i;
 cout<<"Enter the no. of records you want to enter : ";
 cin>>n;


  for(i=0;i<n;i++)
  {
   cout<<"\nEnter name of "<<i+1<<" criminal : ";
   gets(c[i].name);
   cout<<"Enter age : ";
   cin>>c[i].age;
   cout<<"Enter address : ";
   gets(c[i].add);
   cout<<"Enter crime committed : ";
   gets(c[i].crime);
   cout<<"Enter date of crime(DD/MM/YY) : ";
   gets(c[i].date);
   cout<<"Enter punishment given : ";
   gets(c[i].punish);
   cout<<"Enter case incharge : ";
   gets(c[i].inch);
   cout<<"\n";
   }
 }

 void insert(cri c[100])
{
  int i=n;

  cout<<"\nEnter name of criminal : ";
   gets(c[i].name);
   cout<<"Enter age : ";
   cin>>c[i].age;
   cout<<"Enter address : ";
   gets(c[i].add);
   cout<<"\nEnter crime committed : ";
   gets(c[i].crime);
   cout<<"Enter date of crime(DD/MM/YY) : ";
   gets(c[i].date);
   cout<<"Enter punishment given : ";
   gets(c[i].punish);
   cout<<"Enter case incharge : ";
   gets(c[i].inch);


  n++;
}

 void delet( cri c[100])
{
  int i;
  char nam[20];
  int found=0;
  cout<<"Enter the name of criminal whose record is to be deleted\n";
  gets(nam);

  for(i=0;i<n;i++)
   {
    if(strcmpi(c[i].name,nam)==0)
     {
      found=1;
      break;
     }
   }
  if(found==1)
  {
    for( ;i<n-1;i++)
      c[i] = c[i+1];

    n--;
  cout<<"\nRecord deleted\n";
  }
  else
  cout<<"Record not found. Please try again\n";

  }

 void sename(cri c[100])
 {
  char nam[20];
  int i,found=0;
  cout<<"Enter the name of criminal whose record is to be searched\n";
  gets(nam);

  for(i=0;i<n;i++)
   {
    if(strcmpi(c[i].name,nam)==0)
   {  sedisp(c,i);
      found++;
   }
 }

  if(found==0)
   cout<<"No records found!!\n";

 }

 void secrime(cri c[100])
{
   char cr[20];
  int i, found=0;
  cout<<"Enter the crime to be searched\n";
  gets(cr);

  for(i=0;i<n;i++)
   {
    if(strcmpi(c[i].crime,cr)==0)
   {
     sedisp(c,i);
      found++;
   }
}
  if(found==0)
   cout<<"No records found!!\n";

 }

 void seinch(cri c[100])
{
   char in[20];
  int i,found=0;
  cout<<"Enter the case incharge to be searched for\n";
  gets(in);

  for(i=0;i<n;i++)
   {
    if(strcmpi(c[i].inch,in)==0)
     {
	sedisp(c,i);
	found++;
     }
   }
   if(found==0)
    cout<<" No records found!!\n";

}

 void seage(cri c[100])
 {
  int age1, age2,i,found=0;
  cout<<"Enter age group\n";
  cout<<"Lowerlimit : ";
  cin>>age1;
  cout<<"Upperlimit : ";
  cin>>age2;

  for(i=0;i<n;i++)
   {
    if(c[i].age>=age1 && c[i].age<=age2)
    {
     sedisp(c,i);
     found++;
    }
  }
  if(found==0)
   cout<<"No records found!!\n";

 }

 void sedisp(cri c[100], int i)
 {
    cout<<"\nName of criminal : ";
   puts(c[i].name);
   cout<<"Age : ";
   cout<<c[i].age;
   cout<<"\nAddress : ";
   puts(c[i].add);
   cout<<"Crime committed : ";
   puts(c[i].crime);
   cout<<"Date of crime : ";
   puts(c[i].date);
   cout<<"Punishment given : ";
   puts(c[i].punish);
   cout<<"Case incharge : ";
   puts(c[i].inch);
   cout<<"\n";

 }

 void sortn(cri c[100])
{
 int i,j;
 cri temp;

  for(i=0;i<n;i++)
   {
    for(j=0;j<n-i-1;j++)
     {
      if(strcmpi(c[j].name,c[j+1].name)>0)
       {
	 temp = c[j];
	 c[j] = c[j+1];
	 c[j+1] = temp;
       }
      }
    }

  sodisp(c);
 }
 void sorta(cri c[])
 {
   int i,j;
 cri temp;

  for(i=0;i<n;i++)
   {
    for(j=0;j<n-i-1;j++)
     {
      if(c[j].age>=c[j+1].age)
       {
	 temp = c[j];
	 c[j] = c[j+1];
	 c[j+1] = temp;
       }
      }
    }

   sodisp(c);
  }
 void sodisp(cri c[100])
 {
  int i;

   for(i=0;i<n;i++)
  {
   cout<<"\nName of criminal : ";
   puts(c[i].name);
   cout<<"Age : ";
   cout<<c[i].age;
   cout<<"\nAddress : ";
   puts(c[i].add);
   cout<<"Crime committed : ";
   puts(c[i].crime);
   cout<<"Date of crime : ";
   puts(c[i].date);
   cout<<"Punishment given : ";
   puts(c[i].punish);
   cout<<"Case incharge : ";
   puts(c[i].inch);
   cout<<"\n";

  }
 }

 void modver(cri[])
 {
  char nam[20];
  int ag,i;
  cout<<"Enter name of the criminal\n";
  gets(nam);
  cout<<"Enter age\n";
  cin>>ag;
   for(i=0;i<n;i++)
   {
     if(strcmpi(c[i].name,nam)==0 && c[i].age==ag)
      {
	sedisp(c,i);
	cout<<"Enter the changed verdict\n";
	gets(c[i].punish);
	sedisp(c,i);
      }
   }
 }


void modadd(cri[])
{
   char nam[20];
   int ag,i;
   cout<<"Enter name of the criminal\n";
    gets(nam);
    cout<<"Enter age\n";
    cin>>ag;

   for(i=0;i<n;i++)
   {
     if(strcmpi(c[i].name,nam)==0 && c[i].age==ag)
      {
	sedisp(c,i);
	cout<<"Enter new address\n";
	gets(c[i].add);
	sedisp(c,i);
      }
   }
 }

  main()
{
  char k;
  int ch;

  pass();
  enter(c);

do{
  cout<<"User's Menu\n";
  cout<<"1.Display all records\n";
  cout<<"2.Insert new record\n";
  cout<<"3.Delete existing record\n";
  cout<<"4.Search record by name\n";
  cout<<"5.Search record by age\n";
  cout<<"6.Search record by crime\n";
  cout<<"7.Search record by case incharge\n";
  cout<<"8.Sort records by name\n";
  cout<<"9.Sort records by age\n";
  cout<<"10.Modify verdict\n";
  cout<<"11.Modify address\n";
  cout<<"12.Exit\n";


  cout<<"\nInput your choice\n";
  cin>>ch;

  switch(ch)
 {
  case 1: sodisp(c);
  break;
  case 2: insert(c);
  break;
  case 3: delet(c);
  break;
  case 4: sename(c);
  break;
  case 5: seage(c);
  break;
  case 6: secrime(c);
  break;
  case 7: seinch(c);
  break;
  case 8: sortn(c);
  break;
  case 9: sorta(c);
  break;
  case 10: modver(c);
  break;
  case 11: modadd(c);
  break;
  case 12: { exit(0);
	  cout<<"Thank You for using the program\n";
	   getch();
	  }
     break;
  default: cout<<"Please enter a valid choice\n";
  break;
   }
  cout<<"\nDo you wish to continue? (Y/N)\n";
  cin>>k;

  }while(k=='y' || k=='Y');

  getch();
 }

