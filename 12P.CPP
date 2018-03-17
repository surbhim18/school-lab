#include<fstream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<process.h>
#include<dos.h>
 int n;

 class cri
{
 private:
 long int crno;
 char name[20];
 int age;
 char crime[20];
 char add[250];
 char punish[20];
 char inch[20];

 public:
 void enter();
 void display();
 void getval();
 int getcno()
 {
  return crno;
 }
 char* getname()
 {
  return name;
 }

};

 void cri:: enter()
 {
   char ch='\0';
   cin.get(ch);
   cout<<"Enter criminal no: ";
   cin>>crno;
   cout<<"Enter name of criminal : ";
   gets(name);
   cin.get(ch);
   cout<<"Enter age : ";
   cin>>age;
   cout<<"Enter address : ";
   gets(add);
   cout<<"Enter crime committed : ";
   gets(crime);
   cout<<"Enter punishment given : ";
   gets(punish);
   cout<<"Enter case incharge : ";
   gets(inch);
   cout<<"\n";

 }

 void cri:: display()
 {

   cout<<"\nCriminal no.      : ";
   cout<<crno;
   cout<<"\nName of criminal  : ";
   puts(name);
   cout<<"Age               : ";
   cout<<age;
   cout<<"\nAddress           : ";
   puts(add);
   cout<<"Crime committed   : ";
   puts(crime);
   cout<<"Punishment given  : ";
   puts(punish);
   cout<<"Case incharge     : ";
   puts(inch);
   cout<<"\n";
  }

   void insf()
  {
    ofstream fout("A",ios::out | ios::binary);


    cri c;
    int i;

    cout<<"\nEnter no of records u wish to enter: ";
    cin>>n;

    for(i=0;i<n;i++)
    {
      c.enter();
      fout.write((char*)&c,sizeof(c));
    }


    cout<<"\nAll records have been successfully written!!\n ";
    fout.close();
 }

  void dispf()
 {
   cri c;
   ifstream fin("A",ios::in | ios::binary);
   fin.seekg(0);

   while(fin)
   {
     fin.read((char*)&c,sizeof(c));
      if(fin)
	 c.display();
   }
 }


  void seno()
 {
   int no,found=0;
   cri c;

   ifstream fin("A",ios::in | ios::binary);
   fin.seekg(0);

   cout<<"\nEnter the criminal no to search for: ";
   cin>>no;

   while(fin)
   {
    fin.read((char*)&c, sizeof(c));
    if(c.getcno()==no)
     {
       found=1;
       c.display();
       break;
     }
    }

    fin.close();
    if(found==0)
    cout<<"\nNo such record found\n";

  }

   void sename()
 {
   int found=0;
   char n[20];
   cri c;

   ifstream fin("A",ios::in | ios::binary);
   fin.seekg(0);

   cout<<"\nEnter the name of criminal to search for: ";
   gets(n);


   while(fin)
   {
    fin.read((char*)&c, sizeof(c));
    if(strcmpi(c.getname(),n)==0)
     {
       found=1;
       c.display();
       break;
     }
    }

    fin.close();
    if(found==0)
    cout<<"\nNo such record found\n";

  }

  void search()
 {
     int b;
     clrscr();
     cout<<"1.\n By name\n";
     cout<<"2. By criminal no\n";
     cout<<"Enter your choice : ";
     cin>>b;

     switch(b)
    {
	case 1: sename();
		break;
	case 2: seno();
		break;
	default: cout<<"Invalid choice ";
    }

  }

  void insert()
  {
   int f=0;

   ifstream fin("A",ios::in | ios::binary );
   ofstream fout("temp",ios::out | ios::binary);
   cri c,d;
   cout<<"\nEnter record u want to insert\n ";
   d.enter();

   fin.seekg(0);
   while(fin)
   {
     fin.read((char*)&c,sizeof(c));

     if(c.getcno()>=d.getcno())
      {
	 fout.write((char*)&d,sizeof(d));
	 fout.write((char*)&c,sizeof(c));
	 f=1;
	 break;

      }
      else
       fout.write((char*)&c,sizeof(c));
   }
      if(f==1)
       {

	while(fin)
	{
	  fin.read((char*)&c,sizeof(c));
	  if(fin)
	  fout.write((char*)&c,sizeof(c));
	}
       }
      else
      fout.write((char*)&d,sizeof(d));


   fin.close();
   fout.close();
    remove("A");
    rename("temp","A");

    dispf();

  }

/*  void insl()
 {
   cri c;
   ofstream fout("A",ios::app);
   cout<<"Enter the new record\n\n";
   c.enter();
   fout.write((char*)&c,sizeof(c));

   fout.close();
   n=n+1;

   dispf();
 } */

  void delet()
 {  int d,f=0;
   cri c;
   ifstream fin("A",ios::in | ios::binary);
   ofstream fout("temp",ios::out | ios::binary);

   cout<<"Enter cri. no u want to delete \n";
   cin>>d;

   fin.seekg(0);
   while(fin)
   {
     fin.read((char*)&c,sizeof(c));
     if(c.getcno()==d)
     { f=1;
     n=n-1;
     }
     else
     fout.write((char*)&c,sizeof(c));


   }

    fin.close();
    fout.close();

    remove("A");
    rename("temp","A");

    if(f==0)
    cout<<"No such record found! ";
    else
    cout<<"Record deleted!!\n";

    cout<<"\nDisplaying records";
    dispf();
  }



  void cri:: getval()
 {
   char ch;
   display();
  int ag;
  char n[20],crim[20],ad[250], punis[20], inc[20];

   cin.get(ch);
   cout<<"New name (Enter '.' to retain old one):  ";
   gets(n);
   cout<<"New age (Enter -1 to retain old one): : ";
   cin>>ag;
   cout<<"New address (Enter '.' to retain old one): : ";
   gets(ad);
   cout<<"Change in crime (Enter '.' to retain old one): ";
   gets(crim);
   cout<<"New punishment (Enter '.' to retain old one): ";
   gets(punis);
   cout<<"New case incharge (Enter '.' to retain old one): ";
   gets(inc);
   cout<<"\n";


   if(strcmp(n,".")!=0)
    strcpy(name,n);
   if(ag!=-1)
    age=ag;
   if(strcmp(ad,".")!=0)
     strcpy(add,ad);
   if(strcmp(crim,".")!=0)
     strcpy(crime,crim);
   if(strcmp(punis,".")!=0)
     strcpy(punish,punis);
   if(strcmp(inc,".")!=0)
     strcpy(inch,inc);
  }


  void modify()
 {
  cri c;
  int cno,f=0;
   cout<<"Enter the cri.no of record u wish to modify : ";
   cin>>cno;

    ifstream fin("A",ios::in | ios::binary);
   ofstream fout("temp",ios::out | ios::binary);

   fin.seekg(0);
    while(fin)
   {
     fin.read((char*)&c,sizeof(c));
     if(c.getcno()==cno)
     {  f=1;
	c.getval();
	fout.write((char*)&c,sizeof(c));
     }
     else
     fout.write((char*)&c,sizeof(c));
    }

    fin.close();
    fout.close();

    remove("A");
    rename("temp","A");

    if(f==0)
    cout<<"No such record found! ";
    getch();

    dispf();

  }


   main()
 {
   clrscr();
   int a;
   char cha;
   void pas();
   void welc();

   insf();
   pas();




 clrscr();
 do{

   cout<<"\n\n1.Insert New Record In The Sorted File\n";
   cout<<"2.Delete An Existing Record\n";
   cout<<"3.Search For A Record\n";
   cout<<"4.Modify An Existing  Record\n";
   cout<<"5.Display All Records\n";
   cout<<"6.Exit\n";
   cout<<"\nEnter your choice : ";
   cin>>a;

   switch(a)
   {

     case 1: {clrscr();
	     insert();}
	     break;


     case 2:{ clrscr();
	     delet(); }
	   break;

     case 3: { clrscr();
	       search();
	     }
	       break;

     case 4: {clrscr();

	     modify(); }
	     break;

     case 5:{ clrscr();
	     cout<<"Displaying all records\n";
	     dispf();
	   }
	     break;

     case 6:{
	       cout<<"Thanks for using the program ";
	       delay(500); exit(0);

	     }
	     break;

    default: cout<<"Please enter a valid choice\n";
	     break;
    }

    cout<<"Do you wish to continue?(y/n) : ";
    cin>>cha;

   }while(cha=='y'|| cha=='Y');


   getch();
 }



  void pas()
 {
  int i;
 char pass[20] = "Surbhi";
 char str[20];

 cout<<"Enter password :\n";
 for(i=0;i<6;i++)
 {
  str[i] = getch();
  cout<<"*";
 }
  ch[i]= '\0';

  getch();

 if(strcmp(pass,str)==0)
  cout<<"\nCorrect password !!\n";
 else
  cout<<"\nPassword Incorrect !!!\nAccess Denied!!\n";

  getch();
  getch();

  }















