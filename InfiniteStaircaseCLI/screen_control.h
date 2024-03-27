//screen_control.h

#ifndef SCREEN_CONTROL_H
#define SCREEN_CONTROL_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <ctype.h>

#define BLACK	0
#define BLUE1	1
#define GREEN1	2
#define CYAN1	3
#define RED1	4
#define MAGENTA1 5
#define YELLOW1	6
#define GRAY1	7
#define GRAY2	8
#define BLUE2	9
#define GREEN2	10
#define CYAN2	11
#define RED2	12
#define MAGENTA2 13
#define YELLOW2	14
#define WHITE	15

#define DefultColor 11
#define SCREEN_WIDTH 108
#define SCREEN_HEIGHT 96
#define MAX_RENDER_SIZE_X 64
#define MAX_RENDER_SIZE_Y 64

typedef struct location {
	int x;
	int y;
}location;

typedef char* Shape;

typedef char Color[2];

typedef struct RenderInfo {
	Shape shape[MAX_RENDER_SIZE_Y][MAX_RENDER_SIZE_X];
	char* color[MAX_RENDER_SIZE_Y][MAX_RENDER_SIZE_X];
	int sizeX;
	int sizeY;
	int enable;
}RenderInfo;

typedef struct object {
	location postion;
	RenderInfo renderinfo;
}object;

extern RenderInfo BoxSize1;


//=======================


object Object_Make(RenderInfo renderInfo); //������Ʈ �����

void Object_Print(object* obj); //������Ʈ ���

void Object_ChangePostion(object* obj, int x, int y); //������Ʈ ��ġ �̵�

void Object_Move(object* obj, int x, int y); //������Ʈ�� ���� ��ġ �������� �̵�

void Object_SetEnable(object* obj, int a); //������Ʈ ��� ���� ����

void Object_SetRenderInfo(object* obj, RenderInfo ren);//������Ʈ RenderInfo ����

//������Ʈ �� ����
void Object_SetColor(object* obj, char* color);

//�ڽ� �׸���
void Drow_Box(int w, int l, int x, int y, char* color);

#endif // !SCREEN_CONTROL.H