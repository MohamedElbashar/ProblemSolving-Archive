#include"stdafx.h"
#include <iostream>
#include<algorithm>
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
int S, N;
int sizOfvalue[2001], value[2001];
int memo[2001][2001];
int solve(int ind, int valuee) {
	if (ind == N)
		return 0;
	if (memo[ind][valuee] != -1)
		return memo[ind][valuee];

	int a = 0, b = 0;
	a = solve(ind + 1, valuee);
	if (valuee + sizOfvalue[ind] <= S) {
		b = solve(ind + 1, valuee + sizOfvalue[ind]) + value[ind];
	}
	memo[ind][valuee] = max(a, b);
}

int main() {
	memset(memo, -1, sizeof memo);
	cin >> S >> N;
	for (int i = 0; i < N && cin >> sizOfvalue[i] >> value[i]; i++)
		;
	cout << solve(0, 0);
	cout << endl;

}
