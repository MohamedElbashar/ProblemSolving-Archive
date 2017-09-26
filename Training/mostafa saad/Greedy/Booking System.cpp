#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
#define ll long long
#define mem(a,b) memset(a,b,sizeof a)
#define oo 1e8
#define minn(a, b, c) min(min(a, b), c)
#define maxx(a, b, c) max(max(a, b), c)
int dx[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int di[] = { 0, -1, 0, 1 };
int dj[] = { 0, 1, 1, 1 };
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#else
	// online submission
	//freopen("interesting.in", "r", stdin);
#endif
}
//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\//\/\/\/\/\/\/\/\/\/
int n, m;
pi tab[1001];
vector<pair<pair<int, int>, int> > arr;
vpi v;
int cnt, num;
int cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
	if (a.first.second == b.first.second) {
		return a.first.first < b.first.first;
	} else
		return a.first.second > b.first.second;
}
int cmp2(pi a, pi b) {
	return a.first < b.first;
}
int main() {
	file();
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int xx, yy;
		scanf("%d%d", &xx, &yy);
		arr.push_back(make_pair(make_pair(xx, yy), i + 1));
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &tab[i].first);
		tab[i].second = i + 1;
	}
	sort(arr.begin(), arr.end(), cmp);
	sort(tab, tab + m, cmp2);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (tab[j].first == 0)
				continue;
			if (arr[i].first.first <= tab[j].first) {
				cnt += arr[i].first.second;
				num++;
				tab[j].first = 0;
				v.push_back(make_pair(arr[i].second, tab[j].second));
				break;
			}
		}
	}
	printf("%d %d\n", num, cnt);
	for (int i = 0; i < v.size(); i++) {
		printf("%d %d\n", v[i].first, v[i].second);
	}

}
