#include "stdafx.h"
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int S, N;
int value[2000], weight[2000], arr[2000][2000];

int main()
{
	cin >> S >> N;
	memset(arr, -1, sizeof arr);
	arr[0][0] = 0;
	for (int i = 0; i<N&&cin >> weight[i] >> value[i]; i++) {}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < S; j++)
		{ 
			if (arr[i][j] != -1)
			{
				arr[i + 1][j] = max(arr[i][j], arr[i + 1][j]);
				if (j + weight[i] <= S)
				{
					arr[i + 1][j + weight[i]] = arr[i][j] + value[i];
				}
			}
		}
	}
	int max = 0;
	for (int i = 0; i < S; i++)
	{
		if (arr[N][i] > max)
		{
			max = arr[N][i];
		}
	}
	cout << max << endl;

	
    return 0;
}

