#include "stdafx.h"
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
long long int memo[1000001];
long long int solve(long long int x) {
	if (x == 0) {
		return 0;
	}
	if (x <= 1e6) {
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
	cin >> num;
	memset(memo, -1, sizeof memo);
	cout << solve(num);
	cout << endl;

}

