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
int s, c, arr[12], cnt;
int main() {
	file();
	while (scanf("%d%d", &c, &s) != EOF) {
		int sum = 0, cunt = 0;
		double res = 0;
		for (int i = 0; i < 2 * c; i++) {
			if (i < s)
				scanf("%d", &arr[i]);
			else {
				arr[i] = 0;
			}
			sum += arr[i];
		}
		double avg = (double) sum / c;
		sort(arr, arr + (2 * c));
		printf("Set #%d\n", ++cnt);
		for (int i = 0; i < (2 * c) / 2; i++) {
			res += fabs((arr[i] + arr[((2 * c) - (i + 1))]) - avg);
			printf("%2d:", cunt++);
			if (arr[((2 * c) - (i + 1))] > 0) {
				printf(" %d", arr[((2 * c) - (i + 1))]);
			}
			if (arr[i] > 0) {
				printf(" %d", arr[i]);
			}

			printf("\n");
		}
		printf("IMBALANCE = %.5lf\n\n", res);
	}
}
