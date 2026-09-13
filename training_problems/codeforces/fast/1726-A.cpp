#include <bits/stdc++.h>
#define INF 1e9
#define dbg(x) cout<<#x<<" = "<<x<<endl;
#define ll long long
using namespace std;


int n;

vector<int> a;




void slv(){
	cin>>n;
	a.assign(n,0);
	for(int i = 0 ; i < n ; i++) cin>>a[i];
	
	if(n == 1){
		cout<<"0\n";
		return;
	}
	
	int x = INF;
	int ans = -INF;
	for(int i = 0 ; i < n-1 ; i++){
		ans = max(ans,a[i] - a[i+1]);
	}

	for(int i = 0 ; i < n ; i++){
		x = min(x,a[i]);
		ans = max(ans,a[n-1]-x);
	}
	
	x = -INF;
	for(int i = n-1 ; i >= 0 ; i--){
		x = max(x,a[i]);
		ans = max(ans,x - a[0]);
	}
	
	cout<<ans<<"\n";
}

int main(){
    int t = 1; cin>>t;
    while(t--) slv();
    return 0;
}
