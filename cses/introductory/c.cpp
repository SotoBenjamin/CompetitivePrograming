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

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}
const int N = 2e5;
int p[N];

signed slv(){ 
    //setIO("a");
    string s; cin>>s;
    int n = s.size();
    int ans = 1;
    int cnt = 1;
    for(int i = 1 ; i < n ; i++){
        if( s[i] == s[i-1]){
            cnt++;
            continue;
        }
        ans = max(ans,cnt);
        cnt = 1;
    }
    ans = max(ans,cnt);
    cout<<ans<<"\n";
    return 0;
}
     
signed main(){
    int t = 1; 
    while(t--) slv();
    return 0;
}