#include <bits/stdc++.h>
#define INF 1e9;
#define dbg(x) cout<<#x<<" = "<<x<<endl;
#define ll long long
using namespace std;
using i2 = pair<int,int>;



//(1,1) 2

void slv(){
	int n; cin>>n;
	int a[n];
	for(int i = 0 ; i < n ; i++) cin>>a[i];
	sort(a,a+n);
	multiset<i2> ms;
	for(int i = 0 ; i < n ; i++){
		int t = a[i]-1;
		auto it = ms.lower_bound({t,n});
		if(it != ms.begin()){
			it--;
			if(it->first == t){
				int cnt = it->second;
				ms.erase(it);
				ms.insert({a[i],cnt+1});
			}
			else{
				ms.insert({a[i],1});
			}
		}
		else{
			ms.insert({a[i],1});
		}
	}
	cout<<ms.size()<<"\n";
}

int main(){
    int t = 1; cin>>t;
    while(t--) slv();
    return 0;
}
