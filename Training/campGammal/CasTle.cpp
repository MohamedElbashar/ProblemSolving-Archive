// CasTle.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <algorithm>
#include <iostream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<cstdio>
#include<stdint.h>
#include<typeinfo>
#include<vector>
using namespace std;
int n, m, vis[50][50], arr[50][50], sizee[50 * 50], cnt = 0, Max = 0, mx = 0;
char dir = ' ';
void solve(int x, int y, int ind) {
	if (vis[x][y] != -1)
		return;
	vis[x][y] = ind;
	sizee[ind]++;

	if ((arr[x][y] & 1) == 0)
		solve(x, y - 1, ind);
	if ((arr[x][y] & 4) == 0)
		solve(x, y + 1, ind);
	if ((arr[x][y] & 8) == 0)
		solve(x + 1, y, ind);
	if ((arr[x][y] & 2) == 0)
		solve(x - 1, y, ind);
	return;
}
int main() {
	int i, j;
	cin >> m >> n;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	memset(vis, -1, sizeof vis);

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (vis[i][j] == -1)
			{
				solve(i, j, cnt);
				Max = max(Max, sizee[cnt]);

				cnt++;
			}
		}
	}
	for (int i = 1; i < m - 1; i++)
	{
		for (int j = 1; j < n - 1; j++)
		{
			if (vis[i][j] != vis[i][j - 1]) {
				mx = max(mx, sizee[vis[i][j] + vis[i][j - 1]]);
				dir = 'E';
			}
			else if (vis[i][j] != vis[i][j + 1])
			{
				mx = max(mx, sizee[vis[i][j] + vis[i][j + 1]]);
				dir = 'W';
			}
			else if (vis[i][j] != vis[i - 1][j])
			{
				mx = max(mx, sizee[vis[i][j] + vis[i - 1][j]]);
				dir = 'N';
			}
			else if (vis[i][j] != vis[i + 1][j])
			{
				mx = max(mx, sizee[vis[i][j] + vis[i + 1][j]]);
				dir = 'S';
			}

		}
	}


	cout << cnt;
	cout << endl;
	cout << Max;
	cout << endl;
	cout << mx << "  " << dir;
	cout << endl;
}

