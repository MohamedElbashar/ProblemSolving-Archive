// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <algorithm>
#include <iostream>
#include<string.h>

using namespace std;

char word[6001];
int memo[6001][6001];
int res[100];
int solve(int i, int j) {
	int x, y;
	if (i >= j)
		return 0;
	if (memo[i][j] != -1) {
		return memo[i][j];
	}
	if (word[i] == word[j]) {
		return solve(i + 1, j - 1);
	}
	else if (word[i] != word[j]) {
		x = solve(i + 1, j) + 1;
		y = solve(i, j - 1) + 1;
		return memo[i][j] = min(x, y);
	}

}

int main(void) {
	int numcases;
	cin >> numcases;
	for (int i = 0;i < numcases;i++)
	{
		cin >> word;
		int cnt = 0;
		memset(memo, -1, sizeof memo);
		for (cnt = 0;cnt < 6001;cnt++)
		{
			if (word[cnt] == '\0')
				break;
		}
		res[i] = solve(0, cnt - 1);
	}

	for (int j = 0;j < numcases;j++)
	{
		cout << res[j] << endl;
	}
	return 0;
}

