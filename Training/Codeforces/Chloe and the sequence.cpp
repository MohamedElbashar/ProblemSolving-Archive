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
//I64d
/**************BASHAR*****************/
ll n, m, c;
int main() {
	scanf("%lld%lld", &n, &m);
	ll xx = pow(2, n - 1);
	if (m % 2 != 0) {
		printf("%d", 1);
		return 0;
	}
	while (1) {
		if (m % 2 == 0) {
			c++;
		} else {
			break;
		}
		m /= 2;
	}
	c++;
	printf("%lld", c);
}

