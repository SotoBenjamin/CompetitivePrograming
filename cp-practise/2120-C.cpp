#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define dbg(x) cerr<<#x<<" : "<<x<<endl;
#define all(x) x.begin(),x.end()
#define pb push_back
#define EPS 1e-9
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

ll n,m;

using i3 = tuple<int,int,int>;
using i2 = pair<ll,ll>;

void slv(){
	cin>>n>>m;
	ll a[n+1];
	a[1] = 1;
	if( m < n || m > n*(n+1)/2 ){
		cout<<-1<<"\n";
		return;
	}	
	for(int i = 2 ; i <= n ; i++) a[i] = a[i-1] + i;
	int j = (int)n;
	vector<i2> ans;
	while(j >= 1){
		if(a[j] + (n-j) <= m) break;
		j--;
	}
	for(int i = j; i >= 2 ; i--) ans.pb({i,i-1});
	for(int i = j+1 ; i <= n ; i++) ans.pb({i,1});		
	if(j != n){
		ll t = m - (a[j] + n - j);
		ans.back().second += t; 
	}
	cout<<j<<"\n";
	for(auto [u,v] :  ans){
		cout<<u<<" "<<v<<"\n";
  }
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int t; cin>>t;
	while(t--){
		slv();
	}
	return 0;
}
