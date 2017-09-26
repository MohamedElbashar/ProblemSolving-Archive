// MAZE2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>;
#include<string>;
#include<algorithm>;
using namespace std;
char arr[100][100];
bool Maze(int i, int j, int n, int m)
{
	if (i >= n || j >= m || i < 0 || j < 0 )
		return false;

	else if (arr[i][j] == 'x')
		return false;

	else if (arr[i][j] == 'e')
        return true;

	else {//check
		if (Maze(i, j + 1, n, m))
		{
			return true;
		}
		if (Maze(i, j - 1, n, m))
		{
			return true;
		}
		if (Maze(i + 1, j, n, m))
		{
			return true;
		}
		if (Maze(i - 1, j, n, m))
		{
			return true;
		}
		return false;
	}
	
}
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < m;j++)
		{
			cin >> arr[i][j];
		}
	}
	cout << endl;
	
	cout << Maze(0, 0, n, m);
}

