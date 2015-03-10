#include<conio.h>
#include<graphics.h>
#include<stdio.h>
int tx[10]={0,150,300,450,150,300,450,150,300,450};
int ty[10]={0,100,100,100,250,250,250,400,400,400};
int p1p[4]={0,0,0,0};//p1position
int p2p[4]={0,0,0,0};//p2position
char ind[1];
int f[10]={-1,0,0,0,0,0,0,0,0,0};//filled r not
int cp1p2[10]={-1,0,0,0,0,0,0,0,0,0};//filled with p1 or p2
int pv,nv;//pv-key nv-position
int go=0;//game over.
int p1x[4]={0,100,80,60},p1y[4]={0,380,380,380},p2x[4]={0,100,80,60},p2y[4]={0,400,400,400};
int wp1p2=0;//win or not.
void draw();
class pulmek
{
	public:
		void move();
		pulmek(int ppx[4],int ppy[4],int pp1p2,int pp[4]);
		int px[4],py[4];
		int p1p2p[4];//position
		void p1p2pos();  //representing position
		int p1p2;
		int win();
};
pulmek p1(p1x,p1y,1,p1p),p2(p2x,p2y,2,p2p);
pulmek::pulmek(int ppx[4],int ppy[4],int pp1p2,int pp[4])
{	for(int i=0;i<4;i++)
	{	px[i]=ppx[i];
		py[i]=ppy[i];
		p1p2p[i]=pp[i];
	}
	p1p2=pp1p2;
}
void pulmek::p1p2pos()
{	if(p1p2==1)
	{	setcolor(14);
		setfillstyle(SOLID_FILL,2);
	}
	else if(p1p2==2)
	{       setcolor(2);
		setfillstyle(SOLID_FILL,14);
	}
	for(int i=1;i<4;i++)
	{	fillellipse(px[i]+5,py[i],10,10);
		sprintf(ind,"%d",i);
		outtextxy(px[i],py[i],ind);
	}
	setcolor(1);
}
void pulmek::move()
{       gotoxy(1,1);
	printf("\nEnter key [1/2/3] : ");
	while(1)
	{       pv=getche()-48;
		printf("%d",pv);
		if(pv<1||pv>3)
			printf("\nEnter right key [1/2/3] : ");
		else if((p1p2p[pv]==1&&f[2]==1&&f[4]==1&&f[5]==1)||(p1p2p[pv]==2&&f[1]==1&&f[3]==1&&f[5]==1)||(p1p2p[pv]==3&&f[2]==1&&f[5]==1&&f[6]==1)||(p1p2p[pv]==4&&f[1]==1&&f[5]==1&&f[7]==1)||(p1p2p[pv]==5&&f[1]==1&&f[2]==1&&f[3]==1&&f[4]==1&&f[5]==1&&f[6]==1&&f[7]==1&&f[8]==1&&f[9]==1)||(p1p2p[pv]==6&&f[3]==1&&f[5]==1&&f[9]==1)||(p1p2p[pv]==7&&f[4]==1&&f[5]==1&&f[8]==1)||(p1p2p[pv]==8&&f[5]==1&&f[7]==1&&f[9]==1)||(p1p2p[pv]==9&&f[5]==1&&f[6]==1&&f[8]==1))
			printf("\nKey got blocked.");
		else
			break;
	}
	f[p1p2p[pv]]=0;
	cp1p2[p1p2p[pv]]=0;
	printf("\nEnter its new position:");
	while(1)
	{       nv=getche()-48;
		printf("%d",nv);
		if((f[nv]==1||nv<1||nv>9)||(px[pv]==tx[nv]&&py[pv]==ty[nv]))
			printf("\nEnter right position:");
		else if((p1p2p[pv]==1&&!(nv==2||nv==4||nv==5))||(p1p2p[pv]==2&&!(nv==1||nv==3||nv==5))||(p1p2p[pv]==3&&!(nv==2||nv==5||nv==6))||(p1p2p[pv]==4&&!(nv==1||nv==5||nv==7))||(p1p2p[pv]==5&&!(nv==1||nv==2||nv==3||nv==4||nv==5||nv==6||nv==7||nv==8||nv==9))||(p1p2p[pv]==6&&!(nv==3||nv==5||nv==9))||(p1p2p[pv]==7&&!(nv==4||nv==5||nv==8))||(p1p2p[pv]==8&&!(nv==5||nv==7||nv==9))||(p1p2p[pv]==9&&!(nv==5||nv==6||nv==8)))
			printf("\nCan not move to %d position",nv);
		else
		{	f[nv]=1;
			cp1p2[nv]=p1p2;
			p1p2p[pv]=nv;
			break;
		}
	}
	px[pv]=tx[nv];
	py[pv]=ty[nv];
	cleardevice();
	draw();
}
int pulmek::win()
{       int wp=0;
	if((f[1]==1&&f[2]==1&&f[3]==1&&cp1p2[1]==p1p2&&cp1p2[2]==p1p2&&cp1p2[3]==p1p2)||(f[4]==1&&f[5]==1&&f[6]==1&&cp1p2[4]==p1p2&&cp1p2[5]==p1p2&&cp1p2[6]==p1p2)||(f[7]==1&&f[8]==1&&f[9]==1&&cp1p2[7]==p1p2&&cp1p2[8]==p1p2&&cp1p2[9]==p1p2)||(f[1]==1&&f[4]==1&&f[7]==1&&cp1p2[1]==p1p2&&cp1p2[4]==p1p2&&cp1p2[7]==p1p2)||(f[2]==1&&f[5]==1&&f[8]==1&&cp1p2[2]==p1p2&&cp1p2[5]==p1p2&&cp1p2[8]==p1p2)||(f[3]==1&&f[6]==1&&f[9]==1&&cp1p2[3]==p1p2&&cp1p2[6]==p1p2&&cp1p2[9]==p1p2)||(f[1]==1&&f[5]==1&&f[9]==1&&cp1p2[1]==p1p2&&cp1p2[5]==p1p2&&cp1p2[9]==p1p2)||(f[3]==1&&f[5]==1&&f[7]==1&&cp1p2[3]==p1p2&&cp1p2[5]==p1p2&&cp1p2[7]==p1p2))
		wp=1;
	return wp;
}
void draw()
{       setfillstyle(SOLID_FILL,0);
	setcolor(1);
	int board[]={150,100,450,100,450,400,150,400};
	fillpoly(4,board);
	rectangle(150,100,450,400);
	line(300,100,300,400);
	line(150,250,450,250);
	line(150,100,450,400);
	line(150,400,450,100);
	outtextxy(150,90,"1");
	outtextxy(300,90,"2");
	outtextxy(450,90,"3");
	outtextxy(140,250,"4");
	outtextxy(305,255,"5");
	outtextxy(455,250,"6");
	outtextxy(150,405,"7");
	outtextxy(300,405,"8");
	outtextxy(450,405,"9");
	setcolor(2);
	outtextxy(0,380,"PLAYER1:");
	setcolor(14);
	outtextxy(0,400,"PLAYER2:");
	setcolor(1);
	p1.p1p2pos();
	p2.p1p2pos();
}
void main()
{       clrscr();
	int gd=DETECT;
	initgraph(&gd,0,"");
	setbkcolor(9);
	setcolor(1);
	draw();
	while(1)
	{       if(go==20)
			break;
		p1.move();
		if(p1.win())
		{       wp1p2=1;
			break;
		}
		p2.move();
		if(p2.win())
		{       wp1p2=2;
			break;
		}
		go++;
	}
	if(wp1p2==1)
		printf("PLAYER 1 WON THE GAME.");
	else if(wp1p2==2)
		printf("PLAYER 2 WON THE GAME.");
	if(go==20)
		printf("Chances over.");
	getch();
}
