#include "stdafx.h"
#include<iostream>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;

int main()
{
	string A, B;
	cin >> A >> B;
	int arr[100][100];
	char res[100];
	memset(arr, 0, sizeof arr);
	int mx = 0;
	int s = 0;
	for (int i = 1; i <= B.length(); i++)
	{
		for (int j = 1; j <= A.length(); j++)
		{
			if (B[i - 1] == A[j - 1])
			{
				arr[i][j] = arr[i - 1][j - 1] + 1;
				if (arr[i][j] > mx)
				{
					res[s] = B[i-1];
					mx = arr[i][j];
					s++;
				}
			}
			else
			{
				arr[i][j] = 0;
			}
		}
	}
	cout << mx << endl;
	for (int i = 0; i < s; i++)
	{
		cout << res[i];
	}
	cout << endl;

}




