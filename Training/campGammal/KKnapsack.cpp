#include"stdafx.h"
#include <algorithm>
#include <iostream>
#include<string.h>
using namespace std;
char A[2001], B[2001];
int memo[2001][2001], cnt1, cnt2, res[100];
int solve(int x, int y) {
	if (x == cnt1)
		return cnt2 - y;
	if (y == cnt2)
		return cnt1 - x;
	if (A[x] == B[y]) {
		return solve(x + 1, y + 1);
	} else {
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
		return memo[x][y] = mn;
	}
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

