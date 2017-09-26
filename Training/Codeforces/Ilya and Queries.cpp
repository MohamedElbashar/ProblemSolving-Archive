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
int n, l, r;
string s;
int arr[100000];
int main() {
	getline(cin, s);
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == s[i + 1]) {
			arr[i + 1] = arr[i] + 1;
		} else {
			arr[i + 1] = arr[i];
		}
	}
	scanf("%d", &n);
	while (n--) {
		scanf("%d%d", &l, &r);
		cout << arr[r - 1] - arr[l - 1]<<endl;
	}

}

