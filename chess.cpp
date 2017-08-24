#include <graphics.h>
#include <conio.h>


int main(void)
{
	initgraph(600,600);
	int i=60;

	setbkcolor(WHITE);
	cleardevice();
	
	setcolor(BLACK);

	for(;i<600;i+=60)
	{
		line(i,0,i,600);
	}

	for(i=60;i<600;i+=60)
	{
		line(0,i,600,i);
	}
	getch();
	closegraph();


	return 0;
}