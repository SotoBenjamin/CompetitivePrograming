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
    cin>>n;
    vector<int> cnt(32,0);
    for(int i = 0 ; i < n ; i++){
		int e; cin>>e;
		vector<int> x;
		for(int j = 0 ; j < 32 ; j++){
			if(e & (1<<j)) cnt[j]++;
		}
	}
	int c = 0;
	for(int i = 0 ; i < 32 ; i++){
		c = std::gcd(c,cnt[i]);
	}
	if(c == 0){
		for(int i = 0 ; i < n ; i++) cout<<i+1<<" ";
		cout<<"\n";
		return;
	}
	set<int> s;
	for(int i = 1 ; i*i <= c ; i++){
		if(c % i == 0){
			s.insert(i);
			s.insert(c/i);
		}
	}
	for(auto& e : s) cout<<e<<" ";
	cout<<"\n";
}

int main(){
    int t; cin>>t;
	while(t--){
		slv();
	}
	return 0;
}
