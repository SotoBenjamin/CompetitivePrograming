#include <bits/stdc++.h>
#define INF 1e18
#define dbg(x) cout<<#x<<" = "<<x<<endl;
#define ll long long
using namespace std;

//https://codeforces.com/contest/2254/problem/B
int n;
//s0 s1 s2 .... sn-1
// i,j
void slv(){
    cin>>n;
    string s; cin>>s;
    int del = 0;
    for(int i = 1 ; i <= n-2 ; i++){
        if(s[i] != s[i-1] && s[i] != s[i+1]){
            if(s[i-1] == s[i+1]) del = max(del,2);
            else del = max(del,1);
        }
    }
    int i =0 , j= 1;
    int ans = 0;
    while(i < n){
        while(j < n && s[j] == s[j-1]) j++;
        ans++;
        i = j;
        j++;
    }
    cout<<(ans-del)<<"\n";
}

int main(){
    int t = 1; cin>>t;
    while(t--) slv();
    return 0;
}
