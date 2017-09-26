#include <bits/stdc++.h>
using namespace std;
#define f0r(i, j, n) 		for(int i=(j);i<(int)(n);++i)
#define mem(a,b) memset(a,b,sizeof a)
// output handle
#define oti(x) printf("%d", x)
#define nl() printf("\n")
#define ots(x) printf("%s", x)	//output char[]
#define otf(x) printf("%.0lf", x)// output double/float with 0.00
#define otl(x) printf("%lld", x)//output long long int
#define space() printf(" ")
// input handle
#define iln() scanf("\n")		//scan new line
#define ins(n) scanf("%s",n)	//scan char[]
#define inc(n) scanf("%c ",&n)	//scan char
#define inf(n) scanf("%lf",&n)	//scan double/float
#define inl(n) scanf("%lld",&n)	//scan long long int
#define in(n) scanf("%d",&n)	//scan int
#define sz(v) ((int)((v).size()))
typedef long long ll;

int maxval = 100005;
int tree[100005];
int get(int idx) {
	int sum = 0;
	for (; idx > 0; idx -= (idx & -idx))
		sum += tree[idx];
	return sum;
}
void update(int idx, int val) {
	for (; idx <= maxval; idx += (idx & -idx))
		tree[idx] += val;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int n, a, b, val;
	char s;
	while (1) {
		mem(tree, 0);
		in(n);
		if (n == 0) break;
		while (n--) {
			cin >> s;
			if (s == 'Q') {
				in(a);
				int res = get(a);
				oti(res), nl();

			} else {
				in(a), in(b), in(val);
				update(a, val);
				update(b + 1, -val);
			}
		}
	}
	return 0;
}
