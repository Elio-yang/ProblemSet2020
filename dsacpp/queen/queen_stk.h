#pragma once


#include <iostream>
using namespace std;
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include "queen.h"

extern int n_solu;//解的总数
extern int n_check;//尝试的总次数

void place_queen(int);
void display_row(Queen &q,int);

