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
	//freopen("scoreboard.in", "r", stdin);
	//freopen("out.txt", "w", stdout);
#else
	// online submission
	freopen("scoreboard.in", "r", stdin);
#endif
}
//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\//\/\/\/\/\/\/\/\/\/\/
int t, n, xx;
pi arr[105], arr2[105];
string check(int c) {
	if (c == 1)
		return "st";
	else if (c == 2)
		return "nd";
	else if (c == 3)
		return "rd";
	else
		return "th";
}
int main() {
	file();
	scanf("%d", &t);
	while (t--) {
		freopen("in.txt", "r", stdin);
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &xx);
			arr[i].first = xx;
			arr[i].second = i + 1;
		}
		for (int i = 0; i < n; i++) {
			scanf("%d", &xx);
			arr2[i].first = xx;
			arr2[i].second = i + 1;
		}
		sort(arr, arr + n);
		sort(arr2, arr2 + n);
		for (int i = 0; i < n; i++) {
			if (arr2[i].second == arr[i].second) {
				string s = check(arr2[i].second);
				printf("team %d stayed at %d%s position\n", arr[i].first,
						arr[i].second, s.c_str());
			} else {
				string s = check(arr[i].second);
				string ss = check(arr2[i].second);
				printf("team %d moved from %d%s position to %d%s position\n",
						arr[i].first, arr[i].second, s.c_str(), arr2[i].second,
						ss.c_str());
			}
		}
	}

}
