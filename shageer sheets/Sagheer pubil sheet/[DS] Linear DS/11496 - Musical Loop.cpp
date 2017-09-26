#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
#define PI 3.1415926535897932384626433832795
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
int n;
int arr[10001];
int main() {
	file();
	while (scanf("%d", &n) && n) {
		int cnt = 0;
		for (int i = 1; i <= n; scanf("%d", &arr[i]), i++)
			;
		arr[0] = arr[n], arr[n + 1] = arr[1];
		for (int i = 1; i <= n; i++) {
			if (arr[i] > arr[i - 1] && arr[i + 1] < arr[i])
				cnt++;
			else if (arr[i] < arr[i - 1] && arr[i + 1] > arr[i])
				cnt++;
		}
		printf("%d\n", cnt);

	}

}

