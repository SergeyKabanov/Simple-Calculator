#pragma once
#include <limits.h>
//###########################################################################################################################################
// Colors:
#define BLACK			RGB(0,0,0)
#define LIGHTBLUE		RGB(0,0,255)
#define BLUE            RGB(0,0,160)
#define GREEN			RGB(0,255,0)
#define DARK_GREEN		RGB(0,128,0)
#define CYAN			RGB(0,255,255)
#define DARK_CYAN		RGB(0,128,128)
#define RED				RGB(255,0,0)
#define MAGENTA			RGB(255,0,255)
#define BROWN			RGB(165,42,42)
#define LIGHT_BROWN		RGB(255,142,142)
#define GRAY			RGB(128,128,128)
#define LIGHTGRAY		RGB(211,211,211)
#define DARKGRAY		RGB(169,169,169)
#define LIGHTGREEN		RGB(144,255,144)
#define LIGHTCYAN		RGB(0,255,255)
#define YELLOW			RGB(255,255,0)
#define WHITE			RGB(255,255,255)
#define SALAD			RGB(0,128,128)
#define LIGHTSALAD		RGB(174,255,190)
#define PURPLE			RGB(128,0,128)
#define LIGHTPURPLE		RGB(192,0,128)
#define LIGHT_LIGHT_GREEN RGB(200,200,180)
#define GRAY_BLUE       RGB(192,160,212)
//#############################################################################################################################################
#define SAFE_CHAR_ARRAY_SIZE 15
#define MAX_DIGITS_POSSIBLE 10
//#############################################################################################################################################
typedef enum E_ACTION
{
	E_ACTION_NONE,
	E_ACTION_PLUS,
	E_ACTION_MINUS,
	E_ACTION_MUL,
	E_ACTION_DIV,
	E_ACTION_EQUAL,
	E_ACTION_COUNT
} T_ACTION;
//#############################################################################################################################################
