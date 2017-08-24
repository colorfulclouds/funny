#include <graphics.h>
#include <conio.h>

int main(void)
{
	int ball_x = 50;
	int ball_y = 50;
	int r = 5;
	int pos_x = ball_x;
	int pos_y = ball_y;

	initgraph(640,480);
	
	for(;pos_x+r<640;pos_x++)
	{
		setfillcolor(GREEN);
		fillcircle(pos_x,pos_y,r);
		Sleep(10);
		setcolor(BLACK);
		setfillcolor(BLACK);
		fillcircle(pos_x,pos_y,r);
	}

	getch();
	closegraph();


	return 0;
}