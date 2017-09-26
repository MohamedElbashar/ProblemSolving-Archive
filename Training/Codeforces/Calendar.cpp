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
#define scanl(n) scanf("%I64d",&n)
#define mem(a,b) memset(a,b,sizeof(a))
#define ll long long
#define oo 1e8
#define minn(a, b, c) min(min(a, b), c)
#define maxx(a, b, c) max(max(a, b), c)
int di[] = { 0, -1, 0, 1 };
int dj[] = { 0, 1, 1, 1 };
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#else
	// online submission
	//freopen("interesting.in", "r", stdin);
#endif
}
/**************BASHAR*****************/
int year, month, day;
int year2, month2, day2, cnt, flag;
int mn[] = { 31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int mh[] = { 31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int main() {
	file();
	scanf("%d:%d:%d", &year, &month, &day);
	scanf("%d:%d:%d", &year2, &month2, &day2);
	if (year2 < year) {
		swap(year, year2);
		swap(month, month2);
		swap(day, day2);
	} else if (year2 == year) {
		if (month > month2) {
			swap(month, month2);
			swap(day, day2);
		}

		else if (month == month2) {
			if (day > day2) {
				swap(day, day2);
			}
		}
	}
	while (year <= year2) {
		if (year % 100 == 0) {
			if (year % 400 == 0) {
				mn[1] = 29;
			} else {
				mn[1] = 28;
			}
		} else if (year % 4 == 0) {
			mn[1] = 29;
		} else {
			mn[1] = 28;
		}
		if (year == year2 && month == month2 && day == day2) {
			cout << cnt;
			return 0;
		}
		if (day == mn[month - 1]) {
			day = 0;
			month++;
		}
		if (month > 12) {
			month = 1;
			year++;
		}
		day++;
		cnt++;

	}
}
