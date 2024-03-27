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


object Object_Make(RenderInfo renderInfo); //오브젝트 만들기

void Object_Print(object* obj); //오브젝트 출력

void Object_ChangePostion(object* obj, int x, int y); //오브젝트 위치 이동

void Object_Move(object* obj, int x, int y); //오브젝트를 현재 위치 기준으로 이동

void Object_SetEnable(object* obj, int a); //오브젝트 출력 여부 설정

void Object_SetRenderInfo(object* obj, RenderInfo ren);//오브젝트 RenderInfo 변경

//오브젝트 색 변경
void Object_SetColor(object* obj, char* color);

//박스 그리기
void Drow_Box(int w, int l, int x, int y, char* color);

#endif // !SCREEN_CONTROL.H