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
    int n; scanf("%d",&n);
    for(int i = 0 ; i < n-1 ; i++) {
        int item; scanf("%d",&item);
        p[item-1]= 1;
    }

    for(int i = 0 ; i < n ; i++){
        if(!p[i]){
            printf("%d\n",i+1);
            return 0;
        }
    }
    return 0;
}
     
signed main(){
    int t = 1; //scanf("%d",&t);
    while(t--) slv();
    return 0;
}