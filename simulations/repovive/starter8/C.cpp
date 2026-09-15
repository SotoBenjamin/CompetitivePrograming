#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
#define dbg(x) cout<<#x<<" = "<<x<<endl;
using namespace std;
int n;



void f(int*a , int x , int y){
	vector<int> l(n,INF);
	vector<int> r(n,INF);
	int best1 = INF;
	for(int i = x ; i <= y ; i++){
		if(a[i] == 1){
			best1 = i;
		}
		l[i] = best1;
	}
	best1 = INF;
	for(int i = y; i >= x ; i--){
		if(a[i] == 1){
			best1 = i;
		}
		r[i] = best1;
	}

	for(int i = x ; i <= y ; i++){
		int d = INF;
		if(r[i] != INF) d = min(d,abs(r[i]-i));
		if(l[i] != INF) d = min(d,abs(l[i]-i));

		if(d+1 != a[i]){
			cout<<"NO\n";
			return;
		}
	}
	cout<<"YES\n";
}

void slv(){
	int a[n];
	for(int i = 0 ; i < n ; i++) cin>>a[i];
	int x = a[0];
	//dbg(x);
	if(a[x] != 1){
		cout<<"NO\n";
		return;
	}

	for(int i = 1 ; i < x ; i++){
		if(a[i] != a[i-1] -1){
			cout<<"NO\n";
			return;
		}
	}

	int y = a[n-1];
	y = n-y-1;
	//dbg(y);
	if(a[y] != 1){
		cout<<"NO\n";
		return;
	}

	for(int i = y+2 ; i < n ; i++){
		if(a[i] != a[i-1] +1){
			cout<<"NO\n";
			return;
		}
	}

	f(a,x,y);
}

int main(){
	while(cin>>n) slv();
	return 0;
}

