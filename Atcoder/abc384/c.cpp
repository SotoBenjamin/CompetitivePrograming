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



int f(string & s , map<char,int> & mp){
    int ans = 0;
    for(char & c : s){
        ans += mp[c];
    }
    return ans;
}

void slv(){ 
    int a[5];
    for(int i = 0 ; i < 5 ; i++) cin>>a[i];
    string s = "ABCDE";
    map<char,int> mp;
    for(int i = 0 ; i < sz(s) ; ++i){
        mp[s[i]] = a[i];
    }

    
    vector<string> v;
    for(int mask = 1 ; mask < (1<<5) ; mask++){
        string s1;
        for(int i = 0 ; i < 5 ; i++){
            if( mask & (1 << i)){
                s1 += s[i];
            }
        }
        v.push_back(s1);
    }

    sort(v.begin() , v.end() , [&](string &a, string& b){
        if( f(a,mp) != f(b,mp)){
            return f(a,mp) > f(b,mp);
        }
        else{
            return a < b;
        }
    });
    for(auto& s : v){
        cout<<s<<"\n";
    }

}
     
int main(){
    //freopen("b.in" , "r" , stdin);
    slv();
    return 0;
}