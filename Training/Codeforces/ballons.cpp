#include <bits/stdc++.h>
using namespace std;
/**************BASHAR*****************/
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
#define mem(a,b) memset(a,b,sizeof(a))
#define ll long long
#define oo 1e9
#define fir first
#define sec second
int di[] = { 1, -1, 0, 0 };
int dj[] = { 0, 0, 1, -1 };
/**************BASHAR*****************/
int t, n, s, d;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d", &n, &s, &d);
		int ans = s / d;
		if (s % d)
			ans++;
		if (ans > n)
			printf("%d\n", n);
		else {
			printf("%d\n", ans);
		}
	}
}
