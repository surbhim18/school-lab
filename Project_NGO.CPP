#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<dos.h>
#include<process.h>  



  class ngo
  {
    int memid;
    char name[20];
    float amt;
    public:
	    char nm[30],ad[100],fnm[30],cn[15],ed[70];
	    long int d;
	    int md;
	    char msg[200];
	    void putdata()
	  {
	    cout<<"Name\t";
	    puts(name);
	    cout<<"\n";
	    cout<<"Member id\t";
	    cout<<memid<<"\n";
	    cout<<"Amount paid\t\n";
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
	    cout<<amt<"\n";
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

   int enterp();
   void processing();
   void loading();
   void beamb();
   void getform();
   int enter();


     void main()
{
    clrscr();
    int ch,n,b,p,r;
    char cont;
    long int acno,amp,cno;
    for(int i=0;i<76;i++)
      {
	 gotoxy(i,1);
	 delay(30);
	 cout<<"*";
      }
      for(i=0;i<26;i++)
      {
	 gotoxy(1,i);
	 delay(30);
	 cout<<"|";
      }
      for(i=0;i<74;i++)
      {
	 gotoxy(i,26);
	 delay(30);
	 cout<<"*";
      }
      for(i=0;i<25;i++)
      {
	 gotoxy(76,i);
	 delay(30);
	 cout<<"|";
      }

    gotoxy(25,2);
    cout<<"NAVNITA-CHARITY FOR THE DISABLED\n";
    gotoxy(44,20);
    cout<<"MADE BY:\n";
    gotoxy(44,21);
    cout<<"ISHANI GAMBHIR AND PRERNA KAKKAR\n";
    gotoxy(44,22);
    cout<<"CLASS: XII-C";
    gotoxy(2,5);
    cout<<"Enter the password to continue\n";
    gotoxy(7,7);
    r=enterp();
    if(r==0)
    exit(0);
    clrscr();
    cout<<"\t\tWELCOME TO NAVNITA-CHARITY FOR THE DISABLED\n";
    cout<<"Know About Us:\n";
    cout<<"NAVNITA was established in the year 2009,by Prerna Kakkar and Ishani Gambhir.\n";
    cout<<"Our aim is to help the disabled\n";
    cout<<"1.HOME\n";
    cout<<"2.DONATION\n";
    cout<<"3.CONTACT US\n";
    cout<<"4.THE NAVNITA SOCIETY\n";
    cout<<"5.EXIT\n";
    cout<<"Enter your choice\n";
    cin>>ch;
    clrscr();

   gotoxy(32,10);
     cout<<"L ";
     delay(400);
     cout<<"O ";
     delay(400);
     cout<<"A ";
     delay(400);
     cout<<"D ";
     delay(400);
     cout<<"I ";
     delay(400);
     cout<<"N ";
     delay(400);
     cout<<"G . . .";
     delay(400);
     clrscr();



   switch(ch)
   {

    case 1: gotoxy(25,2);
	     cout<<"NAVNITA-CHARITY FOR THE DISABLED";
	     for(i=24;i<60;i++)
	       {
		 gotoxy(i,3);
		 cout<<"-";
	       }
	     gotoxy(3,5);
	     cout<<"Navnita is an initative started by Prerna Kakkar and Ishani Gambhir ";
	     gotoxy(3,6);
	     cout<<"to help the disabled children.Currently our organisations is working  " ;
	     gotoxy(3,7);
	     cout<<"with 50 NGOs.We have helped many disabled people to overcome their" ;
	     gotoxy(3,8);
	     cout<<"disabilities.Over the past years, NAVNITA has evolved to be the most";
	     gotoxy(3,9);
	     cout<<"Succesful NGO helping around 200 children accross Delhi and NCR.";
	     gotoxy(3,10);
	     cout<<"Many famous personalities like Mr.Amitabh Bachchan and Mr.Sachin Tendulkar";
	     gotoxy(3,11);
	     cout<<"are also associated with our Charity.";
	     gotoxy(3,12);
	     cout<<"We put efforts to bring back equality in their lives.";
	     gotoxy(3,13);
	     cout<<"Navnita has helped many to start a new life.";
	     gotoxy(3,14);
	     cout<<"We teach them various activities like dance,music,cooking,art and craft.";
	     break;

	 case 2:gotoxy(30,3);
	     cout<<"DONATION";
	     for(i=29;i<39;i++)
	       {
		 gotoxy(i,4);
		 cout<<"-";
	       }
	     gotoxy(3,6);
	     cout<<"Select the mode of payment";
	     gotoxy(3,7);
	     cout<<"1.By cheque";
	     gotoxy(3,8);
	     cout<<"2.Debit/Credit Card";
	     gotoxy(3,9);
	     cin>>n;
	     clrscr();
	     gotoxy(1,2);
	     cout<<"Enter your password before making payment for authenticity\n";
	     r=enter();
	     if(r==1)
	 {

	  { switch(n)
	    {
	       case 1:clrscr();
		      gotoxy(5,3);
		      cout<<"Enter your account number\t";
		      cin>>acno;
		      gotoxy(5,4);
		      cout<<"Enter the amount to be payed\t";
		      cin>>amp;
		      gotoxy(28,10);
		      processing();
		      break;

	       case 2:clrscr();
		      gotoxy(2,3);
		      cout<<"SELECT YOR BANK:";
		      gotoxy(2,4);
		      cout<<"1.HDFC Bank\n";
		      gotoxy(2,5);
		      cout<<"2.AXIS Bank\n";
		      gotoxy(2,6);
		      cout<<"3.ICICI Bank";
		      gotoxy(2,7);
		      cout<<"4.CITI Bank\t";
		      gotoxy(2,8);
		      cout<<"5.STATE BANK OF INDIA\t";
		      gotoxy(2,9);
		      cout<<"6.PUNJAB NATIONAL Bank";
		      gotoxy(2,10);
		      cin>>b;
		      gotoxy(2,12);
		      cout<<"Enter your credit card number.\t";
		      cin>>cno;
		      gotoxy(2,14);
		      cout<<"Enter the pin.\t";
		      cin>>p;
		      gotoxy(3,16);
		      cout<<"Enter the amount to be paid.\t";
		      cin>>amp;
		      gotoxy(28,22);
		      processing();
		      break;
		      default: cout<<"Enter correct choice\n";
		}

	       }
	     }
	     else exit(0);
		     break;





	 case 3:
		    gotoxy(30,3);
		   cout<<"CONTACT US";
		   for(i=29;i<41;i++)
		      {
		       gotoxy(i,4);
		       cout<<"-";
		      }
		  char msg[200];
		  gotoxy(3,6);
		  cout<<"YOU CAN CONTACT US:\n";
		  gotoxy(3,7);
		  cout<<"PHONE NUMBERS:011-45263526,452369852\n";
		  gotoxy(3,8);
		  cout<<"YOU CAN MAIL US AT: navnitapro@gmail.com\n";
		  gotoxy(3,9);
		  cout<<"We would like to hear from you, leave your message below:\n";
		  gotoxy(3,10);
		  cout<<"* ITS A GREAT INITATIVE.I REALLY APPRECIATE YOU PEOPLE FOR";
		  gotoxy(3,11);
		  cout<<"YOUR WORK.I WOULD ALSO LIKE TO HELP YOU.\t-Sanya Deshmukh.";
		  gotoxy(3,12);
		  cout<<"* MY SON IS DISABLED AND WE LOST ALL HOPES.THANKS FOR SHOWING";
		  gotoxy(3,13);
		  cout<<"US RAY OF HOPE.\t-Anshum Vadera";
		  gotoxy(3,14);
		  ofstream out("msg",ios::binary|ios::out|ios::app);
		  cout<<"We wish to hear from you\n";
		  cout<<"Please enter your message here-\n";
	          gets(x.msg);
	          out.write((char*)&x,sizeof(x));
	          out.close();
	          ifstream in("msg",ios::in|ios::app|ios::binary);
		  while(!in.eof())
		   {
	             in.read((char*)&x,sizeof(x));
		     puts(x.msg);
		   }
		   break;
	case 4:
		   int z;
		   gotoxy(30,3);
		   cout<<"NAVNITA SOCIETY";
		   for(i=29;i<47;i++)
		      {
		       gotoxy(i,4);
		       cout<<"-";
		      }

		 gotoxy(3,6);
		 cout<<"1.BE A MEMBER\n";
		 gotoxy(3,7);
		 cout<<"2.SEARCH FOR EXISTING MEMBERS\n";
		 gotoxy(3,8);
		 cout<<"3.INSERTION\n";
		 gotoxy(3,9);
		 cout<<"4.DELETION\n";
		 gotoxy(3,10);
		 cout<<"5.MODIFICATION\n";
		 gotoxy(3,11);
		 cout<<"Enter your choice\n";
		 cin>>z;
		 clrscr();

		 switch(z)
		   {
			case 1:
				gotoxy(20,2);
				cout<<"BE A MEMBER OF NAVNITA\n";
				gotoxy(1,4);
				cout<<"Please fill the following form:\n";
				beamb();
				getch();
				break;
		   }



	}

//case 5:exit();
   }





int enterp()
   {
       char str1[]="ABCDEF";
       char str[10];
       for(int i=0;i<6;i++)
     {
       str[i]=getch();
       cout<<"*";
     }

     int flag=0;

     for(int k=0,j=0;k<6;k++,j++)
     {
	 if(str1[j]!=str[k])
	   {
	      flag=1;
	      break;
	   }

     }

	if(flag==0)
       {
	   gotoxy(25,10);
		      cout<<"C";
		      delay(200);
		      cout<<"H";
		      delay(200);
		      cout<<"E";
		      delay(200);
		      cout<<"C";
		      delay(200);
		      cout<<"K";
		      delay(200);
		      cout<<"I";
		      delay(200);
		      cout<<"N";
		      delay(200);
		      cout<<"G";
		      delay(200);
	    gotoxy(35,10);
		      cout<<"P";
		      delay(200);
		      cout<<"A";
		      delay(200);
		      cout<<"S";
		      delay(200);
		      cout<<"S";
		      delay(200);
		      cout<<"W";
		      delay(200);
		      cout<<"O";
		      delay(200);
		      cout<<"R";
		      delay(200);
		      cout<<"D";
		      delay(200);
		      gotoxy(28,12);
	   cout<<"Password accessed!!!\n";
	   delay(1000);
	   return 1;

	}

	 else
	{
	    gotoxy(25,10);
		      cout<<"C";
		      delay(200);
		      cout<<"H";
		      delay(200);
		      cout<<"E";
		      delay(200);
		      cout<<"C";
		      delay(200);
		      cout<<"K";
		      delay(200);
		      cout<<"I";
		      delay(200);
		      cout<<"N";
		      delay(200);
		      cout<<"G";
		      delay(200);
	    gotoxy(35,10);
		      cout<<"P";
		      delay(200);
		      cout<<"A";
		      delay(200);
		      cout<<"S";
		      delay(200);
		      cout<<"S";
		      delay(200);
		      cout<<"W";
		      delay(200);
		      cout<<"O";
		      delay(200);
		      cout<<"R";
		      delay(200);
		      cout<<"D";
		      delay(200);
		      gotoxy(28,12);
	   cout<<"Password denied!!!\n";
	   delay(1000);
	   return 0;

	}

  }



	void processing()
	 {

		      cout<<"P";
		      delay(400);
		      cout<<"R";
		      delay(400);
		      cout<<"0";
		      delay(400);
		      cout<<"C";
		      delay(400);
		      cout<<"E";
		      delay(400);
		      cout<<"S";
		      delay(400);
		      cout<<"S";
		      delay(400);
		      cout<<"I";
		      delay(400);
		      cout<<"N";
		      delay(400);
		      cout<<"G";
		      delay(400);
		      cout<<".";
		      delay(400);
		      cout<<".";
		      delay(600);
		      gotoxy(20,17);
		      cout<<"THANK YOU!! Your payment has been made\n";
       }

     void beamb()
      {
	     int l;
	     gotoxy(19,6);
	     for(l=0;l<44;l++)
	     cout<<"_";
	     for(l=6;l<20;l++)
	     {
	       gotoxy(62,l);
	       cout<<"|";
	     }
	     gotoxy(18,18);
	     for(l=0;l<44;l++)
	     {
	       cout<<"_";
	     }
	     for(l=6;l<20;l++)
	     {  gotoxy(18,l);
		cout<<"|";
	     }
	     for(l=19;l<62;l++)
	     {
		gotoxy(l,8);
		cout<<"_";
	     }
	     for(l=19;l<62;l++)
	     {
		 gotoxy(l,10);
		 cout<<"_";
	     }
	     for(l=19;l<62;l++)
	     {
		 gotoxy(l,12);
		 cout<<"_";
	     }
	     for(l=19;l<62;l++)
	     {
		 gotoxy(l,14);
		 cout<<"_";
	     }
	     for(l=19;l<62;l++)
	     {
		 gotoxy(l,16);
		 cout<<"_";
	     }
	     for(l=19;l<62;l++)
	     {
		 gotoxy(l,16);
		 cout<<"_";
	     }
	     for(l=6;l<20;l++)
	     {  gotoxy(33,l);
		cout<<"|";
	     }

	     getform();



      }

	   void getform()
      {


	     ofstream f("member",ios::binary|ios::out|ios::app);
	     gotoxy(19,7);
	     cout<<"NAME:";
	     gotoxy(34,7);
	     gets(x.nm);
	     gotoxy(19,9);
	     cout<<"FATHER'S NAME:";
	     gotoxy(34,9);
	     gets(x.fnm);
	     gotoxy(19,11);
	     cout<<"ADDRESS:";
	     gotoxy(34,11);
	     gets(x.ad);
	     gotoxy(19,13);
	     cout<<"CITY:";
	     gotoxy(34,13);
	     gets(x.cn);
	     gotoxy(19,15);
	     cout<<"MEMBER ID:";
	     gotoxy(34,15);
	     cin>>x.md;
	     gotoxy(19,17);
	     cout<<"E-MAIL ID:";
	     gotoxy(34,17);
	     gets(x.ed);
	     f.write((char*)&x,sizeof(x));
	     f.close();
	     gotoxy(3,20);
	     cout<<"Congrats!! Now You are member of NAVNITA\n";
      }


   int enter()
    {  char st1[]="preish";
       char st[10];
       for(int i=0;i<6;i++)
     {
       st[i]=getch();
       cout<<"*";
     }

     int lag=0;

     for(int k=0,j=0;k<6;k++,j++)
     {
	 if(st[j]!=st[k])
	   {
	      lag=1;
	      break;
	   }

     }

	if(lag==0)
       {
	   gotoxy(25,10);
		      cout<<"C";
		      delay(200);
		      cout<<"H";
		      delay(200);
		      cout<<"E";
		      delay(200);
		      cout<<"C";
		      delay(200);
		      cout<<"K";
		      delay(200);
		      cout<<"I";
		      delay(200);
		      cout<<"N";
		      delay(200);
		      cout<<"G";
		      delay(200);
	    gotoxy(35,10);
		      cout<<"P";
		      delay(200);
		      cout<<"A";
		      delay(200);
		      cout<<"S";
		      delay(200);
		      cout<<"S";
		      delay(200);
		      cout<<"W";
		      delay(200);
		      cout<<"O";
		      delay(200);
		      cout<<"R";
		      delay(200);
		      cout<<"D";
		      delay(200);
		      gotoxy(28,12);
	   cout<<"Password accessed!!!\n";
	   delay(1000);
	   return 1;

	}

	 else
	{
	    gotoxy(25,10);
		      cout<<"C";
		      delay(200);
		      cout<<"H";
		      delay(200);
		      cout<<"E";
		      delay(200);
		      cout<<"C";
		      delay(200);
		      cout<<"K";
		      delay(200);
		      cout<<"I";
		      delay(200);
		      cout<<"N";
		      delay(200);
		      cout<<"G";
		      delay(200);
	    gotoxy(35,10);
		      cout<<"P";
		      delay(200);
		      cout<<"A";
		      delay(200);
		      cout<<"S";
		      delay(200);
		      cout<<"S";
		      delay(200);
		      cout<<"W";
		      delay(200);
		      cout<<"O";
		      delay(200);
		      cout<<"R";
		      delay(200);
		      cout<<"D";
		      delay(200);
		      gotoxy(28,12);
	   cout<<"Password denied!!!\n";
	   delay(100);
	   return 0;

	}

  }