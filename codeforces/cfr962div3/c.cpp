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



int n;
int q;
signed slv(){ 
    scanf("%d %d",&n,&q);
    char a[n+1];
    char b[n+1];
    scanf("%s",a+1);
    scanf("%s",b+1);
    ll frecA[26][n+1];
    ll frecB[26][n+1];

    for(int i = 0 ; i < 26 ; i++)
        for(int j = 0 ; j <= n ; j++) frecA[i][j] = 0;

    for(int i = 0 ; i < 26 ; i++)
        for(int j = 0 ; j <= n ; j++) frecB[i][j] = 0; 
    

    for(int i = 1 ; i <= n ; i++){
        int posA = int(a[i] - 97);
        int posB = int(b[i] - 97);
        for(int j = 0 ; j  < 26 ; j++){
            frecA[j][i] = frecA[j][i-1];
            frecB[j][i] = frecB[j][i-1];
        }
        frecA[posA][i]++;
        frecB[posB][i]++;
    }
    
    while(q--){
        int l,r; scanf("%d %d",&l,&r);
        ll ans = 0;

        for(int i = 0 ; i < 26 ; i++){
            ll cntA = frecA[i][r] - frecA[i][l-1];
            ll cntB = frecB[i][r] - frecB[i][l-1];
            ans += abs(cntA - cntB);
        }
        ans = ans/2;
        printf("%lld\n",ans);
    }


    return 0;
    
}
     
signed main(){
    int t = 1; scanf("%d",&t);
    while(t--) slv();
    return 0;
}