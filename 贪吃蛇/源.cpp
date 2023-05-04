#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<graphics.h>
#include<process.h>
#include<Windows.h>
#pragma comment(lib,"Winmm.lib")

int eat = 0, f = 1, score = 0, speed = 0, len = 0, now = -2, next = 0,nx=12,ny=10;
int map[40][40] = { 0 };
char key='d',r='r';

typedef struct snakebody {
	int x;
	int y;
	snakebody* prebody;
}snakebody;

typedef struct food {
	int x;
	int y;

}food;

snakebody* head, * tail;
food lastfood;

void Begin () {
	TCHAR a[] = _T("贪吃鲲"), b[] = _T("按任意键开始游戏"), c[] = _T("（请调整至英文小写键入）");
	settextstyle (80, 0, _T("华文琥珀"));
	outtextxy(290, 125, a);
	settextstyle(25, 0, _T("华文琥珀"));
	outtextxy(310, 285, b);
	settextstyle(20, 0, _T("楷体"));
	outtextxy(290, 385, c);
	_getch();
}

int Gamemode() {
	TCHAR a[] = _T("选择游戏模式"), b[] = _T("a.无墙"), c[] = _T("b.有墙");
	settextstyle(25, 0, _T("华文琥珀"));
	outtextxy(310, 125, a);
	outtextxy(100, 285, b);
	outtextxy(350, 285, c);
	return _getch() - 'a';
}

int Difficulity() {
	TCHAR a[] = _T("选择游戏难度"), b[] = _T("a.简单"), c[] = _T("b.普通"), d[] = _T("c.困难");
	settextstyle(25, 0, _T("华文琥珀"));
	outtextxy(310, 125, a);
	outtextxy(100, 285, b);
	outtextxy(350, 285, c);
	outtextxy(600, 285, d);
	return _getch() - 'a';
}
void Map1() {
	setlinecolor(COLORREF RGB(11, 191, 206));
	rectangle(0, 0, 410, 410);
}

void Map2 () {
	setlinecolor(COLORREF RGB(11, 191, 206));
	rectangle(0, 0, 410, 410);
	rectangle(10, 10, 400, 400);
}

void Food() {
		int x = rand() % 39 + 1;
		int y = rand() % 39 + 1;
		while (map[x][y] != 0) {
			x = rand() % 39 + 1;
			y = rand() % 39 + 1;
		}
		lastfood.x = x, lastfood.y = y;
		map[x][y] = 1;
		setfillcolor(COLORREF RGB(255, 0, 128));
		solidrectangle(x * 10, y * 10, x * 10 + 10, y * 10 + 10);
}

void Snakeinitial() {
	snakebody* point = NULL;
	head = (snakebody*)malloc(sizeof(snakebody));
	head->x = 12, head->y = 10;
	point = (snakebody*)malloc(sizeof(snakebody));
	point->x = 11, point->y = 10, point->prebody = head;
	tail = (snakebody*)malloc(sizeof(snakebody));
	tail->x = 10, tail->y = 10, tail->prebody = point;
	map[12][10] = 2;
	map[11][10] = 2;
	map[10][10] = 2;
	setlinecolor(LIGHTBLUE);
	setfillcolor(LIGHTGREEN);
	fillrectangle(120, 100, 130, 110);
	fillrectangle(110, 100, 120, 110);
	fillrectangle(100, 100, 110, 110);
}


void Snakedel() {
	int newx = tail->x, newy = tail->y;
	map[newx][newy] = 0;
	snakebody* point;
	point = tail;
	tail = tail->prebody;
	setlinecolor(BLACK);
	setfillcolor(BLACK);
	fillrectangle(newx * 10, newy * 10, newx * 10 + 10, newy * 10 + 10);
	free(point);
	eat = 0;
}

void Getkey() {
	while (_kbhit()) {
		key = _getch();
		switch (key) {
		case 'w':next = 1; break;
		case 's':next = -1; break;
		case 'a':next = 2; break;
		case 'd':next = -2; break;
		}
		if (next != now && next != -now) {
			now = next;
		}
	}
}

void Snakemove1() {
	Getkey();
	switch (now)
	{
	case 1: ny--;
		break;
	case -1:ny++;
		break;
	case 2: nx--;
		break;
	case -2: nx++;
		break;
	};
	
	if (nx < 1) {
		nx = 39;
	}
	else if (nx > 39) {
		nx = 1;
	}
	else if (ny < 1) {
		ny = 39;
	}
	else if (ny > 39) {
		ny = 1;
	};

	if (map[nx][ny] != 2) {
		setlinecolor(LIGHTBLUE);
		setfillcolor(LIGHTGREEN);
		fillrectangle(nx * 10, ny * 10, nx * 10 + 10, ny * 10 + 10);
		head->prebody = (snakebody*)malloc(sizeof(snakebody));
		head = head->prebody;
		head->x = nx, head->y = ny, head->prebody = NULL;
		if (map[nx][ny] == 1) {
			eat = 1;
			score++;
			map[nx][ny] = 2;
			Food();
		}
		else map[nx][ny] = 2;
	}
	else f = 0;
	if (eat == 0)Snakedel();
	else eat = 0;
}

void Snakemove2() {
	Getkey();
	switch (now)
	{
	case 1: ny--;
		break;
	case -1:ny++;
		break;
	case 2: nx--;
		break;
	case -2: nx++;
		break;
	};
	if (nx < 1 || nx>39 || ny < 1 || ny>39)f = 0;
	else {
		if (map[nx][ny] != 2) {
			setlinecolor(LIGHTBLUE);
			setfillcolor(LIGHTGREEN);
			fillrectangle(nx * 10, ny * 10, nx * 10 + 10, ny * 10 + 10);
			head->prebody = (snakebody*)malloc(sizeof(snakebody));
			head = head->prebody;
			head->x = nx, head->y = ny, head->prebody = NULL;
			if (map[nx][ny] == 1) {
				eat = 1;
				score++;
				map[nx][ny] = 2;
				Food();
			}
			else map[nx][ny] = 2;
		}
		else f = 0;
		if (eat == 0)Snakedel();
		else eat = 0;
	}

}

void Datadel() {
	snakebody* point;
	while (tail->prebody!=NULL) {
		map[tail->x][tail->y] = 0;
		point = tail;
		tail = tail->prebody;
		free(point);
	}
	map[tail->x][tail->y] = 0;
	free(tail);
	map[lastfood.x][lastfood.y] = 0;
}
void Endgame() {
	Sleep(1000);
	Datadel();
	cleardevice();
	TCHAR a[] = _T("游戏结束"), b[] = _T("您的鲲进化为"), c[] = _T("按r重新开始游戏");
	TCHAR d[10][8] = { _T("迷你鲲"),_T("小小鲲"),_T("初级鲲"),_T("小神鲲"),_T("超级鲲"),_T("迷你龙"),_T("幼年龙"),_T("小飞龙"),_T("天空龙"),_T("梦幻龙")};
	if (score > 10)score = 10;
	settextstyle(80, 0, _T("华文琥珀"));
	outtextxy(290, 125, a);
	settextstyle(20, 0, _T("楷体"));
	outtextxy(310, 285, b);
	settextstyle(25, 0, _T("华文琥珀"));
	outtextxy(290, 385, c);
	settextcolor(RED);
	settextstyle(30, 0, _T("华文琥珀"));
	outtextxy(310, 325, d[score-3]);
	settextcolor(WHITE);
	Sleep(1000);
	fflush(stdin);
	r = _getch();
}

int main () {
	initgraph(800, 650);
	int a,b,c;
	Begin();
	while (r == 'r') {
		eat = 0, f = 1, score = 3, speed = 0, len = 0, now = -2, next = 0, nx = 12, ny = 10;
		map[40][40] = { 0 };
		key = 'd', r = 'r';
		cleardevice();
		c = Gamemode();
		cleardevice();
		b = Difficulity();
		cleardevice();
		Snakeinitial();
		Food();
		f = 1;
		if (c == 0) {
			while (f) {
				if (score < 8)speed = 100 - score * b * 5;
				else speed = 100 - 8 * b * 5;
				Snakemove1();
				Map1();
				Sleep(speed);
			}
		}
		else {
			while (f) {
				if (score < 8)speed = 100 - score * b * 5;
				else speed = 100 - 8 * b * 5;
				Snakemove2();
				Map2();
				Sleep(speed);
			}
		}
		Endgame();
	}
	closegraph();
	return 0;
}