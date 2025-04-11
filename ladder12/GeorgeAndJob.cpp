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
typedef vector<ll> vl;
typedef vector<pair<ll,ll>> vpll;
typedef vector<pair<int,int>> vpii;

const ll mod = 1e9+7;
const ll cc =  998244353;
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
int t,n,m;
const ll MAX= 1e5 + 5;


void slv(){
    int k;
    cin>>n>>m>>k;
    vl a(n+1);
    for(int i = 1 ; i <= n ; i++) cin>>a[i];
    ll pre[n+1]; pre[0] = 0;
    for(int i = 1 ; i <= n ; i++) pre[i] = pre[i-1] + a[i];
    int l = 1 , r = m;
    
    vpll inter(n-m+2);
    vl v(n-m+2);
    int j = 1;

    while(r <= n){
        inter[j] = {l,r};
        v[j] = pre[r] - pre[l-1];
        r++;
        l++;
        j++;
    }
    vector<int> p( n-m+2 , -1);
    for(int i = 1 + m ; i <= n-m+1 ; i++){
        for(int j = i-1 ; j >= 1 ; j--){
            if( inter[j].se < inter[i].fi){
                p[i] = j;
                break;
            }
        }
    }

    vector<vector<ll>> dp(n-m+2 , vector<ll>(k+1,-1));
    int c = n-m+1;
    dp[1][1] = v[1];
    for(int i  = 1 ; i <= c ; i++){
        dp[i][1] = max(dp[i-1][1] , v[i]);
    }
    for(int j = 2 ; j <= k ; j++){
        for(int i = 1 + (j-1)*m ; i <= c ; i++){
            if( i == 1 + (j-1)*m){
                dp[i][j] = v[i] + dp[p[i]][j-1];
                continue;
            }
            dp[i][j] = max(v[i] + dp[p[i]][j-1] , dp[i-1][j]);
        }
    }
    cout<<dp[c][k]<<"\n";
}   
     
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);    
    freopen("output.txt","w",stdout);
    #endif
    t = 1;
    //cin>>t;
    while(t--) slv();
    return 0;
}