#include <bits/stdc++.h>
#define ll long long
#define int ll 
using namespace std;

int n,k;


int f(int x){
    int cnt = 0;
    int i = 2;
    while(i <= x){
        cnt += (x/i);
        i *= 2;
    }
    return cnt;
}

void slv(){
    int d = f(n) - f(k) - f(n-k);
    if(d > 0){
        cout<<"0\n";
        return;
    }
    cout<<"1\n";
}


signed main(){
    while(cin >> n >> k) slv();
    return 0;
}
