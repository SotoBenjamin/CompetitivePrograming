#include <bits/stdc++.h>
#define dbg(x) cerr<<#x<<" : "<<x<<endl;
#define all(x) x.begin(),x.end()
#define pb push_back
#define EPS 1e-9
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using ld = long double;
using ll = long long int;
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T>
using indexed_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

int n,a,b;



void slv(){
	vector<pair<ld,ld>> ranges;
	ranges.reserve(n);
	for(int i = 0 ; i < n ; i++){
		int m,c; cin>>m>>c;
		ll delta = m*m - 4*a*(b-c);
		if(delta < 0) continue;
		ld x1 = m + sqrtl(delta);
		ld x2 = m - sqrtl(delta);
		ld l = min(x1,x2);
		ld r = max(x1,x2);
		ranges.push_back({l,r});
	}
	sort(all(ranges));
	
	indexed_set<pair<ld,int>> s;
	ll ans = 0;
	int t = 0;
	int i = 0;
	int M = (int) ranges.size();
	while(i < M){
		int j = i;
		ld c = ranges[i].first;
		while(j < M && fabs(c-ranges[j].first) < EPS) j++;
		for(int k = i ; k < j ; k++){
			ld l = ranges[k].first;
			ld r = ranges[k].second;
			if(l >= r) continue;
			ans += s.order_of_key({r,INT_MIN}) - s.order_of_key({l,INT_MAX});
		}
		for(int k = i ; k < j ; k++) s.insert({ranges[k].second,t++});
		i = j;
	}
	
	cout<<ans<<"\n";
}


int main(){
	while(cin>>n>>a>>b){
		slv();
	}
	return 0;
}
