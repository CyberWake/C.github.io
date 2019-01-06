/*	This Program Is Coded By Ritik Kumar Srivastava,Student Of Mr.Vivek Saxena.
	School :-> Dr.VSEC,Farrukhabad.
	Class  :-> 12th-A.
	Roll No:-> 21.
	Subject:-> Computer Science.

	This Is A School Database Managment System.
*/

//                       Header Files Declaration

#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
#include<string.h>
#include<dos.h>
#include<process.h>
#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
#include<fstream.h>


int choice,Control=0;      //Global Variables


struct LOGIN_SYS           //Structure
{
	char ID[20];
	char Password[15];
};


class STU_DET              //CLASS
{
	int CLASS;
	int RNO;
	char NAME[50];
	char SECTION;
	char ADDRESS[50];
	char MOBILENO[15];

	public:

	void getdetail();
	void showdetail();
	int retRNO()
	{
		return RNO;
	}
	int retCLASS()
	{
		return CLASS;
	}
};


void STU_DET::getdetail()
{
	cout<<"ENTER CLASS     ";
	cin>>CLASS;
	cout<<"ENTER RNO       ";
	cin>>RNO;
	cout<<"ENTER NAME      ";
	gets(NAME);
	cout<<"ENTER SECTION   ";
	cin>>SECTION;
	cout<<"ENTER ADDRESS   ";
	gets(ADDRESS);
	cout<<"ENTER MOBILE NO ";
	cin>>MOBILENO;
}


void STU_DET::showdetail()
{
	cout<<"\t"<<CLASS<<"\t"<<RNO<<"\t"<<NAME<<"\t\t"<<SECTION<<"\t"<<ADDRESS<<"\t\t"<<MOBILENO<<endl;
}


void login()
{
	int i=0;
	logn:                       //LABEL
	clrscr();
	int x=DETECT,y;             // FOR USING
	initgraph(&x,&y,"");        // GRAPHICS
	cleardevice();
	LOGIN_SYS IDPASS;
	fstream obj1("login_sys.txt",ios::in|ios::binary);
	char ID[20],Password[15];
	cout<<"\n\n\n\n\n\n\n"<<"\t\t\t\t"<<"Login"<<endl<<endl;
	cout<<"\n\n\t\t\t"<<"ID       : ";
	cin>>ID;
	cout<<"\n\t\t\t"<<"Password : ";
	cin>>Password;
	int entry=0;
	while(obj1.read((char*)&IDPASS,sizeof(IDPASS)))
	{
		if((!(strcmpi(ID,IDPASS.ID)))&&(!(strcmpi(Password,IDPASS.Password))))
		{
			delay(500);
			entry=1;
		}
	}
	if(entry==1);
	else
	{
		cout<<"Access Denied";
		i++;
		delay(200);
		if(i==3) // This is The Max. No of Wrong Trials Permitted
		{
			exit(0);
		}
		clrscr();
		goto logn;
	}

}


void intro()
{
	int counting=0;
	Control=0;
	Wrong:
	clrscr();
	cleardevice();
	int x=DETECT,y;
	initgraph(&x,&y,"");
	setcolor(4);
	rectangle(0,0,639,40);
	setfillstyle(1,4);
	floodfill(1,1,15);
	setcolor(15);
	settextstyle(1,0,3);
	outtextxy(220,5,"DR. V.S.E.C FBD.");
	setcolor(15);
	rectangle(0,40,639,70);
	setfillstyle(1,15);
	floodfill(1,41,15);
	setcolor(4);
	settextstyle(2,0,8);
	outtextxy(60,40,"SCHOOL DATABASE MANAGEMENT SYSTEM.");
	setcolor(1);
	rectangle(80,125,200,160);
	setfillstyle(1,1);
	floodfill(81,126,1);
	setcolor(15);
	settextstyle(8,0,3);
	outtextxy(90,125,"CLASS 1");
	setcolor(1);
	rectangle(264,125,384,160);
	setfillstyle(1,1);
	floodfill(265,126,1);
	setcolor(15);
	settextstyle(8,0,3);
	outtextxy(270,125,"CLASS 2");
	setcolor(1);
	rectangle(448,125,568,160);
	setfillstyle(1,1);
	floodfill(450,126,1);
	setcolor(15);
	settextstyle(8,0,3);
	outtextxy(460,125,"CLASS 3");
	setcolor(1);
	rectangle(80,215,200,250);
	setfillstyle(1,1);
	floodfill(81,216,1);
	setcolor(15);
	settextstyle(8,0,3);
	outtextxy(90,215,"CLASS 4");
	setcolor(1);
	rectangle(264,215,384,250);
	setfillstyle(1,1);
	floodfill(265,216,1);
	setcolor(15);
	settextstyle(8,0,3);
	outtextxy(270,215,"CLASS 5");
	setcolor(1);
	rectangle(448,215,568,250);
	setfillstyle(1,1);
	floodfill(450,216,1);
	setcolor(15);
	settextstyle(8,0,3);
	outtextxy(460,215,"CLASS 6");
	setcolor(1);
	rectangle(80,305,200,340);
	setfillstyle(1,1);
	floodfill(81,306,1);
	setcolor(15);
	settextstyle(8,0,3);
	outtextxy(90,305,"CLASS 7");
	setcolor(1);
	rectangle(264,305,384,340);
	setfillstyle(1,1);
	floodfill(265,306,1);
	setcolor(15);
	settextstyle(8,0,3);
	outtextxy(270,305,"CLASS 8");
	setcolor(1);
	rectangle(448,305,568,340);
	setfillstyle(1,1);
	floodfill(450,306,1);
	setcolor(15);
	settextstyle(8,0,3);
	outtextxy(460,305,"CLASS 9");
	setcolor(1);
	rectangle(80,395,200,430);
	setfillstyle(1,1);
	floodfill(81,396,1);
	setcolor(15);
	settextstyle(8,0,3);
	outtextxy(90,395,"CLASS10");
	setcolor(1);
	rectangle(264,395,384,430);
	setfillstyle(1,1);
	floodfill(265,396,1);
	setcolor(15);
	settextstyle(8,0,3);
	outtextxy(270,395,"CLASS11");
	setcolor(1);
	rectangle(448,395,568,430);
	setfillstyle(1,1);
	floodfill(450,396,1);
	setcolor(15);
	settextstyle(8,0,3);
	outtextxy(460,395,"CLASS12");
	settextstyle(2,0,8);
	outtextxy(110,442,"Press 0 To Add A login Account");
	cout<<"\n\n\n\n\nENTER CLASS ";
	cin>>choice;
	if(choice<0||choice>12)
	{
		clrscr();
		cleardevice();
		cout<<"Wrong Choice Entered.";
		delay(700);
		counting++;
		if(counting==3)
		{
			clrscr();
			cleardevice();
			cout<<"Maximum Permitted Trials Over"<<endl;
			cout<<"Shutting Program Down"<<endl;
			delay(1000);
			exit(0);
		}
		goto Wrong;
	}
	if(choice==0)
	{
		clrscr();
		cleardevice();
		fstream obj("login_sys.txt",ios::app|ios::binary);
		LOGIN_SYS IDPass;
		cout<<"Enter ID ";
		gets(IDPass.ID);
		cout<<"Enter Password ";
		gets(IDPass.Password);
		obj.write((char*)&IDPass,sizeof(IDPass));
		obj.close();
		goto Wrong;
	}
}


void ADD()
{
	int x=DETECT,y;
	initgraph(&x,&y,"");
	clrscr();
	cleardevice();
	fstream obj3("DATA.dat",ios::app|ios::binary);
	STU_DET Student;
	cout<<endl<<endl;
	cout<<"\tWAIT A MOMENT";
	delay(250);
	cout<<".";
	delay(250);
	cout<<".";
	delay(250);
	cout<<".";
	clrscr();
	cleardevice();
	Student.getdetail();
	delay(700);
	clrscr();
	cleardevice();
	obj3.write((char*)&Student,sizeof(Student));
	obj3.close();
	clrscr();
	cleardevice();
	cout<<"\n\tRecord Has Been Added"<<endl;
	delay(700);
	obj3.close();
	Control=1;
}


void MOD()
{
	int x=DETECT,y;
	initgraph(&x,&y,"");
	clrscr();
	cleardevice();
	int Class,RollNo;
	cout<<"\n\tEnter CLASS Of The Record To Be Modified ";
	cin>>Class;
	cout<<"\tEnter RNO   Of The Record To Be Modified ";
	cin>>RollNo;
	cout<<"\n\tRECORDS ARE BEEN SEARCHED ";
	delay(1000);
	clrscr();
	cleardevice();
	fstream obj4("DATA.dat",ios::in|ios::out|ios::binary);
	STU_DET Stud;
	int cou=0;
	while(obj4)
	{
		int pos=obj4.tellg();
		obj4.read((char*)&Stud,sizeof(STU_DET));
		if(Stud.retCLASS()==Class&&Stud.retRNO()==RollNo)
		{
			obj4.seekg(pos);
			cout<<"\n\tEnter New Values"<<endl<<endl;
			Stud.getdetail();
			obj4.write((char*)&Stud,sizeof(STU_DET));
			delay(700);
			clrscr();
			cleardevice();
			cout<<"\n\tRECORD HAS BEEN MODIFIED";
			cou=1;
			delay(700);
			break;
		}
	}obj4.close();
	if(cou!=1)
	{
		delay(700);
		clrscr();
		cleardevice();
		cout<<"\n\tRECORD NOT FOUND";
		delay(700);
	}
	Control=1;
}


void DEL()
{
	int x=DETECT,y;
	initgraph(&x,&y,"");
	clrscr();
	cleardevice();
	fstream obj5("DATA.dat",ios::in|ios::binary);
	fstream obj6("TEMP.dat",ios::out|ios::binary);
	int Class,Rno;
	cout<<"\n\tEnter Class Of The Record To Be Deleted ";
	cin>>Class;
	cout<<"\tEnter Roll No Of The Record To Be Deleted ";
	cin>>Rno;
	STU_DET STUDENT;
	int cou=0;
	while(obj5.read((char*)&STUDENT,sizeof(STU_DET)))
	{
		if(STUDENT.retCLASS()==Class&&STUDENT.retRNO()==Rno)
		{
			cou=1;
		}
		else
		{
			obj6.write((char*)&STUDENT,sizeof(STUDENT));
		}
	}
	if(cou==1)
	{
		delay(700);
		clrscr();
		cleardevice();
		cout<<"\n\tRECORD HAS BEEN DELETED ";
		delay(700);
	}
	else
	{
		delay(700);
		clrscr();
		cleardevice();
		cout<<"\n\tRECORD NOT FOUND  ";
		delay(700);
	}
	obj5.close();
	obj6.close();
	remove("DATA.dat");
	rename("TEMP.dat","DATA.dat");
	Control=1;
}


void database()
{
	int x=DETECT,y;
	initgraph(&x,&y,"");
	clrscr();
	cleardevice();
	fstream obj2("DATA.dat",ios::in|ios::binary);
	int count=0;
	STU_DET student;
	int i=12;
	while(obj2.read((char*)&student,sizeof(STU_DET)))
	{

		if(count==0)
		{
			cout<<endl;
			cout<<"\tCLASS\tROLLNO\tNAME\t\tSECTION\tADDRESS\t\tMOBNO"<<endl<<endl;
			rectangle(6,2,635,40);
			count++;
		}
		if(student.retCLASS()==choice)
		{
			student.showdetail();
			i+=30;
			line(40,40,40,40+i);
			line(98,40,98,40+i);
			line(160,40,160,40+i);
			line(290,40,290,40+i);
			line(360,40,360,40+i);
			line(490,40,490,40+i);
			line(610,40,610,40+i);
			cout<<endl;
		}
	}obj2.close();
	line(40,40+i,610,40+i);
	cout<<endl<<endl<<endl<<endl;
	cout<<"\t\t    For Addition Of New Record (Press 1)"<<endl;
	cout<<"\t\t    For Modifying A Record     (Press 2)"<<endl;
	cout<<"\t\t    For Deletion Of A Record   (Press 3)"<<endl;
	cout<<"\t\t    For Main Screen            (Press 4)"<<endl;
	cout<<"\t\t    To Exit (Press Any NUM Except Above)"<<endl;
	cout<<"\n\t\t\t    YOUR CHOICE ";
	int press;
	cin>>press;
	if(press==1)
		ADD();
	else if(press==2)
		MOD();
	else if(press==3)
		DEL();
	else if(press==4)
		Control=1;
	else;
}


void main()
{
	clrscr();
	login();
	MainScreen:
	intro();
	database();
	if(Control==1)
		goto MainScreen;

}