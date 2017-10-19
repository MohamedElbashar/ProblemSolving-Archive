#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<pi> vpi;
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define mem(a,b) memset(a,b,sizeof a)
#define sz(v) ((int)((v).size()))
#define minn(a, b, c) min(min(a, b), c)
#define maxx(a, b, c) max(max(a, b), c)
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
//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\//\/\/\/\/\/\/\/\/\/\/
int A[100][100];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			scanf("%d", &A[i][j]);
			if (i > 0)
				A[i][j] += A[i - 1][j];
			if (j > 0)
				A[i][j] += A[i][j - 1];
			if (i > 0 && j > 0)
				A[i][j] -= A[i - 1][j - 1];
		}

	maxSubRect = -1e9;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = i; k < n; k++)
				for (int l = j; l < n; l++) {
					subRect = A[k][l];
					if (i > 0)
						subRect -= A[i - 1][l];
					if (j > 0)
						subRect -= A[k][j - 1];
					if (i > 0 && j > 0)
						subRect += A[i - 1][j - 1];
					maxSubRect = max(maxSubRect, subRect);
				}

	printf("%d\n", maxSubRect);
	return 0;
}
