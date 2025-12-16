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

int n,k;

using i3 = tuple<int,int,int>;


void slv(){
    cin>>n>>k;
	vector<i3> a(n);
	for(int i = 0 ; i < n ; i++){
		int l,r,e; cin>>l>>r>>e;
		a[i] = {l,r,e};
	}
	sort(all(a));
	for(int i = 0 ; i < n ; i++){
		auto [l,r,e] = a[i];
		if( k>=l && k <= r && k < e){
			k = e;
		}
	}
	cout<<k<<"\n";
}

int main(){
    int t; cin>>t;
	while(t--){
		slv();
	}
	return 0;
}
