#include <windows.h>

#define SCREEN_WIDTH 108 
#define SCREEN_HEIGHT 96
#define SCREEN_WAIT_TIME 50
#define DefaultColor 11

static int g_nScreenIndex;
static HANDLE g_hScreen[2];


void SetFontSize(int size) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_FONT_INFOEX fontInfo;

    fontInfo.cbSize = sizeof(fontInfo);

    GetCurrentConsoleFontEx(hConsole, FALSE, &fontInfo);

    fontInfo.dwFontSize.X = 0;
    fontInfo.dwFontSize.Y = size;

    SetCurrentConsoleFontEx(hConsole, FALSE, &fontInfo);
}


void Screen_Init()
{
    CONSOLE_CURSOR_INFO cursorInfo;
    COORD Coor = { 0,0 };
    DWORD dw;

    system("mode con:cols=108 lines=96");
    SetFontSize(8);
    SetConsoleTitle("무한의 계단");

    //화면 버퍼 2개를 만든다.
    g_hScreen[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE,
        0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    g_hScreen[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE,
        0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    //커서 숨기기
    cursorInfo.dwSize = 1;
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(g_hScreen[0], &cursorInfo);
    SetConsoleCursorInfo(g_hScreen[1], &cursorInfo);
}

void Screen_BufferFilp()
{
    SetConsoleActiveScreenBuffer(g_hScreen[g_nScreenIndex]);
    g_nScreenIndex = !g_nScreenIndex;
}

void Screen_BufferClear()
{
    COORD Coor = { 0,0 };
    DWORD dw;
    FillConsoleOutputAttribute(g_hScreen[g_nScreenIndex], DefaultColor | DefaultColor << 4, SCREEN_WIDTH * SCREEN_HEIGHT, Coor, &dw);
    FillConsoleOutputCharacter(g_hScreen[g_nScreenIndex], ' ', SCREEN_WIDTH * SCREEN_HEIGHT, Coor, &dw);
}

void Screen_Release()
{
    CloseHandle(g_hScreen[0]);
    CloseHandle(g_hScreen[1]);
}

void Screen_Print(char* string, int x, int y)
{
    DWORD dw;
    COORD CursorPosition = { x, y };
    SetConsoleCursorPosition(g_hScreen[g_nScreenIndex], CursorPosition);
    WriteFile(g_hScreen[g_nScreenIndex], string, strlen(string), &dw, NULL);
}

void Screen_SetColor(int color)
{
    SetConsoleTextAttribute(g_hScreen[g_nScreenIndex], color);
}

void Screen_CursorOff() { // 커서를 안보이게 한다
    CONSOLE_CURSOR_INFO cursorInfo;

    cursorInfo.bVisible = 0;
    SetConsoleCursorInfo(g_hScreen[0], &cursorInfo);
    SetConsoleCursorInfo(g_hScreen[1], &cursorInfo);
}

void Screen_CursorOn() { // 커서를 보이게 한다
    CONSOLE_CURSOR_INFO cursorInfo;

    cursorInfo.bVisible = 1;
    SetConsoleCursorInfo(g_hScreen[0], &cursorInfo);
    SetConsoleCursorInfo(g_hScreen[1], &cursorInfo);
}
