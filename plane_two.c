#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

int position_x;
int position_y;
int bullet_x;
int bullet_y;
int high;
int width;

int enemy_x;
int enemy_y;
int speed;
int score;
int stop_flag;

void startup()
{
	high = 20;
	width = 30;
	position_x = high / 2;
	position_y = width / 2;

	bullet_x = -2;
	bullet_y = position_y;

	enemy_x = 0;
	enemy_y = position_y;

	speed = 50;

	score = 0;
	stop_flag = 1;
}

void gotoxy(int x, int y)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
    SetConsoleCursorPosition(handle , pos);
}

void HideCursor()
{
	CONSOLE_CURSOR_INFO cursor_info = {1 , 0};
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE) , &cursor_info);
}

void show()
{
	int i;
	int j;
//	system("cls");
	
	gotoxy(0 , 0);
	
	for(i=0;i<high;i++)
	{
		for(j=0;j<width;j++)
		{
			if((i == position_x) && (j == position_y))
				printf("*");
			else if((i == enemy_x) && (j == enemy_y))
				printf("@");
			else if((i == bullet_x) && (j == bullet_y))
			{
				printf("|");
			}
			else
				printf(" ");
		}
		printf("\n");
	}

	printf("score:%d\n", score);
	
}

void updateWithoutInput()
{	
	srand((unsigned int)time(NULL));

		
	if(bullet_x > -1)
		bullet_x --;
	
	if((bullet_x == enemy_x) && (bullet_y == enemy_y))
	{
		score ++;
		enemy_x = -1;
		enemy_y = rand() % width;
		bullet_x = -2;
	}
	if(enemy_x > high)
	{
		enemy_x = -1;
		enemy_y = rand() % width;
	}
	
	speed = speed - score - 1;
	
	if(speed <= 0)
	{
		enemy_x ++;
		
		speed = 50 ;
	}
}

void updateWithInput()
{
	char input;

	if(kbhit())
	{
		input = getch();
		switch(input)
		{
			case 'w':
				if(stop_flag)
				{
					position_x --;
					if(position_x < 0)
						position_x = 0;
				}
				break;

			case 'a':
				if(stop_flag)
				{
					position_y --;
					if(position_y < 0)
						position_y = 0;
				}
				break;

			case 's':
				if(stop_flag)
				{
					position_x ++;
					if(position_x > high)
						position_x = high - 1;
				}
				break;
				
			case 'd':
				if(stop_flag)
				{
					position_y ++;
					if(position_y > width)
						position_y = width - 1;
				}
				break;
				
			case ' ':
				if(stop_flag)
				{
					bullet_x = position_x - 1;
					bullet_y = position_y;
				}
				break;

			case 'q':
				if(stop_flag == 1)
					stop_flag = 0;
				else if(stop_flag == 0)
					stop_flag = 1;

				break;
		}
	}
}

int main(void)
{
	HideCursor();
	startup();

	while(1)
	{
		if(stop_flag == 1)
		{
			show();
			updateWithoutInput();
		}

		updateWithInput();

	}

	return 0;
}