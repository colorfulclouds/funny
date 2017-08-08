#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>


void space(int n)
{
	int i;

	for(i=0;i<n;i++)
	{
		printf(" ");
	}
}

void newline(int n)
{
	int i;

	for(i=0;i<n;i++)
	{
		printf("\n");
	}
}

void wall(int x , int y , int length , int width);

void draw(int x , int y)
{
	wall(1,0,21,11);
	system("cls");
	newline(x);
	space(y);
	printf("o\n");
}

void wall(int x , int y , int length , int width)
{
	int i;

	newline(x);
	space(y);

	for(i=0;i<length;i++)
	{
		printf("=");
	}
	printf("\n");

	for(i=0;i<width - 2;i++)
	{
		printf("|");
		space(length - 2);
		printf("|\n");
	}


	for(i=0;i<length;i++)
	{
		printf("=");
	}
}

int main(void)
{
	int x=1;
	int y=5;

	int v_x=1;
	int v_y=1;

	int left=1;
	int right=20;
	int top=1;
	int bottom=10;

	while(1)
	{
		x=x+v_x;
		y=y+v_y;

		system("cls");
		draw(x,y);
		
		if((x==top) ||(x==bottom))
		{
			v_x *= -1;
			printf("\a");
		}

		if((y==left) || (y==right))
		{
			v_y *= -1;
			printf("\a");
		}
		Sleep(50);
		
	}

	return 0;
}