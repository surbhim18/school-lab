#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>

int n;
class crime
{
  int no;
  char name[20];
  char crime[20];

  public:
  int getno()
  {
    return no;
  }
  void getval();
  void enter()
  {
    cout<<"\nEnter criminal no :";
    cin>>no;
    cout<<"Enter name : ";
    gets(name);
    cout<<"Enter crime : ";
    gets(crime);
  }
  void display()
  { cout<<"\nCrim. no :";
    cout<<no;
    cout<<"\nName  : ";
    puts(name);
    cout<<"Crime : ";
    puts(crime);
  }
 };


  void crime:: getval()
 {
   int num;
   char nam[20], cri[20];
   cout<<"Enter new crim. no.(-1 for no change): ";
   cin>>num;
   cout<<"Enter new name ('.' for existing ): ";
   gets(nam);
   cout<<"update crime ('.' for existing)  : ";
   gets(cri);


   if(num!=-1)
   no=num;
   if(strcmp(nam,".")!=0)
   strcpy(name,nam);
   if(strcmp(cri,".")!=0)
   strcpy(crime,cri);
 }

  void insf()
  {
    ofstream fout("A",ios::out | ios::binary);

    crime c;
    int i;

    cout<<"Enter no of records u wish to enter: ";
    cin>>n;

    for(i=0;i<n;i++)
    {
      c.enter();
      fout.write((char*)&c,sizeof(c));
    }
  }

  void dispf()
 {
   crime c;
   ifstream fin("A");
   fin.seekg(0);

   while(fin)
   {
     fin.read((char*)&c,sizeof(c));
      if(fin)
	 c.display();
   }
 }

  void search()
 {
   int cno,f=0;
   crime c;
   ifstream fin("A");
   cout<<"Enter criminal no. you wish to search for: ";
   cin>>cno;

   while(fin)
   {
      fin.read((char*)&c,sizeof(c));
      if(c.getno()==cno)
      {
	 c.display();
	 f=1;
	 break;
       }
   }

   if(f==0)
   cout<<"No such record found!";
 }

  void delet()
 {  int d,f=0;
   crime c;
   ifstream fin("A");
   ofstream fout("temp");

   cout<<"Enter cri. no u want to delete \n";
   cin>>d;

   fin.seekg(0);
   while(fin)
   {
     fin.read((char*)&c,sizeof(c));
     if(c.getno()==d)
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

    cout<<"\nDisplaying records";
    dispf();
  }


  void modify()
 {
  crime c;
  int cno,f=0;
   cout<<"Enter the cri.no of record u wish to modify : ";
   cin>>cno;

    ifstream fin("A");
   ofstream fout("temp");

   fin.seekg(0);
    while(fin)
   {
     fin.read((char*)&c,sizeof(c));
     if(c.getno()==cno)
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


  void insert()
  {
   int f=0;

   ifstream fin("A",ios::in | ios::binary );
   ofstream fout("temp",ios::out | ios::binary);
   crime c,d;
   cout<<"\nEnter record u want to insert ";
   d.enter();

   fin.seekg(0);
   while(fin)
   {
     fin.read((char*)&c,sizeof(c));

     if(c.getno()>=d.getno())
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

  main()
 {
   clrscr();
   insf();
   int a;
   char ch,y,Y;

 do{
   cout<<"Menu\n";
   cout<<"1.Insertion\n";
   cout<<"2.Searching\n";
   cout<<"3.Deletion\n";
   cout<<"4.Modification\n";
   cout<<"5.Display\n";

   cout<<"Enter choice : ";
   cin>>a;

   switch(a)
 {
   case 1: insert();
   break;
   case 2: search();
   break;
   case 3:delet();
   break;
   case 4: modify();
   break;
   case 5: dispf();
   break;
   default:cout<<"Incorrect\n";
   break;
 }

 cout<<"Enter y to continue: ";
 cin>>ch;
}while(ch=='y'|| ch=='Y');


   getch();
 }


