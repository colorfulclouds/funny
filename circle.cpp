#include <graphics.h>
#include <conio.h>

int main(void)
{
	initgraph(640,480);
	setcolor(YELLOW);
	setfillcolor(GREEN);
	fillcircle(100,100,20);

	int y = 0;
	for(;y<=480;y+=48)
	{
		setcolor(RGB(0,0,y));
		line(0,y,640,y);
	}
	
	getch();
	closegraph();

	return 0;
}