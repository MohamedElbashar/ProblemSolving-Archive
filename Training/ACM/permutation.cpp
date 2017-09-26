#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
int main() {
	string str;
	cin>>str;
	do{
		cout<<str<<"\n";
	}while(next_permutation(str.begin(),str.end()));
}
