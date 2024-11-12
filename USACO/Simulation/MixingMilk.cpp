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
	vector<pair<ll,ll>> v(3);
	for(int i = 0 ; i < 3 ; i++) cin>>v[i].fi>>v[i].se;
	int i = 0;
	int cnt = 0;
	while(cnt < 100){
		int j = (i+1)%3;
		ll pas = min(v[j].fi - v[j].se , v[i].se);
		v[j].se += pas;
		v[i].se -= pas;
		i = j;
		cnt++;
	}
	for(int i = 0 ; i < 3 ; i++) cout<<v[i].se<<"\n";
}
     
int main(){
	freopen("mixmilk.in", "r" ,stdin);
	freopen("mixmilk.out", "w", stdout);

    int t = 1; //cin>>t;
    while(t--) slv();
    return 0;
}
