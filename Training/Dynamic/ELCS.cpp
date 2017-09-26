#include "stdafx.h"
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
char A[100], B[100], cnt1, cnt2;
int memo[100][100];
int res = 0;
int ret = 0;
int solve(int i, int j)
{
	if (i == cnt1 || j == cnt2)
		return 0;
	if (memo[i][j] != -1)
		return memo[i][j];
	if (A[i] == B[j])
		ret = solve(i + 1, j + 1) + 1;
	if (A[i] != B[j])
	{
		int res = 0;
		int ret1 = solve(i + 1, j);
		int ret2 = solve(i, j + 1);
		return res = max(ret1, ret2);
	}
	return memo[i][j] = max(ret, res);
}
int main()
{
	memset(memo, -1, sizeof memo);
	cin >> A;
	cin >> B;
	for (cnt1 = 0; cnt1 < 100; cnt1++)
	{
		if (A[cnt1] == '\0')
			break;
	}
	for (cnt2 = 0; cnt2 < 100; cnt2++)
	{
		if (B[cnt2] == '\0')
			break;
	}
	cout << solve(0, 0);
	cout << endl;
}

