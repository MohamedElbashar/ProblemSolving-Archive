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
	freopen("out.txt", "w", stdout);
#else
	// online submission
	//freopen("interesting.in", "r", stdin);
#endif
}
//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\//\/\/\/\/\/\/\/\/\/
int n, nq;
int ar[50005], arr[50005], quer;
//i arr;
set<int> s;
int main() {
	file();
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
		s.insert(ar[i]);
	}
	int cnt = 0;
	while (s.size()) {
		int x = *s.begin();
		s.erase(s.begin());
		arr[cnt++] = x;
	}
	//int xx = sizeof arr;
	//sort(arr.begin(), arr.end());
	scanf("%d", &nq);
	for (int i = 0; i < nq; i++) {
		cin >> quer;
		if (quer == arr[0]) {
			printf("X %d\n", arr[1]);
		} else if (quer == arr[cnt - 1]) {
			printf("%d X\n", arr[cnt - 2]);
		} else if (quer < arr[0]) {
			printf("X %d\n", arr[0]);
		} else if (quer > arr[cnt - 1]) {
			printf("%d X\n", arr[cnt - 1]);
		} else {
			int low = 0, upper = cnt, mid;
			while (low < upper - 1) {
				mid = low + (upper - low + 1) / 2;
				if (quer == arr[mid]) {
					low = mid - 1;
					upper = mid + 1;
					break;
				} else if (quer > arr[mid])
					low = mid;
				else
					upper = mid;
			}
			printf("%d %d\n", arr[low], arr[upper]);
		}
	}
	return 0;
}
