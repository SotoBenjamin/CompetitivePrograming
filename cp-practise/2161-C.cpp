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

int n,x;

using i3 = tuple<int,int,int>;
using i2 = pair<ll,ll>;

void slv(){
	cin>>n>>x;
	int a[n];
	for(int i = 0 ; i < n ; i++) cin>>a[i];
	sort(a,a+n);
	int l = 0 , r = n-1;
	ll ans = 0;
	ll s = 0;
	vector<int> p;
	while(l <= r){
		//dbg(s);
		if(s + a[r] >= x){
			s += a[r];
			ans += a[r];
			p.push_back(r);
			s = s % x;
			r--;
		}
		else{
			s += a[l];
			p.push_back(l);
			l++;
		}
	}
	cout<<ans<<"\n";
	for(auto& i : p) cout<<a[i]<<" ";
	cout<<"\n";
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
