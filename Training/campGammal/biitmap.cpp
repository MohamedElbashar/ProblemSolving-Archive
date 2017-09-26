#include"stdafx.h"
#include<iostream>
#include<algorithm>
#include<string.h>
#include<queue>
using namespace std;
struct node {
	int x, y, d;
};
int grid[182][182];
int dis[182][182];
int n, m;
queue<node> q;
int rx[] = { 1, -1, 0, 0 };
int ry[] = { 0, 0, 1, -1 };
int main() {
	int i, j;
	node moment;
	cin >> n >> m;
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			cin >> grid[i][j];
	memset(dis, -1, sizeof dis);
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			if (grid[i][j] == 1) {
				moment.x = i;
				moment.y = j;
				moment.d = 0;
				q.push(moment);
			}
	while (!q.empty()) {
		moment = q.front();
		q.pop();
		if (dis[moment.x][moment.y] != -1)
			continue;
		dis[moment.x][moment.y] = moment.d;
		for (i = 0; i < 4; i++) {
			node temp;
			temp.x = moment.x + rx[i];
			temp.y = moment.y + ry[i];
			temp.d = moment.d + 1;
			if (temp.x < 0 || temp.x >= n || temp.y < 0 || temp.y >= m)
				continue;
			if (dis[temp.x][temp.y] == -1)
				q.push(temp);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << dis[i][j] << " ";
		}
		cout << endl;
	}
	return 0;

}

