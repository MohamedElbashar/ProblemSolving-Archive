#include "stdafx.h"
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
char A[100], B[100];
int cnt1, cnt2;
int arr[100][100];
int cnt = 0;
int main()
{
	cin >> A;
	cin >> B;
	memset(arr, -1, sizeof arr);
	arr[0][0] = 0;
	for (cnt1 = 0; cnt1 < 100; cnt1++)
	{
		if (A[cnt1] == '\0')
		{
			break;
		}
	}
	for (cnt2 = 0; cnt2 < 100; cnt2++)
	{
		if (B[cnt2] == '\0')
		{
			break;
		}
	}
	for (int i = 1; i <=cnt1; i++)
	{
		for (int j = 1; j <= cnt2; j++)
			if (arr[i-1][j-1] != -1)
			{
				arr[i-1][j] = max(arr[i-1][j-1], arr[i-1][j]);
				arr[i][j-1] = max(arr[i-1][j-1], arr[i][j-1]);
				if (A[i-1] == B[j-1])
				{
					arr[i][j] = arr[i - 1][j - 1] + 1;
				}
				else
				{
					arr[i][j] = max(arr[i][j - 1], arr[i - 1][j]);
				}
			}
	}

	int max = 0;
	for (int i = 0; i <=cnt2; i++)
	{
		if (arr[cnt1][i] > max)
		{
			max = arr[cnt1][i];
		}
	}
	cout << max << endl;
}

