#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<pi> vpi;
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define mem(a,b) memset(a,b,sizeof a)
#define sz(v) ((int)((v).size()))
#define minn(a, b, c) min(min(a, b), c)
#define maxx(a, b, c) max(max(a, b), c)
int dx[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int di[] = { 1, -1, 0, 0 };
int dj[] = { 0, 0, 1, -1 };
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#else
	// online submission
	//freopen("sets.in", "r", stdin);
#endif
}
//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\//\/\/\/\/\/\/\/\/\/\/
int arr[10001], n;
int LR[10001], RL[10001], L[10001];
int main() {
	file();
	while (scanf("%d", &n) != EOF) {
		int flag = 0, f2 = 0;
		/*fill(LR, LR + n, 1);
		 fill(RL, RL + n, 1);*/
		for (int i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
		}
		int lis = 0;
		for (int i = 0; i < n; i++) {
			int pos = lower_bound(L, L + lis, arr[i]) - L;
			L[pos] = arr[i];
			if (pos + 1 > lis)
				lis = pos + 1;
			LR[i] = lis;

		}
		mem(L, 0);
		lis = 0;
		reverse(arr, arr + n);
		for (int i = 0; i < n; i++) {
			int pos = lower_bound(L, L + lis, arr[i]) - L;
			L[pos] = arr[i];
			if (pos + 1 > lis)
				lis = pos + 1;
			RL[i] = lis;
		}
		reverse(RL, RL + n);
		int mx = 0;
		for (int i = 0; i < n; i++)
			if (LR[i] == RL[i])
				mx = LR[i] + RL[i] - 1;

		printf("%d\n", mx == 0 ? -1 : mx);
	}

}
