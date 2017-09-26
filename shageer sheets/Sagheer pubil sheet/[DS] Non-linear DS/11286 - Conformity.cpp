#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
#define PI 3.1415926535897932384626433832795
#define ll long long
#define mem(a,b) memset(a,b,sizeof a)
#define oo 1e8
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
	//freopen("interesting.in", "r", stdin);
#endif
}
//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\//\/\/\/\/\/\/\/\/\/
int main() {
	int n, A[5];
	char buf[20];
	while(scanf("%d", &n) == 1 && n) {
		string str;
		map<string, int> record;
		while(n--) {
			scanf("%d %d %d %d %d", &A[0], &A[1], &A[2], &A[3], &A[4]);
			sort(A, A+5);
			sprintf(buf, "%d%d%d%d%d", A[0], A[1], A[2], A[3], A[4]);
			str = buf;
			record[str]++;
		}
		int max = 0, maxNum = 0;
		for(map<string, int>::iterator i = record.begin(); i != record.end(); i++) {
			if(i->second > max)
				max = i->second, maxNum = 0;
			if(i->second == max)
				maxNum += max;
		}
		printf("%d\n", maxNum);
	}
    return 0;
}
