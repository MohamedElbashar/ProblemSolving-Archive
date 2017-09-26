#include"stdafx.h"
#include <algorithm>
#include <iostream>
#include<string.h>
using namespace std;
char A[2001], B[2001];
int memo[2001][2001], cnt1, cnt2, res[100];
int solve(int x, int y) {
	if (memo[x][y] != -1)
		return memo[x][y];
	if (x == cnt1) {
		int ret = cnt2 - y;
		memo[x][y] = ret;
		return ret;
	}
	if (y == cnt2) {
		int ret = cnt1 - x;
		memo[x][y] = ret;
		return ret;
	}
	if (A[x] == B[y]) {
		int ret = solve(x + 1, y + 1);
		memo[x][y] = ret;
		return ret;
	}
	int res[3];
	res[0] = solve(x + 1, y) + 1;
	res[1] = solve(x, y + 1) + 1;
	res[2] = solve(x + 1, y + 1) + 1;
	int mn = res[0];
	for (int i = 1; i < 3; i++) {
		if (mn > res[i]) {
			mn = res[i];
		}
	}
	memo[x][y] = mn;
	return mn;
}

int main() {
	int Numcases;
	cin >> Numcases;
	for (int i = 0; i < Numcases; i++) {
		cin >> A;
		cin >> B;
		cnt1 = 0, cnt2 = 0;
		memset(memo, -1, sizeof memo);
		for (cnt1 = 0; cnt1 < 2001; cnt1++) {
			if (A[cnt1] == '\0')
				break;
		}
		for (cnt2 = 0; cnt2 < 2001; cnt2++) {
			if (B[cnt2] == '\0')
				break;
		}
		res[i] = solve(0, 0);
	}
	for (int i = 0; i < Numcases; i++) {
		cout << res[i] << endl;
	}
}

