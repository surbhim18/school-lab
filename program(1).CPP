// #1: Menu Driven for insertion, deletion, modification and searching in a file.

#include<fstream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>

 class stud
{
  int rno;
  char name[20];
  int marks;

  public:
  void enter();
  void disp();
  void modify();

  int getrno()
  { return rno;
  }
};


 void stud:: enter()
{
  cout<<"\nEnter rno: ";
  cin>>rno;
  cout<<"Enter name: ";
  gets(name);
  cout<<"Enter marks: ";
  cin>>marks;
}

 void stud:: disp()
{
  cout<<"Rno: ";
  cout<<rno;
  cout<<"Name: ";
  puts(name);
  cout<<"Marks: ";
  cout<<marks;
}

 void stud:: modify()
{
  char nam[20];
  int m;
  cout<<"Enter new name(enter '.' to retain): ";
  gets(nam);
  cout<<"Enter new marks(enter -1 to retain): ";
  cin>>m;

  if(strcmp(nam,".")!=0)
  strcpy(name,nam);
  if(m!=-1)
  marks=m;
}

 int n;
 main()
{
  clrscr();
  stud s;
  ofstream fout;
  ifstream fin;
  int n,ch;
  char c;

  fout.open("a",ios::out|ios::binary);
  cout<<"Enter no of records: ";
  cin>>n;

  for(int i=0;i<n;i++)
 {
   s.enter();
   fout.write((char*)&s,sizeof(s));
 }

  fout.close();


  do{

   cout<<"\n1.Insertion\n";
   cout<<"2.Deletion\n";
   cout<<"3.Modification\n";
   cout<<"4.searching\n";

   cout<<"Enter your choice: ";
   cin>>ch;


   switch(ch)
   {

     case 1:
     {
	fin.open("a",ios::in | ios::binary);
		fout.open("temp",ios::out | ios::binary);
		fin.seekg(0);

		stud s,s1;
		cout<<"enter the details whose record is to be inserted\n";
		s1.enter();
		int f=0;
		while(fin)
		{      fin.read((char*)&s,sizeof(s));
		       if(s1.getrno()<s.getrno())
			{
			   fout.write((char*)&s1,sizeof(s1));
			   fout.write((char*)&s,sizeof(s));
			    f=1;
			   break;
			 }
		       else
		       fout.write((char*)&s,sizeof(s));
		 }


		 if(f==0)
		    fout.write((char*)&s1,sizeof(s1));
		 else
		 while(fin)
		 {
		     fin.read((char*)&s,sizeof(s));
		     fout.write((char*)&s,sizeof(s));
		 }


		fin.close();
		 fout.close();
		 remove("a");
		 rename("temp","a");


	fin.open("a",ios::in | ios::binary);

	fin.seekg(0);
	  while(fin)
	 {
	   fin.read((char*)&s1,sizeof(s1));
	       if(fin)
		 s1.disp();
	}
	     fin.close();
    }     break;



    case 2:
   {

	   fin.open("a",ios::in|ios::binary);
	   fout.open("temp",ios::out| ios::binary);
	   int rno;
	   cout<<"\nEnter the room no of the guest whose record is to be deleted\n";
	   cin>>rno;
	   fin.seekg(0);

		  int f=0;
		   stud s;

		  while(fin)
		  {
		      fin.read((char*)&s,sizeof(s));
		       if(s.getrno()==rno)
		       {   f=1;

		       }
			else
			   fout.write((char*)&s,sizeof(s));
		   }
		       if(f==0)
			   cout<<"\nrecord not found";
			   fin.close();
			   fout.close();
			remove("a");
			rename("temp","a");

			fin.open("a",ios::in | ios::binary);

			 fin.seekg(0);
			 while(fin)
			 {
			   fin.read((char*)&s,sizeof(s));
			   if(fin)
			   s.disp();
			 }
			   fin.close();

	   }  break;


    case 3:
   {

	      stud s;
	      int rno;
	      fin.open("a",ios::in|ios::binary);
	      fout.open("temp",ios::out| ios::binary);

	      fin.seekg(0);
	      cout<<"\nEnter the roll no whose record u wish to modify: ";
	      cin>>rno;


	      while(fin)
	    {
	       fin.read((char*)&s,sizeof(s));

	       if(rno==s.getrno())
	       {
		  s.modify();
		  fout.write((char*)&s,sizeof(s));
	       }
	       else
		fout.write((char*)&s,sizeof(s));
	    }

	    fin.close();
	    fout.close();

		remove("a");
			rename("temp","a");

			fin.open("a",ios::in | ios::binary);

			 fin.seekg(0);
			 while(fin)
			 {
			   fin.read((char*)&s,sizeof(s));
			   if(fin)
			   s.disp();
			 }
			   fin.close();

       } break;


    case 4:
      {

		   stud s;
		   fin.open("a",ios::in|ios::binary);
		   int f=0;
		   int rno;
		   fin.seekg(0);
		   cout<<"Enter the room no to be searched\n";
		   cin>>rno;

		   while(fin)
		   {
			fin.read((char*)&s,sizeof(s));
			if(rno==s.getrno())
			     {
				s.disp();
				f=1;
				break;
			      }
		    }
			 if(f==0)
			 cout<<"Record not found\n";
			 fin.close();

      }      break;

  default: cout<<"Enter a valid choice\n";

  }

 cout<<"Do you wish to continue: ";
 cin>>c;

 }while(c=='y'|| c=='Y');

 getch();

 }


