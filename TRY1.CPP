#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<process.h>
#include<stdio.h>
#include<dos.h>

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
char str[15] = "Loading...";
void enter( cri[]);
void pass();
void sedisp(cri[], int);
void sodisp(cri[]);
void box();
void search();
void sort();
void modify();
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

 cout<<"\n  Enter password :\n  ";
 for(i=0;i<6;i++)
 {
  ch[i] = getch();
  cout<<"*";
 }
  ch[i]= '\0';

  getch();

 if(strcmp(pass,ch)==0)
 clrscr();

 else
 { cout<<"\nAccess Denied!!\n";
   exit(0);
 }

}


void enter(cri c[100])
{

 clrscr();
 cout<<"\n  ";
  for(int k=0; str[k]!='\0';k++)
    {
      delay(300);
      cout<<str[k];
    }
  clrscr();

  cout<<"\n          WELCOME TO THE PROGRAM  \n";
  cout<<"\n";

 cout<<"\n  ENTER\n";
 int i;
 cout<<"  Enter the no. of records you want to enter : ";
 cin>>n;


  for(i=0;i<n;i++)
  {
   cout<<"\n  Enter name of "<<i+1<<" criminal : ";
   gets(c[i].name);
   cout<<"  Enter age : ";
   cin>>c[i].age;
   cout<<"  Enter address : ";
   gets(c[i].add);
   cout<<"  Enter crime committed : ";
   gets(c[i].crime);
   cout<<"  Enter date of crime(DD/MM/YY) : ";
   gets(c[i].date);
   cout<<"  Enter punishment given : ";
   gets(c[i].punish);
   cout<<"  Enter case incharge : ";
   gets(c[i].inch);
   cout<<"\n";
   }
 }

 void insert(cri c[100])
{
  int i=n;
   clrscr();

   cout<<"\n  ";
   for(int k=0; str[k]!='\0';k++)
    {
      delay(500);
      cout<<str[k];
    }
   clrscr();
   cout<<"\n  INSERT\n";
   cout<<"\n  Enter name of criminal : ";
   gets(c[i].name);
   cout<<"  Enter age : ";
   cin>>c[i].age;
   cout<<"  Enter address : ";
   gets(c[i].add);
   cout<<"  Enter crime committed : ";
   gets(c[i].crime);
   cout<<"  Enter date of crime(DD/MM/YY) : ";
   gets(c[i].date);
   cout<<"  Enter punishment given : ";
   gets(c[i].punish);
   cout<<"  Enter case incharge : ";
   gets(c[i].inch);


  n++;
}

 void delet( cri c[100])
{
  int i;
  char nam[20];
  int found=0,ag;

  clrscr();
  cout<<"\n  ";
  for(int k=0; str[k]!='\0';k++)
    {
      delay(500);
      cout<<str[k];
    }

  clrscr();
  cout<<"\n  DELETE\n";
  cout<<"  Enter the name of criminal whose record is to be deleted : ";
  gets(nam);
  cout<<"  Enter age : ";
  cin>>ag;

  for(i=0;i<n;i++)
   {
    if(strcmpi(c[i].name,nam)==0 && c[i].age==ag)
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
  cout<<"\n  Record deleted\n";
  }
  else
  cout<<"  Record not found. Please try again\n";

  }
 void sort()
 {

  clrscr();
  cout<<"\n  ";
  for(int t=0; str[t]!='\0';t++)
    {
      delay(500);
      cout<<str[t];
    }
  clrscr();
  int k;
  cout<<"  SORT\n";
  cout<<"  1.Sort by name\n";
  cout<<"  2.Sort by age\n";
  cout<<"  Enter your choice :  ";
  cin>>k;
  cout<<"\n";

  switch(k)
  {
    case 1: sortn(c);
    break;
    case 2: sorta(c);
    break;
    default : cout<<"  Enter valid choice\n";
    break;
  }

 }

  void search()
  {
   int k;
   clrscr();
  cout<<"\n  ";
  for(k=0; str[k]!='\0';k++)
    {
      delay(500);
      cout<<str[k];
    }

   clrscr();

   cout<<"\n  SEARCH\n";
   cout<<"  1.Search record by name\n";
   cout<<"  2.Search record by age\n";
   cout<<"  3.Search record by crime\n";
   cout<<"  4.Search record by case incharge\n";
   cout<<"  Enter choice : ";
   cin>>k;
   cout<<"\n";

   switch(k)
  {
   case 1: sename(c);
   break;
   case 2: seage(c);
   break;
   case 3: secrime(c);
   break;
   case 4: seinch(c);
   break;
   default: cout<<" Enter valid choice\n";
   break;
   }

  }
 void modify()
 {

   clrscr();
  cout<<"\n  ";
  for(int t=0; str[t]!='\0';t++)
    {
      delay(500);
      cout<<str[t];
    }
  clrscr();
   int k;
   cout<<"  MODIFY\n";
   cout<<"  1.Modify address\n";
   cout<<"  2.Modify verdict\n";
    cout<<"  Enter your choice : ";
  cin>>k;
  cout<<"\n";

  switch(k)
  {
    case 1: modadd(c);
    break;
    case 2: modver(c);
    break;
    default : cout<<"  Enter valid choice\n";
    break;
  }

 }


 void sename(cri c[100])
 {
  char nam[20];
  int i,found=0;
  cout<<"  Enter the name of criminal whose record is to be searched\n  ";
  gets(nam);

  for(i=0;i<n;i++)
   {
    if(strcmpi(c[i].name,nam)==0)
   {  sedisp(c,i);
      found++;
   }
 }

  if(found==0)
   cout<<"  No records found!!\n";

 }

 void secrime(cri c[100])
{
   char cr[20];
  int i, found=0;
  cout<<"  Enter the crime to be searched\n  ";
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
   cout<<"  No records found!!\n";

 }

 void seinch(cri c[100])
{
   char in[20];
  int i,found=0;
  cout<<"  Enter the case incharge to be searched for\n  ";
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
    cout<<"  No records found!!\n";

}

 void seage(cri c[100])
 {
  int age1, age2,i,found=0;
  cout<<"  Enter age group\n";
  cout<<"  Lowerlimit : ";
  cin>>age1;
  cout<<"  Upperlimit : ";
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
   cout<<"  No records found!!\n";

 }

 void sedisp(cri c[100], int i)

 {
  cout<<"\n  ";

   cout<<"\n";
  cout<<"\n  Name of criminal : ";
   puts(c[i].name);
   cout<<"  Age : ";
   cout<<c[i].age;
   cout<<"\n  Address : ";
   puts(c[i].add);
   cout<<"  Crime committed : ";
   puts(c[i].crime);
   cout<<"  Date of crime : ";
   puts(c[i].date);
   cout<<"  Punishment given : ";
   puts(c[i].punish);
   cout<<"  Case incharge : ";
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

   clrscr();

  cout<<"\n  ";
  for(int k=0; str[k]!='\0';k++)
    {
      delay(500);
      cout<<str[k];
    }
  clrscr();
   for(i=0;i<n;i++)
  {
   cout<<"\n  Name of criminal : ";
   puts(c[i].name);
   cout<<"  Age : ";
   cout<<c[i].age;
   cout<<"\n  Address : ";
   puts(c[i].add);
   cout<<"  Crime committed : ";
   puts(c[i].crime);
   cout<<"  Date of crime : ";
   puts(c[i].date);
   cout<<"  Punishment given : ";
   puts(c[i].punish);
   cout<<"  Case incharge : ";
   puts(c[i].inch);
   cout<<"\n";

  }
 }

 void modver(cri[])
 {
  char nam[20];
  int ag,i, found=0;
  cout<<"  Enter name of the criminal : ";
  gets(nam);
  cout<<"  Enter age : ";
  cin>>ag;
   for(i=0;i<n;i++)
   {
     if(strcmpi(c[i].name,nam)==0 && c[i].age==ag)
      {
	found=1;
	sedisp(c,i);
	cout<<"  Enter the changed verdict : ";
	gets(c[i].punish);
	sedisp(c,i);
      }
   }

   if(found==0)
  cout<<"  No such record found!!\n";

 }


void modadd(cri[])
{
   char nam[20];
   int ag,i,found=0;
   cout<<"  Enter name of the criminal : ";
    gets(nam);
    cout<<"  Enter age : ";
    cin>>ag;

   for(i=0;i<n;i++)
   {
     if(strcmpi(c[i].name,nam)==0 && c[i].age==ag)
      {
	found=1;
	sedisp(c,i);
	cout<<"  Enter new address\n  ";
	gets(c[i].add);
	sedisp(c,i);
      }
   }

  if(found==0)
  cout<<"  No such record found!!\n";

 }

  main()
{
  char k;
  int ch;

  pass();

  enter(c);

do{
  delay(300);
  clrscr();
  cout<<"\n  User's Menu\n";
  cout<<"  1.Display all records\n";
  cout<<"  2.Insert new record\n";
  cout<<"  3.Delete existing record\n";
  cout<<"  4.Search\n";
  cout<<"  5.Sort\n";
  cout<<"  6.Modify\n";
  cout<<"  7.Exit\n";


  cout<<"\n  Input your choice\n  ";
  cin>>ch;

  switch(ch)
 {
  case 1: sodisp(c);
  break;
  case 2: insert(c);
  break;
  case 3: delet(c);
  break;
  case 4: search();
  break;
  case 5: sort();
  break;
  case 6: modify();
  break;
  case 7: { exit(0);
	  cout<<"  Thank You for using the program\n";
	   getch();
	  }
  break;
  default: cout<<"  Please enter a valid choice\n";
  break;
   }
  cout<<"\n  Do you wish to continue? (Y/N) : ";
  cin>>k;

  }while(k=='y' || k=='Y');

  getch();
 }

 void box()
 {
 clrscr();
 static int i=1, j=1, x=1, y=1;

 for( ;i<=80;i++)
 {
  gotoxy(i,j);
  cout<<"*";
  gotoxy(i,j+23);
  cout<<"*";
 }

 for( ;y<=23;y++)
 {
  gotoxy(x,y);
  cout<<"*";
  gotoxy(x+79,y);
  cout<<"*";
 }

 gotoxy(1,1);

 getch();
}


