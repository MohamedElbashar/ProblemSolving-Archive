#include "stdafx.h"
#include<iostream>;
#include<string>;
#include<algorithm>;
using namespace std;
int arr[100][100];
int grid(int r, int c, int n)
{
	if (r >= n || c >= n)
		return 0;

	grid(r, c + 1, n);
	grid(r + 1, c, n);
	return arr[r][c] + max(grid(r, c + 1, n), grid(r + 1, c, n));
}


int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0;j < n;j++)
		{
			cin >> arr[i][j];
		}
	}
	cout << endl;
	cout << grid(0, 0, n) << endl;
}

