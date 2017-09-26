#include "stdafx.h"
#include<iostream>
#include<algorithm>
using namespace std;
int n, m;
int x, y, i, j;
int dwn, rght;


int main()
{
	
	
	scanf("%d %d", &n, &m);
	scanf("%d %d", &x, &y);
	int num[n][m];
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			scanf("%d", &num[i][j]);
		}
	}
	int arr[n][m] = { 0 };
	arr[x-1][y-1] = num[x - 1][y - 1];
	for (i = x; i < n; i++) {
		arr[i][y-1] = arr[i - 1][y-1] - num[i][y-1];
	}
	for (i = y; i < m; i++) {
		arr[x-1][i] = arr[x-1][i-1] - num[x-1][i];
	}
	for (i = x; i < n; i++) {
		for (j = y; j < m; j++) {
			arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]) - num[i][j];
		}
	}
	if (arr[n - 1][m - 1] >= 0) {
		printf("Y %d\n", arr[n - 1][m - 1]);
	}
	else {
		printf("N\n");
	}
}


