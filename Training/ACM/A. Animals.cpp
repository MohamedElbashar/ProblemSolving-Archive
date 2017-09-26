#include <bits/stdc++.h>
using namespace std;
int n, x, arr[101];
int i;
int mem[101][10001];
int solve(int ind, int food) {
	int ret2, ret1;
	if (food < 0) {
		return -1e9;
	}
	if (food == 0 || ind == n) {
		return 0;
	}
	if(mem[ind][food]!=-1)
	{
		return mem[ind][food];
	}
	ret1 = solve(ind + 1, food);
	ret2 = solve(ind + 1, food - (arr[ind] * (n - ind))) + 1;
	return mem[ind][food]=max(ret1, ret2);

}
int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	memset(mem,-1,sizeof mem);
	cin >> n >> x;

	for (i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << solve(0, x);
}
