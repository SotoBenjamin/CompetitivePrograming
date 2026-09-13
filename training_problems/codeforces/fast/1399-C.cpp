#include <bits/stdc++.h>
#define INF 1e9;
#define dbg(x) cout<<#x<<" = "<<x<<endl;
#define ll long long
using namespace std;



int f(int *a, int n, int x){
	map<int,vector<int>> mp;
	int ans = 0;
	for(int i = 0 ; i < n ; i++){
		int target = x - a[i];
		if(mp.count(target) > 0 && mp[target].size() > 0){
			ans++;
			mp[target].pop_back();
		}
		else{
			mp[a[i]].push_back(i);
		}
	}
	return ans;
}


void slv(){
	int n; cin>>n;
	int a[n];
	for(int i = 0 ; i < n ; i++) cin>>a[i];
	int ans = -INF;
	for(int x = 2 ; x <= 2*n ; x++){
		ans = max(ans,f(a,n,x));
	}
	cout<<ans<<"\n";
}

int main(){
    int t = 1; cin>>t;
    while(t--) slv();
    return 0;
}
