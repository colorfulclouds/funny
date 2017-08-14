#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <conio.h>

#define HIGH 25
#define WIDTH 50

int cells[HIGH][WIDTH];

void startup()
{
	int i;
	int j;

	for(i=0;i<HIGH;i++)
		for(j=0 ; j<WIDTH ; j ++)
		{
			cells[i][j] = rand() % 2;
		}
}

void gotoxy(int x , int y)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(handle , pos);
}

void show()
{
	int i;
	int j;

	gotoxy(0 , 0);

	for(i=0;i<HIGH;i++)
	{
		for(j=0 ; j<WIDTH ; j ++)
		{
			if(cells[i][j])
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}

	Sleep(50);
}

void update_with_input()
{
	
}
void update_without_input()
{
	int new_cells[HIGH][WIDTH];
	int count;
	int i;
	int j;

	for(i=1;i<HIGH-1;i++)
	{
		for(j=1 ; j<WIDTH-1 ; j ++)
		{
			count = cells[i-1][j-1] + cells[i-1][j] + cells[i-1][j+1] + cells[i][j-1] + cells[i][j+1] + cells[i+1][j-1] + cells[i+1][j] + cells[i+1][j+1] ; 
			switch(count)
			{
			case 3:
				new_cells[i][j] = 1;
				break;
				
			case 2:
				new_cells[i][j] = cells[i][j];
				break;

			default:
				new_cells[i][j] = 0;
				break;
			}
		}
	}

	for(i=1;i<HIGH-1;i++)
		for(j=1 ; j<WIDTH-1 ; j ++)
			cells[i][j] = new_cells[i][j];
	
}

int main(void)
{
	startup();

	while(1)
	{
		show();
		update_with_input();
		update_without_input();
	}

	return 0;
}