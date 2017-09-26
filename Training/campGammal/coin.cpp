#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<cstdio>
#include<stdint.h>
#include<typeinfo>
#include<vector>
#include<set>
using namespace std;
int num;
int memo[1000001];
int ret;
int solve(int x)
{
	if (x == 0) {
		return 0;
	}
	if (memo[x] != -1) {
		return memo[x];
	}
	if (x <= 1000000) {
		return memo[x] = max(x, solve(x / 2) + solve(x / 3) + solve(x / 4));
	}

	else {
		return  max(x, solve(x / 2) + solve(x / 3) + solve(x / 4));
	}


}
int main()
{
	cin >> num;
	memset(memo, -1, sizeof memo);
	cout << solve(num);

}

