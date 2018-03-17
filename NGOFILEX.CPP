#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
  class ngo
  {
    int memid;
    char name[20];
    float amt;
    public:
	  void getdata()
	  {
	    cout<<"Enter name\n";
	    gets(name);
	    cout<<"Enter member id\n";
	    cin>>memid;
	    cout<<"Enter amount to be paid\n";
	    cin>>amt;
	  }
	  void putdata()
	  {
	    cout<<"Name\t:";
	    puts(name);
	    cout<<"Member id\t:";
	    cout<<memid<<"\n";
	    cout<<"Amount paid\t:";
	    cout<<amt<<"\n";
	  }
	  int getmemid()
	  {
	     return memid;
	  }
     void modify()
     {
	  cout<<"Name\t";
	    puts(name);
	    cout<<"\n";
	    cout<<"Member id\t";
	    cout<<memid<<"\n";
	    cout<<"Amount paid\t";
	    cout<<amt<<"\n";
       cout<<"Enter the new details\n";
       char nm[50];
       int id;
       cout<<"new name:(enter '*' to retain old one)";
       gets(nm);
       cout<<"new id:(enter '-1' to retain old one)";
       cin>>id;
       if(strcmpi(nm,"*")!=0)
       strcpy(name,nm);
       if(id!=-1)
       memid=id;
    }

  }p,x;

main()
{
  clrscr();
  int mi,found=0,n;
  ofstream fout;
  fout.open("don");
  char ans='y';
  while(ans=='y'||ans=='Y')
  {
    p.getdata();
    fout.write((char*)&p,sizeof(p));
    cout<<"Do you want to enter more records(y/n)\n";
    cin>>ans;
  }
  fout.close();
  cout<<"\n1.Searching\n";
  cout<<"2.Insertion\n";
  cout<<"3.Deletion\n";
  cout<<"4.Modify\n";
  cout<<"Enter choice : ";

  cin>>n;
  switch(n)
  {
     case 1:
	 {
	     found =0;
	     ifstream finp;
	     finp.open("don");
	     finp.seekg(0);
	     cout<<"Enter the member id you want to search for\n";
	     cin>>mi;
	     while (!finp.eof())
	      {
		 finp.read((char*)&x,sizeof(x));
		 if(x.getmemid()==mi)
		   {
		      x.putdata();
		      found=1;
		      break;
		   }
		if(found==0)
		cout<<"Record not found";
	      }
	     finp.close();
	  }
     break;

    case 2:
	  {  ifstream fin;
	    ofstream fout;
	    fin.open("don");
	    fout.open("temp");
	    char last='y';
	    cout<<"Enter the details of member to be inserted\n";
	    x.getdata();
	    while(!fin.eof())
	    {
	       fin.read((char*)&p,sizeof(p));
	       if(x.getmemid()<=p.getmemid())
	       {
		  fout.write((char*)&x,sizeof(x));
		  last=n;
		  break;
	       }
	       else
	       fout.write((char*)&p,sizeof(p));
	    }
	    if(last=='y')
	    fout.write((char*)&x,sizeof(x));
	    else if(!fin.eof())
	    {
	       while(!fin.eof())
	       {
		  fin.read((char*)&p,sizeof(p));
		  fout.write((char*)&p,sizeof(p));
	       }
	    }
	    fin.close();
	    fout.close();
	    remove("don");
	    rename("temp","don");
	    fin.open("don");
	    cout<<"New list of members\n";
	    while(!fin.eof())
	    {
	       fin.read((char*)&p,sizeof(p));
	       if(fin.eof())
	       break;
	       p.putdata();

	    }
	   fin.close();
	 }
     break;

   case 3:
	 {	  ifstream fine("don");
		  ofstream foute("temp1");
		  int i;
		  char find='f';
		  char sure='n';
		  cout<<"Enter the id of the member whose record is to be deleted\n";
		  cin>>i;
		  while(!fine.eof())
		  {
		    fine.read((char*)&x,sizeof(x));
		    if(x.getmemid()==i)
		    {
		      x.putdata();
		      find='t';
		      cout<<"Are you sure you want to delete this record?(y/n)";
		      cin>>sure;
		      if(sure=='n')
			 foute.write((char*)&x,sizeof(x));
		    }
		    else
		    foute.write((char*)&x,sizeof(x));
		  }
		    if(find=='f')
		    cout<<"Record not found!!!!!\n";
		    fine.close();
		    foute.close();
		    remove("don");
		    rename("temp1","don");
		    fine.open("don");
		    fine.seekg(0);
		    cout<<"The updated list as follows\n";
		    while(!fine.eof())
		    {
		      fine.read((char*)&p,sizeof(p));
		      if(fine.eof())
		      break;
		      p.putdata();
		    }
		      fine.close();
	    }
	    break;
      case 4:
	{     fstream fio("don",ios::in|ios::binary|ios::out|ios::app);
	     int idn;
	     long pos;
	     char found='f';
	     cout<<"Enter the member id you want to modify\n";
	     cin>>idn;
	     while(!fio.eof())
	      {
		pos=fio.tellg();
		fio.read((char*)&p,sizeof(p));
		if(p.getmemid()==idn)
		{
		   p.modify();
		   fio.seekg(pos);
		   fio.write((char*)&p,sizeof(p));
		   found='t';
		   break;
		}

	      }
	  if(found=='f')
	  cout<<"Record not found!!!\n";
	  fio.seekg(0);
	  cout<<"The updated list as follows\n";
	  while(!fio.eof())
	  {
	    fio.read((char*)&p,sizeof(p));
	    p.putdata();
	  }
	  fio.close();
	}
	break;

  }

 getch();

}
