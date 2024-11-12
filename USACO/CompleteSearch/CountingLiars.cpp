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



void slv(int n){
	vector<pair<int,char>> a(n);
	for(auto &i : a) cin>>i.se>>i.fi;
	sort(all(a));
	int ans = n+1;
	for(int i = 0 ; i < n ; i++){
		int cnt = 0;
		for(int j = 0 ; j <i ; j++ ) if(a[j].se == 'L') cnt++;
		for(int j = i+1 ; j < n ; j++) if(a[j].se == 'G') cnt++;
		ans = min(ans,cnt);
	}
	cout<<ans<<"\n";
}
     
int main(){
	//freopen("liars.in", "r" ,stdin);
	//freopen("blocks.out", "w", stdout);
	int n;
    while(cin>>n){
		slv(n);
	}
    return 0;
}


