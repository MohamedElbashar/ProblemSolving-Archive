#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pi> vpi;
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define mem(a,b) memset(a,b,sizeof a)
#define sz(v) ((int)((v).size()))
#define minn(a, b, c) min(min(a, b), c)
#define maxx(a, b, c) max(max(a, b), c)and
int dx[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int di[] = { 1, -1, 0, 0 };
int dj[] = { 0, 0, 1, -1 };
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#else
	// online submission
	//freopen("sets.in", "r", stdin);
#endif
}
//\/\/\/\/\/\/\/\/\/\/\/\/\/\//\/\/\/\//\/\/\/\/\/\/\/\/\/\/

int main() {
	file();
	int Case = 0;
	int n, m, word_count[21]{0};
	map<string, int> store;
	char s[21][1000];

	while (scanf("%d %d ", &m, &n) != EOF) {
		store.clear();
		for (int i = 0; i < m; i++) {
			scanf(" %s ", &s[0]);
			store[s[0]] = 1;
		}
		int word_max = -1;
		for (int i = 1; i < n; i++) {
			gets(s[i]);
			word_count[i] = 0;
			int len = strlen(s[i]), k = 0;
			string word = "";
			while (k < len) {
				if (isalpha(s[i][k]))
					word += tolower(s[i][k]);
				else {
					if (word != "")
						word_count[i] += store[word];
					word = "";
				}
				k++;
			}
			if (word != "")
				word_count[i] += store[word];
			word_max = max(word_count[i], word_max);
		}

		printf("Excuse Set #%d\n", ++Case);
		for (int i = 1; i < n; i++)
			if (word_count[i] == word_max)
				puts(s[i]);
		putchar('\n');
	}
}
