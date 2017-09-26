#include <bits/stdc++.h>
int n, s, t, arr[100001], cnt;
using namespace std;
int main() {
/*	freopen("out.txt", "w", stdout);
	freopen("in.txt", "r", stdin);*/
	scanf("%d%d%d", &n, &s, &t);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	int cur;
	while (s != t) {
		cur=s;
		s = arr[s];

		if(cur==s)
			break;
		cnt++;
		if(cnt>n){
			break;
		}
	}

	if (s == t) {
		cout << cnt;
	} else {
		puts("-1");
	}
}
