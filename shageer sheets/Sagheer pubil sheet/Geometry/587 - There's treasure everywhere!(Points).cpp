#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pi> vpi;
//#define EPS numeric_limits<double>::epsilon()
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define pb push_back
//#define mp make_pair
#define all(v) v.begin(),v.end()
#define mem(a,b) memset(a,b,sizeof a)
#define sz(v) ((int)((v).size()))
#define minn(a, b, c) min(min(a, b), c)
#define maxx(a, b, c) max(max(a,	 b), c)
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
struct point {
	double x, y;
	point() {
		x = y = 0.0;
	}
	point(double _x, double _y) :
			x(_x), y(_y) {
	}
	bool operator <(point other) const {
		if (fabs(x - other.x) > EPS)
			return x < other.x;
		return y < other.y;
	}
	bool operator ==(point other) const {
		return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS));
	}
};

struct vec {
	double x, y;
};

point translate(point p, vec v) {
	return point(p.x + v.x, p.y + v.y);
}

double dist(point p1, point p2) {
	return hypot(p1.x - p2.x, p1.y - p2.y);
}
vec scale(vec v, double s) {
	return vec { v.x * s, v.y * s };
}

int cnt;
int main() {
	file();
	map<string, vec> mp;
	vec w8;
	mp["N"] = vec { 0, 1 }, mp["E"] = vec { 1, 0 };
	mp["S"] = vec { 0, -1 }, mp["W"] = vec { -1, 0 };
	mp["NE"] = vec { 1.0 / sqrt(2), 1.0 / sqrt(2) }, mp["NW"] = vec { -1.0 / sqrt(2), 1.0 / sqrt(2) };
	mp["SW"] = vec { -1.0 / sqrt(2), -1.0 / sqrt(2) }, mp["SE"] = vec { 1.0 / sqrt(2), -1.0 / sqrt(2) };
	string s;
	while (getline(cin, s) && s != "END") {
		stringstream iss(s);
		string str;
		point cur = point(0, 0);
		while (getline(iss, str, ',')) {
			string pos;
			double stp = 0.0;
			for (int i = 0; i < (int) str.length(); i++) {
				if (str[i] >= '0' && str[i] <= '9')
					stp *= 10, stp += str[i] - '0';
				else if (isalpha(str[i]))
					pos += str[i];
			}
//			elawal b3ml scale 3a4an atl3 4akl el segement
//			b3ml translate 3a4an an2l el start point ll end bta3 el segement ele 2blha
			w8 = scale(mp[pos], stp), cur = translate(cur, w8);
			pos.clear();
		}
		printf("Map #%d\n", ++cnt);
		printf("The treasure is located at (%.3lf,%.3lf).\n", cur.x, cur.y);
		printf("The distance to the treasure is %.3lf.\n\n",
				dist(point(0,0), cur));
	}

}

