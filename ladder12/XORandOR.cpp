#include <bits/stdc++.h>
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
 
int n,k;
const int MX = 1e5;

void slv(){
    string a,b;
    cin>>a>>b;
    if( sz(a) != sz(b)){
        cout<<"NO"<<"\n";
        return;
    }
    n = sz(a);
    vector<int> pre(n);
    vector<int> suff(n);
    pre[0] = a[0] == '1' ? 1 : 0;
    for(int i = 1 ; i < n ; i++) a[i] == '1' ? pre[i] = pre[i-1] + 1 : pre[i] = pre[i-1];
    suff[n-1] = a[n-1] == '1' ? 1 : 0;
    for(int i = n-2 ; i >= 0 ; i--) a[i] ==  '1' ? suff[i] = suff[i+1] + 1 : suff[i] = suff[i+1];
    int c = 0;
    int d = 0;
    for(int i = 0 ; i < sz(a) ; i++){
        if(a[i] == b[i]) continue;
        if(a[i] == '1'){
            if( i <= n-2 && suff[i+1] > 0){
                c++;
                continue;
            }
            if( i >= 1 && pre[i-1] + d - c > 0){
                c++;
                continue;
            }
            cout<<"NO"<<"\n";
            return;
        }
        else{
            if( i >= 1 && pre[i-1] + d - c > 0){
                d++;
                continue;
            }
            if( i <= n-2 && suff[i+1] > 0){
                d++;
                continue;
            }
            cout<<"NO"<<"\n";
            return;
        }
    }
    cout<<"YES"<<"\n";
}   
     
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);    
    freopen("output.txt","w",stdout);
    #endif
    int t = 1;
    //cin>>t;
    while(t--) slv();
    return 0;
}