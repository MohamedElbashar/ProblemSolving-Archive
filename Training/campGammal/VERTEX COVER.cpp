#include "stdafx.h"
#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
#include<string>
using namespace std;
vector<int> arr[100000];
int memo[100000][2];

int solve(int node, int parent, bool flag) {
	if (arr[node].size() == 1 && arr[node][0] == parent)
		return !flag;
	if (memo[node][flag] != -1)
		return memo[node][flag];
	int ret1 = 1;
	int ret2 = 0;
	for (int i = 0; i < arr[node].size(); i++) {
		if (arr[node][i] == parent)
			continue;
		ret1 += solve(arr[node][i], node, 1);
		if (flag) {
			ret2 += solve(arr[node][i], node, 0);
		}
	}
	if (flag)
		ret1 = min(ret1, ret2);
	return memo[node][flag] = ret1;
}
int main() {
	memset(memo, -1, sizeof memo);
	int n, cnt = 0, temp, s, e;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		cin >> s >> e;
		arr[s].push_back(e);
		arr[e].push_back(s);
		if (cnt == 0) {
			temp = s;
			cnt++;
		}
	}
	int ret = solve(temp, 0, 1);
	cout << ret << endl;
}

