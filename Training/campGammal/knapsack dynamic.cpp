#include"stdafx.h"
#include <algorithm>
#include <iostream>
#include<string.h>
using namespace std;
int S, N;
int value[2001];
int sizOfvalue[2001];
int arr[2001][2001];
int main()
{
	cin >> S >> N;
	for (int i = 0;i < N&&cin >> sizOfvalue[i] >> value[i];i++);
	memset(arr, -1, sizeof arr);
	arr[0][0] = 0;
	for (int i = 0;i < N;i++)
	{
		for (int j = 0;j <= S;j++)
		{

			if (arr[i][j] != -1)
			{
				arr[i + 1][j] = max(arr[i + 1][j], arr[i][j]);

				if (j + sizOfvalue[i] <= S)
				{
					arr[i + 1][j + sizOfvalue[i]] = arr[i][j] + value[i];
				}
			}

		}
	}
	int max = 0;
	for (int j = 0;j <= S;j++)
	{
		if (arr[N][j]>max)
		{
			max = arr[N][j];
		}
	}
	cout << max;
	cout << endl;
}
