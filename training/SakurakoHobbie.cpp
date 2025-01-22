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
int t;
int n;
string s;
int f(vi &p , vector<bool>& vis , int u){
    int cnt = (s[u] == '0');
    int current = p[u];
    vis[u] = true;
    while( current != u){
        cnt += (s[current] == '0');
        vis[current] = true;
        current = p[current];
    }
    return cnt;
}

void g(vi& p , vi& ans , int u , int cnt){
    ans[u] = cnt;
    int current = p[u];
    while(current != u){
        ans[current] = cnt;
        current = p[current];
    }       
}

void slv(){
    cin>>n;
    vi p(n);
    for(int i = 0 ; i < n ; i++) {
        cin>>p[i];
        p[i]--;
    }
    cin>>s;
    vector<bool> vis(n,false);
    vi ans(n);
    for(int i = 0 ; i < n ; i++){
        if( vis[i]){
            continue;
        }
        int cnt = f(p,vis,i);
        g(p,ans,i,cnt);
    }
    for(int& i : ans) cout<<i<<" ";
    cout<<"\n";
}   
     
int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);    
    freopen("output.txt","w",stdout);
    #endif

    cin>>t;
    while(t--) slv();
    
    return 0;
}