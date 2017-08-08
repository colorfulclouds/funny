#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <conio.h>

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

void draw_plane(int x , int y , int *is_fire)
{
	int i;

	if( (*is_fire) == 1)
	{
		for(i=0;i<x;i++)
		{
			space(y);
			printf("|\n");
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

void draw_fire(int x , int y)
{
	int i;
	
	for(i=0;i<y;i++)
	{
		space(y);
		printf("|\n");
	}

//	draw_plane(x , y);
}

int main(void)
{
	char c;
	int x;
	int y;
	int is_fire=0;
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
			
			
			draw_plane(x , y , &is_fire);

		}
		
	}


	return 0;
}