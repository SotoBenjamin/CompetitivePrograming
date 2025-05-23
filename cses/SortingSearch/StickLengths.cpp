#include <algorithm>
#include <bits/stdc++.h>
#include <cstdint>
#include <vector>
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
typedef vector<int> vi;
typedef vector<pair<int,int>> vpii;
typedef vector<ll> vl;
typedef vector<pair<ll,ll>> vpll;
     
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
int n,m,k;
ll x;


void slv(){
    vl a(n);
    for(auto& i : a) cin>>i;
    sort(all(a));
    vl pre(n); pre[0] = a[0];
    for(int i = 1 ; i < n ; i++) pre[i] = pre[i-1] + a[i];
    ll ans = (pre[n-1] - pre[0]) - a[0]*(n-1);
    for(int i = 1 ; i < n ; i++){
        ll left =  a[i]*i - pre[i-1];
        ll right = (pre[n-1] - pre[i]) - a[i]*(n-i-1); 
        ans = min(ans,left+right);
    }
    cout<<ans<<"\n";
}   
     
int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);    
    freopen("output.txt","w",stdout);
    #endif


    while(cin>>n) slv();
    return 0;
}