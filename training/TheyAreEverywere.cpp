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

bool isvalid(map<char,int>& f , map<char,int>& g){
    for(auto& p : f){
        if(p.se > g[p.fi]){
            return false;
        }
    }
    return true;
}


void slv(){
    string s; cin>>s;
    map<char,int> f;
    map<char,int> g;
    for(char& c : s) f[c] = 1;
    
    int l = 0 , r = 0;
    for(; r < n ; r++){
        g[s[r]]++;
        if(isvalid(f,g)){
            break;
        }
    }
    int ans = r-l+1;
    g[s[l]]--;
    l++;
    while(r < n){
        if(isvalid(f,g)){
            ans = min(ans,r-l+1);
            g[s[l]]--;
            l++;
        }
        else{
            r++;
            g[s[r]]++;
        }
    }
    cout<<ans<<"\n";
}        
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);    
    freopen("output.txt","w",stdout);
    #endif

    
    while(cin>>n) slv();
    
    return 0;
}