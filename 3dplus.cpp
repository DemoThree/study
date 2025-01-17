#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <cstring>
#include <math.h>
#define CUBE_WIDTH 10
#define WIDTH 160
#define HEIGHT 44

// 全局变量声明
extern float zbuffer[];
extern char buffer[];
extern  char BACKGROUND_CHAR;
extern  int PROPORTION;
extern  int FROM_CAM;
extern float X, Y, Z;
extern float A, B, C;
extern int two_dimension_x, two_dimension_y;
extern float depth;
extern float INCREASE;

// 函数声明
float calcX(int x, int y, int z);
float calcY(int x, int y, int z);
float calcZ(int x, int y, int z);
void surface(float cubeX, float cubeY, float cubeZ, char ch);


// Created on iPad.
static int indexs = 0;
// 计算每个表面上的值
float DEEPTH;
void surface(float i, float j, float k, char ch) {
    // 根据变换函数求出变换后的坐标
    X = calcX(i, j, k);
    Y = calcY(i, j, k);
    Z = calcZ(i, j, k) + FROM_CAM;

    // 开始想办法压缩到二维平面里面
    // 使用z-suffer算法，目的就是根据z值去进行压缩
    DEEPTH = 1 / Z;
    // 假设压缩后的二维坐标为 two_dimension_x, two_dimension_y
    two_dimension_x = (int) (WIDTH / 2 + PROPORTION * DEEPTH * X * 2); // 变大可以获取更好的视野
    two_dimension_y = (int) (HEIGHT / 2 + PROPORTION * DEEPTH * Y);
    // 然根据这个坐标来进行判断
    indexs = two_dimension_x + two_dimension_y * WIDTH;
    // 数组不越界
    if (indexs >= 0 && indexs < WIDTH * HEIGHT) {
        // z- buffer算法，z小的遮挡z大的
        if (DEEPTH > zbuffer[indexs]) {
            // 被遮挡
            zbuffer[indexs] = DEEPTH;
            buffer[indexs] = ch;
        }
    }
}

// 全局变量定义
float zbuffer[WIDTH * HEIGHT];
char buffer[WIDTH * HEIGHT];
char BACKGROUND_CHAR = ' ';
int PROPORTION = 30;
int FROM_CAM = 50;
float X, Y, Z;
float A, B, C;
int two_dimension_x, two_dimension_y;
float depth;
float INCREASE = 0.5f;

/// @brief calcX
/// @param i 
/// @param j 
/// @param k 
/// @return spining-cube's coordinate of X 
float calcX(int i, int j, int k) {
    return j * sin(A) * sin(B) * cos(C) - k * cos(A) * sin(B) * cos(C) +
           j * cos(A) * sin(C) + k * sin(A) * sin(C) + i * cos(B) * cos(C);
}

/// @brief calcY
/// @param i 
/// @param j 
/// @param k 
/// @return spining-cube's coordinate of Y
float calcY(int i, int j, int k) {
    return j * cos(A) * cos(C) + k * sin(A) * cos(C) +
           j * sin(A) * sin(B) *  sin(C) + k * cos(A) * sin(B) * sin(C) -
           i * cos(B) * sin(C);  
}

/// @brief calcZ
/// @param i 
/// @param j 
/// @param k 
/// @return spining-cube's coordinate of Z
float calcZ(int i, int j, int k) {
    return k * cos(A) * cos(B) - j * sin(A) * cos(B) + i * sin(B);
}

int main() {
    // clear函数
    printf("\x1b[2J");
    while (true) {
        memset(buffer, BACKGROUND_CHAR, WIDTH * HEIGHT);
        memset(zbuffer, 0, WIDTH * HEIGHT * sizeof(float));
        for (float xStart = -CUBE_WIDTH; xStart < CUBE_WIDTH; xStart += INCREASE) {
            for (float yStart = -CUBE_WIDTH; yStart < CUBE_WIDTH; yStart += INCREASE) {
                surface(xStart, yStart, -CUBE_WIDTH, '.');
                surface(xStart, yStart, CUBE_WIDTH, '#');
                surface(xStart, -CUBE_WIDTH, yStart, '*');
                surface(xStart, CUBE_WIDTH, yStart, '&');
                surface(-CUBE_WIDTH, xStart, yStart, '?');
                surface(CUBE_WIDTH, xStart, yStart, '@');
            }
        }
        printf("\x1b[H");
        
        // 记得换行
        for(int z = 0; z < WIDTH * HEIGHT; z++){
        putchar(z % WIDTH ? buffer[z] : '\n');
      }
        A += 0.005;
        B += 0.005;
        usleep(3000);
    }
}