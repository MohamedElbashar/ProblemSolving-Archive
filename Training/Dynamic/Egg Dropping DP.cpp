#include "stdafx.h"
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int main()
{
	int arr[100][100];
	int eggs, floors, i, j, k;
	cin >> eggs >> floors;
	memset(arr, 0, sizeof arr);
	for (int s = 1; s <= floors; s++)
	{
		arr[1][s] = s;
	}
	int res, mn;
	i = 2;
	while (i <= eggs)
	{
		for (j = 1; j <= floors; j++)
		{
			arr[i][j] = INT_MAX;
			for (k = 1; k <= j; k++)
			{
				if (j < i)
				{
					arr[i][j] = arr[i - 1][j];
				}
				else
				{
					res = max(arr[i - 1][k - 1], arr[i-1][j - k]);
					arr[i][j] = min(arr[i][j], 1 + res);
				}
			}
		}
		i++;
	}
	cout << arr[eggs][floors] << endl;
}



