#pragma once

#include <iostream>
using namespace std;

#include <cstdio>
#include <cstdlib>

#define max_q 20

extern int cnt_solu;
extern int cnt_check;


void place_queen(int,int);
void display_queen(int*,int);
bool collision(int*,int);
