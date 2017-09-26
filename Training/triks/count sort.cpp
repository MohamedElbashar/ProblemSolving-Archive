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
int main() {
	file();
	int n;
	while (scanf("%d", &n) && n) {
		int arr[n];
		for (int i = 0; i < n; scanf("%d", &arr[i]), i++)
			;
		int mx = *max_element(arr, arr + n);
		int count[mx + 1];
		mem(count, 0);
		int output[n];
		for (int i = 0; i < n; i++) {
			count[arr[i]]++;
		}
		for (int i = 1; i < mx + 1; i++) {
			count[i] += count[i - 1];
		}
		for (int i = 0; i < n; i++) {
			output[count[arr[i]] - 1] = arr[i];
			count[arr[i]]--;
		}
		printf("%d", output[0]);
		for (int i = 1; i < n; i++) {
			printf(" %d", output[i]);
		}
		printf("\n");
	}

}

