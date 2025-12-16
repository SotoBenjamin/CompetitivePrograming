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

int n,m;

using i3 = tuple<int,int,int>;
using i2 = pair<int,int>;

void slv(){
	cin>>n;
	int a[n];
	for(int i = 0 ; i < n ; i++) cin>>a[i];
	map<int,int> f;
	ll ans = 0;
	for(int i = 0 ; i < n ; i++){
		int t = a[i]-i;
		if(f.count(t) > 0) ans += f[t];
		f[a[i]-i]++;
	}
	cout<<ans<<"\n";
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
