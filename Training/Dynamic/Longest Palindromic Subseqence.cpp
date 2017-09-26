#include "stdafx.h"
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;

char A[100];
int arr[100][100];
int cnt;
int main()
{
	cin >> A;
	memset(arr, 0, sizeof arr);
	arr[0][0] = 1;
	for (cnt = 0; cnt < 100; cnt++)
	{
		if (A[cnt] == '\0')
		{
			break;
		}
	}
	int s = 1;
	for (int i = 1; i < cnt; i++)
	{
		arr[i][s] = 1;
		s++;
	}

	for (int l = 1; l <= cnt; l++)
	{
		for (int i = 0; i < cnt - 1; i++)
		{
			int j = i + l;
			if(j>cnt-1)
			{
				continue;
			}
			

			if (A[i] == A[j])
			{

				arr[i][j] = 2 + arr[i + 1][j - 1];
			}
			else
			{
				arr[i][j] = max(arr[i + 1][j], arr[i][j - 1]);
			}
		}
	}
	cout << arr[0][cnt - 1] << endl;
	return 0;
}

