#ifndef NUMBER_PRINT_H
#define NUMBER_PRINT_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <ctype.h>
#include "screen_control.h"
#include "graphic.h"

typedef struct NumberObject
{
	int value;
	int digit;
	int valuesOfEeahDigit[10];
	object numbers[10];
	location postion;
	Color color;
}NumberObject;

void NumberPrint_Set();

NumberObject NumberObject_Make(int value, int x, int y);

void NumberObject_Print(NumberObject* obj);

void NumberObject_SetValue(NumberObject* obj, int value);

void NumberObject_ChangePostion(NumberObject* obj, int x, int y);

void NumberObject_Move(NumberObject* obj, int x, int y);

// NumberObject 색 바꾸기
void NumberObject_SetColor(NumberObject* obj, char* color);
#endif
