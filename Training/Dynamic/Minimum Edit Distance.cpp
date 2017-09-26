#include "stdafx.h"
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
char A[2002];
char B[2002];
int arr[2002][2002];
int cnt1, cnt2;
int n;
int result[2002];
int main()
{
	cin >> n;
	for (int l = 0; l < n; l++)
	{
		cin >> A;
		cin >> B;
		memset(arr, -1, sizeof arr);
		arr[0][0] = 0;
		for (cnt1 = 0; cnt1 < 2002; cnt1++)
		{
			if (A[cnt1] == '\0')
			{
				break;
			}
		}
		for (cnt2 = 0; cnt2 < 2002; cnt2++)
		{
			if (B[cnt2] == '\0')
			{
				break;
			}
		}
		for (int i = 1; i <= cnt1; i++)
		{
			arr[0][i] = i;
		}
		for (int i = 1; i <= cnt2; i++)
		{
			arr[i][0] = i;
		}
		for (int i = 1; i <= cnt1 + 1; i++)
		{
			for (int j = 1; j <= cnt2 + 1; j++)
			{
				if (B[i - 1] == A[j - 1])
				{
					arr[i][j] = arr[i - 1][j - 1];
				}
				else
				{
					int min1 = arr[i - 1][j - 1];
					int min2 = min(arr[i - 1][j], arr[i][j - 1]);
					arr[i][j] = min(min1, min2) + 1;
				}
			}
		}
		result[l] = arr[cnt2][cnt1];
	}
	for (int i = 0; i < n; i++)
	{
		cout << result[i] << endl;
	}
	}

