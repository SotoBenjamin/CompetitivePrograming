#include <bits/stdc++.h>
#define INF 1e18
#define dbg(x) cout<<#x<<" = "<<x<<endl;
#define ll long long
using namespace std;

//https://codeforces.com/contest/2253/problem/B
int n;

vector<int> a;

using i2 = pair<int,int>;
vector<i2> v;


bool f(i2& el1 , i2& el2, int& ans , int i){
	int x = el1.second , y = el2.second;
	if(x == 1 && y == 1) return false;
	int p = (int)v.size() - 2;
	if(x > 1 && y > 1){
		ans = max(ans,p+4);
		return true;
	}
	
	if(x == 1){
		if(i-2 >= 0 && v[i-2].first == el2.first) return false;
		ans = max(ans,p+3);
		return false;
	}
	

	if(i+1 < (int) v.size() && v[i+1].first == el1.first) return false;
	ans = max(ans,p+3);
	return false;
	
}

void slv(){
	cin>>n;
	a.assign(n,0);
	for(int i = 0 ; i < n ; i++) cin>>a[i];
	int l = 0 , r = 1;
	while(l < n){
		while(r < n && a[r] == a[r-1]) r++;
		v.push_back({a[l],r-l});
		l = r;
		r++;
	}
	int ans = (int) v.size();
	int c = 0;
	for(int i = 1 ; i < (int) v.size() ; i++){
		f(v[i-1],v[i],c,i);
		ans = max(ans,c);
		c = 0;	
	}
	
	cout<<ans<<"\n";
	
	v.clear();
}

int main(){
    int t = 1; cin>>t;
    while(t--) slv();
    return 0;
}
