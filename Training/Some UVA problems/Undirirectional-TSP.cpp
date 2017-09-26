#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long int
using namespace std;
#define clr(v , d)	memset(v , d , sizeof v)
#define sz(v)		((int)(v).size())
const int VISITED = 1;
const int UNVISITED = -1;
const long long OO = 1e12;
const int OOI = 1e9;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int xdir[] = { 1, -1, 0, 0 };
int ydir[] = { 0, 0, 1, -1 };
int n  , m , arr[11][101] , mem[11][101] , path[11][101];
vi vec[11];
int cnt = 0;
int solve(int x , int y){
	if(y > m)
		return 0;
	if(x > n)
		x = 1;
	if(x <= 0)
		x = n;

	int& ret = mem[x][y];
	if(ret != OOI)
		return ret;

	int p[3] = {x+1 , x , x-1};
	if(p[0] > n)
		p[0] = 1;
	if(p[2] <= 0)
		p[2] = n;

	for(int i = 0; i < 3 ; i++){
		int val = solve(p[i] , y + 1) + arr[x][y];
		if(val < ret || (ret == val && path[x][y]> p[i])){
			ret = val;
			path[x][y] = p[i];
		}
	}

	return ret;
}

int main() {
	freopen("in.txt", "r", stdin);
	while(cin >> n >> m ){
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j){
				cin >> arr[i][j];
				mem[i][j] = OOI;
			}


		int ma = OOI;
		int r = 0;
		for(int i = 1 ; i <= n;i++){
			int res = solve(i , 1);
			if(res < ma){
				ma = res;
				r = i ;
			}
		}

		for(int i = 1 ; i <= m;i++){
			printf((i==1)?"%d":" %d" , r);
			r = path[r][i];
		}
		printf("\n%d\n", ma);
	}
	return 0;
}
