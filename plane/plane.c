#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <time.h>

void newline(int n)
{
	int i;
	
	for(i=0;i<n;i++)
	{
		printf("\n");
	}
}

void space(int n)
{
	int i;
	
	for(i=0;i<n;i++)
	{
		printf(" ");
	}
}

void draw_target(int x , int y)
{
	newline(x);
	space(y);
	printf("+\n");
}

void draw_score(int x , int y , int score)
{
	newline(x);
	space(y);
	printf("score:%d\n", score);
}

void draw_plane(int x , int y , int *is_fire , int *is_target , int target_x , int target_y )
{
	static int score = 0;
	int i;
	int flag = 1;//fade laser
	
	
	draw_score(0 , 21 , score);
	if((*is_target) == 1)
	{
		draw_target(target_x , target_y);
	}
	if( (*is_fire) == 1)
	{
		if((*is_target) == 1)
		{
			if(y == target_y)
			{
				//ok
				score ++;
				(*is_target) = 0;
				system("cls"); //flush target
				flag = 0;
			}
		}
		
		for(i=0;i<x;i++)
		{
			space(y);
			//	if(flag == 1)
			printf("|\n");
			//	else
			//		printf("\n");	//no draw laser
		}
		
		(*is_fire) = 0;
		space(y);
	}
	else
	{
		newline(x);
		space(y);
	}
	printf("*\n");
	space(y-2);
	printf("*****\n");
	space(y-1);
	printf("* *");
}


int main(void)
{
	char c;
	int x;
	int y;
	int is_fire=0;
	
	int is_target = 1;
	int target_x = 0;
	int target_y = 10;
	srand((unsigned int)time(NULL));
	x = 0;
	y = 2;
	
	while(1)
	{
		if(kbhit())
		{
			
			c = getch();
			
			switch(c)
			{
			case 'w':
				x --;
				if(x < 0)
					x = 0;
				break;
				
			case 'a':
				y --;
				if(y < 2)
					y = 2;
				break;
				
			case 's':
				x ++;
				break;
				
			case 'd':
				y ++;
				break;
				
			case ' ':
				printf("\a");
				is_fire = 1;
				break;
				
			default:
				;
				break;
			}
			system("cls");
			
			if(is_target == 0)
			{
				
				target_x = 0;
				target_y = rand() % 20 + 3;
				is_target = 1;
			}
			draw_plane(x , y , &is_fire , &is_target , target_x , target_y);
			
		}
		
	}
	
	return 0;
}