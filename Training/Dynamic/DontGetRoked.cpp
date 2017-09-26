#include"stdafx.h"
#include<iostream>
#include<string.h>
#include<string>
#include<algorithm>
using namespace std;
char arr[5][5];
int n;
bool safe(int r, int c)
{
	for (int i = r; i > -1 && arr[i][c]!='X'; i--)
		if (arr[i][c] == 'R')
			return 0;
	for (int j = c; j > -1 && arr[r][j]!='X'; j--)
		if (arr[r][j] == 'R')
			return 0;
	return 1;
}
int solve(int x, int y)
{
	if (y == n) return solve(x + 1, 0);
	if (x == n)return 0;
	int ret = 0;
	if (arr[x][y] == '.'&&safe(x, y)) {
		arr[x][y] = 'R';
		ret = 1 + solve(x, y+1);
		arr[x][y] = '.';
	}
	ret = max(ret, solve(x, y + 1));
	return ret;

}
int main() {
	cin >> n;
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			cin >> arr[i][j];

	}
	int res = solve(0, 0);
	cout << res << endl;

	
}

