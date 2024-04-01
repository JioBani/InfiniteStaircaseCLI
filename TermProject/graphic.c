#include "screen_control.h"
#include "graphic.h"

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
#define BackGround 11

#define BOX_Black "00"
#define BOX_Blue "11"
#define BOX_Green "22"
#define BOX_LightBlue "33"
#define BOX_Red "44"
#define BOX_Purple "55"
#define BOX_Ivory "66"
#define BOX_Gray "77"
#define BOX_DarkGray "88"
#define BOX_Brown "99"
#define BOX_LightGreen "AA"
#define BOX_SkyBlue "BB"
#define BOX_Orange "CC"
#define BOX_Pink "DD"
#define BOX_Yellow "EE"
#define BOX_White "FF"

#define DefaultColor "BB"

char graphic_stair[2][9] =
{
 "бсбсбсбс",
 "бсбсбсбс"
};

char graphic_player[4][9] = {
	"бсбс",
	"бсбс",
	"бсбс",
	"бсбс"
};
/*
typedef struct RenderInfo {
	Shape shape[10][10];
	Color color[10][10];
	int sizeX;
	int sizeY;
	int enable;
}RenderInfo;
*/

char* ch = "ch";

#define Stair "78"
#define InStar "77"
#define G BOX_Gray
#define D BOX_DarkGray

RenderInfo renderinfo_stair = {
	{
		{"бс","бс","бс","бс",},
		{"бс","бс","бс","бс",},
	},
	{
		{Stair,Stair,Stair,Stair,},
		{Stair,Stair,Stair,Stair,},
	},
	4,
	2,
	1
};

RenderInfo renderinfo_bigStair = {
	{
		{"бс","бс","бс","бс","бс","бс","бс","бс","бс"},
		{"бс","бс","бс","бс","бс","бс","бс","бс","бс"},
		{"бс","бс","бс","бс","бс","бс","бс","бс","бс"},
		{"бс","бс","бс","бс","бс","бс","бс","бс","бс"},
	},
	{
		{D,G,G,G,G,G,G,D,G,},
		{D,G,G,D,D,G,G,G,G,},
		{D,G,G,G,G,G,D,G,G,},
		{D,G,D,D,G,G,G,G,G,},
	},
	9,
	4,
	1
};

RenderInfo renderinfo_bigStairStd = {
	{
		{"бс","бс","бс","бс","бс","бс","бс","бс","бс"},
		{"бс","бс","бс","бс","бс","бс","бс","бс","бс"},
		{"бс","бс","бс","бс","бс","бс","бс","бс","бс"},
		{"бс","бс","бс","бс","бс","бс","бс","бс","бс"},
	},
	{
		{D,D,D,D,D,D,D,D,D,},
		{D,D,D,D,D,D,D,D,D,},
		{D,D,D,D,D,D,D,D,D,},
		{D,D,D,D,D,D,D,D,D,},
	},
	9,
	4,
	1
};

RenderInfo renderinfo_bigStairStdM = {
	{
		{"бс","бс","бс","бс","бс","бс","бс","бс","бс"},
		{"бс","бс","бс","бс","бс","бс","бс","бс","бс"},
		{"бс","бс","бс","бс","бс","бс","бс","бс","бс"},
		{"бс","бс","бс","бс","бс","бс","бс","бс","бс"},
	},
	{
		{G,G,G,G,G,G,G,G,G,},
		{G,G,G,G,G,G,G,G,G,},
		{G,G,G,G,G,G,G,G,G,},
		{G,G,G,G,G,G,G,G,G,},
	},
	9,
	4,
	1
};
#undef D
#undef Stair
#undef InStair
#undef G


#define Gray BOX_Gray
#define White BOX_White
RenderInfo renderinfo_building = {
	{
		{"бс","бс","бс","бс","бс","бс","бс",},
		{"бс","бс","бс","бс","бс","бс","бс",},
		{"бс","бс","бс","бс","бс","бс","бс",},
		{"бс","бс","бс","бс","бс","бс","бс",},
		{"бс","бс","бс","бс","бс","бс","бс",},
	},
	{
		{Gray,Gray,Gray,Gray,Gray,Gray,Gray,},
		{Gray,Gray,Gray,Gray,Gray,Gray,Gray,},
		{Gray,Gray,Gray,Gray,Gray,Gray,Gray,},
		{Gray,Gray,Gray,Gray,Gray,Gray,Gray,},
		{Gray,Gray,Gray,Gray,Gray,Gray,Gray,},
	},
	7,
	5,
	1
};


#undef Gray
#undef White

#define R BOX_Red
#define Y BOX_Yellow
#define B BOX_Black
#define P BOX_Pink
#define N DefaultColor

RenderInfo renderinfo_playerRight = {
	{
		{"NA","бс","бс","бс","бс","бс","бс","бс"},
		{"бс","бс","бс","бс","бс","бс","бс","бс"},
		{"бс","бс","бс","бс","бс","бс","бс","бс"},
		{"бс","бс","бс","бс","бс","бс","бс","бс"},
		{"бс","бс","бс","бс","бс","бс","бс","бс"},
		{"бс","бс","бс","бс","бс","бс","бс","бс"},
		{"NA","бс","бс","бс","бс","бс","бс","NA"},
		{"NA","бс","бс","бс","бс","бс","бс","NA"},
		{"NA","бс","бс","бс","бс","бс","бс","бс"},
		{"NA","бс","бс","бс","бс","бс","бс","бс"},
		{"NA","бс","бс","бс","бс","бс","бс","NA"},
		{"NA","бс","бс","бс","бс","бс","бс","NA"},
	},
	{
		{N,R,R,R,R,R,R,R},
		{R,R,R,R,R,R,R,R},
		{R,R,Y,Y,Y,Y,Y,Y},
		{R,R,Y,Y,B,Y,Y,B},
		{R,R,Y,Y,B,Y,Y,B},
		{R,R,Y,Y,Y,R,R,Y},
		{N,P,P,P,P,P,P,N},
		{N,P,P,P,P,P,P,N},
		{N,Y,Y,P,P,P,Y,Y},
		{N,Y,Y,R,R,R,Y,Y},
		{N,R,R,R,R,R,R,N},
		{N,R,R,N,N,R,R,N},
	},
	8,
	12,
	1
};

RenderInfo renderinfo_playerLeft = {
	{
		{"бс","бс","бс","бс","бс","бс","бс","NA"},
		{"бс","бс","бс","бс","бс","бс","бс","бс"},
		{"бс","бс","бс","бс","бс","бс","бс","бс"},
		{"бс","бс","бс","бс","бс","бс","бс","бс"},
		{"бс","бс","бс","бс","бс","бс","бс","бс"},
		{"бс","бс","бс","бс","бс","бс","бс","бс"},
		{"NA","бс","бс","бс","бс","бс","бс","NA"},
		{"NA","бс","бс","бс","бс","бс","бс","NA"},
		{"бс","бс","бс","бс","бс","бс","бс","NA"},
		{"бс","бс","бс","бс","бс","бс","бс","NA"},
		{"NA","бс","бс","бс","бс","бс","бс","NA"},
		{"NA","бс","бс","бс","бс","бс","бс","NA"},
	},
	{
		{R,R,R,R,R,R,R,N},
		{R,R,R,R,R,R,R,R},
		{Y,Y,Y,Y,Y,Y,R,R},
		{B,Y,Y,B,Y,Y,R,R},
		{B,Y,Y,B,Y,Y,R,R},
		{Y,R,R,Y,Y,Y,R,R},
		{N,P,P,P,P,P,P,N},
		{N,P,P,P,P,P,P,N},
		{Y,Y,P,P,P,Y,Y,N},
		{Y,Y,R,R,R,Y,Y,N},
		{N,R,R,R,R,R,R,N},
		{N,R,R,N,N,R,R,N},
	},
	8,
	12,
	1
};

RenderInfo renderinfo_playerClimbingRight = {
	{
		{"NA","бс","бс","бс","бс","бс","бс","бс"},
		{"бс","бс","бс","бс","бс","бс","бс","бс"},
		{"бс","бс","бс","бс","бс","бс","бс","бс"},
		{"бс","бс","бс","бс","бс","бс","бс","бс"},
		{"бс","бс","бс","бс","бс","бс","бс","бс"},
		{"бс","бс","бс","бс","бс","бс","бс","бс"},
		{"NA","бс","бс","бс","бс","бс","бс","NA"},
		{"NA","бс","бс","бс","бс","бс","бс","бс"},
		{"NA","бс","бс","бс","бс","бс","бс","бс"},
		{"NA","бс","бс","бс","бс","бс","бс","NA"},
		{"NA","бс","бс","NA","NA","бс","бс","NA"},
		{"NA","бс","бс","NA","NA","NA","NA","NA"},
	},
	{
		{N,R,R,R,R,R,R,R},
		{R,R,R,R,R,R,R,R},
		{R,R,Y,Y,Y,Y,Y,Y},
		{R,R,Y,Y,B,Y,Y,B},
		{R,R,Y,Y,B,Y,Y,B},
		{R,R,Y,Y,Y,R,R,Y},
		{N,P,P,P,P,P,P,N},
		{N,P,P,P,P,P,Y,Y},
		{N,Y,Y,P,P,P,Y,Y},
		{N,Y,Y,P,P,R,R,N},
		{N,R,R,N,N,R,R,N},
		{N,R,R,N,N,N,N,N},
	},
	8,
	12,
	1
};

RenderInfo renderinfo_playerClimbingLeft = {
	{
		{"бс","бс","бс","бс","бс","бс","бс","NA"},
		{"бс","бс","бс","бс","бс","бс","бс","бс"},
		{"бс","бс","бс","бс","бс","бс","бс","бс"},
		{"бс","бс","бс","бс","бс","бс","бс","бс"},
		{"бс","бс","бс","бс","бс","бс","бс","бс"},
		{"бс","бс","бс","бс","бс","бс","бс","бс"},
		{"NA","бс","бс","бс","бс","бс","бс","NA"},
		{"бс","бс","бс","бс","бс","бс","бс","NA"},
		{"бс","бс","бс","бс","бс","бс","бс","бс"},
		{"NA","бс","бс","бс","бс","бс","бс","бс"},
		{"NA","бс","бс","NA","NA","бс","бс","NA"},
		{"NA","NA","NA","NA","NA","бс","бс","NA"},
	},
	{
		{R,R,R,R,R,R,R,N},
		{R,R,R,R,R,R,R,R},
		{Y,Y,Y,Y,Y,Y,R,R},
		{B,Y,Y,B,Y,Y,R,R},
		{B,Y,Y,B,Y,Y,R,R},
		{Y,R,R,Y,Y,Y,R,R},
		{N,P,P,P,P,P,P,N},
		{Y,Y,P,P,P,P,P,N},
		{Y,Y,P,P,P,P,Y,Y},
		{N,R,R,P,P,P,Y,Y},
		{N,R,R,N,N,R,R,N},
		{N,N,N,N,N,R,R,N},
	},
	8,
	12,
	1
};


#undef R
#undef Y
#undef B
#undef P
#undef N


// ========== number_print ========== //

#define Y BOX_Yellow
RenderInfo renderinfo_number0 = {
	{
		{"бс","бс","бс",},
		{"бс","NA","бс",},
		{"бс","NA","бс",},
		{"бс","NA","бс",},
		{"бс","бс","бс",},
	},
	{
		{Y,Y,Y,},
		{Y,Y,Y,},
		{Y,Y,Y,},
		{Y,Y,Y,},
		{Y,Y,Y,},
	},
	3,
	5,
	1
};

RenderInfo renderinfo_number1 = {
	{
		{"NA","бс","NA",},
		{"бс","бс","NA",},
		{"NA","бс","NA",},
		{"NA","бс","NA",},
		{"бс","бс","бс",},
	},
	{
		{Y,Y,Y,},
		{Y,Y,Y,},
		{Y,Y,Y,},
		{Y,Y,Y,},
		{Y,Y,Y,},
	},
	3,
	5,
	1
};

RenderInfo renderinfo_number2 = {
	{
		{"бс","бс","бс",},
		{"NA","NA","бс",},
		{"бс","бс","бс",},
		{"бс","NA","NA",},
		{"бс","бс","бс",},
	},
	{
		{Y,Y,Y,},
		{Y,Y,Y,},
		{Y,Y,Y,},
		{Y,Y,Y,},
		{Y,Y,Y,},
	},
	3,
	5,
	1
};

RenderInfo renderinfo_number3 = {
	{
		{"бс","бс","бс",},
		{"NA","NA","бс",},
		{"бс","бс","бс",},
		{"NA","NA","бс",},
		{"бс","бс","бс",},
	},
	{
		{Y,Y,Y,},
		{Y,Y,Y,},
		{Y,Y,Y,},
		{Y,Y,Y,},
		{Y,Y,Y,},
	},
	3,
	5,
	1
};

RenderInfo renderinfo_number4 = {
	{
		{"бс","NA","бс",},
		{"бс","NA","бс",},
		{"бс","бс","бс",},
		{"NA","NA","бс",},
		{"NA","NA","бс",},
	},
	{
		{Y,Y,Y,},
		{Y,Y,Y,},
		{Y,Y,Y,},
		{Y,Y,Y,},
		{Y,Y,Y,},
	},
	3,
	5,
	1
};

RenderInfo renderinfo_number5 = {
	{
		{"бс","бс","бс",},
		{"бс","NA","NA",},
		{"бс","бс","бс",},
		{"NA","NA","бс",},
		{"бс","бс","бс",},
	},
	{
		{Y,Y,Y,},
		{Y,Y,Y,},
		{Y,Y,Y,},
		{Y,Y,Y,},
		{Y,Y,Y,},
	},
	3,
	5,
	1
};

RenderInfo renderinfo_number6 = {
	{
		{"бс","бс","бс",},
		{"бс","NA","NA",},
		{"бс","бс","бс",},
		{"бс","NA","бс",},
		{"бс","бс","бс",},
	},
	{
		{Y,Y,Y,},
		{Y,Y,Y,},
		{Y,Y,Y,},
		{Y,Y,Y,},
		{Y,Y,Y,},
	},
	3,
	5,
	1
};

RenderInfo renderinfo_number7 = {
	{
		{"бс","бс","бс",},
		{"бс","NA","бс",},
		{"NA","NA","бс",},
		{"NA","NA","бс",},
		{"NA","NA","бс",},
	},
	{
		{Y,Y,Y,},
		{Y,Y,Y,},
		{Y,Y,Y,},
		{Y,Y,Y,},
		{Y,Y,Y,},
	},
	3,
	5,
	1
};

RenderInfo renderinfo_number8 = {
	{
		{"бс","бс","бс",},
		{"бс","NA","бс",},
		{"бс","бс","бс",},
		{"бс","NA","бс",},
		{"бс","бс","бс",},
	},
	{
		{Y,Y,Y,},
		{Y,Y,Y,},
		{Y,Y,Y,},
		{Y,Y,Y,},
		{Y,Y,Y,},
	},
	3,
	5,
	1
};

RenderInfo renderinfo_number9 = {
	{
		{"бс","бс","бс",},
		{"бс","NA","бс",},
		{"бс","бс","бс",},
		{"NA","NA","бс",},
		{"NA","NA","бс",},
	},
	{
		{Y,Y,Y,},
		{Y,Y,Y,},
		{Y,Y,Y,},
		{Y,Y,Y,},
		{Y,Y,Y,},
	},
	3,
	5,
	1
};

RenderInfo renderinfo_numberNULL = {
	{
		{"NA","NA","NA",},
		{"NA","NA","NA",},
		{"NA","NA","NA",},
		{"NA","NA","NA",},
		{"NA","NA","NA",},
	},
	{
		{Y,Y,Y,},
		{Y,Y,Y,},
		{Y,Y,Y,},
		{Y,Y,Y,},
		{Y,Y,Y,},
	},
	3,
	5,
	1
};

#undef Y

#define Y BOX_Yellow
#define O "CC"
#define G BOX_Gray
RenderInfo renderinfo_timer = {
	{
		{"бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс",},
		{"бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс",},
		{"бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс",},
		{"бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс",},
	},
	{	
		{O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,},
		{O,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,O,},
		{O,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,O,},
		{O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,},
	},
	32,
	4,
	1
};

RenderInfo renderinfo_timer0 = {
	{
		{"бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс",},
		{"бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс",},
		{"бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс",},
		{"бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс",},
	},
	{
		{O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,},
		{O,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,O,},
		{O,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,O,},
		{O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,},
	},
	30,
	4,
	1
};

RenderInfo renderinfo_timer1 = {
	{
		{"бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс",},
		{"бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс",},
		{"бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс",},
		{"бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс",},
	},
	{
		{O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,},
		{O,Y,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,O,},
		{O,Y,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,O,},
		{O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,},
	},
	30,
	4,
	1
};

RenderInfo renderinfo_timerIn = {
	{
		{"бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс",},
		{"бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс",},
	},
	{
		{Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,},
		{Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,},
	},
	28,
	2,
	1
};


#undef Y
#undef I
#undef O


#define O BOX_Orange
#define Y BOX_Yellow
#define R BOX_Red
#define B BOX_Blue
#define b BOX_Black
#define S BOX_SkyBlue
#define W BOX_White
#define P BOX_Pink
#define G BOX_Green
#define N "NA"
#define NA "NA"
#define Box2 "бс","бс"
#define Box5 "бс","бс","бс","бс","бс"
#define Box10 Box5,Box5

// {O,O,O,O,O,O,O,O,O,O,
// {Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,}
RenderInfo renderinfo_PREES_R = {
	{
		{"бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс",},
		{"бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс",},
		{"бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс",},
		{"бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс",},
		{"бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс",},
	},
	{
		{O,O,O,Y,O,O,Y,Y,O,O,O,Y,O,O,O,Y,O,O,O,Y,Y,Y,Y,R,R,Y,Y,},
		{O,Y,O,Y,O,Y,O,Y,O,Y,Y,Y,O,Y,Y,Y,O,Y,Y,Y,Y,Y,Y,R,Y,R,Y,},
		{O,O,O,Y,O,O,O,Y,O,O,O,Y,O,O,O,Y,O,O,O,Y,Y,Y,Y,R,R,R,Y,},
		{O,Y,Y,Y,O,O,Y,Y,O,Y,Y,Y,Y,Y,O,Y,Y,Y,O,Y,Y,Y,Y,R,R,Y,Y,},
		{O,Y,Y,Y,O,Y,O,Y,O,O,O,Y,O,O,O,Y,O,O,O,Y,Y,Y,Y,R,Y,R,Y,},
	},
	26,
	5,
	1
};

RenderInfo renderinfo_TO_RESTART = {
	{
		{Box10,Box10,Box10,Box5,Box2,"бс",},
		{Box10,Box10,Box10,Box5,Box2,"бс",},
		{Box10,Box10,Box10,Box5,Box2,"бс",},
		{Box10,Box10,Box10,Box5,Box2,"бс",},
		{Box10,Box10,Box10,Box5,Box2,"бс",},
	},
	{
		{O,O,O,Y,O,O,O,Y,Y,Y,Y,O,O,O,Y,O,O,O,Y,O,O,O,Y,O,O,O,Y,O,O,O,Y,O,O,O,Y,O,O,O,Y,},
		{Y,O,Y,Y,O,Y,O,Y,Y,Y,Y,O,Y,O,Y,O,Y,Y,Y,O,Y,Y,Y,Y,O,Y,Y,O,Y,O,Y,O,Y,O,Y,Y,O,Y,Y,},
		{Y,O,Y,Y,O,Y,O,Y,Y,Y,Y,O,O,O,Y,O,O,O,Y,O,O,O,Y,Y,O,Y,Y,O,O,O,Y,O,O,O,Y,Y,O,Y,Y,},
		{Y,O,Y,Y,O,Y,O,Y,Y,Y,Y,O,O,Y,Y,O,Y,Y,Y,Y,Y,O,Y,Y,O,Y,Y,O,Y,O,Y,O,O,Y,Y,Y,O,Y,Y,},
		{Y,O,Y,Y,O,O,O,Y,Y,Y,Y,O,Y,O,Y,O,O,O,Y,O,O,O,Y,Y,O,Y,Y,O,Y,O,Y,O,Y,O,Y,Y,O,Y,Y,},
	},
	38,
	5,
	1
};

RenderInfo renderinfo_SCORE_Colon = {
	{
		{Box10,Box10,Box2},
		{Box10,Box10,Box2},
		{Box10,Box10,Box2},
		{Box10,Box10,Box2},
		{Box10,Box10,Box2},
	},
	{
		{B,B,B,Y,B,B,B,Y,B,B,B,Y,B,B,B,Y,B,B,B,Y,Y,Y,},
		{B,Y,Y,Y,B,Y,Y,Y,B,Y,B,Y,B,Y,B,Y,B,Y,Y,Y,Y,B,},
		{B,B,B,Y,B,Y,Y,Y,B,Y,B,Y,B,B,B,Y,B,B,B,Y,Y,Y,},
		{Y,Y,B,Y,B,Y,Y,Y,B,Y,B,Y,B,B,Y,Y,B,Y,Y,Y,Y,B,},
		{B,B,B,Y,B,B,B,Y,B,B,B,Y,B,Y,B,Y,B,B,B,Y,Y,Y,},
	},
	22,
	5,
	1
};

RenderInfo renderinfo_GO = {
	{
		{Box10},
		{Box10},
		{Box10},
		{Box10},
		{Box10},
		{Box10},
	},
	{
		{O,O,O,O,Y,Y,O,O,Y,Y,},
		{O,Y,Y,Y,Y,O,Y,Y,O,Y,},
		{O,Y,Y,Y,Y,O,Y,Y,O,Y,},
		{O,Y,O,O,Y,O,Y,Y,O,Y,},
		{O,Y,Y,O,Y,O,Y,Y,O,Y,},
		{O,O,O,O,Y,Y,O,O,Y,Y,},
	},
	10,
	6,
	1
};

RenderInfo renderinfo_UP_EXEX = {
	{
		{Box10,Box2,Box2},
		{Box10,Box2,Box2},
		{Box10,Box2,Box2},
		{Box10,Box2,Box2},
		{Box10,Box2,Box2},
		{Box10,Box2,Box2},
	},
	{
		{O,Y,Y,O,Y,O,O,O,Y,Y,Y,O,Y,O,},
		{O,Y,Y,O,Y,O,Y,Y,O,Y,Y,O,Y,O,},
		{O,Y,Y,O,Y,O,Y,Y,O,Y,Y,O,Y,O,},
		{O,Y,Y,O,Y,O,O,O,Y,Y,Y,O,Y,O,},
		{O,Y,Y,O,Y,O,Y,Y,Y,Y,Y,Y,Y,Y,},
		{Y,O,O,Y,Y,O,Y,Y,Y,Y,Y,O,Y,O,},
	},
	14,
	6,
	1
};

RenderInfo renderinfo_PRESS_W = {
	{
		{Box10,Box10,Box10,},
		{Box10,Box10,Box10,},
		{Box10,Box10,Box10,},
		{Box10,Box10,Box10,},
		{Box10,Box10,Box10,},
	},
	{
		{O,O,O,Y,O,O,Y,Y,O,O,O,Y,O,O,O,Y,O,O,O,Y,Y,Y,Y,Y,Y,R,Y,Y,Y,R},
		{O,Y,O,Y,O,Y,O,Y,O,Y,Y,Y,O,Y,Y,Y,O,Y,Y,Y,Y,Y,Y,Y,Y,R,Y,R,Y,R},
		{O,O,O,Y,O,O,O,Y,O,O,O,Y,O,O,O,Y,O,O,O,Y,Y,Y,Y,Y,Y,R,Y,R,Y,R},
		{O,Y,Y,Y,O,O,Y,Y,O,Y,Y,Y,Y,Y,O,Y,Y,Y,O,Y,Y,Y,Y,Y,Y,R,Y,R,Y,R},
		{O,Y,Y,Y,O,Y,O,Y,O,O,O,Y,O,O,O,Y,O,O,O,Y,Y,Y,Y,Y,Y,Y,R,Y,R,Y},
	},
	30,
	5,
	1
};

RenderInfo renderinfo_TO_START = {
	{
		{Box10,Box10,Box10,},
		{Box10,Box10,Box10,},
		{Box10,Box10,Box10,},
		{Box10,Box10,Box10,},
		{Box10,Box10,Box10,},
	},
	{
		{O,O,O,Y,O,O,O,Y,Y,Y,Y,O,O,O,Y,O,O,O,Y,O,O,O,Y,O,O,O,Y,O,O,O,},
		{Y,O,Y,Y,O,Y,O,Y,Y,Y,Y,O,Y,Y,Y,Y,O,Y,Y,O,Y,O,Y,O,Y,O,Y,Y,O,Y,},
		{Y,O,Y,Y,O,Y,O,Y,Y,Y,Y,O,O,O,Y,Y,O,Y,Y,O,O,O,Y,O,O,O,Y,Y,O,Y,},
		{Y,O,Y,Y,O,Y,O,Y,Y,Y,Y,Y,Y,O,Y,Y,O,Y,Y,O,Y,O,Y,O,O,Y,Y,Y,O,Y,},
		{Y,O,Y,Y,O,O,O,Y,Y,Y,Y,O,O,O,Y,Y,O,Y,Y,O,Y,O,Y,O,Y,O,Y,Y,O,Y,},
	},
	30,
	5,
	1
};

RenderInfo renderinfo_W = {
	{
		{Box5},
		{Box5},
		{Box5},
		{Box5},
		{Box5},
	},
	{
		{O,Y,Y,Y,O},
		{O,Y,O,Y,O},
		{O,Y,O,Y,O},
		{O,Y,O,Y,O},
		{Y,O,Y,O,Y},
	},
	5,
	5,
	1
};

RenderInfo renderinfo_SPACE = {
	{
		{Box10,Box10,Box10,},
		{Box10,Box10,Box10,},
		{Box10,Box10,Box10,},
		{Box10,Box10,Box10,},
		{Box10,Box10,Box10,},
	},
	{
		{O,O,O,Y,O,O,O,Y,O,O,O,Y,O,O,O,Y,O,O,O,},
		{O,Y,Y,Y,O,Y,O,Y,O,Y,O,Y,O,Y,Y,Y,O,Y,Y,},
		{O,O,O,Y,O,O,O,Y,O,O,O,Y,O,Y,Y,Y,O,O,O,},
		{Y,Y,O,Y,O,Y,Y,Y,O,Y,O,Y,O,Y,Y,Y,O,Y,Y,},
		{O,O,O,Y,O,Y,Y,Y,O,Y,O,Y,O,O,O,Y,O,O,O,},
	},
	19,
	5,
	1
};

RenderInfo renderinfo_UpArrow = {
	{
		{Box5,},
		{Box5,},
		{Box5,},
		{Box5,},
		{Box5,},
		{Box5,},
		{Box5,},
	},
	{
		{S,S,b,S,S},
		{S,b,b,b,S},
		{b,b,b,b,b},
		{S,S,b,S,S},
		{S,S,b,S,S},
		{S,S,b,S,S},
		{S,S,b,S,S},
	},
	5,
	7,
	1
};

RenderInfo renderinfo_SideArrow = {
	{
		{Box10,},
		{Box10,},
		{Box10,},
		{Box10,},
		{Box10,},
		{Box10,},
		{Box10,},
	},
	{
		{S,S,b,S,S,S,S,S,S,S},
		{S,b,b,S,S,S,S,S,S,S},
		{b,b,b,b,b,b,b,b,b,b},
		{S,S,S,S,S,S,S,S,S,S},
		{b,b,b,b,b,b,b,b,b,b},
		{S,S,S,S,S,S,S,b,b,S},
		{S,S,S,S,S,S,S,b,S,S},
	},
	10,
	7,
	1
};

RenderInfo renderinfo_coin = {
	{
		{N,N,"бс","бс","бс",N,N,},
		{N,"бс","бс","бс","бс","бс",N,},
		{"бс","бс","бс","бс","бс","бс","бс",},
		{"бс","бс","бс","бс","бс","бс","бс",},
		{"бс","бс","бс","бс","бс","бс","бс",},
		{N,"бс","бс","бс","бс","бс",N,},
		{N,N,"бс","бс","бс",N,N,},
	},
	{
		{Y,Y,O,O,O,Y,Y,},
		{Y,O,Y,Y,Y,O,Y,},
		{O,Y,O,O,O,Y,O,},
		{O,Y,Y,O,Y,Y,O,},
		{O,Y,Y,O,Y,Y,O,},
		{Y,O,Y,Y,Y,O,Y,},
		{Y,Y,O,O,O,Y,Y,},
	},
	7,
	7,
	1
};

RenderInfo renderinfo_sun = {
	{
		{NA ,NA ,NA ,"бс","бс","бс",NA ,NA ,NA ,},
		{NA ,"бс","бс","бс","бс","бс","бс","бс",NA ,},
		{NA ,"бс","бс","бс","бс","бс","бс","бс",NA ,},
		{"бс","бс","бс","бс","бс","бс","бс","бс","бс",},
		{"бс","бс","бс","бс","бс","бс","бс","бс","бс",},
		{"бс","бс","бс","бс","бс","бс","бс","бс","бс",},
		{NA ,"бс","бс","бс","бс","бс","бс","бс",NA ,},
		{NA ,"бс","бс","бс","бс","бс","бс","бс",NA ,},
		{NA ,NA ,NA ,"бс","бс","бс",NA ,NA ,NA ,},
	},
	{
		{Y,Y,Y,Y,Y,Y,Y,Y,Y,},
		{Y,Y,Y,Y,Y,Y,Y,Y,Y,},
		{Y,Y,Y,Y,Y,Y,Y,Y,Y,},
		{Y,Y,Y,Y,Y,Y,Y,Y,Y,},
		{Y,Y,Y,Y,Y,Y,Y,Y,Y,},
		{Y,Y,Y,Y,Y,Y,Y,Y,Y,},
		{Y,Y,Y,Y,Y,Y,Y,Y,Y,},
		{Y,Y,Y,Y,Y,Y,Y,Y,Y,},
		{Y,Y,Y,Y,Y,Y,Y,Y,Y,},
	},
	9,
	9,
	1
};

RenderInfo renderinfo_cloud0 = {
	{
		{NA ,NA ,NA ,"бс","бс","бс","бс",NA ,NA ,},
		{NA ,"бс","бс","бс","бс","бс","бс","бс",NA ,},
		{"бс","бс","бс","бс","бс","бс","бс","бс","бс",},
		{NA ,NA ,"бс","бс","бс","бс","бс",NA ,NA ,},
	},
	{
		{W,W,W,W,W,W,W,W,W,},
		{W,W,W,W,W,W,W,W,W,},
		{W,W,W,W,W,W,W,W,W,},
		{W,W,W,W,W,W,W,W,W,},
	},
	9,
	4,
	1
};

RenderInfo renderinfo_cloud1 = {
	{
		{NA ,NA ,NA ,"бс",NA ,NA ,},
		{NA ,"бс","бс","бс","бс",NA ,},
		{"бс","бс","бс","бс","бс","бс",},
	},
	{
		{W,W,W,W,W,W,},
		{W,W,W,W,W,W,},
		{W,W,W,W,W,W,},
	},
	6,
	3,
	1
};

RenderInfo renderinfo_cloud2 = {
	{
		{NA ,NA ,"бс","бс","бс",NA ,NA ,NA ,},
		{NA ,"бс","бс","бс","бс","бс",NA ,NA ,},
		{"бс","бс","бс","бс","бс","бс","бс","бс",},
		{NA ,NA ,"бс","бс","бс","бс",NA ,NA ,},
	},
	{
		{W,W,W,W,W,W,W,W,},
		{W,W,W,W,W,W,W,W,},
		{W,W,W,W,W,W,W,W,},
		{W,W,W,W,W,W,W,W,},
	},
	8,
	4,
	1
};

RenderInfo renderinfo_cloud3 = {
	{
		{NA ,NA ,NA ,"бс","бс",NA ,NA ,NA ,NA ,},
		{NA ,NA ,"бс","бс","бс","бс","бс",NA ,NA ,},
		{NA ,"бс","бс","бс","бс","бс","бс","бс",NA ,},
		{"бс","бс","бс","бс","бс","бс","бс","бс","бс",},
		{NA ,NA ,"бс","бс","бс",NA ,NA ,NA ,NA ,},
	},
	{
		{W,W,W,W,W,W,W,W,W,},
		{W,W,W,W,W,W,W,W,W,},
		{W,W,W,W,W,W,W,W,W,},
		{W,W,W,W,W,W,W,W,W,},
		{W,W,W,W,W,W,W,W,W,},
	},
	9,
	5,
	1
};

RenderInfo renderinfo_cloud4 = {
	{
		{NA ,NA ,NA ,NA ,"бс","бс",NA ,},
		{"бс",NA ,NA ,NA ,"бс","бс","бс",},
		{"бс","бс","бс","бс","бс","бс",NA ,},
		{"бс","бс","бс","бс","бс","бс",NA,},
		{NA ,"бс","бс","бс","бс",NA ,NA ,},
		{NA ,NA ,"бс",NA ,NA ,NA ,NA ,},
	},
	{
		{W,W,W,W,W,W,W,},
		{W,W,W,W,W,W,W,},
		{W,W,W,W,W,W,W,},
		{W,W,W,W,W,W,W,},
		{W,W,W,W,W,W,W,},
		{W,W,W,W,W,W,W,},
	},
	7,
	6,
	1
};

RenderInfo renderinfo_cloud5 = {
	{
		{NA ,NA ,NA ,NA ,NA ,NA ,"бс","бс","бс","бс",NA ,NA ,NA ,NA ,NA ,NA ,NA ,NA ,},
		{NA ,NA ,NA ,"бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс",NA ,NA ,NA ,NA ,},
		{NA ,NA ,"бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс",NA ,NA ,NA ,},
		{"бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс",NA ,},
		{NA ,"бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс",},
		{NA ,NA ,"бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс",NA ,},
		{NA ,NA ,"бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс","бс",NA ,NA ,},
		{NA ,NA ,NA ,NA ,NA ,"бс","бс","бс","бс","бс","бс","бс",NA ,NA ,NA ,NA ,NA ,NA ,},
	},
	{
		{W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,},
		{W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,},
		{W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,},
		{W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,},
		{W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,},
		{W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,},
		{W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,},
		{W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,W,},
	},
	18,
	8,
	1
};

RenderInfo renderinfo_balloonRed = {
	{
		{NA ,"бс","бс",NA ,},
		{"бс","бс","бс","бс",},
		{"бс","бс","бс","бс",},
		{"бс","бс","бс","бс",},
		{"бс","бс","бс","бс",},
		{"бс","бс","бс","бс",},
		{NA ,"бс","бс",NA ,},
		{NA ,NA ,"бс",NA ,},
		{NA ,NA ,"бс",NA ,},
		{NA ,"бс",NA ,NA ,},
		{NA ,"бс","бс",NA ,},
		{NA ,NA ,"бс",NA ,},
	},
	{
		{R,R,R,R},
		{R,R,R,R},
		{R,R,R,R},
		{R,R,R,P},
		{R,R,R,P},
		{R,R,R,P},
		{R,R,P,R},
		{b,b,b,b},
		{b,b,b,b},
		{b,b,b,b},
		{b,b,b,b},
		{b,b,b,b},
	},
	4,
	12,
	1
};

RenderInfo renderinfo_balloonOrange = {
	{
		{NA ,"бс","бс",NA ,},
		{"бс","бс","бс","бс",},
		{"бс","бс","бс","бс",},
		{"бс","бс","бс","бс",},
		{"бс","бс","бс","бс",},
		{"бс","бс","бс","бс",},
		{NA ,"бс","бс",NA ,},
		{NA ,NA ,"бс",NA ,},
		{NA ,NA ,"бс",NA ,},
		{NA ,"бс",NA ,NA ,},
		{NA ,"бс","бс",NA ,},
		{NA ,NA ,"бс",NA ,},
	},
	{
		{O,O,O,O},
		{O,O,O,O},
		{O,O,O,O},
		{O,O,O,BOX_Ivory},
		{O,O,O,BOX_Ivory},
		{O,O,O,BOX_Ivory},
		{O,O,BOX_Ivory,O},
		{b,b,b,b},
		{b,b,b,b},
		{b,b,b,b},
		{b,b,b,b},
		{b,b,b,b},
	},
	4,
	12,
	1
};

RenderInfo renderinfo_balloonGreen = {
	{
		{NA ,"бс","бс",NA ,},
		{"бс","бс","бс","бс",},
		{"бс","бс","бс","бс",},
		{"бс","бс","бс","бс",},
		{"бс","бс","бс","бс",},
		{"бс","бс","бс","бс",},
		{NA ,"бс","бс",NA ,},
		{NA ,NA ,"бс",NA ,},
		{NA ,NA ,"бс",NA ,},
		{NA ,"бс",NA ,NA ,},
		{NA ,"бс","бс",NA ,},
		{NA ,NA ,"бс",NA ,},
	},
	{
		{G,G,G,G},
		{G,G,G,G},
		{G,G,G,G},
		{G,G,G,BOX_LightGreen},
		{G,G,G,BOX_LightGreen},
		{G,G,G,BOX_LightGreen},
		{G,G,BOX_LightGreen,G},
		{b,b,b,b},
		{b,b,b,b},
		{b,b,b,b},
		{b,b,b,b},
		{b,b,b,b},
	},
	4,
	12,
	1
};

/*
RenderInfo renderinfo_bird = {
	{
		{NA ,NA ,"бс","бс","бс",NA ,"бс","бс","бс",NA ,NA ,},
		{NA ,NA ,"бс","бс","бс",NA ,"бс","бс","бс",NA ,NA ,},
		{"бс","бс","бс","бс","бс","бс","бс","бс","бс","бс",NA ,},
		{NA ,NA ,"бс","бс","бс","бс","бс","бс","бс","бс","бс",},
	},
	{
		{W,W,W,W,W,W,BOX_Gray,BOX_Gray,W,W,W},
		{W,W,W,b,W,BOX_Gray,BOX_Gray,BOX_Gray,BOX_Gray,W,W},
		{b,Y,Y,W,W,BOX_Gray,BOX_Gray,W,W,W,W},
		{W,W,W,W,W,W,W,W,W,W,W},
	},
	11,
	4,
	1
};

*/










