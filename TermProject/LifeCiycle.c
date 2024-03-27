#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <ctype.h>
#include <math.h>
#include "screen_control.h"
#include "graphic.h"
#include "number_print.h"
#include "timer.h"	
#include "screen.h"

#define _Color_Yellow_ "EE"
#define _Color_Orange_ "CC"
#define _Color_Blue_ "11"
#define _Color_SkyBlue_ "BB"
#define _Color_Green_ "22"

#define _stairsAmount_ 25 // 계단 갯수
#define _wayChangeProperty_ 4 // 계단의 방향이 바뀌는 빈도 
#define _maxTime_ 10000 // 초기 제한시간
#define _startX_ SCREEN_WIDTH / 2
#define _startY_ 92
#define _cloudAmount_ 10

object objects_stairs[_stairsAmount_]; //계단
object objects_clouds[_cloudAmount_]; //구름
object object_player; //플레이어
object object_sun; //태양
object object_balloon; //풍선

object object_PRESS_R; //글자 : PRESS R
object object_TO_RESTART; // 글자 : TO RESTART
object object_SCORE_Colon; // 글자 : SCORE :

object object_GO;
object object_UP_EXEX;
object object_PRESS_W;
object object_TO_START;
object object_UpArrow;
object object_SideArrow;
object object_W;
object object_SPACE;

object object_timer;

NumberObject numberObject_score; // 인게임 점수
NumberObject numberObject_overScore; // 게임 오버 점수

RenderInfo playerSprites[2];
RenderInfo playerUpSprites[2];
RenderInfo cloudsSprites[6];

Timer timer_gameOver; //게임 오버 루틴 시간
Timer timer_playerDrop; //플레이어 떨어지는 애니매이션 시간
Timer timer_leftTime; // 계단을 올라가야하는 남은 시간
Timer timer_playerUp; // 계단을 올라가는 애니매이션 시간
Timer timer_BallonMove;
Timer timer_BirdMove;

//게임 상태
enum GameState {
	state_inGame = 0, //인게임
	state_gameOver = 1, //게임 오버
	state_beforeStart = 2, //게임 오버후 다시시작하기 전
	state_FirstStart = 3, //r게임 처음시작할때
};

enum GameState gameState = state_FirstStart; // 게임상태

int score; //점수
int topStairIndex; //가장 위에있는 계단 index
int stdStairIndex; //기준 계단 index
int buildWay = 1; //계단을 쌓을 방향
int playerSpriteIndex = 0; //플레이어 스프라이트 인덱스
int playerWay = -1; // 플레이어가 바라보는 방향 , -1 : 왼쪽
int isOnUpAnime = 0; // 계단을 올라가는 애니메이션이 실행중인지
int scoreOfStair0 = 1;

void OnEnd();
void Render();

void BuildStair(int index);
int Mod(int n, int x);
void StairUp();
void OnStairUp();
void SetGameStart();
void GameOver();
void WaitRestart();
void CloudControl();
void CloudSetting();
void BalloonSetting();
void BalloonControl();

void OnAwake() {

	srand(time(NULL));

	score = 0;
	playerSprites[0] = renderinfo_playerLeft;
	playerSprites[1] = renderinfo_playerRight;

	playerUpSprites[0] = renderinfo_playerClimbingLeft;
	playerUpSprites[1] = renderinfo_playerClimbingRight;

	cloudsSprites[0] = renderinfo_cloud0;
	cloudsSprites[1] = renderinfo_cloud1;
	cloudsSprites[2] = renderinfo_cloud2;
	cloudsSprites[3] = renderinfo_cloud3;
	cloudsSprites[4] = renderinfo_cloud4;
	cloudsSprites[5] = renderinfo_cloud5;

	NumberPrint_Set();
}

void OnStart() {


	// ============ 오브젝트 생성 ==============
	for (int i = 0; i < _stairsAmount_; i++) //계단 생성
		objects_stairs[i] = Object_Make(renderinfo_bigStair);
	object_player = Object_Make(renderinfo_playerLeft);

	for (int i = 0; i < _cloudAmount_; i++) {
		int k = rand() % 6;
		objects_clouds[i] = Object_Make(cloudsSprites[k]);
	}

	object_sun = Object_Make(renderinfo_sun);
	object_balloon = Object_Make(renderinfo_balloonRed);

	object_PRESS_R = Object_Make(renderinfo_PREES_R);
	object_TO_RESTART = Object_Make(renderinfo_TO_RESTART);
	object_SCORE_Colon = Object_Make(renderinfo_SCORE_Colon);

	object_GO = Object_Make(renderinfo_GO);
	object_UP_EXEX = Object_Make(renderinfo_UP_EXEX);
	object_GO = Object_Make(renderinfo_GO);
	object_PRESS_W = Object_Make(renderinfo_PRESS_W);
	object_TO_START = Object_Make(renderinfo_TO_START);
	object_UpArrow = Object_Make(renderinfo_UpArrow);
	object_SideArrow = Object_Make(renderinfo_SideArrow);
	object_W = Object_Make(renderinfo_W);
	object_SPACE = Object_Make(renderinfo_SPACE);

	object_timer = Object_Make(renderinfo_timer);	

	numberObject_score = NumberObject_Make(0, SCREEN_WIDTH / 2 - 2, 8);
	numberObject_overScore = NumberObject_Make(0, 80, 22);

	timer_gameOver = Timer_Make(1000);
	timer_playerDrop = Timer_Make(70);
	timer_leftTime = Timer_Make(10000);
	timer_playerUp = Timer_Make(50);
	timer_BallonMove = Timer_Make(200);
	timer_BirdMove = Timer_Make(200);

	//  ============ 오브젝트 설정 ==============

	for (int i = 0; i < _cloudAmount_; i++) {
		int k = rand() % 6;
		Object_ChangePostion(&objects_clouds[i], 0, -20);
		Object_SetEnable(&objects_clouds[i], 0);
	}
	Object_ChangePostion(&object_balloon, 0, -30);
	Object_SetEnable(&object_balloon, 0);

	Object_ChangePostion(&object_PRESS_R, 30, 42);
	Object_ChangePostion(&object_TO_RESTART, 18, 49);
	Object_ChangePostion(&object_SCORE_Colon, 18, 22);
	Object_ChangePostion(&object_GO,26,11);
	Object_ChangePostion(&object_UP_EXEX,56,11);
	Object_ChangePostion(&object_PRESS_W,24,39);
	Object_ChangePostion(&object_TO_START,24,47);
	Object_ChangePostion(&object_W, 14, 83);
	Object_ChangePostion(&object_SPACE, 60, 83);

	Object_ChangePostion(&object_SideArrow, 70, 72);
	Object_ChangePostion(&object_UpArrow, 14, 72);

	Object_ChangePostion(&object_sun, 82,13);

	Object_ChangePostion(&object_timer, 22, 3);

	NumberObject_SetColor(&numberObject_overScore, _Color_SkyBlue_);

	SetGameStart();
	CloudSetting();
	gameState = state_FirstStart;
}

void Update() {
	switch (gameState)
	{
	case state_inGame: {
		if (Timer_IsTimeUp(&timer_leftTime))
			GameOver();	
		if (Timer_IsTimeUp(&timer_BallonMove) && object_balloon.renderinfo.enable == 1) {
			Object_Move(&object_balloon, 0, -10);
			Timer_Reset(&timer_BallonMove);
		}

		break;
	}
	case state_gameOver: {
		if (Timer_IsTimeUp(&timer_gameOver)) {
			WaitRestart();
		}
		else {
			if (Timer_IsTimeUp(&timer_playerDrop)) {
				Timer_Reset(&timer_playerDrop);
				Object_Move(&object_player, 0, 5);
			}
		}
		break;
	}
	case state_beforeStart: {


		break;
	}
	
	default:
		break;
	}
}

void KeyProcess(char _ch) {

	switch (gameState)
	{
	case state_FirstStart:
	{
		switch (_ch) {

		case 'w':
			SetGameStart();
			break;
		}
	}
	break;

	case state_inGame : 
	{
		switch (_ch)
		{

		case 'w': // 위로 오르기
		{
			if (objects_stairs[Mod(_stairsAmount_, stdStairIndex + 1)].postion.x -
				objects_stairs[stdStairIndex].postion.x == playerWay * 16) {
				StairUp();
				NumberObject_SetValue(&numberObject_score, score);
				if (score == 10 || score == 100 || score == 1000) 
					NumberObject_ChangePostion(&numberObject_score,
						numberObject_score.postion.x - 4, numberObject_score.postion.y);
				OnStairUp();	
			}
			else {
				Object_Move(&object_player, playerWay * 16, -4);
				GameOver();
			}
			break;
		}

		case 32: // 스페이스바 : 방향 바꾸면서 오르기
		{
			playerSpriteIndex = !playerSpriteIndex;
			Object_SetRenderInfo(&object_player, playerSprites[playerSpriteIndex]);
			playerWay *= -1;
			if (objects_stairs[Mod(_stairsAmount_, stdStairIndex + 1)].postion.x -
				objects_stairs[stdStairIndex].postion.x == playerWay * 16) {
				StairUp();
				NumberObject_SetValue(&numberObject_score, score);
				if (score == 10 || score == 100 || score == 1000) NumberObject_ChangePostion(&numberObject_score,
					numberObject_score.postion.x - 4, numberObject_score.postion.y);
				OnStairUp();
		
			}
			else {
				Object_Move(&object_player, playerWay * 16, -4);
				GameOver();
			}
			break;
		}

		case 'd': // 자동으로 올라가기
			if (objects_stairs[Mod(_stairsAmount_, stdStairIndex + 1)].postion.x -
				objects_stairs[stdStairIndex].postion.x == playerWay * 16)
			{			
				StairUp();
				NumberObject_SetValue(&numberObject_score, score);
				if (score == 10 || score == 100 || score == 1000)
					NumberObject_ChangePostion(&numberObject_score,
						numberObject_score.postion.x - 4, numberObject_score.postion.y);
				OnStairUp();
			}	
			else
			{	
				playerSpriteIndex = !playerSpriteIndex;
				Object_SetRenderInfo(&object_player, playerSprites[playerSpriteIndex]);
				playerWay *= -1;

				StairUp();
				NumberObject_SetValue(&numberObject_score, score);
				if (score == 10 || score == 100 || score == 1000) NumberObject_ChangePostion(&numberObject_score,
					numberObject_score.postion.x - 4, numberObject_score.postion.y);
				OnStairUp();
			}
			break;
		case 'b' :
		{
			BalloonSetting();
			break;
		}

		default:
			break;
		}
	}
	break;


	case state_gameOver :
	{
		switch (_ch)
		{
		case 'r':
			SetGameStart();
			break;
		default:
			break;
		}
	}
	break;

	case state_beforeStart:
	{
		switch (_ch)
		{
		case 'r':
			SetGameStart();
			break;
		default:
			break;
		}
	}
	break;


	default:
		break;
	}
}

void OnEnd() {
	
}

void Render() {	

	Screen_BufferClear();
	//========================
	switch (gameState)
	{
	case state_FirstStart:
	{

		Drow_Box(45, 22, 10, 3, "CC");
		Drow_Box(43, 20, 12, 4, "EE");
		Object_Print(&object_GO);
		Object_Print(&object_UP_EXEX);
		
		Drow_Box(34, 17, 20, 37, "CC");
		Drow_Box(32, 15, 22, 38, "EE");

		Object_Print(&object_PRESS_W);
		Object_Print(&object_TO_START);

		Object_Print(&object_UpArrow);
		Object_Print(&object_SideArrow);

		Drow_Box(9, 9, 10, 81, "CC");
		Drow_Box(7, 7, 12, 82, "EE");
		Object_Print(&object_W);

		Drow_Box(23, 9, 56, 81, "CC");
		Drow_Box(21, 7, 58, 82, "EE");
		Object_Print(&object_SPACE);

		break;
	}
	break;

	case state_inGame:
	{		
		Object_Print(&object_sun);
		for (int i = 0; i < _cloudAmount_; i++) {
			Object_Print(&objects_clouds[i]);
		}
		for (int i = 0; i < _stairsAmount_; i++)
			Object_Print(&objects_stairs[i]);
		Object_Print(&object_player);
		Object_Print(&object_balloon);
		NumberObject_Print(&numberObject_score);

		Object_Print(&object_timer);
		Drow_Box((int)(30 * ((double)Timer_GetLeftTime(&timer_leftTime)/ Timer_GetMaxTime(&timer_leftTime))), 2,
			24, 4, _Color_Yellow_);	
	}
	break;

	case state_gameOver:
	{
		for (int i = 0; i < _stairsAmount_; i++)
			Object_Print(&objects_stairs[i]);
		Object_Print(&object_player);
		NumberObject_Print(&numberObject_score);
	}
	break;

	case state_beforeStart:
	{
		for (int i = 0; i < _stairsAmount_; i++)
			Object_Print(&objects_stairs[i]);

		Drow_Box(44, 10, 10, 19, "CC");
		Drow_Box(42, 8, 12, 20, "EE");
		Object_Print(&object_SCORE_Colon);
		NumberObject_Print(&numberObject_overScore);

		Drow_Box(42, 18, 14, 39, "CC");
		Drow_Box(40, 16, 16, 40, "EE");
		Object_Print(&object_PRESS_R);
		Object_Print(&object_TO_RESTART);
	}
	break;

	default:
		break;
	}
	
	
	//========================
	Screen_BufferFilp();
}


//계단 쌓기
void BuildStair(int index) {

	if (!(rand() % _wayChangeProperty_)) buildWay *= -1;

	Object_ChangePostion(&objects_stairs[index],
		objects_stairs[topStairIndex].postion.x + 16 * buildWay, objects_stairs[topStairIndex].postion.y - 4);

	topStairIndex = Mod(_stairsAmount_, topStairIndex + 1);	
}

// 모듈러 연산
int Mod(int n, int x) {
	if (n <= 0) return 0;
	else if (x < 0) {
		return n - Mod(n, -1 * x);
	}
	else {
		return x % n;
	}
}

// 계단 올라가기
void StairUp() {
	int moveX = 0;
	if (score > 9) {
		BuildStair(Mod(_stairsAmount_, topStairIndex + 1)); //점수가 10보다 클때만 쌓기
	}

	stdStairIndex = Mod(_stairsAmount_, stdStairIndex + 1); // 기준 계단 + 1

	//카메라 위치 계산
	moveX = objects_stairs[Mod(_stairsAmount_, stdStairIndex - 1)].postion.x
		- objects_stairs[stdStairIndex].postion.x;

	if (score <= 10) {
		for (int i = 0; i < _stairsAmount_; i++) // 기준 계단으로 카메라 고정
			Object_Move(&objects_stairs[i], moveX, 0);
		Object_Move(&object_player, 0, -4);
	}
	else {
		for (int i = 0; i < _stairsAmount_; i++) // 기준 계단으로 카메라 고정
			Object_Move(&objects_stairs[i], moveX, 4);
	}
		


	score++;
}

// 계단을 올라간 후
void OnStairUp() {
	Timer_AddTime(&timer_leftTime, 1000);
	if (Timer_GetMaxTime(&timer_leftTime) > 100) {
		if(score <= 100 )
			Timer_SetMaxTime(&timer_leftTime, Timer_GetMaxTime(&timer_leftTime) - 50);
		else if(score <= 200)
			Timer_SetMaxTime(&timer_leftTime, Timer_GetMaxTime(&timer_leftTime) - 20);
	}	
	
	scoreOfStair0++;

	if (Timer_GetLeftTime(&timer_leftTime) >= Timer_GetMaxTime(&timer_leftTime))
		Timer_Reset(&timer_leftTime);

	CloudControl();
	BalloonControl();

	if (score % 2 == 0 && score > 10) {
		for (int i = 0; i < _stairsAmount_; i++) {
			if (objects_clouds[i].renderinfo.enable == 1)
				Object_Move(&objects_clouds[i], 0,2);
		}
	}		//Object_Move(&object_sun,0,1);
}

// 게임 시작 세팅
void SetGameStart() {
	gameState = state_inGame;
	score = 0;
	playerWay = -1;
	buildWay = 1;
	playerSpriteIndex = 0;

	Timer_Reset(&timer_leftTime);

	Object_ChangePostion(&objects_stairs[0], _startX_, _startY_);
	Object_ChangePostion(&objects_stairs[1], _startX_ - 16, _startY_ - 4);
	stdStairIndex = 0;
	topStairIndex = 1;

	for (int i = 2; i < _stairsAmount_; i++) //계단 생성
		BuildStair(i);

	Object_SetRenderInfo(&object_player, playerSprites[playerSpriteIndex]);
	Object_ChangePostion(&object_player, _startX_ + 2, _startY_ - 12);

	Object_SetEnable(&object_balloon, 0);
	Object_ChangePostion(&object_balloon, 0, SCREEN_HEIGHT + 4);

	NumberObject_SetValue(&numberObject_score, score);
	numberObject_score = NumberObject_Make(0, SCREEN_WIDTH / 2 - 2, 8);
}

//게임 오버됬을때
void GameOver() {
	gameState = state_gameOver;
	Render();
	Sleep(450);
	Timer_Reset(&timer_gameOver);
	Timer_Reset(&timer_playerDrop);

	Timer_SetMaxTime(&timer_leftTime, _maxTime_);
	Timer_Reset(&timer_leftTime);
}

//게임 재시작 대기 상태로 만들기
void WaitRestart() {
	NumberObject_ChangePostion(&numberObject_overScore, 80, 22);
	NumberObject_SetValue(&numberObject_overScore,score);
	NumberObject_SetColor(&numberObject_overScore, _Color_SkyBlue_);
	if (score >= 10)
		NumberObject_Move(&numberObject_overScore, -8, 0);
	else if (score >= 100)
		NumberObject_Move(&numberObject_overScore, -16, 0);
	else if (score >= 1000)
		NumberObject_Move(&numberObject_overScore, -24, 0);
	gameState = state_beforeStart;
	//SetGameStart();
}

void CloudSetting(){
	int k;
	for (int i = 0; i < _cloudAmount_; i++) {
		k = rand() % 3;
		if (k == 0) {
			int x = rand() % (SCREEN_WIDTH / 2 - 4);
			int y = rand() % (SCREEN_HEIGHT / 2);
			int j = rand() % 6;
			Object_SetRenderInfo(&objects_clouds[i], cloudsSprites[j]);
			Object_SetEnable(&objects_clouds[i], 1);
			Object_ChangePostion(&objects_clouds[i], x * 2, y);
		}
		else {
			Object_SetEnable(&objects_clouds[i], 0);
			Object_ChangePostion(&objects_clouds[i], 0, -20);
		}
	}
	
}

void CloudControl() {
	int k;
	for (int i = 0; i < _cloudAmount_; i++) {
		if (objects_clouds[i].renderinfo.enable == 0)
		{
			k = rand() % 10;
			if (k == 0) {
				int x = rand() % (SCREEN_WIDTH / 2 - 4);
				int j = rand() % 6;
				Object_SetRenderInfo(&objects_clouds[i], cloudsSprites[j]);
				Object_SetEnable(&objects_clouds[i], 1);
				Object_ChangePostion(&objects_clouds[i],x * 2, -10);
				break;
			}
		}
		else if (objects_clouds[i].postion.y > SCREEN_HEIGHT + 8) {
			Object_SetEnable(&objects_clouds[i], 0);
			Object_ChangePostion(&objects_clouds[i], 0, -20);
		}
	}
}

void BalloonSetting() {
	int k = rand() % 3;
	int x = rand() % (SCREEN_WIDTH - 4) / 2;
	Object_SetEnable(&object_balloon, 1);
	if (k == 0)
		Object_SetRenderInfo(&object_balloon,renderinfo_balloonRed);
	else if(k == 1)
		Object_SetRenderInfo(&object_balloon, renderinfo_balloonOrange);
	else
		Object_SetRenderInfo(&object_balloon, renderinfo_balloonGreen);

	Object_ChangePostion(&object_balloon, x * 2, SCREEN_HEIGHT + 4);
	Timer_Reset(&timer_BallonMove);
}

void BalloonControl() {
	if (object_balloon.postion.y < -10) {
		Object_SetEnable(&object_balloon, 0);
		Object_ChangePostion(&object_balloon, 0, SCREEN_HEIGHT + 4);
	}
	
	else if(object_balloon.renderinfo.enable == 0) {
		int k = rand() % 20;
		if (k == 0) BalloonSetting();
	}
}