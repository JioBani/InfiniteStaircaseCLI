#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <ctype.h>
#include <math.h>
//#include "screen_control.h"
#include "number_print.h"
//#include "graphic.h"

#define NUMBER_SIZE_X 6

/*
typedef struct NumberObject
{
	int value;
	int digit;
	int valuesOfEeahDigit[10];
	object numbers[10];
	location postion;
	Color color;
}NumberObject;

*/
static RenderInfo numbers[10];


void NumberPrint_Set() {
	numbers[0] = renderinfo_number0;
	numbers[1] = renderinfo_number1;
	numbers[2] = renderinfo_number2;
	numbers[3] = renderinfo_number3;
	numbers[4] = renderinfo_number4;
	numbers[5] = renderinfo_number5;
	numbers[6] = renderinfo_number6;
	numbers[7] = renderinfo_number7;
	numbers[8] = renderinfo_number8;
	numbers[9] = renderinfo_number9;
}



NumberObject NumberObject_Make(int value, int x, int y) {
	NumberObject obj;
	int i = 0;
	obj.value = value;
	if (value <= 1) obj.digit = 1;
	else obj.digit = floor(log10(value) + 1);
	obj.postion.x = x;
	obj.postion.y = y;

	for (i = 0; i < 10; i++) {
		obj.valuesOfEeahDigit[i] = 0;
	}

	for (i = obj.digit - 1; i >= 0; i--) {
		obj.valuesOfEeahDigit[(obj.digit - 1) - i] = value / (int)pow(10, i);
		value %= (int)pow(10, i);
	}
	for (i = 0; i < 10; i++) {
		obj.numbers[i] = Object_Make(numbers[obj.valuesOfEeahDigit[i]]);
		Object_ChangePostion(&obj.numbers[i], x + i * (NUMBER_SIZE_X + 2), y);
	}
	return obj;
}

void NumberObject_SetValue(NumberObject* obj, int value) {
	int i = 0;
	obj->value = value;
	if (value <= 1) obj->digit = 1;
	else obj->digit = floor(log10(value) + 1);
	for (i = obj->digit - 1; i >= 0; i--) {
		obj->valuesOfEeahDigit[(obj->digit - 1) - i] = value / (int)pow(10, i);
		value %= (int)pow(10, i);
	}
	for (i = 0; i < obj->digit; i++) {
		Object_SetRenderInfo(&obj->numbers[i], numbers[obj->valuesOfEeahDigit[i]]);
	}
}

void NumberObject_ChangePostion(NumberObject* obj, int x, int y) {
	int i = 0;
	obj->postion.x = x;
	obj->postion.y = y;
	for (i = 0; i < 10; i++) {
		Object_ChangePostion(&obj->numbers[i], x + i * (NUMBER_SIZE_X + 2), y);
	}
}

void NumberObject_Move(NumberObject* obj, int x, int y) {
	NumberObject_ChangePostion(obj, obj->postion.x + x, obj->postion.y + y);
}


void NumberObject_Print(NumberObject* obj) {
	for (int i = 0; i < obj->digit; i++)
		Object_Print(&obj->numbers[i]);
}

void NumberObject_SetColor(NumberObject* obj, char* color){
	for (int i = 0; i < 10; i++) {
		Object_SetColor(&obj->numbers[i], color);
	}
}
