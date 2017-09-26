#include "stdafx.h"
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int n;
int Node[100];
int cost[100];
int arr[100][100];
int sum(int ferq[], int x, int y)
{
	int add = 0;
	for (int i = x; i <= y; i++)
	{
		add += ferq[i];
	}
	return add;
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> Node[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> cost[i];
	}
	memset(arr, -1, sizeof arr);
	int s=0;
	for (int i = 0; i < n; i++)
	{
		arr[i][s] = cost[i];
		s++;
	}
	for (int l = 1; l < n; l++)
	{
		for (int i = 0; i < n - 1; i++)
		{
			int j = i + l;
			if (j < n)
			{
				arr[i][j] = INT_MAX;
				for (int k = i; k <= j; k++)
				{
					arr[i][j] = min(arr[i][j], ((k > i) ? arr[i][k - 1] : 0) + ((k < j) ? arr[k + 1][j] : 0) + sum(cost, i, j));
				}
			}
		}
	}
	cout << arr[0][n - 1] << endl;
}