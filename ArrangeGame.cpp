#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
int a[4][4]={1,4,15,7,8,10,2,11,14,3,6,13,12,9,5,' '};
void gotoxy(int x,int y)
{
	HANDLE hStdout=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position={x,y};
	SetConsoleCursorPosition(hStdout,position);
}
void drawbox()
{
	int i,j;
	system("cls");
	//Horizontal lines.
	for(i=0;i<5;i++)
	{
		gotoxy(5,5+(i*3));
		for(j=1;j<=12;j++)
		printf("%c",196);
	}
	//Vertical lines.
	for(i=0;i<5;i++)
	{
		gotoxy(5+(i*3),5);
		for(j=1;j<=13;j++)
		{
			printf("%c",179);
			gotoxy(5+(i*3),5+j);
		}
	}
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			gotoxy(6+(j*3),6+(i*3));
			if(a[i][j]!=32)
			printf("%d",a[i][j]);
			else
			printf("%c",a[i][j]);
		}
	}
}
int getkey()
{
	int ch1,ch2;
	ch1=getch();
	ch2=getch();
	return ch2;
	return ch1;
}
int check()
{
	int i,j,crr=0;
	int arr[4][4]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,32};
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			if(a[i][j]!=arr[i][j])
			{
				crr++;
			}
		}
	}
	return crr;
}
int main()
{
	int row=3;
	int col=3;
	int turns=0;
	drawbox();
	int i,j,t,chck;
	do
	{
		int key=getkey();
		gotoxy(1,20);
		if(key!=72&&key!=75&&key!=77&&key!=80)
			continue;
		
		turns++;
		switch(key)
		{
			case 72:if(0<=(row-1) && (row-1)<=3)
					{
						t=a[row-1][col];
						a[row-1][col]=a[row][col];
						a[row][col]=t;
						row--;
						drawbox();
					}
					break;
					
			case 75:if(0<=(col-1) && (col-1)<=3)
					{
						t=a[row][col-1];
						a[row][col-1]=a[row][col];
						a[row][col]=t;
						col--;
						drawbox();
					}
					break;
					
			case 77:if(0<=(col+1) && (col+1)<=3)
					{
						t=a[row][col+1];
						a[row][col+1]=a[row][col];
						a[row][col]=t;
						col++;
						drawbox();
					}
					break;
					
			case 80:if(0<=(row+1) && (row+1)<=3)
					{
						t=a[row+1][col];
						a[row+1][col]=a[row][col];
						a[row][col]=t;
						row++;
						drawbox();
					}
					break;
		}
		chck=check();
		gotoxy(1,20);
		//printf("%d",chck);
	}while(chck);
	
	gotoxy(1,20);
	printf("Turns taken by you is : %d",turns);
}
