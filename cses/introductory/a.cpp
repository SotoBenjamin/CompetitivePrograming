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

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}



signed slv(){ 
    //setIO("a");
    ll n; cin>>n;
    cout<<n<<" ";
    while( n != 1){
        if( n&1) n = 3*n +1;
        else n = n/2;
        cout<<n<<" ";
    }
    cout<<"\n";
    return 0;
}
     
signed main(){
    int t = 1; //scanf("%d",&t);
    while(t--) slv();
    return 0;
}
