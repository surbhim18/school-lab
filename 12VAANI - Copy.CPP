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
     char add[80];
     public:
     void getinfo()
     {
	   cout<< "Enter your name: ";
	   gets(name);
	   cout<<"Enter the room no: ";
	   cin>>rno ;
     cout<<"Enter the check in date: " ;
	   gets(cid);
	   cout<<"Enter the check out date: " ;
	   gets(cod);
	   cout<<"Enter your phone no: " ;
	   gets(phno);
	    cout<<"Enter your adress: " ;
	   gets(add);
	   cout<<"Enter the duration(days): ";
	   cin>>dur;
     }

      void dispinfo()
     {
	  cout<<"\nName of guest: ";
	  puts(name);
	   cout<<"Room no: ";
	  cout<<(rno);
	cout<<"\nCheck in date(DD//MM//YY): ";
	  puts(cid);
	  cout<<"Check out date(DD//MM//YY): ";
	  puts(cod );
	  cout<<"Duration: ";
	  cout<<(dur);
	  cout<<"\nPhone no: \n";
	  puts(phno);
	  cout<<"Address: ";
	  puts(add);

     }

     void modify();

      int getrno()
	{   return rno;
	     }


 };

  void hotel:: modify()
 {
      char id[20], od[20],phn[10], ad[80];
      int d;

     cout<<"Retaining name and room no....\n";

	  cout<<"Enter the check in date(press '.' to retain) " ;
	   gets(id);
	   if(strcmpi(id,".")!=0)strcpy(cid,id);
	   cout<<"Enter the check out date(press '.' to retain) : " ;
	   gets(od);
	   if(strcmpi(od,".")!=0)strcpy(cod,od);
	   cout<<"Enter your phone no(press '.' to retain) : " ;
	   gets(phn);
	   if(strcmpi(phn,".")!=0)strcpy(phno,phn);
	    cout<<"Enter your adress(press '.' to retain): " ;
	   gets(ad);
	   if(strcmpi(ad,".")!=0)strcpy(add,ad);
	   cout<<"Enter the duration(days)(enter -1 to retain): ";
	   cin>>d;
	   if(d!=-1)dur=d;
     }





  main()

{
   clrscr();
   char ch;

    int a;


   cout<<"\tWELCOME TO ******* HOTEL\n " ;

  ifstream fin;
  ofstream fout;
  fout.open ("hl", ios::out| ios::binary);
  hotel h;
  ch='y';
   while(ch=='y')
    {
       cout<<"\n";
       h.getinfo();
       fout.write((char*)&h,sizeof(h));
       cout<<"\nDo u want to enter more records: ";
       cin>>ch;

    }

    fout.close();




  do{ cout<<"\n";
      cout<<"1.INSERTION\n" ;
      cout<<"2.DELETION\n";
      cout<<"3.SEARCHING\n";
      cout<<"4.MODIFY\n";
      cout<<"5.DISPLAY\n";


      cout<<" ENTER YOUR CHOICE\n";
      cin>>a;
    switch(a)
    {

	  case 1:
	  {

		fin.open("hl",ios::in | ios::binary);
		fout.open("temp",ios::out | ios::binary);
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
			   fout.write((char*)&h,sizeof(h));
			    f=1;
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


	fin.open("hl",ios::in | ios::binary);

	fin.seekg(0);
	  while(fin)
	 {
	   fin.read((char*)&h1,sizeof(h1));
	       if(fin)
		 h1.dispinfo();
	}
	     fin.close();
    }     break;



      case 2:
	 {

	   fin.open("hl",ios::in|ios::binary);
	   fout.open("temp",ios::out| ios::binary);
	   int rno;
	   cout<<"\nEnter the room no of the guest whose record is to be deleted\n";
	   cin>>rno;
	   fin.seekg(0);

		  int f=0;
		   hotel h;

		  while(fin)
		  {
		      fin.read((char*)&h,sizeof(h));
		       if(h.getrno()==rno)
		       {   f=1;

		       }
			else
			   fout.write((char*)&h,sizeof(h));
		   }
		       if(f==0)
			   cout<<"\nrecord not found";
			   fin.close();
			   fout.close();
			remove("hl");
			rename("temp","hl");

			fin.open("hl",ios::in | ios::binary);

			 fin.seekg(0);
			 while(fin)
			 {
			   fin.read((char*)&h,sizeof(h));
			   if(fin)
			   h.dispinfo();
			 }
			   fin.close();

	   }  break;
		case 3:
		{
		   hotel h;
		   fin.open("hl",ios::in|ios::binary);
		   int f=0;
		   int rno;
		   fin.seekg(0);
		   cout<<"Enter the room no to be searched\n";
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
			 cout<<"Record not found\n";
			 fin.close();

	     }      break;



	     case 4:
	   {
	      hotel h;
	      int rno;
	      fin.open("hl",ios::in|ios::binary);
	      fout.open("temp",ios::out| ios::binary);

	      fin.seekg(0);
	      cout<<"\nEnter the room no of guest whose record u wish to modify: ";
	      cin>>rno;


	      while(fin)
	    {
	       fin.read((char*)&h,sizeof(h));

	       if(rno==h.getrno())
	       {
		  h.modify();
		  fout.write((char*)&h,sizeof(h));
	       }
	       else
		fout.write((char*)&h,sizeof(h));
	    }

	    fin.close();
	    fout.close();

		remove("hl");
			rename("temp","hl");

			fin.open("hl",ios::in | ios::binary);

			 fin.seekg(0);
			 while(fin)
			 {
			   fin.read((char*)&h,sizeof(h));
			   if(fin)
			   h.dispinfo();
			 }
			   fin.close();

	    } break;

	     case 5:
		  {
			 hotel h;
			 fin.open("hl",ios::in | ios::binary);

			 fin.seekg(0);
			 while(fin)
			 {
			   fin.read((char*)&h,sizeof(h));
			   if(fin)
			   h.dispinfo();
			}
			   fin.close();
		   }
		     break;

     }
     cout<<"\n\nDo you want to continue\n";
     cin>>ch ;
}while(ch=='y'||ch=='Y');
	    getch();

  }






































































































































































































