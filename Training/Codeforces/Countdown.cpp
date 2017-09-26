#include <bits/stdc++.h>
using namespace std;
/**************BASHAR*****************/
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
#define rep( i, n ) 	for ( int i = 0; i < (n); i++ )
#define scan(n) scanf("%d",&n)
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
	//freopen("coaches.in", "r", stdin);
#endif
}
/**************BASHAR*****************/
int cant[1000];
string s[1000];
bool comp(const int& i, const int& j) {
	if (cant[i] != cant[j])
		return cant[i] > cant[j];
	return s[i] < s[j];
}
int main() {
	file();
	int t, n, d;
	char arr[100];
	int father[1000];

	int idx[1000];

	map<string, int> mp;

	scan(t);
	int cnt = 0;
	while (t--) {
		mp.clear();
		int nn = 0;
		mem(father, -1);
		mem(cant, 0);
		scanf("%d%d", &n, &d);
		rep(i,n)
		{
			int sons;
			scanf("%s%d", &arr, &sons);
			string parent(arr);
			if (mp.find(parent) == mp.end()) {
				s[nn] = parent;
				mp[parent] = nn;
				nn++;
			}
			while (sons--) {
				scanf("%s", &arr);
				string child(arr);
				if (mp.find(child) == mp.end()) {
					s[nn] = child;
					mp[child] = nn;
					nn++;
				}
				father[mp[child]] = mp[parent];
			}
		}
		rep(i,nn)
		{
			idx[i] = i;
			int x = i;
			rep(j,d)
			{
				x = father[x];
				if (x == -1)
					break;
			}
			if (x)
				cant[x]++;
		}

		sort(idx, idx + nn, comp);

		printf("Tree %d:\n", ++cnt);

		int changes = 0;
		rep(i,nn)
		{
			int id = idx[i];
			if (cant[id] == 0)
				break;
			if (i && cant[id] != cant[idx[i - 1]])
				changes++;
			if (i && cant[id] != cant[idx[i - 1]] && i >= 3)
				break;
			if (changes == 3)
				break;
			printf("%s %d\n", s[id].c_str(), cant[id]);

		}
	}
}

