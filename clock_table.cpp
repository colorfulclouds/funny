#include <graphics.h>
#include <conio.h>
#include <math.h>

#define PI 3.14159

class needle
{
private:
	int m_x;
	int m_y;
	int r;
	
	double delta;
	SYSTEMTIME ti;

public:
	needle(int r)
	{
		this->r = r;
	}

	void update(int flag)
	{
		GetLocalTime(&ti);

		switch(flag)
		{
			case 1:
				delta = ti.wHour * 2*PI/12;
				break;
			case 2:
				delta = ti.wMinute * 2*PI/60;
				break;
			case 3:
				delta = ti.wSecond * 2*PI/60;
				break;
		}
		
		m_x = 200 + (int)(r*sin(delta));
		m_y = 200 - (int)(r*cos(delta));
	}

	void draw(int flag)
	{
		switch(flag)
		{
		case 1:
			setcolor(YELLOW);
			break;
			
		case 2:
			setcolor(GREEN);
			break;
			
		case 3:
			setcolor(WHITE);
			break;
		}
		line(200 , 200 , m_x , m_y);
	}

	void clear()
	{
		setcolor(BLACK);
		line(200 , 200 , m_x , m_y);
	}
};

class clock
{
private:
	int pos_x;
	int pos_y;
	
	needle *hour;
	needle *minute;
	needle *second;
	
public:
	clock()
	{
		pos_x = 400/2;
		pos_y = 400/2;
		
		hour = new needle(80);
		minute = new needle(120);
		second = new needle(150);
	}
	~clock()
	{
		delete hour;
		delete minute;
		delete second;
	}

	void draw_ring()
	{
		setcolor(BLUE);
		setlinestyle(PS_SOLID , 2);
		circle(pos_x , pos_y , 200);

		int i;
		int x;
		int y;
		
		for(i=0;i<60;i++)
		{
			//60 seconds
			x = pos_x + (int)(400/2.1*sin(PI*2*i/60));
			y = pos_y + (int)(400/2.1*cos(PI*2*i/60));

			if(i%15 == 0)
				bar(x-5,y-5,x+5,y+5);
			else if(i%5 == 0)
				circle(x,y,3);
			else
				putpixel(x,y,WHITE);
		}
	}

	void go()
	{
		while(1)
		{
			hour->update(1);
			minute->update(2);
			second->update(3);
			
			hour->draw(1);
			minute->draw(2);
			second->draw(3);
			Sleep(100);
			hour->clear();
			minute->clear();
			second->clear();

		//	setlinestyle(PS_SOLID , 2);
		}
	}

};

int main(void)
{
	clock one;
	initgraph(400,400);

	one.draw_ring();
	one.go();
	
	
	getch();
	closegraph();

	return 0;
}