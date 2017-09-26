#include "stdafx.h"
#include<iostream>;
#include<algorithm>
using namespace std;
int solve(int n, int k)
{
	if (k == 0 || k == 1)
		return k;
	if (n == 1)
		return k;
	int mn = INT_MAX;
	int res;
	for (int i = 1; i <= k; i++)
	{
		int res = max(solve(n - 1, i - 1), solve(n, k - i));
		if (res < mn)
		{
			mn = res;
		}
	}
	return mn + 1;

}
int main()
{
	int Eggs;
	cin >> Eggs;
	int Floors;
	cin >> Floors;

	cout << solve(Eggs, Floors) << endl;
}

