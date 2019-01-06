#include<iostream.h>
#include<conio.h>
#include<ctype.h>
#include<process.h>
#include<stdlib.h>
#include<dos.h>
#include<graphics.h>
#include<time.h>
#include<stdio.h>
#include<string.h>
#include<fstream.h>

/*                               CHESS GAME
		     MADE BY:-> RITIK KUMAR SRIVASTAVA
				Class:-> XII A

*/

//DECLARATION OF THE CHESS BOARD
char board[9][10]={" 12345678",
		   "ARNBKQBNR",
		   "BPPPPPPPP",
		   "C        ",
		   "D        ",
		   "E        ",
		   "F        ",
		   "Gpppppppp",
		   "Hrnbqkbnr"};

int score1=0,score2=0;
//(xi,yi) is the coordinate of the initial position of the peice.
//(xf,yf) is the coordinate of the initial position of the peice.
int xi,yi,xf,yf;

//chance decides the turn of the palyer
int chance=0;

//peice stores the value of the selected peice for move.
char peice;

class savedata
{
	char player1name[20];
	char player2name[20];
	int score1;
	int score2;
	char outcome[20];
	public:
	void score();
	void playername();
	void display();
	void out1();
	void out2();
}obj;

void savedata::score()
{
	score1=::score1;
	score2=::score2;
}

void savedata::playername()
{
	clrscr();
	cout<<"\n\n\n\n\n\n\n\n\t\t\t";
	cout<<"Enter Player 1 name: ";
	gets(player1name);
	cout<<"\t\t\t";
	cout<<"Enter Player 2 name: ";
	gets(player2name);
}

void savedata::display()
{
	cout<<"  ";
	cout<<player1name<<"\t\t";
	cout<<player2name<<"\t\t   ";
	cout<<score1<<"\t\t   ";
	cout<<score2<<"\t\t";
	cout<<outcome;
	cout<<"\n";
}

void savedata::out1()
{
	strcpy(outcome,"Player 1 won");
}

void savedata::out2()
{
	strcpy(outcome,"Player 2 won");
}

void save()
{
	fstream fout("data.txt",ios::app|ios::binary);
	if(!fout)
	{
		cout<<"file not created";
		delay(1000);
		exit(0);
	}
	fout.write((char*)&obj,sizeof(obj));
	fout.close();
}

void read()
{
	clrscr();
	cout<<"\n\n\n\n\n\n\n\n\n\n";
	cout<<"   Player 1\tPlayer 2\tPlayer 1\tPlayer 2\tOutcome\n";
	cout<<"     Name  \t  Name  \t  Score \t  Score \n\n";
	fstream fin("data.txt",ios::in|ios::binary);
	if(!fin)
	{
		cout<<"file not opened";
		delay(1000);
		exit(0);
	}
	//Player 2 Name\tPlayer 1 Score\tPlayer 2 Score\tOutcome\n");
	while(fin.read((char*)&obj,sizeof(obj)))
	{
		obj.display();
	}
	fin.close();
}
//void score calculates the score of both the players.
void score()
{
	int scoremax=55;
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
			if(board[i][j]=='p' || board[i][j]=='P')
			{
				if(islower(board[i][j]))
				{
					score1+=2;
				}
				else
				{
					score2+=2;
				}
			}
			else if(board[i][j]=='r' || board[i][j]=='R')
			{
				if(islower(board[i][j]))
				{
					score1+=3;
				}
				else
				{
					score2+=3;
				}
			}
			else if(board[i][j]=='n' || board[i][j]=='N')
			{
				if(islower(board[i][j]))
				{
					score1+=4;
				}
				else
				{
					score2+=4;
				}
			}
			else if((board[i][j]=='b' || board[i][j]=='B') && j>0)
			{
				if(islower(board[i][j]))
				{
				score1+=4;
				}
				else
				{
					score2+=4;
				}
			}
			else if(board[i][j]=='q' || board[i][j]=='Q')
			{
				if(islower(board[i][j]))
				{
					score1+=7;
				}
				else
				{
					score2+=7;
				}
			}
			else if(board[i][j]=='k' || board[i][j]=='K')
			{
				if(islower(board[i][j]))
				{
					score1+=10;
				}
				else
				{
					score2+=10;
				}
			}
		}
	}
	score1=scoremax-score1;
	score2=scoremax-score2;
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t             "<<score1;
	cout<<"\t\t        "<<score2;
	obj.score();
};

//displayboard() displayes the board every time after the move of any peice
void displayboard()
{
	clrscr();
	int x=DETECT,y;
	initgraph(&x,&y,"");
	//main frame
	rectangle(40,40,350,440);
	//horizontal sub divisons
	rectangle(40,40,350,390);
	rectangle(40,40,350,340);
	rectangle(40,40,350,290);
	rectangle(40,40,350,240);
	rectangle(40,40,350,190);
	rectangle(40,40,350,140);
	rectangle(40,40,350,90);
	//vertical sub-divisions
	//LTRB
	rectangle(40,40,78,440);
	rectangle(40,40,117,440);
	rectangle(40,40,156,440);
	rectangle(40,40,195,440);
	rectangle(40,40,234,440);
	rectangle(40,40,273,440);
	rectangle(40,40,312,440);
	//colorfill
	setfillstyle(1,0);
	floodfill(0,0,15);
	setfillstyle(1,15);
	floodfill(41,41,15);
	floodfill(41,141,15);
	floodfill(41,241,15);
	floodfill(41,341,15);
	floodfill(118,41,15);
	floodfill(118,141,15);
	floodfill(118,241,15);
	floodfill(118,341,15);
	floodfill(196,41,15);
	floodfill(196,141,15);
	floodfill(196,241,15);
	floodfill(196,341,15);
	floodfill(274,41,15);
	floodfill(274,141,15);
	floodfill(274,241,15);
	floodfill(274,341,15);
	floodfill(79,129,15);
	floodfill(157,129,15);
	floodfill(235,129,15);
	floodfill(313,129,15);
	floodfill(79,229,15);
	floodfill(157,229,15);
	floodfill(235,229,15);
	floodfill(313,229,15);
	floodfill(79,329,15);
	floodfill(157,329,15);
	floodfill(235,329,15);
	floodfill(313,329,15);
	floodfill(79,429,15);
	floodfill(157,429,15);
	floodfill(235,429,15);
	floodfill(313,429,15);
	for(int i=0,xa=15;i<10;i++,xa+=50)
	{
		for(int j=0,ya=17;j<10;j++,ya+=39)
		{
			if(board [i][j]=='A')
			{
				setcolor(15);
				outtextxy(ya,xa,"A");
			}
			else if(board[i][j]=='B' && j==0)
			{
				setcolor(15);
				outtextxy(ya,xa,"B");
			}
			else if(board[i][j]=='C')
			{
				setcolor(15);
				outtextxy(ya,xa,"C");
			}
			else if(board[i][j]=='D')
			{
				setcolor(15);
				outtextxy(ya,xa,"D");
			}
			else if(board[i][j]=='E')
			{
				setcolor(15);
				outtextxy(ya,xa,"E");
			}
			else if(board[i][j]=='F')
			{
				setcolor(15);
				outtextxy(ya,xa,"F");
			}
			else if(board[i][j]=='G')
			{
				setcolor(15);
				outtextxy(ya,xa,"G");
			}
			else if(board[i][j]=='H')
			{
				setcolor(15);
				outtextxy(ya,xa,"H");
			}
			else if(board[i][j]=='B')
			{
				setcolor(4);
				outtextxy(ya,xa,"B");
			}
			else if(board[i][j]=='K')
			{
				setcolor(4);
				outtextxy(ya,xa,"K");
			}
			else if(board[i][j]=='N')
			{
				setcolor(4);
				outtextxy(ya,xa,"N");
			}
			else if(board[i][j]=='P')
			{
				setcolor(4);
				outtextxy(ya,xa,"P");
			}
			else if(board[i][j]=='Q')
			{
				setcolor(4);
				outtextxy(ya,xa,"Q");
			}
			else if(board[i][j]=='R')
			{
				setcolor(4);
				outtextxy(ya,xa,"R");
			}
			else if(board[i][j]=='r')
			{
				setcolor(9);
				outtextxy(ya,xa,"r");
			}
			else if(board[i][j]=='n')
			{
				setcolor(9);
				outtextxy(ya,xa,"n");
			}
			else if(board[i][j]=='b')
			{
				setcolor(9);
				outtextxy(ya,xa,"b");
			}
			else if(board[i][j]=='q')
			{
				setcolor(9);
				outtextxy(ya,xa,"q");
			}
			else if(board[i][j]=='k')
			{
				setcolor(9);
				outtextxy(ya,xa,"k");
			}
			else if(board[i][j]=='p')
			{
				setcolor(9);
				outtextxy(ya,xa,"P");
			}
			else if(board[i][j]=='1')
			{
				setcolor(15);
				outtextxy(ya,xa,"1");
			}
			else if(board[i][j]=='2')
			{
				setcolor(15);
				outtextxy(ya,xa,"2");
			}
			else if(board[i][j]=='3')
			{
				setcolor(15);
				outtextxy(ya,xa,"3");
			}
			else if(board[i][j]=='4')
			{
				setcolor(15);
				outtextxy(ya,xa,"4");
			}
			else if(board[i][j]=='5')
			{
				setcolor(15);
				outtextxy(ya,xa,"5");
			}
			else if(board[i][j]=='6')
			{
				setcolor(15);
				outtextxy(ya,xa,"6");
			}
			else if(board[i][j]=='7')
			{
				setcolor(15);
				outtextxy(ya,xa,"7");
			}
			else if(board[i][j]=='8')
			{
				setcolor(15);
				outtextxy(ya,xa,"8");
			}
		}
	}
	setcolor(5);
	outtextxy(400,195,"peice of          peice of");
	outtextxy(405,205,"player1           player2");
	setcolor(11);
	line(505,210,505,340);
	setcolor(4);
	outtextxy(400,225,"R:");
	outtextxy(400,245,"N:");
	outtextxy(400,265,"B:");
	outtextxy(400,285,"Q:");
	outtextxy(400,305,"K:");
	outtextxy(400,325,"P:");
	setcolor(2);
	outtextxy(420,225,"Rook");
	outtextxy(420,245,"Knight");
	outtextxy(420,265,"Bishop");
	outtextxy(420,285,"Queen");
	outtextxy(420,305,"King");
	outtextxy(420,325,"Pawn");
	setcolor(9);
	outtextxy(545,225,"r:");
	outtextxy(545,245,"n:");
	outtextxy(545,265,"b:");
	outtextxy(545,285,"q:");
	outtextxy(545,305,"k:");
	outtextxy(545,325,"p:");
	setcolor(6);
	outtextxy(565,225,"Rook");
	outtextxy(565,245,"Knight");
	outtextxy(565,265,"Bishop");
	outtextxy(565,285,"Queen");
	outtextxy(565,305,"King");
	outtextxy(565,325,"Pawn");
	outtextxy(380,430,"Score player 1");
	outtextxy(525,430,"Score player 2");
	setcolor(11);
	line(505,420,505,490);
	score();
};

//player_peice_selection() generates the coordinate(xi,yi).

void player_peice_selection()
{
	time_t first,second,y;
	char select[3];
	int xa=26,ya=480;
	enteragain:
	if(chance%2==0)
	{
		setcolor(4);
		outtextxy(ya,xa,"Player 1");
	}
	else
	{
		setcolor(9);
		outtextxy(ya,xa,"Player 2");
	}
	setcolor(7);
	outtextxy(360,37,"select peice:(eg:B1):->");
	first = time(NULL);
	gotoxy(69,3);
	cin>>select;
	second = time(NULL);
	y=difftime(second,first);
	if(y>=20.0)
	{
		cout<<"timeup";
	}
	switch(select[0])
	{
		case'A':xi=1;
			break;
		case'B':xi=2;
			break;
		case'C':xi=3;
			break;
		case'D':xi=4;
			break;
		case'E':xi=5;
			break;
		case'F':xi=6;
			break;
		case'G':xi=7;
			break;
		case'H':xi=8;
			break;
		case'0':xi=0;
			break;
		default:cout<<"wrong selection";
	}
	switch(select[1])
	{
		case'1':yi=1;
			break;
		case'2':yi=2;
			break;
		case'3':yi=3;
			break;
		case'4':yi=4;
			break;
		case'5':yi=5;
			break;
		case'6':yi=6;
			break;
		case'7':yi=7;
			break;
		case'8':yi=8;
			break;
		case'0':yi=0;
			break;
		default:cout<<"wrong selection";
	}
	if(!(isupper(select[0])) || !(isdigit(select[1])))
	{
		if(xi==0 || yi==0)
		{
			exit(0);
		}
		goto enteragain;
	}
};


//player_peice_move() generates the coordinate(xf,yf).
void player_peice_move()
{
	int xa=54,ya=360;
	char move[3];
	enteragain:
	outtextxy(ya,xa,"enter the move:");
	gotoxy(61,4);
	cin>>move;
	switch(move[0])
	{
		case'A':xf=1;
			break;
		case'B':xf=2;
			break;
		case'C':xf=3;
			break;
		case'D':xf=4;
			break;
		case'E':xf=5;
			break;
		case'F':xf=6;
			break;
		case'G':xf=7;
			break;
		case'H':xf=8;
			break;
		case'0':xf=0;
			break;
		default:cout<<"wrong move";
	}
	switch(move[1])
	{
		case'1':yf=1;
			break;
		case'2':yf=2;
			break;
		case'3':yf=3;
			break;
		case'4':yf=4;
			break;
		case'5':yf=5;
			break;
		case'6':yf=6;
			break;
		case'7':yf=7;
			break;
		case'8':yf=8;
			break;
		case'0':yf=0;
			break;
		default:cout<<"wrong move";
	}
	if(!(isupper(move[0])) || !(isdigit(move[1])))
	{
		if(xf==0 || yf==0)
		{
			exit(0);
		}
		goto enteragain;
	}
}
;


//rook() checks the legal moves of the peice rook

void rook()
{
	int llim,ulim,i,empty=0,con=0;
	if(board[xi][yi]=='r'||board[xi][yi]=='R')
	{
		if(xi==xf)
		{
			empty=0;
			if(yi>yf)
			{
				llim=yf;
				ulim=yi-1;
			}
			else
			{
				llim=yi;
				ulim=yf+1;
			}
			for(i=llim;i<ulim;i++)
			{
				if(board[xi][i]==' ')
				{
					empty++;

				}
			}
			if(yi>yf)
			{
				 ulim=yi;
			}
			con=ulim-llim-1;
			if(isupper(board[xf][yf]) && board[xi][yi]=='r')
			{
				empty++;
			}
			else if(islower(board[xf][yf]) && board[xi][yi]=='R')
			{
				empty++;
			}
			if(empty==con)
			{
				if(board[xi][yi]=='r')
				{
					board[xf][yf]='r';
					board[xi][yi]=' ';
				}
				else
				{
					board[xf][yf]='R';
					board[xi][yi]=' ';
				}
			}
		}
		if(yi==yf)
		{
			empty=0;
			if(xi>xf)
			{
				llim=xf;
				ulim=xi-1;
			}
			else
			{
				llim=xi;
				ulim=xf+1;
			}
			for(i=llim;i<ulim;i++)
			{
				if(board[i][yi]==' ')
				{
					empty++;

				}
			}
			if(xi>xf)
			{
				 ulim=xi;
			}
			if(isupper(board[xf][yf]) && board[xi][yi]=='r')
			{
				empty++;
			}
			else if(islower(board[xf][yf]) && board[xi][yi]=='R')
			{
				empty++;
			}
			con=ulim-llim-1;
			if(empty==con)
			{
				if(board[xi][yi]=='r')
				{
					board[xf][yf]='r';
					board[xi][yi]=' ';
				}
				else
				{
					board[xf][yf]='R';
					board[xi][yi]=' ';
				}
			}
		}
	}
}

//knight() checks the legal moves of the peice kinght

void knight()
{
	if(board[xi][yi]=='n' || board[xi][yi]=='N')
	{
		if((xf==xi+2 && (yf==yi+1 || yf==yi-1))||
		   (xf==xi-2 && (yf==yi+1 || yf==yi-1))||
		   (yf==yi+2 && (xf==xi+1 || xf==xi-1))||
		   (yf==yi-2 && (xf==xi+1 || xf==xi-1)))
		{
			if(isupper(board[xi][yi]))
			{
				if(islower(board[xf][yf]) || board[xf][yf]==' ')
				{
					board[xf][yf]='N';
				}
			}
			else if(islower(board[xi][yi]))
			{
				if(isupper(board[xf][yf]) || board[xf][yf]==' ')
				{
					board[xf][yf]='n';
				}
			}
			board[xi][yi]=' ';
		}
	}
}

//bishop() checks the legal moves of the peice bishop

void bishop()
{
	int empty,llimi,ulimi,llimj,ulimj,i,j,con;
	if(board[xi][yi]=='b' || board[xi][yi]=='B')
	{
		empty=0;
		if(xi>xf)
		{
			llimi=xf;
			ulimi=xi;
		}
		else
		{
			llimi=xi;
			ulimi=xf;
		}
		if(yi>yf)
		{
			llimj=yf;
			ulimj=yi;
		}
		else
		{
			llimj=yi;
			ulimj=yf;
		}
		if(xf>xi && yf>yi)
		{
			ulimi=xf+1;
			ulimj=yf+1;
		}
		for(i=llimi,j=llimj;i<ulimi;j++,i++)
		{
			if(board[i][j]==' ')
			{
				empty++;
			}
		}
		if(xi>xf && yf>yi)
		{
			empty++;
		}
		if(isupper(board[xf][yf]) && board[xi][yi]=='b')
		{
			empty++;
		}
		else if(islower(board[xf][yf]) && board[xi][yi]=='B')
		{
			empty++;
		}
		if(xi>xf)
		{
			con=xi-xf;
		}
		else
		{
			con=xf-xi;
		}
		if(yi<yf && xi>xf)
		{
			con++;
		}
		if(empty==con && empty!=0 && con!=0)
		{
			if(board[xi][yi]=='b')
			{
				board[xf][yf]='b';
			}
			else
			{
				board[xf][yf]='B';
			}
			board[xi][yi]=' ';
		}
	}
}

//queen() checks the legal moves of the peice queen

void queen(int xi,int xf,int yi,int yf)
{
	int empty,llim,ulim,llimi,ulimi,llimj,ulimj,i,j,con;
	if(xi==xf || yi==yf)
	{
		if(xi==xf)
		{
			empty=0;
			if(yi>yf)
			{
				llim=yf;
				ulim=yi-1;
			}
			else
			{
				llim=yi;
				ulim=yf+1;
			}
			for(i=llim;i<ulim;i++)
			{
				if(board[xi][i]==' ')
				{
					empty++;
				}
			}
			if(yi>yf)
			{
				ulim=yi;
			}
			if(isupper(board[xf][yf]) && board[xi][yi]=='q')
			{
				empty++;
			}
			else if(islower(board[xf][yf]) && board[xi][yi]=='Q')
			{
				empty++;
			}
			con=ulim-llim-1;
			if(empty==con)
			{
				if(board[xi][yi]=='q')
				{
					board[xf][yf]='q';
				}
				else
				{
					board[xf][yf]='Q';
				}
				board[xi][yi]=' ';
			}
		}
		if(yi==yf)
		{
			empty=0;
			if(xi>xf)
			{
				llim=xf;
				ulim=xi-1;
			}
			else
			{
				llim=xi;
				ulim=xf+1;
			}
			for(i=llim;i<ulim;i++)
			{
				if(board[i][yi]==' ')
				{
					empty++;

				}
			}
			if(xi>xf)
			{
				ulim=xi;
			}
			if(isupper(board[xf][yf]) && board[xi][yi]=='q')
			{
				empty++;
			}
			else if(islower(board[xf][yf]) && board[xi][yi]=='Q')
			{
				empty++;
			}
			con=ulim-llim-1;
			if(empty==con)
			{
				if(board[xi][yi]=='q')
				{
					board[xf][yf]='q';
				}
				else
				{
					board[xf][yf]='Q';
				}
				board[xi][yi]=' ';
			}
		}
	}
	else
	{
		empty=0;
		if(xi>xf)
		{
			llimi=xf;
			ulimi=xi;
		}
		else
		{
			llimi=xi;
			ulimi=xf;
		}
		if(yi>yf)
		{
			llimj=yf;
			ulimj=yi;
		}
		else
		{
			llimj=yi;
			ulimj=yf;
		}
		if(xf>xi && yf>yi)
		{
			ulimi=xf+1;
			ulimj=yf+1;
		}
		for(i=llimi,j=llimj;i<ulimi;j++,i++)
		{
			if(board[i][j]==' ')
			{
				empty++;
			}
		}
		if(xi>xf && yf>yi)
		{
			empty++;
		}
		if(isupper(board[xf][yf]) && board[xi][yi]=='q')
		{
			empty++;
		}
		else if(islower(board[xf][yf]) && board[xi][yi]=='Q')
		{
			empty++;
		}
		if(xi>xf)
		{
			con=xi-xf;
		}
		else
		{
			con=xf-xi;
		}
		if(yi<yf && xi>xf)
		{
			con++;
		}
		if(empty==con && empty!=0 && con!=0)
		{
			if(board[xi][yi]=='q')
			{
				board[xf][yf]='q';

			}
			else
			{
				board[xf][yf]='Q';
			}
			board[xi][yi]=' ';
		}
	}
}

//kin() checks the legal moves of the peice king

void king()
{
	if(board[xi][yi]=='k' || board[xi][yi]=='K')
	{
		if((xi==xf+1 || xi==xf || xi==xf-1) && (yi==yf+1 || yi==yf || yi==yf-1))
		{
			if(board[xi][yi]=='k' && (isupper(board[xf][yf]) || board[xf][yf]==' '))
			{
				board[xf][yf]=board[xi][yi];
				board[xi][yi]=' ';
			}
			else if(board[xi][yi]=='K' && (islower(board[xf][yf]) || board[xf][yf]==' '))
			{
				board[xf][yf]=board[xi][yi];
				board[xi][yi]=' ';
			}
		}
	}
}

//pawn() checks the legal moves of the peice pawn

void pawn()
{
	if(board[xi][yi]=='p' || board[xi][yi]=='P')
	{
		if((xi==xf+1 || xi==xf || xi==xf-1) && (yi==yf+1 || yi==yf || yi==yf-1))
		{
			if(xi==xf+1 && board[xf][yf]==' ' && yi==yf && islower(board[xi][yi]))
			{
					board[xf][yf]=board[xi][yi];
					board[xi][yi]=' ';
			}
			else if(xi==xf-1 && board[xf][yf]==' ' && yi==yf && isupper(board[xi][yi]))
			{
				board[xf][yf]=board[xi][yi];
				board[xi][yi]=' ';
			}
			else if(yi!=yf && xi==xf+1 && isupper(board[xf][yf]) && islower(board[xi][yi]))
			{
				board[xf][yf]=board[xi][yi];
				board[xi][yi]=' ';
			}
			else if(yi!=yf && xi==xf-1 && islower(board[xf][yf]) && isupper(board[xi][yi]))
			{
				board[xf][yf]=board[xi][yi];
				board[xi][yi]=' ';
			}
		}

	}
};

/*player_move_selection generates the value of
  peice i.e. it identifies the peice
*/

void player_move_selection()
{
	if(board[xi][yi]=='R' || board[xi][yi]=='r' )
	{
		rook();
	}
	else if(board[xi][yi]=='N' || board[xi][yi]=='n')
	{
		knight();
	}
	else if(board[xi][yi]=='B' || board[xi][yi]=='b')
	{
		bishop();
	}
	else if(board[xi][yi]=='K' || board[xi][yi]=='k')
	{
		king();
	}
	else if(board[xi][yi]=='Q' || board[xi][yi]=='q')
	{
		queen(xi,xf,yi,yf);
	}
	else if(board[xi][yi]=='P' || board[xi][yi]=='p')
	{
		pawn();
	}
};

void main()
{
	clrscr();
	char lastboard[9][10];
	int choice,king=2;
	mainmenu:
	clrscr();
	cout<<"\t\t\t\t   CHESS BOARD"
	    <<"\n\n"
	    <<"\t\t\tMade By :->Ritik Kumar Srivastava"
	    <<"\n\n"
	    <<"\t\t\t  Guided By :->Mr. Vivek Saxena";
	cout<<"\n\n\n\n\n\n";
	cout<<"\t\t\t\t1.START GAME(PRESS 1)\n"
	    <<"\t\t\t\t2.INSTRUCTIONS(PRESS 2)\n"
	    <<"\t\t\t\t3.HISTORY(PRESS 3)\n"
	    <<"\t\t\t\t4.EXIT(PRESS 4)\n";
	cin>>choice;
	if(choice==1)
	{
		obj.playername();
		int a,b;
		while(king==2)
		{
			displayboard();
			for(int i=0;i<10;i++)
			{
				for(int j=0;j<10;j++)
				{
					lastboard[i][j]=board[i][j];
				}
			}
			king=0;
			player_peice_selection();
			if((isupper(board[xi][yi]) && chance%2==0)||(islower(board[xi][yi]) && chance%2==1))
			{
				player_peice_move();
				player_move_selection();
			}
			int compare=0;
			for(i=0;i<10;i++)
			{
				if(strcmpi(board[i],lastboard[i])==0)
				{
					compare++;
				}
			}
			if(compare!=9)
			{
				::chance++;
			}
			displayboard();
			for(i=0;i<9;i++)
			{
				for(int j=0;j<9;j++)
				{
					if(board[i][j]=='k' ||board[i][j]=='K')
					{
						king++;
						a=i;b=j;
					}
				}
			}
			if(king==1)
			{
				break;
			}
		}
		settextstyle(7,0,4);
		if(isupper(board[a][b]))
		{
			setcolor(4);
			outtextxy(365,90,"PLAYER 1 WINS");
			obj.out1();
		}
		else if(islower(board[a][b]))
		{
			setcolor(9);
			outtextxy(365,90,"PLAYER 2 WINS");
			obj.out2();
		}
		obj.score();
		save();
	}
	else if(choice==2)
	{
		clrscr();
		cout<<"1.Firstly enter the coordinates of the peice to be moved.\n"
		    <<"2.Then enter the coordinates of the position where the peice is to be moved.\n"
		    <<"3.If the entered move is legal move of the peice then the peice will be shifted   to that coordinate.\n"
		    <<"4.If you beat an opponents peice then your score is increased.\n"
		    <<"5.If you beat the opponents king then you win.";
		cout<<"\n\n\n\n\t\t\tPress 1 to return to main menu.";
		int cho;
		cin>>cho;
		if(cho==1)
		{
			goto mainmenu;
		}
	}
	else if(choice==3)
	{
		read();
	}
	else
	{
		clrscr();
		cout<<"the program is exiting\n\n\n";
		for(int i=1;i<20;i++)
		{
			delay(100);
			cout<<"....";
		}
		delay(500);
		exit(0);
	}
	getch();
}