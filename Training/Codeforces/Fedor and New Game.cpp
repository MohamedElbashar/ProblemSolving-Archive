#include <bits/stdc++.h>
using namespace std;
/**************BASHAR*****************/
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
#define mem(a,b) memset(a,b,sizeof(a))
#define ll long long
#define fir first
#define sec second
int di[] = { 1, -1, 0, 0 };
int dj[] = { 0, 0, 1, -1 };
/**************BASHAR*****************/
string s;
void solve(int b) {
	s.clear();
	char x;
	while (b != 0) {
		x = b % 2 + '0';
		s += x;
		b /= 2;
	}
}

int main() {
	int n, m, k, cnt, cnt2;
	string vs[1001];
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i <= m; i++) {
		int a;
		scanf("%d", &a);
		solve(a);
		vs[i] = s;
		for (int j = vs[i].length(); j < n; j++) {
			vs[i].push_back('0');
		}
	}
	string y = vs[m];
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < vs[i].length(); j++) {
			if (y[j] != vs[i][j])
				cnt2++;
		}
		if (cnt2 <= k) {
			cnt++;
		}
		cnt2 = 0;

	}
	printf("%d", cnt);
	return 0;

}
