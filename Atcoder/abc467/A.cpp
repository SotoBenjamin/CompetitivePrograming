#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll h,w;
//w/h2 >= 25

void slv(){
	if(w*10000 >= 25*h*h){
		cout<<"Yes\n";
		return;
	}
	cout<<"No\n";
}

int main(){
	while(cin >> h >> w) slv();
	return 0;
}
