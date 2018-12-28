//***********************************************************************************************
//    PROJECT HOTEL MANAGEMENT SYSTEM
//    PASSWORD : abc
//***********************************************************************************************
//***********************************************************************************************
//   INCLUDED HEADER FILES
//***********************************************************************************************
#include<conio.h>
#include<string.h>
#include<graphics.h>
#include<fstream.h>
#include<process.h>
#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
#include<dos.h>
void info(void);
float restaurant(void);
//***********************************************************************************************
//CLASS NAME :MENU
//DETAILS   :IT COTROLS ALL FUNCTIONS
//***********************************************************************************************
class menu
{
     public:
	  void main_menu(void);
	  void enter_password (void);
     private:
	  void edit_menu(void);
	  void report_menu(void);
	  void room_edit_menu(void);
	  void customer_edit_menu(void);
} ;
//***********************************************************************************************
//      CLASS NAME :ROOM
//      DETAILS    :IT CONTROLS OVER ALL THE  FUNCTIONS  RELATED TO ROOM
//***********************************************************************************************
class room
{
      public:
	     void add(void);
	     void modify(void);
	     void deletion(void);
	     void display_room_record(void);
	     void display_list(void);
	     int room_found(int);
	     void change_status(int,char);
	     char room_status(int);
	     float get_data(int);
    private:
	 int recordno(int);
	 void display_record(int);
	 int  roomno ;
	 char roomcode[5],status;
	 float tarriff;
};
//***********************************************************************************************
//      CLASS NAME:CUSTOMER
/*       DETAILS    :IT CONTROLLS OVER ALL THE FUNCTIONS RELATED TO CUSTOMER*/
//***********************************************************************************************
class customer
{
     public :
	    void checkin(void);
	    void checkout(void);
	    void modify(void);
	    void deletion(void);
	    void display_list(void);
	    void display_customer_record(void);
     private:
	     int recordno(int);
	     void display_record(int);
	     void delete_record(int);
	     int roomno;
	     char name[21],phone[8];
	     float advance,misc,room_srv;
};
//***********************************************************************************************
//    CLASS NAME : ACCOUNT
/*     DETAILS : IT CONTROLS OVER ALL THE FUNCTIONS  RELATED TO PREPARATION OF BILL  */
//***********************************************************************************************
class account
{
       public:
       void prepare_bill(int,float,char t_name[21],float,float,float);
};
//***********************************************************************************************
//    CLASS NAME : MENU
//    FUNCTION NAME : ENTER_PASSWORD
/*    DETAILS : IT ACCEPTS THE PASSWORD AND TERMINATES  THE PROGRAM IF WRONG ENTERED*/
//***********************************************************************************************
void menu::enter_password()
{
	 char pass1,pass2,pass3;
	 cout<<"\n\n\n\t\t\t\t\t\t\t\t\t\t\tEnter the password";
	 pass1=getch();
	 cout<<"*";
	 pass2=getch();
	 cout<<"*";
	 pass3=getch();
	 cout<<"*";
	 if(pass1=='a' && pass2=='b' && pass3=='c')
	 {
		clrscr();
		int gdriver=DETECT,gmode,errorcode;
		initgraph(&gdriver,&gmode,"c:\\tc\\bgi");
		errorcode=graphresult();
		if(errorcode!=grOk)
		{
		cout<<grapherrormsg(errorcode)<<"\n";
		getch();
		}
		settextstyle(1,0,6);
		outtextxy(75,50," W E L C O M E  ");
		outtextxy(275,150,"T O     ");
		outtextxy(20,250," HOTEL MANAGEMENT ");
		outtextxy(150,350,"S Y S T E M");
		getch();
		cleardevice();
		outtextxy(50,50,"PRESENTED BY:-");
		outtextxy(125,150,"PEEYUSH GOEL");
		outtextxy(50,250,"UNDER GUIDANCE:-");
		outtextxy(125,350,"MR.AJAI SINGH");
		getch();
		cleardevice();
		return;
	 }
	else
	cout<<"\nWRONG PASSWORD????????                     ";
	getch();
	exit(0);
}
//***********************************************************************************************
//     CLASS NAME : MENU
//     FUNCTION NAME : MAIN_MENU
//     DETAILS : IT CREATE MAIN MENU TO CONTROL FUNCTIONS
//***********************************************************************************************
void menu::main_menu(void)
{
	char ch;
	textmode(C80);
	textbackground(WHITE);
	textcolor(RED);
	cout<<"\n\t\t\t*************HOTEL MANAGEMENT****************\n";
	int x=1;
	while(x==1){
	cout<<"\n\t\t1.CHECK IN";
	cout<<"\n\t\t2.CHECK OUT";
	cout<<"\n\t\t3.CUSTOMER RECORD";
	cout<<"\n\t\t4.ROOM RECORD";
	cout<<"\n\t\t5.EDIT";
	cout<<"\n\t\t6.REPORT";
	cout<<"\n\t\t7.RESTAURANT";
	cout<<"\n\t\t0.EXIT TO DOS";
	cout<<"\n\t\tEnter your choice :\t";
	ch=getch();
	float res;
	if(ch=='1')
	{
		customer c;
		c.checkin();
	}
	else
	if(ch=='2')
	{
		customer c;
		c.checkout();
	}
	else
	if(ch=='3')
	{
		customer c;
		c.display_customer_record();
	}
	else
	if(ch=='4')
	{
		room r;
		r.display_room_record();
	}
	else
	if(ch=='5')
	      edit_menu();
	else
	if(ch=='6')
	      report_menu();
	else
	if(ch=='7')
	      res=restaurant();
	else
	if(ch=='0')
	exit(0);
	cout<<"Enter 1 to enter other record";
	cin>>x;
	}
}
//***********************************************************************************************
//     CLASS NAME :MENU
//     FUNCTION NAME : EDIT_MENU
/*     DETAILS : IT CREATE EDIT MENU TO CONTROL  FUNCTIONS OF ROOM AND CUSTOMER CLASSES*/
//***********************************************************************************************
void menu::edit_menu(void)
{
	char ch;
	while(1)
	{
		clrscr();
		cout<<"\n\t    EDIT";
		cout<<"\n\t    1.ROOM RECORDS";
		cout<<"\n\t   2.CUSTOMER RECORDS";
		cout<<"\n\t   0.EXIT";
		cout<<"\n\tEnter your choice :\t";
		ch=getch();
		if(ch=='1')
			room_edit_menu();
		else
		if(ch=='2')
			customer_edit_menu();
		else
		if(ch=='0')
		break;
	}
}
//***********************************************************************************************
//     CLASS NAME : MENU
//     FUNCTIONS NAME : ROOM_EDIT_MENU
//     DETAILS : IT CREATE EDIT MENU TO CONTROL FUNCTIONS OF ROOM CLASS
//***********************************************************************************************
void menu::room_edit_menu(void)
{
	char ch;
	while(1)
	{
		clrscr();
		cout<<"\n\t1.ADD ROOM RECORDS";
		cout<<"\n\t2.MODIFY ROOM RECORDS";
		cout<<"\n\t3.DELETE ROOM RECORDS";
		cout<<"\n\t0.EXIT";
		cout<<"\n\tENTER YOUR CHOICE:   \t";
		ch=getch();
		if(ch=='1')
		{
		   room r;
		   r.add();
		}
		else
		if(ch=='2')
		{
		   room r;
		   r.modify();
		}
		else
		if(ch=='3')
		{
		    room r;
		    r.deletion();
		}
		else
		if(ch=='0')
		  break;
	}
}
//***********************************************************************************************
//       CLASS NAME   :MENU
//       FUNCTION NAME:CUSTOMER EDIT MENU
/*       DETAILS         IT CREATE EDIT MENU TO CONTROL  FUNCTIONS OF CUSTOMER CLASS*/
//***********************************************************************************************
void menu :: customer_edit_menu(void)
{
	char ch;
	while(1)
	{
		clrscr();
		cout<<"\n\t1.MODIFY CUSTOMER RECORDS";
		cout<<"\n\t2.DELETE CUSTOMER RECORDS";
		cout<<"\n\t0.EXIT";
		cout<<"\n\tENTER YOUR CHOICE\t";
		ch =getch();
		if (ch=='1')
		{
		     customer c;
		     c.modify();
		}
		else
		if(ch=='2')
		{
		      customer c;
		      c.deletion();
		}
		else
		if(ch=='0')
		break;
	}
}
//***********************************************************************************************
//    CLASS NAME : MENU
//     FUNCTION NAME : REPORT_MENU
/*     DETAILS : IT CREATE REPORT MENU TO DISPLAY THE  REPORT OF ROOMS AND
              CUSTOMERS*/
//***********************************************************************************************
void menu::report_menu(void)
{
	char ch;
	while(1)
	{
		clrscr();
		cout<<"\n\t1.LIST OF ROOMS";
		cout<<"\n\t2.LIST OF CUSTOMERS";
		cout<<"\n\t0.EXIT";
		cout<<"\n\tEnter your choice ;\t";
		ch=getch();
		if (ch=='1')
		{
		    room r;
		    r.display_list();
		}
		else
		if(ch=='2')
		{
		      customer c;
		      c.display_list();
		}
		else
		if(ch=='0')
		break;
	}
}
//***********************************************************************************************
//     CLASS NAME : ROOM
//     FUNCTION NAME : ROOM_FOUND
//      DETAILS : IT RETURNS THE VALUE 1 IF GIVEN ROOM NO.FOUND
//***********************************************************************************************
int room::room_found(int t_roomno)
{
	fstream file;
	file.open("HROOM.DAT",ios::in);
	file.seekg(0);
	int found=0;
	while(file.read((char*)this,sizeof(room)))
	{
	      if(roomno==t_roomno)
		  found=1;
	}
	file.close();
	return found;
}
//***********************************************************************************************
//      CLASS NAME : ROOM
//      FUNCTION NAME : DISPLAY_LIST
//      DETAILS  : IT DISPLAYS THE LIST OF THE ROOM
//***********************************************************************************************
void room::display_list(void)
{
	clrscr();
	fstream file;
	file.open("HROOM.DAT",ios::in);
	file.seekg(0);
	int row=5,found=0,pageno=1;
	cout<<"\n\tLIST OF ROOMS";
	cout<<"\n\tRoom code \t Room no. \t Status \t Tarriff";
	while(file.read((char*)this,sizeof(room)))
	{
		found=1;
		cout<<roomcode;
		cout<<"\t"<<roomno;
		cout<<"\t"<<"\t"<<status;
		cout<<"\t"<<"\t"<<"\t"<<tarriff;
		if(row==23)
		{
			row=5;
			cout<<"\n\tpage no. : "<<pageno;
			pageno++;
			cout<<"\n\tPress any key to continue...";
			getch();
			cout<<"\n\tLIST OF ROOMS\n";
			cout<<"\n\tRoom code \t Room no. \t Status \t Tarriff";
		}
		else
		     row++;
	}
	if(!found)
	{
		cout<<"\n\tRecords not found";
	}
	cout<<"\n\t Page no. :"<<pageno;
	cout<<"\n\t Press any key to continue...";
	getch();
	file.close();
}
//***********************************************************************************************
//     CLASS NAME  : ROOM
//     FUNCTION NAME : RECORDNO
//     DETAILS  : IT RETURNS THE RECORD NO. OF THE GIVEN ROOM NO.
//***********************************************************************************************
int room::recordno(int t_roomno)
{
	fstream file;
	file.open("HROOM.DAT",ios::in);
	file.seekg(0);
	int count=0;
	while(file.read((char*)this,sizeof(room)))
	{
		count++;
		if(t_roomno==roomno)
		       break;
	}
	file.close();
	return count;
}
//***********************************************************************************************
//     CLASS NAME  : ROOM
//     FUNCTION NAME  : DISPLAY_RECORD
//      DETAILS   : IT DISPLAYS THE RECORD OF THE GIVEN ROOM NO.
//***********************************************************************************************
void room::display_record(int t_roomno)
{
	fstream file;
	file.open("HROOM.DAT",ios::in);
	file.seekg(0);
	int  found=0;
	while(file.read((char*)this,sizeof(room)) && !found)
	{
		if(t_roomno == roomno)
		{
			found=1;
			cout<<"\n\tRoom code :"<<roomcode;
			cout<<"\n\tRoom no.  :"<<roomno;
			cout<<"\n\tStatus    :"<<status;
			cout<<"\n\tTariff    :"<<tarriff;
		}
	}
	file.close();
}
//***********************************************************************************************
//       CLASS NAME    :ROOM
//        FUNCTION NAME : DISPLAY_ROOM_RECORD
//        DETAILS          : IT GIVES ROOM NO. TO DISPLAY THE ROOM RECORD.
//***********************************************************************************************
void room :: display_room_record(void)
{
	clrscr();
	int valid;
	int t_roomno;
	cout<<"\n\tENTER THE ROOM no.  :\t";
	cin>>t_roomno;
	if(!room_found(t_roomno))
	{
		cout<<"\n\tROOM NO. NOT FOUND";
		cout<<"\n\tPress any key to continue...";
		getch();
		return;
	}
	clrscr();
	cout<<"\n\tHROOM RECORD";
	display_record(t_roomno);
	cout<<"\n\tPress any key to continue...";
	getch();
}
//**********************************************************************************************
//        CLASS NAME       :ROOM
//         FUNCTION NAME : CHANGE_STATUS
/*         DETAILS       : IT CHANGES THE STATUS OF THE GIVEN  ROOM TO THE GIVEN STATUS .*/
//***********************************************************************************************
void room ::change_status(int t_roomno  ,  char t_status)
{
	int recno ;
	recno=recordno(t_roomno);
	fstream file ;
	file.open("HROOM.DAT",ios::out | ios::ate);
	int location;
	location=(recno-1) * sizeof(room);
	file.seekp(location) ;
	status  =t_status  ;
	file.write((char *) this, sizeof(room));
	file.close();
}
//***********************************************************************************************
//     CLASS NAME      :ROOM
//      FUNCTION NAME : ROOM_STATUS
//       DETAILS        :IT RETURNS THE STATUS OF THE GIVEN  ROOM NO.
//***********************************************************************************************
char room :: room_status(int t_roomno)
{
	fstream file;
	file.open("HROOM.DAT",ios::in);
	file.seekg(0);
	int found=0;
	char t_status;
	while(file.read((char*)this,sizeof(room)) && !found)
	{
		if(t_roomno==roomno)
		{
		      found=1;
		      t_status=status;
		}
	}
	file.close();
	return t_status;
}
//***********************************************************************************************
//     CLASS NAME  : ROOM
//     FUNCTION NAME  : GET_DATA
//     DETAILS  : IT RETURNS THE TARRIFF OF THE GIVEN  ROOM NO.
//***********************************************************************************************
float room::get_data(int t_roomno)
{
	fstream file;
	file.open("HROOM.DAT",ios::in);
	file.seekg(0);
	float t_tarriff;
	while(file.read((char*)this,sizeof(room)))
	{
		if(t_roomno==roomno)
		{
		     t_tarriff=tarriff;
		     break;
		}
	}
	file.close();
	return t_tarriff;
}
//***********************************************************************************************
//     CLASS NAME  : ROOM
//     FUNCTION NAME  : ADD
//     DETAILS  : IT ADDS THE ROOM RECORD TO THE ROOM  FILE(ROOM.DAT)
//***********************************************************************************************
void room::add(void)
{
	char ch;
	char t_rcode[5];
	int t_roomno;
	char t_status;
	float t_tarriff;
	do
	{
		fstream file;
		file.open("HOOM.DAT",ios::out | ios::app);
		clrscr();
		cout<<"\n\tEnter the details for the room";
		cout<<"\n\tCode   : ";
		cout<<"\n\tRoom no.   :";
		cout<<"\n\tStatus   :";
		cout<<"\n\tTarriff   :";
		cout<<"\n\tSS : SINGLE SUITE \t";
		cout<<"\n\tSR : SINGLE ROOM \t";
		cout<<"\n\tDR : DOUBLE ROOM \t";
		cout<<"\n\tDS : DOUBLE SUITE \t";
		int valid=0;
		do
		{
			valid=1;
			cout<<"\n\tENTER THE ROOM CODE (SS/SR/DR/DS)\t";
			cin>>t_rcode;
			strupr(t_rcode);
			char *string[4]={"SS","DR","SR","DS"};
			int result,count=0;
			for(int i=0;i<4;i++)
			{
				result=strcmp(t_rcode,string[i]);
				if( result!=0)
				count++;
			}
			if(count==4)
			{
				valid=0;
				cout<<"\n\tINVALID CODE";
				cout<<"\n\tPress any key to continue...";
				getch();
			}
		}
		while(valid==0);
		do
		{
			valid=1;
			cout<<"\n\tENTER THE ROOM NUMBER \t";
			cin>>t_roomno;
			if(t_roomno<=0 || t_roomno>=900)
			{
				valid=0;
				cout<<"\n\tIT SHOULD NOT BE NEGATIVE OR ZERO OR GREATER THAN 900";
				cout<<"\n\tPress any key to continue...";
				getch();
			}
			if(room_found(t_roomno))
			{
				valid=0;
				cout<<"\n\tROOM NO.ALREADY EXIST";
				cout<<"\n\tPress any key to continue...";
				getch();
			}
		}
		while(!valid);
		do
		{
			valid=1;
			cout<<"\n\tENTER THE ROOM STATUS : V=vacant,O=occupied \t";
			cin>>t_status;
			t_status=toupper(t_status);
			if(t_status !='O' && t_status !='V')
			{
				valid=0;
				cout<<"\n\tINVALID DATA ENTERED";
				cout<<"\n\tPress any key to comtinue...";
				getch();
			}
		}
		while(!valid);
		do
		{
			valid=1;
			cout<<"\n\tENTER THE TARRIFF FOR THE ROOM	\t";
			cin>>t_tarriff;
			if(t_tarriff<=0)
			{
				valid=0;
				cout<<"\n\tIT SHOULD NOT BE NEGATIVE OR ZERO";
				cout<<"\n\tPress any key to continue...";
				getch();
			}
		}
		while(!valid);
		cout<<"\n\tDo you want to save the record(y/n) : ";
		do
		{
			valid=1;
			ch=getch();
			ch=toupper(ch);
			if(ch!='Y' && ch!='N')
			{
			     valid=0;
			}
		}
		while(!valid);
		if(ch=='Y')
		{
			strcpy(roomcode,t_rcode);
			roomno=t_roomno;
			status=t_status;
			tarriff=t_tarriff;
			file.write((char*)this,sizeof(room));
		}
		cout<<"\n\tDo you want to add more records(y/n) : ";
		do
		{
			valid=1;
			ch=getch();
			ch=toupper(ch);
			if(ch!='Y' && ch!='N')
			{
			      valid=0;
			}
		}
		while(!valid);
		file.close();
	}
	while(ch=='Y');
}
//***********************************************************************************************
//     CLASS NAME  : ROOM
//     FUNCTION NAME  : MODIFY
//     DETAILS  : IT MODIFY THE ROOM RECORD IN THE ROOM  FILE(ROOM.DAT).
//***********************************************************************************************
void room::modify(void)
{
	clrscr();
	int valid;
	char ch;
	char t_rcode[5];
	int t_roomno,tr;
	char t_status;
	float t_tarriff;
	fstream file;
	file.open("HROOM.DAT",ios::out | ios::ate);
	cout<<"\n\tEnter the Room no. to be modified \t";
	cin>>tr;
	if(!room_found(tr))
	{
		cout<<"\n\tHROOM NO.NOT FOUND";
		cout<<"\n\tPress any key to continue...";
		getch();
		return;
	}
	display_record(tr);
	cout<<"\n\tDo you want to modify this Room Record(y/n) : ";
	do
	{
		valid=1;
		ch=getch();
		ch=toupper(ch);
		if(ch!='Y' && ch!='N')
		{
		     valid=0;
		}
	}
	while(!valid);
	if(ch=='N')
	    return;
	cout<<"\n\tENTER THE NEW DATA FOR THE ROOM";
	cout<<"\n\tCode   : ";
	cout<<"\n\tRoom no.   :";
	cout<<"\n\tStatus   :";
	cout<<"\n\tTarriff   :";
	do
	{
		valid=1;
		cout<<"\n\tENTER THE ROOM CODE (SS/SR/DR/DS)\t";
		cin>>t_rcode;
		strupr(t_rcode);
		char *string[4]={"SS","DR","SR","DS"};
		int result,count=0;
		for(int i=0;i<4;i++)
		{
		result=strcmp(t_rcode,string[i]);
		if( result!=0)
			count++;
		}
		if(count==4)
		{
			valid=0;
			cout<<"\n\tINVALID CODE";
			cout<<"\n\tPress any key to continue…..";
			getch();
		}
	}
	while(valid==0);
	do
	{
		valid=1;
		cout<<"\n\tENTER THE ROOM NUMBER \t";
		cin>>t_roomno;
		if(t_roomno<=0 || t_roomno>=900)
		{
			valid=0;
			cout<<"\n\tIT SHOULD NOT BE NEGATIVE OR ZERO OR GREATER THAN 900";
			cout<<"\n\tPress any key to continue...";
			getch();
		}
		if( room_found(t_roomno ) && t_roomno!=tr)
		{
			valid=0;
			cout<<"\n\tROOM NO.ALREADY EXIST";
			cout<<"\n\tPress any key to continue...";
			getch();
		}
	}
	while(!valid);
	do
	{
		valid=1;
		cout<<"\n\tENTER THE ROOM STATUS : V=vacant,O=occupied \t";
		cin>>t_status;
		t_status=toupper(t_status);
		if(t_status !='O' && t_status !='V')
		{
			valid=0;
			cout<<"\n\tINVALID DATA ENTERED";
			cout<<"\n\tPress any key to comtinue...";
			getch();
		}
	}
	while(!valid);
	do
	{
		valid=1;
		cout<<"\n\tENTER THE TARRIFF FOR THE ROOM	\t";
		cin>>t_tarriff;
		if(t_tarriff<=0)
		{
			valid=0;
			cout<<"\n\tIT SHOULD NOT BE NEGATIVE OR ZERO";
			cout<<"\n\tPress any key to continue...";
			getch();
		}
	}
	while(!valid);
	cout<<"\n\tDo you want to save the record(y/n) : ";
	do
	{
		valid=1;
		ch=getch();
		ch=toupper(ch);
		if(ch!='Y' && ch!='N')
		{
		     valid=0;
		}
	}
	while(!valid);
	if(ch=='Y')
	{
		int recno;
		recno=recordno(tr);
		int location;
		location=(recno-1)*sizeof(room);
		file.seekp(location);
		strcpy(roomcode,t_rcode);
		roomno=t_roomno;
		status=t_status;
		tarriff=t_tarriff;
		file.write((char*)this,sizeof(room));
	}
	file.close();
}
//***********************************************************************************************
//     CLASS NAME  : ROOM
//     FUNCTION NAME  : DELETION
//     DETAILS  : IT DELETES THE ROOM RECORD IN THE ROOM FILE(HROOM.DAT).
//***********************************************************************************************
void room::deletion(void)
{
	clrscr();
	int valid ;
	char ch;
	int t_roomno;
	cout <<"\n\tEnter the room no. to be deleted\t";
	cin>>t_roomno;
	if(!room_found(t_roomno ))
	{
	cout<<"\n\tROOM NO. NOT FOUND";
	cout<<"\n\tPress any key to continue...";
	getch();
	return;
	}
	display_record(t_roomno);
	cout<<"\n\tDo you want to delete this Room Record(y\n):";
	do
	{
		valid=1;
		ch=getch();
		ch=toupper(ch);
		if (ch !='Y' && ch!='N')
		{
			valid=0;
		}
	}
	while(!valid);
	if(ch=='N')
	      return ;
	fstream file;
	file.open("HROOM.DAT",ios::in);
	fstream temp;
	temp.open("temp.dat",ios::out);
	while(!file.eof())
	{
		file.read((char*)this,sizeof(room));
		if(file.eof())
		break;
		if(roomno!=t_roomno)
		temp.write((char*)this,sizeof(room));
	}
	file.close();
	temp.close();
	file.open("HROOM.DAT",ios::in);
	temp.open("temp.dat",ios::in);
	temp.seekg(0);
	while(!temp.eof())
	{
		temp.read((char*) this,sizeof(room));
		if(temp.eof())
		break;
		file.write((char*) this,sizeof(room));
	}
	file.close();
	temp.close();
}
//***********************************************************************************************
//        CLASS NAME       :CUSTOMER
//         FUNCTION NAME  :  DISPLAY_LIST
//         DETAILS    :IT DISPLAYS THE LIST OF THE CUSTOMER  RECORDS
//***********************************************************************************************
void customer::display_list(void)
{
	clrscr();
	fstream file;
	file.open("HROOM.DAT",ios::in);
	file.seekg(0);
	int row=5,found=0,pageno=1,total=0;
	cout<<"\n\tLIST OF CUSTOMERS";
	while(file.read((char*)this,sizeof(customer)))
	{
		total++;
		found=1;
		cout<<"\n\tRoom no. \t";
		cout<<roomno;
		cout<<"\n\t Name \t";
		puts(name);
		cout<<"\n\t Phone \t";
		cout<<phone;
		cout<<"\n\tRoom service \t";
		cout<<room_srv;
		cout<<"\n\t Advanced \t";
		cout<<advance;
		cout<<"\n\t Misc. \t";
		cout<<misc;
		if(row==23)
		{
			row=5;
			cout<<"\n\t Page no.  : "<<pageno;
			pageno++;
			cout<<"\n\tPress any key to continue...";
			getch();
			clrscr();
			cout<<"\n\tLIST OF CUSTOMERS";
			cout<<"\n\t Room no.  \t  Name  \t  Phone  \t  Room service  \t  Advance  \t  Misc.";
		}
		else
			 row++;
			}
		if(!found)
		{
		     cout<<"\n\t Records not found";
		}
		cout<<"\n\tPage no  :  "<<pageno;
		cout<<"\n\t Press any key to continue...";
		getch();
		clrscr();
		cout<<"\n\tTotal no. of customers ="<<total;
		cout<<"\n\t Press any key to continue...";
		getch();
		file.close();
}
//***********************************************************************************************
//     CLASS NAME   : CUSTOMER
//     FUNCTION NAME   : CHECK IN
//     DETAILS    :  IT ADDS THE RECORDS IN THE CUSTOMER  FILE(CUSTOMER.DAT)
//***********************************************************************************************
void customer::checkin(void)
{
	room r;
	char ch;
	int valid=1;
	int t_roomno,t_no_cust;
	char t_name[21],t_address[35],t_phone[8],t_nation[16],t_passport[30];
	float t_advance,t_misc,t_room_srv;
	clrscr();
	cout<<"\n\tEnter the details of the customer";
	cout<<"\n\tRoom no.   : ";
	cin>>t_roomno;
	cout<<"\n\tName           : ";
	do
	{
		valid=1;
		cout<<"\n\tENTER THE NAME OF THE CUSTOMER \t";
		gets(t_name);
		strupr(t_name);
		if((strlen(t_name)<=0)||(strlen(t_name)>20))
		{
			valid=0;
			cout<<"\n\tLENGTH SHOULD NOT BE ZERO OR GREATER THAN 20";
			cout<<"\n\t Press any key to continue...";
			getch();
		}
	}
	while(!valid);
	cout<<"\n\t No. of guests   :  ";
	do
	{
		valid=1;
		cout<<"\n\t ENTER THE NO. OF GUESTS WITH THE CUSTOMER  \t";
		cin>>t_no_cust;
		if((t_no_cust<0)||(t_no_cust>4))
		{
			valid=0;
			cout<<"\n\tGUESTS SHOULD NOT BE LESS THAN 0 OR GREATER THAN 4";
			cout<<"\n\t Press any key to continue...";
			getch();
		}
	}
	while(!valid);
	cout<<"\n\tAddress		:";
	do
	{
		valid=1;
		cout<<"\n\tENTER THE ADDRESS OF THE CUSTOMER\t";
		gets(t_address);
		if((strlen(t_address)<=0) || (strlen(t_address)>50))
		{
			valid=0;
			cout<<"\n\tLENGTH SHOULD NOT BE ZERO OR GREATER THAN 50";
			cout<<"\n\tPress any key to continue...";
			getch();
		}
	}
	while(!valid);
	cout<<"\n\tPhone   : ";
	do
	{
		valid=1;
		cout<<"\n\tENTER THE PHONE NO. OF THE CUSTOMER,ENTER '-' FOR NO PHONE  NO.\t";
		cin>>t_phone;
		if((strlen(t_phone)<7 && strlen(t_phone)>1) || (strlen(t_phone)>7))
		{
			valid=0;
			cout<<"\n\t LENGTH SHOULD NOT LESS THAN 7 OR GREATER THAN 7";
			cout<<"\n\tPress any key to continue...";
			getch();
		}
	}
	while(!valid);
	cout<<"\n\t Nationality    :";
	do
	{
		valid=1;
		cout<<"\n\tENTER NATIONALITY OF THE CUSTOMER   \t";
		gets(t_nation);
		if((strlen(t_nation)<=0) || (strlen(t_nation)>15))
		{
			valid=0;
			cout<<"\n\tLENGTH SHOULD NOT LESS THAN ZERO OR GREATER THAN 15";
			cout<<"\n\t Press any key to continue...";
			getch();
		}
	}
	while(!valid);
	cout<<"\n\tPassport no.   : ";
	do
	{
		valid=1;
		cout<<"\n\tENTER PASSPORT NO. OF THE CUSTOMERS \t ";
		gets(t_passport);
		if((strlen(t_passport)<=0) || (strlen(t_passport)>15))
		{
			valid=0;
			cout<<"\n\tLENGTH SHOULD NOT LESS THAN ZERO OR GREATER THAN 15";
			cout<<"\n\t Press any key to continue...";
			getch();
		}
	}
	while(!valid);
	cout<<"\n\t Advance   : ";
	do
	{
		valid=1;
		cout<<"\n\tENTER THE ADVANCE RS.\t";
		cin>>t_advance;
		if(t_advance<0)
		{
			valid=0;
			cout<<"\n\tSHOULD NOT LESS THAN ZERO ";
			cout<<"\n\t Press any key to continue...";
			getch();
		}
	}
	while(!valid);
	cout<<"\n\tMiscellineous   :  ";
	do
	{
		valid=1;
		cout<<"\n\tENTER THE MISCELLINEOUS CHARGES\t";
		cin>>t_misc;
		if(t_misc<0)
		{
			valid=0;
			cout<<"\n\tSHOULD NOT LESS THAN ZERO ";
			cout<<"\n\t Press any key to continue...";
			getch();
		}
	}
	while(!valid);
	cout<<"\n\tRoom Service   :  ";
	do
	{
		valid=1;
		cout<<"\n\tENTER THE ROOM SERVICE CHARGES \t";
		cin>>t_room_srv;
		if(t_room_srv<0)
		{
			valid=0;
			cout<<"\n\tSHOULD NOT LESS THAN ZERO";
			cout<<"\n\tPress any key to continue...";
			getch();
		}
	}
	while(!valid);
	cout<<"\n\tDo you want to save the record (y/n)  :  ";
	cin>>ch;
	if(ch=='Y')
	{
		r.change_status(t_roomno,'O');
		roomno=t_roomno;
		strcpy(name,t_name);
		strcpy(phone,t_phone);
		advance=t_advance;
		misc=t_misc;
		room_srv=t_room_srv;
		fstream file;
		file.open("HROOM.DAT",ios::out | ios::app);
		file.write((char*)this,sizeof(customer));
		file.close();
	}
}
//***********************************************************************************************
//CLASS NAME 	: CUSTOMER
//FUNCTION NAME	:DISPLAY _RECORD
/*DETAILS		:IT DISPLAYS THE RECORDS OF CUSTOMER IN THE GIVEN  ROOM NO.*/
//***********************************************************************************************
void customer::display_record(int t_roomno)
{
	fstream file;
	file.open("HROOM.DAT",ios::in);
	file.seekg(0);
	int found=0;
	while (file.read((char*)this, sizeof(customer)) && !found)
	{
		if(t_roomno==roomno)
		{
			found=1;
			cout<<"\n\tRoom no.		:"<<roomno;
			cout<<"\n\tCustomer Name		:"<<name;
			cout<<"\n\tPhone no.		 :"<<phone;
			cout<<"\n\tAdvance no.		:"<<advance;
			cout<<"\n\tMisc.charges		:"<<misc;
			cout<<"\n\tRoom Service Charges		:"<<room_srv;
		}
	}
	file.close ();
}

//***********************************************************************************************
//	CLASS NAME		:CUSTOMER
//	FUNCTION NAME	:RECORDNO
/*	DETAILS		:IT RETURNS THE RECORD NO. OF THE GIVEN ROOM NO. IN CUSTOMER FILE*/
//***********************************************************************************************
int customer ::recordno(int t_roomno)
{
	fstream file;
	file.open("HROOM.DAT", ios::in);
	file.seekg(0);
	int count=0;
	while (file.read((char*)this,sizeof(customer)))
	{
		count++;
		if(t_roomno==roomno)
		       break;
	}
	file.close();
	return count;
}
//***********************************************************************************************
//	CLASS NAME		:CUSTOMER
//	FUNCTION NAME	:MODIFY
/*	DETAILS	:IT MODIFY THE CUSTOMER’S RECORD IN THE CUSTOMER
//                               FILE(CUSTOMER.DAT)*/
//***********************************************************************************************
void customer	::modify(void)
{
	clrscr();
	room r;
	int valid;
	char ch;
	int t_roomno, tr;
	char t_name[21], t_phone[8];
	float t_advance, t_misc,t_room_srv;
	fstream file;
	file.open("HROOM.DAT",ios::out | ios::ate);
	cout<<"\n\tEnter the Room no. of the customer to be modified\t";
	cin>>tr;
	char t_status;
	t_status=r.room_status(tr);
	if(!r.room_found(tr) || t_status== 'V')
	{
		cout<<"\n\tROOM NO.NOT FOUND OR ROOM IS VACANT";
		cout<<"\n\tPress any key to continue...";
		getch();
		return;
	}
	display_record(tr);
	cout<<"\n\t Do you want to modify this Room Record(y/n):";
	do
	{
		valid=1;
		ch=getch();
		ch=toupper(ch);
		if (ch!= 'Y' && ch!= 'N')
		{
			valid=0;
		}
	}
	while(!valid);
	if(ch== 'N')
		return;
	cout<<"\n\tENTER THE NEW DATA FOR THE CUSTOMER";
	cout<<"\n\tRoom no.	: " ;
	cout<<"\n\tName	: " ;
	cout<<"\n\tPhone	: " ;
	cout<<"\n\tAdvance	: " ;
	cout<<"\n\tMiscellineous	: " ;
	cout<<"\n\tRoom service	: " ;
	do
	{
		valid =1;
		cout<<"\n\tENTER THE ROOM NUMBER FOR CUSTOMER\t";
		cin>>t_roomno;
		t_status=r.room_status(t_roomno);
		if(!r.room_found(t_roomno) || (r.room_found(t_roomno) && t_roomno!=tr && t_status =='O'))
		{
			valid=0;
			cout<<"\n\tROOM NO. EXIST OR NOT VACAVT\t";
			cout<<"\n\tPress any key to continue...";
			getch();
		}
	}
	while (!valid);
	do
	{
		valid=1;
		cout<<"\n\tENTER THE NAME OF THE CUSTOMER\t";
		gets(t_name);
		strupr(t_name);
		if((strlen(t_name)<=0 || strlen(t_name)>20))
		{
			valid=0;
			cout<<"\n\tLENGTH SHOULD NOT BE ZERO OR GREATHER THAN 20";
			cout<<"\n\tPress any key to continue...";
			getch();
		}
	}
	while(!valid);
	do
	{
		valid=1;
		cout<<"\n\tENTER THE PHONE NUMBER OF THE  CUSTOMER, ENTER '-' FOR NO PHONE NO. \t";
		cin>>t_phone;
		if((strlen(t_phone)<7 && strlen(t_phone)>1 ) || (strlen(t_phone)>7))
		{
			valid =0;
			cout<<"\n\tLENGTH SHOULD NOT LESS THAN 7 OR GREATER THAN 7";
			cout<<"\n\tPress any key to continue...";
			getch();
		}
	}
	while(valid);
	do
	{
		valid=1;
		cout<<"\n\tENTER THE ADVANCE RS.\t";
		cin>>t_advance;
		if (t_advance<0)
		{
			valid=0;
			cout <<"\n\tSHOULD NOT LESS THAN ZERO";
			cout<<"\n\tPress any key to continue...";
			getch();
		}
	}
	while(!valid);
	do
	{
		valid=1;
		cout<<"\n\tENTER THE MISCALLENIOUS CHARGES\t";
		cin>>t_misc;
		if( t_misc<0)
		{
			cout<<"\n\tSHOULD NOT LESS THAN ZERO";
			cout<<"\n\tPress any key to continue...";
			getch();
		}
	}
	while(!valid);
	do
	{
		valid=1;
		cout<<"\\tnENTER THE ROOM SERVICE CHARGES\T";
		cin>>t_room_srv;
		if(t_room_srv<0)
		{
			valid=0;
			cout<<"\n\tSHOULD NOT LESS THAN ZERO";
			cout<<"\n\tPress any key to continue...";
			getch();
		}
	}
	while(!valid);
	cout<<"\n\tDo you want to save the record(y/n): " ;
	do
	{
		valid=1;
		ch=getch();
		ch=toupper(ch);
		if( ch!= 'Y' && ch!= 'N')
		{
			valid=0;
		}
	}
	while(!valid);
	if(ch== 'Y')
	{
		if(t_roomno!=tr)
		{
		r.change_status(t_roomno, 'O');
		r.change_status(tr, 'V');
		}
		int recno;
		recno=recordno(tr);
		int location;
		location=(recno-1)*sizeof (customer);
		file.seekp(location);
		roomno=t_roomno;
		strcpy(name,t_name);
		strcpy(phone,t_phone);
		room_srv=t_room_srv;
		advance=t_advance;
		misc=t_misc;
		file.write((char*)this, sizeof (customer));
	}
	file.close();
}
//***********************************************************************************************
//	CLASS NAME		:CUSTOMER
//	FUNCTION NAME	:DELETE_RECORD
/*	DETAILS	:IT DELETE THE CUSTOMER’S RECORD IN THE CUSTOMER
                                FILE(CUSTOMER.DAT) OF THE GIVEN ROOM NO.*/
//***********************************************************************************************
void customer::delete_record(int t_roomno)
{
	fstream file;
	file.open("HROOM.DAT" ,ios::in);
	fstream temp;
	temp.open("temp.dat",ios::out);
	while (!file.eof())
	{
		file.read((char*)this, sizeof(customer));
		if (file.eof())
		      break;
		if(roomno!=t_roomno)
		     temp.write((char*)this, sizeof (customer));
	}
	file.close();
	temp.close();
	file.open("HROOM.DAT" ,ios::out);
	temp.open("temp.dat",ios::in);
	temp.seekg(0);
	while(!temp.eof())
	{
		temp.read((char*)this,sizeof (customer));
		if(temp.eof())
		      break;
		file.write((char*)this,sizeof (customer));
	}
	file.close();
	temp.close();
}
//***********************************************************************************************
//	CLASS NAME		:CUSTOMER
//	FUNCTION NAME	:DISPLAY_CUSTOMER_RECORD
/*	DETAILS	:IT  GIVES THE  ROOM NO. OF THE CUSTOMER   TO DISPLAY THE
                        CUSTOMER RECORD*/
//***********************************************************************************************
void customer::display_customer_record(void)
{
	clrscr();
	room r;
	int valid;
	int t_roomno;
	cout<<"\n\tEnter the room no.of the customer:" ;
	cin>>t_roomno;
	char t_status;
	t_status=r.room_status(t_roomno);
	if (!r.room_found(t_roomno) || t_status== 'V')
	{
		cout<<"\n\tROOM NO.NOT FOUND OR ROOM IS VACANT\t";
		cout<<"\n\tPress any key to continue...";
		getch();
		return;
	 }
	clrscr();
	cout<<"\n\t CUSTOMER RECORD";
	display_record(t_roomno);
	cout<<"\n\tPress any key to continue...";
	getch();
}
//***********************************************************************************************
//	CLASS NAME		:CUSTOMER
//	FUNCTION NAME	:DELETION
/*	DETAILS	:IT  GIVES THE  ROOM NO. OF THE CUSTOMER TO DELETE  THE
                           CUSTOMER RECORD*/
//***********************************************************************************************
void customer::deletion(void)
{
	clrscr();
	room r;
	int valid;
	char ch ;
	int t_roomno;
	cout<<"\n\tEnter the Roomno of the customer to be deleted";
	cin>>t_roomno;
	char t_status;
	t_status=r.room_status(t_roomno);
	if(!r.room_found(t_roomno) || t_status== 'V')
	{
		cout<<"\n\tROOM NO.NOT FOUND OR ROOM IS VACANT\t";
		cout<<"\n\tPress any key to continue...";
		getch();
		return;
	}
	display_record(t_roomno);
	cout<<"\n\t Do you want to delete the customer record(y/n):";
	do
	{
		valid=1;
		ch=getch();
		ch=toupper(ch);
		if( ch!= 'Y' && ch!= 'N')
		{
		     valid=0;
		}
	}
	while(!valid);
	if(ch=='N')
	     return;
	r.change_status(t_roomno, 'V');
	delete_record(t_roomno);
}

//***********************************************************************************************
//	CLASS NAME		:CUSTOMER
//	FUNCTION NAME	:CHECKOUT
/*	DETAILS	:IT  GIVES THE  DATA OF THE CUSTOMER PERPARE BILL OF THE
                            CUSTOMER AND ALSO   THE CUSTOMER RECORD*/
//***********************************************************************************************
void customer ::checkout(void)
{
	clrscr();
	room r;
	int valid ;
	char ch;
	int t_roomno;
	cout<<"\n\tEnter the room no of the customer to be check out \t" ;
	cin>>t_roomno;
	char t_status;
	t_status=r.room_status(t_roomno);
	if(!r.room_found(t_roomno) || t_status== 'V')
	{
		cout<<"\n\tROOM NO.NOT FOUND OR ROOM IS VACANT\t";
		cout<<"\n\tPress any key to continue...";
		getch();
		return;
	}
	display_record(t_roomno);
	cout<<"\n\t Do you want to prepare bill of this Customer Record(y/n):";
	do
	{
		valid=1;
		ch=getch();
		ch=toupper(ch);
		if( ch!= 'Y' && ch!= 'N')
		{
		       valid=0;
		}
	}
	while(!valid);
	if(ch=='N')
	     return;
	fstream file;
	file.open("HROOM.DAT",ios::in);
	file.seekg(0);
	char t_name[21];
	float t_advance,t_room_srv,t_misc,t_tarriff;
	while(file.read((char*)this,sizeof(customer)))
	{
		if(t_roomno==roomno)
		{
			strcpy(t_name,name);
			t_advance=advance;
			t_room_srv=room_srv;
			t_misc=misc;
			break;
		}
	}
	file.close();
	t_tarriff=r.get_data(t_roomno);
	account a;
	a.prepare_bill(t_roomno,t_tarriff,t_name,t_advance,t_room_srv,t_misc);
	r.change_status(t_roomno,'V');
	delete_record(t_roomno);
	cout<<"\n\tPress any key to continue…”.";
	getch();
}
//***********************************************************************************************
//	CLASS NAME	       :ACCOUNT
//	FUNCTION NAME    :PREPARE BILL
/*	DETAILS      :IT ACCEPTS THE DATA OF THE CUSTOMER & ALSO CREATES BILL SLIP*/
//***********************************************************************************************
void account::prepare_bill(int t_roomno,float t_tarriff,char t_name[21],float t_advance,float t_room_srv,float t_misc)
{
	int valid;
	int days;
	float tax,total,x;
	cout<<"\n\t Enter the no. of days  :  ";
	cin>>days;
	fstream f;
	f.open("HROOM.DAT",ios::in || ios::out);
	x=((t_tarriff*days)+t_misc+t_room_srv)-t_advance;
	tax=0.1*x;
	float res=restaurant();
	total=res+tax+x;
	f<<total;
	f.close();
	cout<<"\n\t  !! BILL SLIP !! \n";
	cout<<"\n\t  Customer name  :  ";
	puts(t_name);
	cout<<"\n\t Restaurant bill \t"<<res;
	cout<<"\n\t Room no. \t"<<t_roomno;
	cout<<"\n\t Room service charges \t"<<t_room_srv;
	cout<<"\n\t Tax \t"<<tax;
	cout<<"\n\t Rent per day \t"<<t_tarriff;
	cout<<"\n\t other charges \t"<<t_tarriff;
	cout<<"\n\t TOTAL AMOUNT PAYABLE \t"<<total;
	cout<<"\n\t**** THANKS FOR VISIT **** ";
	cout<<"\n\t **** VISIT AGAIN ***** ";
}
float restaurant()
{
	cout<<"\n\t  Menu";
	cout<<"\n\t  1.Tea \t Rs.15";
	cout<<"\n\t 2.Cold Drink \t Rs 20";
	cout<<"\n\t 3.Today’s Special \t Rs 150";
	cout<<"\n\t 4. Special Thali \t Rs 100";
	cout<<"\n\t 5. Exit";
	int a,q;
	float t=0;
	char ch;
	do
	{
		cout<<"\n\t Enter Choice \t";
		cin>>a;
		cout<<"\n\t Enter quantity \t";
		cin>>q;
		if(a==1)
			t=t+15*q;
		if(a==2)
			t=t+20*q;
		if(a==3)
			t=t+150*q;
		if(a==4)
			t=t+100*q;
		if(a==5)
			break;
		cout<<"\n\t Do you want to anything else\t";
		cin>>ch;
	}
	while(ch=='y');
	cout<<"\n\t Restaurant Bill \t"<<t;
	return t;
}
//***********************************************************************************************
//Function  name : Info
//This function contains information about the hotel
//***********************************************************************************************
void info()
{
	menu m1;
	m1.enter_password();
	textmode(C80);
	textbackground(WHITE);
	textcolor(RED);
	m1.main_menu();
}
void main()
{
	textmode(C80);
	textbackground(WHITE);
	textcolor(RED);
	clrscr();
	cout<<"\n\t**************C++ PROJECT ON HOTEL MANAGEMENT***************";
	info();
}

