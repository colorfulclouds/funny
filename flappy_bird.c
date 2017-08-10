#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>

int bird_x;
int bird_y;

int high;
int width;

int handicap_top;
int handicap_down;
int handicap_y;


void gotoxy(int x , int y)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(handle , pos);
}

void startup()
{
	high = 20;
	width = 30;

	bird_x = high / 2;
	bird_y = width / 2;

	handicap_top = high / 3;
	handicap_down = high / 3 * 2;
	handicap_y = width / 3 * 2;
}

void show()
{
	int i;
	int j;
	gotoxy(0 , 0);

	for(i=0;i<high;i++)
	{
		for(j=0;j<width;j++)
		{
			if((i == bird_x) && (j == bird_y) )
			{
				printf("@");
			}
			else if( (j == handicap_y) && ( (i<=handicap_top) ||(i >= handicap_down) ) )
				printf("*");
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}
	Sleep(50);
}

void update_with_input()
{
	char input;

	if(kbhit())
	{
		input = getch();

		switch(input)
		{
		case ' ':
			if(bird_x > 0)
				bird_x --;	//up to sky
			break ;

		default:
			;	//nothing
			break ;
		}
	}
}

void update_without_input()
{
	static int speed_bird = 10;

	static int speed_handicap = 10;

	speed_bird --;

	if(speed_bird == 0)
	{
		bird_x ++;	//down to ground
		speed_bird = 10;

		//replace prime
		if(bird_x > high)
			bird_x = high / 2;
	}

	speed_handicap --;
	if(speed_handicap == 0)
	{
		handicap_y --;
		speed_handicap = 10;

		if(handicap_y < 0)
			handicap_y = width / 3 * 2;
	}
}

void hide_cursor()
{
	CONSOLE_CURSOR_INFO cursor_info = {1 , 0};
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE) , &cursor_info);
}

int main(void)
{
	hide_cursor();
	
	startup();

	while(1)
	{
		show();
		update_without_input();
		update_with_input();
	}

	return 0;
}