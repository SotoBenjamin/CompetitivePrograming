#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n;
void slv(){
	int x = 10000, y = 10000;
	for(int i = 0 ; i < n ; i++){
		int a,b; cin>>a>>b;
		string s; cin>>s;
		y -= a;
		if(s == "keep") x -= b;
		else x -= a;
	}
	
	cout<<(y-x)<<"\n";
}

int main(){
	while(cin >> n) slv();
	return 0;
}
