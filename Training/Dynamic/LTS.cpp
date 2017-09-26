#include "stdafx.h"
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int m;
int arr[100];
int memo[100][100];
int ans[100];
int solve(int ind, int prev)
{
	if (ind == m)
		return 0;
	if (memo[ind][prev] != -1)
		return memo[ind][prev];
	int ret1 = solve(ind+1,prev);
	int ret2 = 0;
	if (arr[ind] > arr[prev])
	{
		ret2 = 1 + solve(ind + 1, ind);
	}
	return  memo[ind][prev]=max(ret1, ret2);
}
int main()
{
	memset(memo, -1, sizeof memo);
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> arr[i];
	}
	int res=solve(0,-1);
	cout << res << endl;
}

