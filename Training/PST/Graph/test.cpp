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
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#else
// online submission
	//freopen("*.in", "r", stdin);
#endif
}
/**************BASHAR*****************/
int t, n, xx;
int main() {
	file();
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		if (n % 2) {
			xx = (n / 2);
			xx++;
		} else {
			xx = n / 2;
		}
		cout << xx << endl;
		//printf("%d\n", &xx);
	}
}

