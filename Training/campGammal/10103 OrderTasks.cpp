#include "stdafx.h"
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
int n, m;
vector<int>arr[100001];
int cnt[100001];
queue<int>myQ;
vector<int>ans;
int main()
{
	int i, j, cur, t, r;
	cin >> n >> m;
	for (i = 0;i < m;i++)
	{
		cin >> t >> r;
		arr[t].push_back(r);
		cnt[r]++;
	}
	for (j = 1;j <= n;j++)
	{
		if (!cnt[j])
		{
			myQ.push(j);
		}
	}
	while (myQ.size())
	{
		cur = myQ.front();
		myQ.pop();
		ans.push_back(cur);

		for (i = 0;i < arr[cur].size();i++)
		{
			cnt[arr[cur][i]]--;
			if (cnt[arr[cur][i]] == 0)
			{
				myQ.push(arr[cur][i]);
			}
		}

	}
	if (ans.size() != n)
	{
		cout << "fail";
	}
	else
	{
		for (int i = 0;i < n;i++)
		{
			cout << ans[i];
		}
		cout << endl;
	}


}

