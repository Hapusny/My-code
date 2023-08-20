#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

#define ROW 3
#define COL 3

void screen1();
void board(char pieces[ROW][COL],int row,int col);
int place_p(char pieces[ROW][COL], int choice);
void place_c(char pieces[ROW][COL]);
int judge_p(char pieces[ROW][COL]);
int judge_c(char pieces[ROW][COL]);
int judge(char pieces[ROW][COL]);