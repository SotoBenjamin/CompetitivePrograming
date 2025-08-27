#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> 
using ordered_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define ll long long 
const int MAX = 1e6 +5;
const ll MOD = 1e9 + 7;

void slv(){
	int n,q;	
	cin>>n>>q;
	int v[n];
	ordered_set<pair<int,int>> s;
	for(int i = 0 ; i < n ; ++i){ 
		cin>>v[i];
		s.insert({v[i],i});
	}
	while(q--){
		char type; cin>>type;
		if(type == '!'){
			int k,x; cin>>k>>x;
			k--;
			s.erase({v[k],k});
			v[k] = x;
			s.insert({v[k],k});
		}
		else{
			int a,b; cin>>a>>b;
			int ans = s.order_of_key({b+1,-1}) - s.order_of_key({a,-1});
			cout<<ans<<"\n";
		}
	}
	
}



int main() {
	int t=1; //cin>>t;
	while(t--) slv();
	return 0;
}

