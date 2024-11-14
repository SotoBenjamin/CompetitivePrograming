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



signed slv(){ 
    int n,a,b;
    string s;
    cin>>n>>a>>b;
    cin>>s;
    int posx = 0 , posy = 0;
    for(int i = 1 ; i<= 100; i++){
        for(char &c : s){
            if(posx == a && posy == b){
                cout<<"YES"<<"\n";
                return 0;
            }
            switch (c){
                case 'N':
                    posy++;
                    break;
                case 'S':
                    posy--;
                    break;
                case 'E':
                    posx++;
                    break;
                case 'W':
                    posx--;
                    break;
                
                default: break;
            }
        }
    }
    cout<<"NO"<<"\n";
    return 0;
}
     
signed main(){
    //freopen("a.in" , "r" , stdin);
    int t = 1; cin>>t;
    while(t--) slv();
    return 0;
}
