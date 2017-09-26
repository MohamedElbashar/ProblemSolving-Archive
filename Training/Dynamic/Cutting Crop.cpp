#include "stdafx.h"
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int rod, n;
int arr[100][100];
int len[100];
int price[100];


int main()
{
	cin >> rod;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> len[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> price[i];
	}
	memset(arr, 0, sizeof arr);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= rod; j++)
		{
			if (j - len[i-1] >= 0)
			{
				arr[i][j] = max(arr[i - 1][j], price[i - 1] + arr[i][j - len[i-1]]);
			}
			else
			{
				arr[i][j] = arr[i - 1][j];
			}
		}
	}
	cout << arr[n][rod] << endl;
	
}

