#include "stdafx.h"
#include<iostream>
using namespace std;
int tree[250000];
int n;
void update(int node, int s, int e, int ind, int NewVal)
{
	if (ind > e || ind < s)return;
	if (s == e)
	{
		if (s == ind)
			tree[node] = NewVal;
		return;
	}



	int mid = (s + e) / 2;
	update(node * 2, s, mid, ind, NewVal);
	update(node * 2 + 1, mid + 1, e, ind, NewVal);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
	return;
}
int solve(int node, int s, int e, int x, int y)
{
	if (s > y || e < x) return 0;
	if (s >= x&&e <= y)
		return tree[node];

	int ret = 0;
	int mid = (s + e) / 2;
	ret += (node * 2, s, mid, x, y);
	ret += (node * 2 + 1, mid + 1, e, x, y);
	return ret;


}
int main()
{
	int  k;
	cin >> n;
	int i;
	for (i = 0;i < n;i++)
	{
		cin >> k;
		update(1, 0, n - 1, i, k);
	}
	int res = solve(1, 0, n - 1, 1,n);
	cout << res << endl;
	return 0;
}

