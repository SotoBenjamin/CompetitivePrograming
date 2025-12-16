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

int n,q;

using i3 = tuple<int,int,int>;

vector<int> ind[2];
vector<int> pre[2];

int first_greater(vector<int>& a,int t){
	int l = 0 , r = (int) a.size()-1;
	int ans = -1;
	while(l <= r){
		int m = (l+r)/2;
		if(a[m] >= t){
			ans = m;
			r = m-1;
		}
		else l = m+1;
	}
	return ans;
}

int last_less(vector<int>& a,int t){
	int l = 0 , r = (int) a.size()-1;
	int ans = -1;
	while(l <= r){
		int m = (l+r)/2;
		if(a[m] <= t){
			ans = m;
			l = m+1;
		}
		else r = m-1;
	}
	return ans;
}

int query(int l,int r){
	int len = r-l+1;
	if(len % 3 != 0) return -1;
	int s0 = first_greater(ind[0],l);
	int e0 = last_less(ind[0],r);
	int s1 = first_greater(ind[1],l);
	int e1 = last_less(ind[1],r);
	int cnt0 = 0 , cnt1 = 0;
	if( e0 != -1 && s0 != -1 && s0 <= e0) cnt0 = e0-s0+1;
	if( e1 != -1 && s1 != -1 && s1 <= e1) cnt1 = e1-s1+1;
	if(cnt0 % 3 != 0 || cnt1 % 3 != 0) return -1;
	if(cnt0 == 0 || cnt1 == 0) return len/3;
	int cntp0 = s0 == 0 ?  pre[0][e0] : pre[0][e0] - pre[0][s0-1];
	int cntp1 = s1 == 0 ?  pre[1][e1] : pre[1][e1] - pre[1][s1-1];
	int cntip0 = cnt0 - cntp0;
	int cntip1 = cnt1 - cntp1;
	if(cntp0 == cnt0 && cntip1 == cnt1) return len/3 + 1;
	if(cntp1 == cnt1 && cntip0 == cnt0) return len/3 + 1;
	return len/3;
}

void slv(){
	cin>>n>>q;
	ind[0].clear();
	ind[1].clear();
	for(int i = 0 ; i < n ; i++){
		int e; cin>>e;
		ind[e].pb(i);
	}
	for(int i = 0 ; i < 2 ; i++){
		pre[i].assign(ind[i].size(),0);
		if(ind[i].empty()) continue;
		pre[i][0] = ind[i][0] % 2 == 0;
		for(int j = 1 ; j < (int) ind[i].size(); j++){
			pre[i][j] = pre[i][j-1] + (ind[i][j] % 2 == 0);
		}
	}
	
	while(q--){
		int l,r;
		cin>>l>>r;
		l--;
		r--;
		cout<<query(l,r)<<"\n";
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
