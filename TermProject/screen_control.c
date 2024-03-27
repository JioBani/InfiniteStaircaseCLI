#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <ctype.h>
#include "screen_control.h"
#include "screen.h"

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


// ================================================================================

static RenderInfo printSprite;
static object makeObject;

//
RenderInfo BoxSize1 = {
	{
		{"■",},
	},
	{
		{"BOX_Black",},
	},
	1,1,1
};

//
static int Color_To_TextAttribute(char* color) {
	int fg_color = 0;
	int bg_color = 0;

	if ('0' <= color[0] && color[0] <= '9') fg_color = color[0] - '0';
	else if ('A' <= color[0] && color[0] <= 'F') fg_color = color[0] - 'A' + 10;
	else fg_color = 0;

	if ('0' <= color[1] && color[1] <= '9') bg_color = color[1] - '0';
	else if ('A' <= color[1] && color[1] <= 'F') bg_color = color[1] - 'A' + 10;
	else bg_color = 0;

	return fg_color | bg_color << 4;
}


void Object_Print(object* obj) {
	printSprite = obj->renderinfo;
	if (printSprite.enable == 0) return;
	location loc = obj->postion;
	for (int y = 0; y < printSprite.sizeY; y++) {
		if ((0 <= obj->postion.y + y && obj->postion.y + y < SCREEN_HEIGHT - 1)) {
			for (int x = 0; x < printSprite.sizeX; x++) {
				if ((strcmp("NA", printSprite.shape[y][x])) &&
					0 <= obj->postion.x + 2 * x && obj->postion.x + 2 * x <= SCREEN_WIDTH - 2) {
					if (!strcmp(printSprite.shape[y][x], "NA"))
						Screen_SetColor(Color_To_TextAttribute("11"));
					else 
						Screen_SetColor(Color_To_TextAttribute(obj->renderinfo.color[y][x]));
					Screen_Print(printSprite.shape[y][x], loc.x, loc.y);
				}
				loc.x += 2;
			}
		}

		loc.x = obj->postion.x;
		loc.y++;
	}
	Screen_SetColor(Color_To_TextAttribute("BB"));
}

//====== 오브젝트 처리 ======
object Object_Make(RenderInfo renderInfo) {
	object obj;
	obj.postion.x = 0; 
	obj.postion.y = 0;
	obj.renderinfo = renderInfo;
	return obj;
}

void Object_ChangePostion(object* obj, int x, int y)
{
	obj->postion.x = x;
	obj->postion.y = y;
}

void Object_Move(object* obj, int x, int y) {
	obj->postion.x = obj->postion.x + x;
	obj->postion.y = obj->postion.y + y;
}

void Object_SetEnable(object* obj, int a) {
	if (a > 1) a = 1;
	else if (a < 0) a = 0;
	obj->renderinfo.enable = a;
}

void Object_SetRenderInfo(object* obj, RenderInfo ren) {
	obj->renderinfo = ren;
}

void Object_SetColor(object* obj , char* color) {
	for (int i = 0; i < obj->renderinfo.sizeY; i++) {
		for (int j = 0; j < obj->renderinfo.sizeX; j++) {
			obj->renderinfo.color[i][j] = color;
		}
	}
}


//==


void Drow_Box(int w, int l, int x, int y, char* color) {
	object tmpBox = Object_Make(BoxSize1);
	Object_ChangePostion(&tmpBox, x, y);
	Object_SetColor(&tmpBox, color);
	for (int i = 0; i <l; i++) {
		Object_ChangePostion(&tmpBox, x, y + i);
		for (int j = 0; j <w; j++) {
			Object_Print(&tmpBox);
			Object_Move(&tmpBox, 2, 0);
		}
	}
}

//=================디버그======================


