#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
#define ll long long
#define oo 1e8
#define minn(a, b, c) min(min(a, b), c)
#define maxx(a, b, c) max(max(a, b), c)
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
int n, k;
char arr[101][101], flag;
int main() {
	file();

	scanf("%d%d", &n, &k);
	if (k > (n * n + 1) / 2) {
		printf("%s", "NO");
		return 0;
	}
	printf("%s\n", "YES");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = 'S';
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (k == 0) {
				flag = 1;
			}
			if ((i + j) % 2 == 0 && k) {
				arr[i][j] = 'L';
				k--;
			}
		}
		if (flag)
			break;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j];
		}
		printf("\n");
	}
}
