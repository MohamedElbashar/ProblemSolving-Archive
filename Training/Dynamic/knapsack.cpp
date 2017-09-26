#include "stdafx.h"
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int capacity;
int NumLines;
int siz[2001];
int valu[2001];
int memo[2001][2001];
int solve(int i, int value) {
	if (i == NumLines)
		return 0;
	if (memo[i][value] != -1)
		return memo[i][value];
	int ret1 = solve(i + 1, value);
	int ret2 = 0;
	if (siz[i]+value <= capacity)
		ret2 = solve(i + 1, value + siz[i]) + valu[i];
	return memo[i][value] = max(ret1, ret2);
}
int main() {
	memset(memo, -1, sizeof memo);
	cin >> capacity >> NumLines;
	for (int i = 0; i < NumLines && cin >> siz[i] >> valu[i]; i++)
		;
	cout << solve(0,0);
	cout << endl;
}

