#include <bits/stdc++.h>
#define sz(x) (int)x.size()
#define fi first
#define se second
#define DBG(x) cout << #x << " = " << x << '\n';
#define DBGS(x) cout << #x << " = " << x << ", ";
#define all(x) x.begin() , x.end()
using namespace std;


typedef long long int ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
     
template<typename T>                                                             
T minV(T a){
    return a;
}

template<typename T, typename ... Args>
T minV(T a , Args... arg){
    T b = minV(arg...);
    return min(a,b);
}



void slv(){
	int n; cin>>n;
	vector<ll> ans(26,0);
	while(n--){
		string a,b; cin>>a>>b;
	
		vector<ll> freca(26,0);
		vector<ll> frecb(26,0);
		for(char c : a) freca[int(c)-97] ++;
		for(char c : b) frecb[int(c)-97] ++;
		for(int i = 0 ; i < 26 ; i++){
			ans[i] += max(freca[i],frecb[i]);
		}	
	}
	
	for(auto i : ans) cout<<i<<"\n";	
}
     
int main(){
	freopen("blocks.in", "r" ,stdin);
	freopen("blocks.out", "w", stdout);

    int t = 1; //cin>>t;
    while(t--) slv();
    return 0;
}


