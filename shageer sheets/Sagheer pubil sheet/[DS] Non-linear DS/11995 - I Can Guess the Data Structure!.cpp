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
	file();
	int n, op, x;
	while (scanf("%d", &n) != EOF) {
		queue<int> q;
		stack<int> s;
		priority_queue<int> pq;
		bool isS = true, isQ = true, isPQ = true;

		for (int i = 0; i < n; i++) {
			scanf("%d %d", &op, &x);

			switch (op) {
			case 1:
				if (isS)
					s.push(x);
				if (isQ)
					q.push(x);
				if (isPQ)
					pq.push(x);
				break;
			case 2:
				if (isS) {
					if (s.empty() || s.top() != x)
						isS = false;
					else
						s.pop();
				}
				if (isQ) {
					if (q.empty() || q.front() != x)
						isQ = false;
					else
						q.pop();
				}
				if (isPQ) {
					if (pq.empty() || pq.top() != x)
						isPQ = false;
					else
						pq.pop();
				}
				break;
			}
		}

		if (isS == true && isQ == false && isPQ == false)
			cout << "stack" << endl;
		else if (isS == false && isQ == true && isPQ == false)
			cout << "queue" << endl;
		else if (isS == false && isQ == false && isPQ == true)
			cout << "priority queue" << endl;
		else if (isS == false && isQ == false && isPQ == false)
			cout << "impossible" << endl;
		else
			cout << "not sure" << endl;
	}
}
