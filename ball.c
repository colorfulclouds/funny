#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

int high;
int width;
int ball_x;
int ball_y;
int ball_vx;
int ball_vy;

int times;

//board
int position_x;
int position_y;
int radius;
int left;
int right;


int x_1,y_1;

int x_2,y_2;
int **target;


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
	int i;
	int j;

	high = 15;
	width = 20;
	ball_x = high - 4;
	ball_y = width / 2;
	ball_vx = 1;
	ball_vy = 1;

	radius = 5;
	position_x = high ;
	position_y = width / 2;
	left = position_y - radius;
	right = position_x + radius;

	times = 0;

	//
	x_1 = 0;
	y_1 = 0;

	x_2 = high / 2;
	y_2 = width ;

	target = (int **)malloc(sizeof(int *) * (x_2 - x_1) );
	for(i=0;i<x_2-x_1;i++)
	{
		target[i] = (int *)malloc(sizeof(int) * (y_2 - y_1));
	}
	for(i=0;i<x_2 - x_1;i++)
	{
		for(j=0;j<y_2 - y_1;j++)
		{
			target[i][j] = 1;
		}
	}

}

void show()
{
	int i;
	int j;
	gotoxy(0 , 0);

	for(i=0;i<=high + 1;i++)
	{
		for(j=0;j<=width;j++)
		{
			if((i == ball_x) && (j == ball_y))
			{
				printf("0");
			}
			else if(j == width)
			{
				printf("|");
			}
			else if(i == high + 1)
			{
				printf("-");
			}
			else if( (i == high) &&  (j>=left)  && (j <= right) )
			{
				printf("*");
			}
			else if( (i>=x_1) && (i<x_2) && (j>=y_1) && (j<y_2) )
			{
				if(target[i-x_1][j-y_1])
					printf("B");
				else
					printf(" ");
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}
}

void updateWithoutInput()
{
	int i;

	if(ball_x == high - 1)
	{
		if((ball_y >= left) && (ball_y <= right))
		{
			printf("\a");
		}
		else
		{
			printf("game over\n");
			printf("game over\n");
			exit(EXIT_FAILURE);
			getchar();
			//nothing
		}
	}

	ball_x += ball_vx;
	ball_y += ball_vy;

	if((ball_x == 0) || (ball_x == high - 1))
	{
		ball_vx *= -1;
	}
	if((ball_y == 0) || (ball_y == width - 1))
	{
		ball_vy *= -1;
	}
	if((ball_x >= x_1) && (ball_x < x_2) &&(ball_y >= y_1)&&(ball_y < y_2) )
	{
		if(target[ball_x - x_1][ball_y - y_1])
		{
			target[ball_x - x_1][ball_y - y_1] = 0;

			if((ball_x == 0) || (ball_x == high - 1))
				;
			else
				ball_vx *= -1;

			if((ball_y == 0) || (ball_y == width - 1))
				;
			else
				ball_vy *= -1;
		
		
			times ++;
		}
		
		
	}
	
	printf("score:%d", times);
	Sleep(50);
}

void updateWithInput()
{
	char input;

	if(kbhit())
	{
		input = getch();
		switch(input)
		{
		case 'a':
			position_y --;
			left = position_y - radius;
			right = position_y + radius;
			if(left < 0)
			{
				left = 0;
				right = left + 2 * radius;
				position_y = left + radius;
			}
			break;

		case 'd':
			position_y ++;
			left = position_y - radius;
			right = position_y + radius;
			if(right > width)
			{
				left = width - 2 * radius;
				right = width;
				position_y = width - radius;
			}
			break;

		//speed up and speed down
		case '1':
			ball_vx *= 2;
			break;

		case '2':
			if(ball_vx >= 2)
				ball_vx /= 2;
			break;
			
		case '3':
			ball_vy *= 2;
			break;
			
		case '4':
			if(ball_vy >= 2)
				ball_vy /= 2;
			break;


		}
	}
}

int main(void)
{
	startup();
	while(1)
	{
		show();
		updateWithoutInput();
		updateWithInput();
	}

	return 0;
}