#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <ctype.h>

#include "LifeCiycle.h"
#include "screen.h"

#define _waitTime_ 0
int main()
{
    Screen_Init();

    OnAwake();
    OnStart();
    char ch;

    while (1)
    {
        if (kbhit()) {
            ch = getch();
            KeyProcess(ch);
        }

        Update();//������ ����

        Render();//ȭ�� ���
        Sleep(_waitTime_);
    }

    OnEnd();
    Screen_Release();
}