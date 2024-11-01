#include <bits/stdc++.h>
#define sz(x) (int)x.size()
#define fi first
#define se second
#define DBG(x) cout << #x << " = " << x << '\n';
#define DBGS(x) cout << #x << " = " << x << ", ";
#define all(x) x.begin() , x.end()
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
T minV(T a){
    return a;
}
 
template<typename T, typename ... Args>
T minV(T a , Args... arg){
    T b = minVariadic(arg...);
    return min(a,b);
}



ll gcd(ll a,ll b){
    if(b == 0) return a;
    else return gcd(b,a%b);
}



ll lcm(ll a,ll b){
    return (a/gcd(a,b))*b;
}



signed slv(){ 
    ll N; cin>>N;
    int k; cin>>k;
    vector<ll> e(k);
    for(int i = 0 ; i < k; i++) cin>>e[i];
    sort(e.begin() , e.end());
    ll ans = N/e[0] + N/e[1] - N/(e[1]*e[0]);

    for(int i = 2  ; i < k ; i++){
        if( e[i] > N) continue;
        ans += N/e[i];
        ll d = e[i];
        int cnt = 0;
        for(int j = 0 ; j <= i-1 ; j++){
            ll f  = e[i]*e[j];
            ans -= N/f;
            if( d*e[j] <= N){
                d = d*e[j];
                cnt++;
            }
        }
        if(cnt > 1) ans += N/d;
        
    }

    

    cout<<ans<<"\n";



    return 0;
}
     
signed main(){
    int t = 1; //cin>>t;
    while(t--) slv();
    return 0;
}