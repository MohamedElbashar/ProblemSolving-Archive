#include "stdafx.h"
#include<iostream>
#include<algorithm>
#include<string.h>

using namespace std;
int n;
int coin [100];
int total;
int arr[100][100];

int main()
{
	cin >> total;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> coin[i];
	}
	memset(arr, 0, sizeof arr);
	arr[0][0] = 1;
	int cnt;
	for (int i = 1; i < n; i++)
	{
		arr[i][0] = 1;
	}
	for (int i = 0; i <= n; i++)
	{
		for (int j = 1; j <= total; j++)
		{
			if (i == 0)
			{
				if (j - coin[i] >= 0)
				{
					arr[i][j] = arr[i][j - coin[i]];
				}
			}
			else
			{
				if (j - coin[i] >= 0)
				{
					arr[i][j] = arr[i][j - coin[i]] + arr[i - 1][j];
				}
				else
				{
					arr[i][j] = arr[i - 1][j];
				}
			}
		}
	}
	cout << arr[n-1][total]<<endl;
}

