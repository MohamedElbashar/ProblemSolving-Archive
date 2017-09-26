#include "stdafx.h"
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int N;
int arr[101];
int memo[101][101];
int solve(int i, int prev)
{
	if (i == N + 1)
		return 0;
	if (memo[i][prev] != -1)
		return memo[i][prev];

	int ret1 = solve(i + 1, prev);
	int ret2 = 0;
	if (arr[i] >= arr[prev])
		ret2 = solve(i + 1, i) + 1;
	return memo[i][prev] = max(ret1, ret2);


}
int main()
{
	cin >> N;
	arr[0] = -1;
	memset(memo, -1, sizeof memo);
	for (int i = 0;i < N;i++)
	{
		cin >> arr[i];
	}
	int res = solve(1, 0);
	cout << res << endl;
	return 0;
}

