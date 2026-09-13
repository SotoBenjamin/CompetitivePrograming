#include <bits/stdc++.h>
#define INF 1e9
#define dbg(x) cout<<#x<<" = "<<x<<endl;
#define ll long long
using namespace std;


int n;
int m;

string a,b;


void f(string& s, map<string,int>& A){
	for(int i = 0 ; i < (int) s.size() ; i++){
		string temp;
		for(int j = i ; j < (int) s.size() ; j++){
			temp += s[j];
			//dbg(temp);
			if(A.count(temp) > 0){
				int v = A[temp];
				A[temp] = min(v,i + (int)s.size()-1 -j);
			}
			else A[temp] = i + (int)s.size()-1-j;
		}
		
	}
	//cout<<"-----------------------------------\n";
}

void slv(){
	cin>>a>>b;
	n = (int) a.size();
	m = (int) b.size();
	

	map<string,int> A,B;

	f(a,A);
	f(b,B);

	int ans = n+m;
	for(auto& [s,op] : A){
		if(B.count(s) > 0){
			ans = min(ans,op + B[s]);
		}
	}
	
	cout<<ans<<"\n";
	
}

int main(){
    int t = 1; cin>>t;
    while(t--) slv();
    return 0;
}
