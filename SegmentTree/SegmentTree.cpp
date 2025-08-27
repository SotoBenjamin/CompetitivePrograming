#include <bits/stdc++.h>
#define fi first
#define se second
#define DBG(x) cout << #x << " = " << x << '\n';
#define DBGS(x) cout << #x << " = " << x << ", ";
#define all(x) x.begin() , x.end()
#define NEUTRAL 0LL
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<pair<int,int>> vpii;
typedef vector<ll> vl;
typedef vector<pair<ll,ll>> vpll;
     

     
struct Node{
	int l,r;
	ll value;
};


struct SegmentTree{
	vector<Node> st;
	int sz;	
	SegmentTree(){}
	
	
	SegmentTree(vector<ll>& a){
		sz = 1;
		int n = a.size();
        //DBG(n);
		while(sz < n) sz*=2;
        //DBG(sz);
		st.resize(2*sz);
		for(int i = 0 ; i < st.size() ; ++i){
			st[i] = {-1,-1,NEUTRAL};
		}
		build(a,1,0,sz-1);
	}

    void build(vector<ll>& a, int i , int tl, int tr){
		if(tl == tr){
			if(tl < a.size()) st[i].value = a[tl]; //operation
			else st[i].value = NEUTRAL;
			st[i].l = tl;
			st[i].r = tr;
			return;
		}
		int m = (tl+tr)/2;
		build(a,2*i,tl,m);
		build(a,2*i+1,m+1,tr);
		st[i].value = st[i*2].value + st[i*2+1].value; //operation
		st[i].l = tl;
		st[i].r = tr;
	}


	ll query(int i,int lq,int rq){
		if( lq > rq) return NEUTRAL;
		if(st[i].l == lq && st[i].r == rq){
			return st[i].value;
		}
		int m = (st[i].l + st[i].r) / 2;
		return query(2*i , lq, min(rq,m)) + query(2*i + 1 , max(lq,m+1) , rq); // operation
	}
	
	void update(int i , int pos, ll x){
		if(st[i].l == st[i].r){
			st[i].value = x;
			return;
		}
		int m = (st[i].l + st[i].r) / 2;
		if(pos <= m) update(2*i,pos,x);
		else update(2*i + 1,pos,x);
		st[i].value = st[2*i].value + st[2*i+1].value; //operation
	}

	ll query(int lq , int rq){
        //cout<<"xd"<<endl;
		return query(1,lq,rq);
	}
	
	void update(int pos, ll x){
		update(1,pos,x);
	}
};




void slv(){
   int n,m; cin>>n>>m;
   vector<ll> a(n);
   for(int i = 0 ; i < n ; i++) cin>>a[i];
   SegmentTree st(a);
   while(m--){
      int type;
      cin>>type;
      if(type == 1){
        int id; ll v;
        cin>>id>>v;
        st.update(id,v);
      }
      else{
        int l,r; cin>>l>>r;
        ll x = st.query(l,r-1);
        cout<<x<<"\n";
      }
   }
}


     
int main(){
    int t = 1; //cin>>t;
    while(t--) slv();
    return 0;
}
