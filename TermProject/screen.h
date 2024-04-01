#ifndef SCREEN_H
#define SCREEN_H

void SetFontSize(int size);

void Screen_Init();

void Screen_BufferFilp();

void Screen_BufferClear();

void Screen_Release();

void Screen_Print(char* string, int x, int y);

void Screen_SetColor(int color);

void Screen_CursorOff();

void Screen_CursorOn();

#endif // !SCREEN_H
