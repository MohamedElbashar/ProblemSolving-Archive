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
int arr[5] = { 1, 5, 10, 25, 50 }, n, memo[6][7495];
int solve(int ind, int rem) {
	if (rem == 0)
		return 1;
	if (ind == 5 || rem < 0)
		return 0;
	int &ret = memo[ind][rem];
	if (ret != -1)
		return ret;
	return ret = solve(ind + 1, rem) + solve(ind, rem - arr[ind]);

}
int main() {
	file();
	mem(memo, -1);
	while (scanf("%d", &n) != EOF) {
		printf("%d\n", solve(0, n));
	}
}
