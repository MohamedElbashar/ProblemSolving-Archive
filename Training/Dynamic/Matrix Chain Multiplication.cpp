#include "stdafx.h"
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	pair<int, int>res[100];
	int arr[100][100];
	memset(arr, -1, sizeof arr);
	arr[0][0] = 0;
	for (int i = 0; i<n&&cin >> res[i].first >> res[i].second; i++) {}
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < n; j++)
		{
			if (arr[i - 1][j - 1] != -1)
			{
				arr[i][j] = max(arr[i - 1][j - 1], arr[i][j]);
			}
		}
	}
	for (int l = 1; l < n; l++)
	{
		for (int i = 0; i < n - 1; i++)
		{
			int j = i + l;
			if (j < n)
			{
				arr[i][j] = INT_MAX;
				for (int k = i; k < j; k++)
				{
					arr[i][j] = min(arr[i][j], arr[i][k] + arr[k + 1][j] + res[i].first * res[k].second * res[j].second);
				}
			}
		}
	}
	cout << arr[0][n - 1] << endl;
}