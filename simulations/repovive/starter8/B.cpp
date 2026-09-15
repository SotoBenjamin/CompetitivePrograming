#include <bits/stdc++.h>
#define ll long long
#define INF 1e18
using namespace std;
int n;

void slv(){
	ll a[n];
	for(int i = 0 ; i < n ; i++) cin>>a[i];
	ll ans = -INF;
	for(int i = 0 ; i < n ; i++){
		int j = (i+1)%n;
		ans = max(ans,a[i]+a[j]);
	}
	cout<<ans<<"\n";
}

int main(){
	while(cin>>n) slv();
	return 0;
}
