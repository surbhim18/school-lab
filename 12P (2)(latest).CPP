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
 char g;
 char gender[15];
 char cat[15];
 int age;
 char crime[20];
 char add[250];
 char desc[250];
 char verdict[20];


 public:
 void enter();
 void assign();
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
   char ch;
   cin.get(ch);
   cout<<"\nEnter criminal no                       : ";
   cin>>crno;
   cout<<"Enter name of criminal                  : ";
   gets(name);
   cin.get(ch);
   cout<<"Enter gender(M/F/.)                     : ";
   cin>>g;
   cout<<"Enter age                               : ";
   cin>>age;
   cout<<"Enter current address                   : ";
   gets(add);
   cout<<"Enter crime committed                   : ";
   gets(crime);
   cout<<"Enter verdict (pending/guilty/innocent) : ";
   gets(verdict);
   cout<<"Add physical description(optional)      : ";
   gets(desc);

   assign();
 }

 void cri:: assign()
{
  if(g=='m' || g=='M')
  strcpy(gender,"Male");
  else if(g=='f' || g=='F')
  strcpy(gender,"Female");
  else
  strcpy(gender,"Other");

  if(age<=18)
  strcpy(cat,"Juvenile");
  else
  strcpy(cat,"Adult");
}




 void cri:: display()
 {

   cout<<"\nCriminal no.         : ";
   cout<<crno;
   cout<<"\nName of criminal     : ";
   puts(name);
   cout<<"Age                  : ";
   cout<<age;
   cout<<"\nGender               : ";
   puts(gender);
   cout<<"Category             : ";
   puts(cat);
   cout<<"Address              : ";
   puts(add);
   cout<<"Crime committed      : ";
   puts(crime);
   cout<<"Verdict              : ";
   puts(verdict);
   cout<<"Physical description :\n";
   puts(desc);
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
     cout<<"\n1.By name\n";
     cout<<"2.By criminal no\n";
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

   void load()
 {

   int i;
   cout<<endl<<endl;
   char str1[]="LOADING.....";
   cout<<"        ";
   for(i=0;str1[i]!='\0';i++)
   {

     delay(500);
     cout<<str1[i];

   }
   clrscr();

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
    if(fin)
     {
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
   if(fin)
   {
     if(c.getcno()==d)
     { f=1;
     n=n-1;
     }
     else
     fout.write((char*)&c,sizeof(c));
   }

   }

    fin.close();
    fout.close();

    remove("A");
    rename("temp","A");

    if(f==0)
    cout<<"No such record found! ";
    else
    cout<<"Record deleted!!\n";

    load();

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
   cout<<"Retaining criminal no an d name of the criminal\n";

   cout<<"New age (Enter -1 to retain old one): ";
   cin>>ag;
   cout<<"New address (Enter '.' to retain old one): ";
   gets(ad);
   cout<<"Verdict (Enter '.' to retain old one): ";
   gets(punis);

   cout<<"\n";



   if(ag!=-1)
    age=ag;
   if(strcmp(ad,".")!=0)
     strcpy(add,ad);

   if(strcmp(punis,".")!=0)
     strcpy(verdict,punis);

   assign();

  }


  void modify()
 {
  cri c;
  int cno,f=0;
   cout<<"Enter the cri.no of record u wish to modify : ";
   cin>>cno;

    ifstream fin("A",ios::in | ios::binary);
   ofstream fout("temp",ios::out | ios::binary);

   fout.seekp(0);
   fin.seekg(0);
    while(fin)
   {
     fin.read((char*)&c,sizeof(c));

    if(fin)
    {
     if(c.getcno()==cno)
     {  f=1;
	c.getval();
	fout.write((char*)&c,sizeof(c));
     }
     else
     fout.write((char*)&c,sizeof(c));
    }
   }
    fin.close();
    fout.close();

    remove("A");
    rename("temp","A");

    if(f==0)
    cout<<"No such record found! ";
    getch();

    cout<<"\n";
    dispf();

  }


  void beg()
 {
  int i;
 char pass[20] = "surbhi",uid[20];
 char str[20];

 cout<<"\n\n PLEASE VERIFY YOUR IDENTITY BEFORE ACCESSING THE DATA.\n";

 cout<<"\n\nEnter user id:\n";
 gets(uid);
 cout<<"\nEnter password:\n";
 for(i=0;i<6;i++)
 {
  str[i] = getch();
  cout<<"*";
 }
  str[i]= '\0';

  getch();

 if(strcmp(pass,str)==0)
 { cout<<"\n\nThe password is correct. Access Allowed to user.\n";
   clrscr();}
 else
 { cout<<"\nPassword Incorrect !!!\nAccess Denied!!\n";
   exit(0);}



  clrscr();
  load();

  cout<<"WELCOME TO THE MANAGEMENT SOFTWARE FOR CRIMINAL RECORDS.\n";
  cout<<"\n\t\tRULES\n";
  cout<<"\nA Few Rules Should Be Kept In Mind While Using The Software\n";
  cout<<"1.Multiple records would be entered for the same person with multiple criminal numbers.\n";
  cout<<"2.Search via name when looking for suspects or multiple records for the same person.\n";
  cout<<"3.Search via criminal no for specific records\n";
  cout<<"4.Modify records to keep the data updated\n";



  cout<<"\n\n\nPress enter to continue\n";
  getch();



 }


   main()
 {
   clrscr();
   int a;
   char cha;

   beg();

   clrscr();
   load();
   insf();
   if(n==0)
   exit(0);


 clrscr();
 do{
   load();
   cout<<"\n\n1.Insert New Record In The Sorted File\n";
   cout<<"2.Delete An Existing Record\n";
   cout<<"3.Search For A Record\n";
   cout<<"4.Modify An Existing  Record\n";
   cout<<"5.Display All Records\n";
   cout<<"6.Exit\n";
   cout<<"\nEnter your choice : ";
   cin.get();
   cin>>a;

   switch(a)
   {

     case 1: {clrscr();
	      load();
	     insert();}
	     break;


     case 2:{ clrscr();
	      load();
	     delet(); }
	   break;

     case 3: { clrscr();
	       load();
	       search();
	     }
	       break;

     case 4: {clrscr();
	      load();
	     modify(); }
	     break;

     case 5:{ clrscr();
	     load();
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