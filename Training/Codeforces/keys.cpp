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
int t, n, k;

int main() {
	scanf("%d", &t);
	while (t--) {
		int ans = 0, arr[26] = { 0 };
		string s;
		scanf("%d%d", &n, &k);
		for (int i = 0; i < 26; i++)
			scanf("%d", &arr[i]);
		for (int i = 0; i < n; i++) {
			cin >> s;
			ans = 0;
			for (int j = 0; j < s.length(); j++) {
				ans += arr[s[j] - 'a'];
			}
			if (ans >= k) {
				cout << s << endl;
			}
		}
	}

}
