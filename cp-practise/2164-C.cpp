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
	cin>>n>>m;
	multiset<int> a;
	vector<i2> monsters(m);
	for(int i = 0 ; i < n ; i++){
		int x; cin>>x;
		a.insert(x);	
	}
	for(int i = 0 ; i < m ; i++) cin>>monsters[i].first;
	for(int i = 0 ; i < m ; i++) cin>>monsters[i].second;
	vector<i2> v1,v2;
	for(int i = 0 ; i < m ; i++){
		if(monsters[i].second != 0) v1.pb(monsters[i]);
		else v2.pb(monsters[i]);
	}
	sort(all(v1));
	sort(all(v2));
	int ans = 0;
	for(auto& e : v1){
		int t = e.first;
		auto it = a.lower_bound(t);
		if(it == a.end()) continue;
		int x = *it;
		a.erase(it);
		ans++;
		x = max(x,e.second);
		a.insert(x);
	}
	for(auto& e : v2){
		int t = e.first;
		auto it = a.lower_bound(t);
		if(it == a.end()) continue;
		a.erase(it);
		ans++;
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
