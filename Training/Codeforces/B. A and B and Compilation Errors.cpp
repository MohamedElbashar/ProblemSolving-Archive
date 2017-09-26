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
int di[] = { 1, -1, 0, 0 };
int dj[] = { 0, 0, 1, -1 };
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
ll sum1, sum2, sum3;
int main() {
	file();
	scanf("%d", &n);
	int x;
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		sum1 += x;
	}
	for (int i = 0; i < n - 1; i++) {
		scanf("%d", &x);
		sum2 += x;
	}
	for (int i = 0; i < n - 2; i++) {
		scanf("%d", &x);
		sum3 += x;
	}
	printf("%I64d\n", sum1 - sum2);
	printf("%I64d\n", sum2 - sum3);

}

