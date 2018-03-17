#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<process.h>
#include<stdio.h>
#include<fstream.h>
class hotel
{

     int rno ;
     char name[20];
     char cid[20];
     char cod[20];
     int dur;
     char phno[10];
     char add[20];
     public:
     void getinfo()
     {
	   cout<< "enter the name\n";
	   gets(name);
	   cout<<"enter the room no\n";
	   cin>>rno;
      /*	   cout<<"enter the check in date\n" ;
	   gets(cid);
	   cout<<"enter the check out date\n" ;
	   gets(cod);
	   cout<<"enter the phone no\n" ;
	   gets(phno);
	    cout<<"enter the adress\n" ;
	   gets(add);
	   cout<<" enter the duration(days)";
	   cin>>dur;    */
     }

      void dispinfo()
     {
	  cout<<" name of guest\n";
	  puts(name);
	   cout<<" \n room no:";
	  cout<<(rno);
	/*  cout<<" check in date(DD//MM//YY):";
	  puts(cid);
	  cout<<" \n check out date(DD//MM//YY):";
	  puts(cod );
	  cout<<" \n duration:";
	  cout<<(dur);
	  cout<<" \n phone no:";
	  puts(phno);
	  cout<<" \n address:";
	  puts(add);  */

     }
	  int getrno()
	     {   return rno;
	     }


 };
  main()
{
    int a;
    do
  {

      cout<<"1.INSERTION\n" ;
      cout<<"2.DELETION\n";
      cout<<"3.SEARCHING\n";
      cout<<"4.DISPLAY\n";
      cout<<" ENTER YOUR CHOICE\n";
      cin>>a;
    switch(a)
    {
	case 1:
	{      char ch;
	     ofstream fout;
	  fout.open ("hl", ios::app);
	     hotel h;
	     ch='y';
	       while(ch=='y')
	       {
		  h.getinfo();
		  fout.write((char*)&h,sizeof(h));
		  cout<<" do u want to enter more records \n";
		  cin>>ch;
		  fout.close();
		}
	  }
	  case 1:
	  {
		ifstream fin;
		fin.open("hl",ios::in);
		ofstream fout("temp",ios::out);
		fin.seekg(0);

		hotel h,h1;
		cout<<"enter the details whose record is to be inserted\n";
		h1.getinfo();
		int f=0;
		while(fin)
		{      fin.read((char*)&h,sizeof(h));
		       if(h1.getrno()<h.getrno())
			{
			   fout.write((char*)&h1,sizeof(h1));
			   int f=1;
			   break;
			 }
		       else
		       fout.write((char*)&h,sizeof(h));
		 }
		 if(f==0)
		    fout.write((char*)&h1,sizeof(h1));
		 else
		 while(fin)
		 {
		     fin.read((char*)&h,sizeof(h));
		     fout.write((char*)&h,sizeof(h));

		 }
		  fin.close();
		  fout.close();
		 remove("hl");
		 rename("temp","hl");


		  fin.open("hl");

		  fin.seekg(0);
		  while(fin)
			 {
			      fin.read((char*)&h1,sizeof(h1));
			       if(fin)
			       break;
				 h1.dispinfo();
			}
			     fin.close();


	    }
	       case 2:
	       {
		   ifstream fin;
		   fin.open("hl",ios::in);
		   ofstream fout("temp");
		   int rno;
		   cout<<"Enter the room no of the guest whose record is to be deleted\n";
		   cin>>rno;
		   fin.seekg(0);

		  int f=0;
		   hotel h,h2;
		   h2.getinfo();
		  while(fin)
		  {
		      fin.read((char*)&h,sizeof(h));
		       if(h2.getrno()==rno)
		       {   f=1;
			   fout.write((char*)&h2,sizeof(h2));

				  break;

			}
			else
			   fout.write((char*)&h,sizeof(h));
		   }
		       if(f==0)
			   cout<<"record not found";
			   fin.close();
			   fout.close();
			remove("hl");
			rename("temp","hl");

			  fin.open("hl");

			 fin.seekg(0);
			 while(fin)
			 {
			   fin.read((char*)&h2,sizeof(h2));
			   if(fin)
			   h2.dispinfo();
			   }
			   fin.close();

	   }
		case 3:
		{
		   hotel h;
		   ifstream fin("hl");
		   int f=0;
		   int rno;
		   fin.seekg(0);
		   cout<<"enter the room no to be searched\n";
		   cin>>rno;

		   while(fin)
		   {

			fin.read((char*)&h,sizeof(h));
			if(rno==h.getrno())
			     {
				h.dispinfo();
				f=1;
				break;
			      }
		    }
			 if(f==0)
			 cout<<"record not found\n";
			 fin.close();


	     }
		  case 4:
		  {
			 hotel h;
			 ifstream fin("hl");

			 fin.seekg(0);
			 while(fin)
			 {
			   fin.read((char*)&h,sizeof(h));
			   if(fin)
			   h.dispinfo();
			}
			   fin.close();

		   }
	    getch();
  }






































































































































































































