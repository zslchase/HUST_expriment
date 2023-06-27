#ifndef HELLODPLL_H_INCLUDED
#define HELLODPLL_H_INCLUDED

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <iostream>
#include <ctime>
#include <algorithm>
#include <fstream>
#define OK 1
#define ERROR 0
using namespace std;

int sudoku_begin[9][9];
int sudoku_dig[9][9];
int line_mark[9][10];
int row_mark[9][10];
int unit_mark[3][3][10];
int sudoku_solution[730];
int holes_mark[82][2];
int RESULT[5000];
int times[5000],maxtimes[5000],pos[5000],neg[5000];   
int SUM_SOLUTION;

int INDEX;
int m,n;


typedef struct node
{
    int data;
    struct node* next;
} node;

typedef struct LIST
{
    struct node* head;
    int length;
    struct LIST* NEXT;
} LIST;

LIST* HEAD;
FILE* fp;
clock_t Start1,End1;

LIST* single(LIST* HEAD);
LIST *Copy(LIST *L);
LIST* add(LIST* HEAD, int value);
LIST* deletelist(LIST* HEAD);
LIST* deletenode(LIST* HEAD, int value);
int DELETE_(LIST* HEAD, int value);
int empty(LIST* HEAD);
int DPLL(LIST* HEAD, int* RESULT,int maxtimes[]);
int dig_mark(int x,int y,int value);
int re_dig_mark(int x,int y,int value);
int show();
int ass(int x,int y,int value,int index);
void dfs(int x,int y);
int singlesolution();
void createStartinggrid(int num);
int Digit(int a[][9], int x, int y);
void randomFirstRow(int a[], int n);
void createSudoku(int a[][9]);
void print();
int ToCnf(int a[][9],int holes);
int CNF_TRANSLATER_SUDOKU();
int find_solution();
int CNF_TRANSLATER();
int SAT_FUNCTION();
int SUDOKU_FUNCTION();

void setColor(unsigned short ForeColor=7,unsigned short BackGroundColor=0)
{
HANDLE handle=GetStdHandle(STD_OUTPUT_HANDLE);//获取当前窗口句柄
SetConsoleTextAttribute(handle,ForeColor+BackGroundColor*0x10);//设置颜色
}

void SetPos(int x,int y)
{
    COORD pos;
    HANDLE handle;
    pos.X=x;
    pos.Y=y;
    handle=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(handle,pos);
}


#endif // HELLODPLL_H_INCLUDED