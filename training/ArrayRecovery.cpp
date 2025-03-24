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
int t,n;


void slv(){
    cin>>n;
    int p[n];
    for(int&i : p) cin>>i;
    int a[n]; a[0] = p[0];
    for(int i = 1 ; i < n ; i++){
        if(p[i] != 0  &&  a[i-1] - p[i] >= 0){
            cout<<-1<<"\n";
            return;
        }
        a[i] = a[i-1] + p[i];
    }
    for(int& i : a) cout<<i<<" ";
    cout<<"\n";
}   
     
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);    
    freopen("output.txt","w",stdout);
    #endif
    t = 1;
    cin>>t;
    while(t--) slv();
    return 0;
}