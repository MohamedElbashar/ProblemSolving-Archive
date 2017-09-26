#include "stdafx.h"
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
char A[100], B[100];
int memo[100][100], cnt1, cnt2;


int solve(int i, int j) {
	int ret, res;
	if (i == cnt1 || j == cnt2)
		return 0;
	if (memo[i][j] != -1)
		return memo[i][j];
	if (A[i] == B[j])
		return ret = solve(i + 1, j + 1) + 1;
	else {
		int ret1 = solve(i, j + 1);
		int ret2 = solve(i + 1, j);
		return res = max(ret1, ret2);
	}
	return memo[i][j] = max(res, ret);

}
int main() {
	cin >> A;
	cin >> B;
	memset(memo, -1, sizeof memo);
	for (cnt1 = 0; cnt1 < 100; cnt1++) {
		if (A[cnt1] == '\0')
			break;
	}
	for ( cnt2 = 0; cnt2 < 100; cnt2++) {
		if (B[cnt2] == '\0')
			break;
	}
	int res = solve(0, 0);
	cout << res << endl;
	return 0;
}

