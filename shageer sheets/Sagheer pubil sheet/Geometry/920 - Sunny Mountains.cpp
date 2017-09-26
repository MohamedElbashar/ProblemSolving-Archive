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
//\/\/\/\/\/\/\/\/\/\/\/\/\/\//\/\/\/\//\/\/\/\/\/\/\/\/\/\/
typedef struct node {
	double x, y;
} point;
vector<point> P;

bool cmp(point a, point b) {
	return a.x > b.x;
}

double dist(point a, point b) {
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main() {
	file();
	int T, N;
	while (~scanf("%d", &T))
		while (T--) {
			scanf("%d", &N);
			for (int i = 0; i < N; ++i)
				scanf("%lf%lf", &P[i].x, &P[i].y);
			sort(P.begin(), P.end(), cmp);

			double sums = 0.0;
			int last = 0;
			for (int i = 1; i < N; ++i)
				if (P[i].y > P[last].y) {
					sums += dist(P[i], P[i - 1]) * (P[i].y - P[last].y)
							/ (P[i].y - P[i - 1].y);
					last = i;
				}

			printf("%.2lf\n", sums);
		}
	return 0;
}

