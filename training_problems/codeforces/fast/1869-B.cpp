#include <bits/stdc++.h>
#define INF 1e18
#define dbg(x) cout<<#x<<" = "<<x<<endl;
#define ll long long
using namespace std;


int n,k,a,b;

using i2 = pair<ll,ll>;
vector<i2> v;


ll dist(int i , int j){
	if(i < k && j < k) return 0;
	return abs(v[i].first - v[j].first) + abs(v[i].second - v[j].second);
}

void slv(){
	cin>>n>>k>>a>>b;
	a--;
	b--;
	v.assign(n,{});
	for(int i = 0 ; i  < n ; i++) cin>>v[i].first>>v[i].second;
	ll ans = dist(a,b);
	ll d1 = INF, d2 = INF;
	for(int i = 0 ; i < k ; i++) d1 = min(d1, dist(i,a)) , d2 = min(d2,dist(i,b));
	if(d1 != (ll)INF && d2 != (ll)INF) ans = min(ans, d1 + d2);
	cout<<ans<<"\n";
}

int main(){
    int t = 1; cin>>t;
    while(t--) slv();
    return 0;
}
