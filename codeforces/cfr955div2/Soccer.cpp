#include "bits/stdc++.h"
#define sz(x) (int)x.size()
#define fi first
#define se second
#define DBG(x) cout << #x << " = " << x << '\n';
#define DBGS(x) cout << #x << " = " << x << ", ";
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
 
const ll mod = 1e9+7;
 
int nxt() {
    int x; cin >> x;
    return x;
}
 
const int inf = INT_MAX;
 
template<typename T>
T sign(T a){
	if(a > 0) return 1;
	else if(a < 0) return -1;
	return 0;
}
 
        
signed slv() {
	int x1,y1; cin>>x1>>y1;
	int x2,y2; cin>>x2>>y2;
	if(sign(x1-y1) == sign(x2-y2)){
		cout<<"YES"<<"\n";
		return 0;
	}
    
    cout<<"NO"<<"\n";
		
 
    return 0;
}
 
signed main(){
	//freopen("a.in","r",stdin);
    int t; cin>>t;
    while(t--) slv();
    return 0;
}
