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
    T b = minV(arg...);
    return min(a,b);
}



signed slv(){ 
    string s,t;
    cin>>s>>t;
    int i = 0 , j = 0;
    int n = s.size() , m = t.size();
    while(i < n && j < m ){
        if(s[i] != t[j]) break;
        i++;
        j++;
    }
    i--;
    j--;
    int ans = min( n + m - i, n+m);
    cout<<ans<<"\n";

    return 0;
}
     
signed main(){
    int t = 1; //cin>>t;
    while(t--) slv();
    return 0;
}