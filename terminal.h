#include <stdio.h>
#include <unistd.h>

/* Cursor setting */
//清屏
#define CLEAR() printf("\033[2J")

//上移光标
#define MOVE_UP(x) printf("\033[%dA", (x))

// 下移光标
#define MOVE_DOWN(x) printf("\033[%dB"), (x)

// 左移光标
#define MOVE_LEFT(y) printf("\033[%dD", (y))

// 右移光标
#define MOVE_RIGHT(y) printf("\033[%dC", (y))

// 定位光标， 将光标移动到第几行第几列，终端是从第一行第一列开始的，没有0行0列
#define MOVE_TO(row, colum) printf("\033[%d;%dH", (row), (colum))

// 讲光标定位到坐标（x，y）位置，从（0,0）开始
#define GOTO_XY(x,y) MOVE_TO(y+1,x+1)

//光标复位
#define CURSOR_RESET() printf("\033[H")

// 隐藏光标
#define CURSOR_HIDE() printf("\033[?25l")

// 显示光标
#define CURSOR_SHOW() printf("\033[?25h")

// 反显
#define HIGH_LIGHT() printf("\033[7m")
#define UN_HIGH_LIGHT() printf("\033[27m")

/* Color setting*/

//设置颜色
#define SET_FRONT_COLOR(color) printf("\033[%dm", (color))
#define SET_BACKGROUND_COLOR(color) printf("\033[%dm", (color))

//前景色
#define FRONT_BLAXK       30
#define FRONT_RED         31
#define FRONT_GREEN       32
#define FRONT_YELLOW      33
#define FRONT_BLUE        34
#define FRONT_PURPLE      35
#define FRONT_DEEP_GREEN  36
#define FRONT_WHITE       37

//背景色
#define BACKGROUND_BLACK       40
#define BACKGROUND_RED         41
#define BACKGROUND_GREEN       42
#define BACKGROUND_YELLOW      43
#define BACKGROUND_BLUE        44
#define BACKGROUND_PURPLE      45
#define BACKGROUND_DEEP_GERRN  46
#define BACKGROUND_WHITE       47