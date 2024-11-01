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
    string s; cin>>s;
    int k; cin>>k;
    
    for(int i = 0 ; i < sz(s) ; i++){
        char c = s[i];
        int idx = i;
        for(int j = i+1 ; j < sz(s); j++){
            if( s[j] >= c){
                idx = j;
            }
        }
        if( s[i] == s[idx] ) continue;
        
        if( k >= 1) {swap(s[i],s[idx]);k--;}
        if( k == 0) break;
        
    }

    cout<<s<<"\n";

    return 0;
}
     
signed main(){
    int t = 1; //cin>>t;
    while(t--) slv();
    return 0;
}