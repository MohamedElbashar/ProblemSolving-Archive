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
string s;
int cntx, cnty;
int main() {
	getline(cin, s);
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'x') {
			cntx++;
		} else {
			cnty++;
		}
	}
	int x;
	if (cntx > cnty) {
		x = cntx - cnty;
		for (int i = 0; i < x; i++) {
			printf("%c", 'x');
		}
	} else {
		x = cnty - cntx;
		for (int i = 0; i < x; i++) {
			printf("%c", 'y');
		}
	}
}

