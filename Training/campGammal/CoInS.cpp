#include <iostream>
#include <algorithm>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<cstdio>
#include<stdint.h>
#include<typeinfo>
#include<vector>
#include<set>
using namespace std;
long long int num;
long long int memo[10000001];
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#else
	// online submission
	//freopen("sets.in", "r", stdin);
#endif
}
long long int solve(long long int x) {
	if (x == 0) {
		return 0;
	}
	if (x <= 1e7) {
		if (memo[x] != -1) {
			return memo[x];
		}
		return memo[x] = max(x, solve(x / 2) + solve(x / 3) + solve(x / 4));
	}

	else {
		return max(x, solve(x / 2) + solve(x / 3) + solve(x / 4));
	}

}
int main() {
	file();
	memset(memo, -1, sizeof memo);
	while (scanf("%lld", &num) != EOF) {

		cout << solve(num);
		cout << endl;
	}

}

