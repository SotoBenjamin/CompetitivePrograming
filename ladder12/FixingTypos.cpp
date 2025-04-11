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
    string s; cin>>s;
    n = s.size();
    vector<bool> p(n,true);
    int cnt_act = 1;
    int cnt_prev = 0;
    int i = 1;
    while(i < n){
        while(s[i] == s[i-1]){
            cnt_act++;
            if(cnt_prev == 2){
                if(cnt_act >= 2){
                    p[i] = false;
                }
            }
            else{
                if( cnt_act >= 3){
                    p[i] = false;
                }
            }
            i++;
        }
        if(cnt_prev == 2){
            cnt_prev = 1;
            cnt_act = 1;
            i++;
            continue;
        }
        //cnt_prev = 1
        if(cnt_act >= 3){
            cnt_prev = 2;
            cnt_act =1;
            i++;
            continue;
        }
        // cnt_act = 2 o 1
        cnt_prev = cnt_act;
        cnt_act = 1;
        i++;        
    }
    string ans;
    for(int i = 0 ; i < n ; i++){
        if(p[i]) ans += s[i];
    } 
    cout<<ans<<"\n";
    
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