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
void slv(){ 
    cin>>n;
    string s; cin>>s;
    int cnt = 0;
    for(char i : s){
        if( i == '1'){
            cnt++;
        }
    }

    if( cnt == 2){
        for(int i = 1 ; i < n ; i++){
            if( s[i] == '1' && s[i-1] == '1'){
                cout<<"NO"<<"\n";
                return;
            }
        }

        cout<<"YES"<<"\n";
        return;
    }


    cnt % 2 == 0  ?  cout<<"YES" : cout<<"NO";
    cout<<"\n";
}
     
int main(){
    freopen("a.in" , "r" , stdin);
    int t = 1; cin>>t;
    while(t--) slv();
    return 0;
}