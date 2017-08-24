#include <graphics.h>
#include <conio.h>
#include <time.h>
#include <math.h>

class ball
{
private:
	int pos_x[10];
	int pos_y[10];
	int r;
	int v_x[10];
	int v_y[10];

public:
	ball()
	{
		srand((unsigned int)time(NULL));
		int i;
		for(i=0;i<10;i++)
		{
			pos_x[i] = rand()%640+10;
			pos_y[i] = rand()%480+10;
			v_x[i] = v_y[i] = 1;
		}
		this->r = 10;
	}
	~ball()
	{
	}

	void move()
	{
		setfillcolor(RED);
		int i;
		for(i=0;i<10;i++)
			fillcircle(pos_x[i] , pos_y[i] , r);
		FlushBatchDraw();
		Sleep(5);
		setcolor(BLACK);
		setfillcolor(BLACK);
		for(i=0;i<10;i++)
			fillcircle(pos_x[i] , pos_y[i] , r);
	}

	double distance(int x1 , int y1 , int x2 , int y2)
	{
		return ((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
	}

	void pz()
	{
		int i;
		int j;

		for(i=0;i<10;i++)
			for(j=i+1;j<10;j++)
			{
				if(distance(pos_x[i] , pos_y[i] , pos_x[j] , pos_y[j]) < r)
				{
					v_x[i] *= -1;
					v_y[i] *= -1;

					v_x[j] *= -1;
					v_y[j] *= -1;
				}
			}
	}

	void update()
	{
		int i;
		pz();
		for(i=0;i<10;i++)
		{
			pos_x[i] += v_x[i];
			pos_y[i] += v_y[i];
		}
		
		for(i=0;i<10;i++)
		{
			if(pos_x[i]+r > 640 || pos_x[i]-r<0)
				v_x[i] *= -1;
			if(pos_y[i]+r > 480 || pos_y[i]-r<0)
				v_y[i] *= -1;
		}
	}

	void play()
	{
		move();
		update();
	}
};

int main(void)
{
	ball balls;

	initgraph(640,480);
	
	BeginBatchDraw();
	while(1)
	{
			balls.play();
	}

	EndBatchDraw();

	getch();
	closegraph();

	return 0;
}