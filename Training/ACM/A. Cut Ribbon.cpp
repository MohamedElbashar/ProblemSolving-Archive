#include <bits/stdc++.h>
using namespace std;
int n, a, b, c;
int mem[4001];
int solve(int m) {
	int ret1 = -1e9;
	int ret2 = -1e9;
	int ret3 = -1e9;
	if(m==0)
		{
			return 0;
		}
	if (m < a && m < b && m < c) {
		return -1e9;
	}
	if (mem[m]!=-1)
	{
		return mem[m];
	}

	if (m - a >= 0) {
		ret1 = solve(m - a) + 1;

	}
	if (m - b >= 0) {
		ret2 = solve(m - b) + 1;

	}
	if (m - c >= 0) {
		ret3 = solve(m - c) + 1;
	}
	return mem[m]=max(max(ret1, ret2), ret3);
}
int main() {
	cin >> n >> a >> b >> c;
	memset(mem,-1,sizeof mem);
	cout << solve(n);
}
