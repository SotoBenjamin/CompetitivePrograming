#include <bits/stdc++.h>
#include <numeric>
#define ll long long int
#define dbg(x) cerr<<#x<<" = "<<x<<endl;

#define all(x) x.begin(),x.end()

const int MAXN = 2e5 + 5;

using namespace std;

int n;
string s;
void slv(){
    cin>>n>>s;
    vector<int> ans;
    int last_z = -1;
    int last_one = -1;
    for(int i = 0 ; i < n-1 ; i++){
        char c = s[i];
        int res = 0;
        if(c == '1'){
            int r = i+2;
            int l = r - last_z -1;
            res = r-l+1;
            last_one = i;
        }
        else{
            int l = 1;
            int r = l + last_one + 1;
            res = r-l+1;
            last_z = i;
        }
        ans.push_back(res);
    }
    for(int i : ans) cout<<i<<" ";
	  cout<<"\n";
}

signed main(){
	  ios_base::sync_with_stdio(false);
	  cin.tie(NULL);
	  int t = 1; cin>>t;
	  while(t--) slv(); 
	  return 0;
}
