#include <bits/stdc++.h>
using namespace std;
/**************BASHAR*****************/
struct node {
	int u, v, c;
	node(int u, int v, int c) :
			u(u), v(v), c(c) {
	}
	bool operator <(const node &e) const {
		return c > e.c;
	}
};
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
#define rep( i, n ) for (int i = 0; i < (n); i++)
#define scan(n) scanf("%d",&n)
#define mem(a,b) memset(a,b,sizeof(a))
#define ll long long
#define oo 1e15
int di[] = { 1, -1, 0, 0 };
int dj[] = { 0, 0, 1, -1 };
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//	freopen("out.txt", "w", stdout);
#else
	// online submission
	//freopen("interesting.in", "r", stdin);
#endif
}
/**************BASHAR*****************/
string str1, str2;

int solve(int i, int j) {
	if (i == str1.length() || j == str2.length())
		return 0;
	if (str1[i] == str2[j])
		return solve(i + 1, j + 1) + 1;
	int choice1 = solve(i + 1, j);
	int choice2 = solve(i, j + 1);
	return max(choice1, choice2);
}
int main() {
	file();
	cin >> str1 >> str2;
	cout << solve(0, 0);

}

