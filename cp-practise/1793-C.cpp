#include <bits/stdc++.h>
#define ll long long int

#define all(x) x.begin(),x.end()

const int MAXN = 2e5 + 5;

using namespace std;

int n;

void slv(){
    cin>>n;
	int p[n];
	set<int> s;
	for(int i = 0 ; i < n ; i++) cin>>p[i], s.insert(p[i]);
	if(n <= 3){
		cout<<-1<<"\n";
		return;
	}
	int l = 0 , r = n-1;
	while(r-l+1 > 3){
		int mn = *s.begin();
		int mx = *s.rbegin();
		bool ok1 = true, ok2 = true;
		if(p[l] == mn || p[l] == mx){
			s.erase(p[l]);
			l++;
			ok1 = false;
		}
		if(p[r] == mn || p[r] == mx){
			s.erase(p[r]);
			r--;
			ok2 = false;
		}
		if(ok1 && ok2) {
			cout<<(l+1)<<" "<<(r+1)<<"\n";
			return;
		}
	}
	cout<<-1<<"\n";
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t = 1; cin>>t;
	while(t--) slv(); 
	return 0;
}
