#include <bits/stdc++.h>

using namespace std;

#define ll long long int

#define sz(x) (int) x.size()

template <typename T>
struct Point2D{
	T x,y;

	Point2D(){};

	Point2D(T _x ,T _y){
		x = _x;
		y = _y;
	}

	Point2D operator - (const Point2D &other) const {
		return Point2D(this->x - other.x , this->y - other.y);
	}
	
	bool operator < (const Point2D &other) const{
		return y < other.y || (y == other.y && x < other.x);
	}
};

template<typename T>
int sign(T t){
	if(t > 0) return 1;
	if(t  == 0) return 0;
	return -1;
}

template<typename T>
int orientation(const Point2D<T> & A ,Point2D<T>& B ,const Point2D<T> & C){
	auto v1 = B - A;
	auto v2 = C - A;
	// v1.x v1.y
	// v2.x v2.y
	return sign(v1.x*v2.y - v1.y*v2.x); 
}


int n,m;

int prev(int i){
	return (i - 1 + n)%n;
}
int next(int i ){
	return (i+1)%n;
}

template <typename T>
T dot_product(const Point2D<T> &A , const Point2D<T> &B){
	return A.x*B.x + A.y*B.y;
}

template <typename T>
bool is_in(const Point2D<T> &A,const Point2D<T> &B,const Point2D<T> &C){
	auto u = C-A;
	auto v = C-B;
	return sign(dot_product(u,v)) <= 0;
}

template <typename T>
bool insise_polygon_handle_overflow(const vector<Point2D<T>> &vertices,const Point2D <T> &p){
    n = sz(vertices);
    int cnt = 0;
    for(int i = 0 ; i < n ; i++){
        auto p1 = vertices[i];
        auto p2 = vertices[next(i)];
        if(p1.y == p2.y) continue;
        if( p.y >= min(p1.y,p2.y) && p.y < max(p1.y,p2.y)){
            Point2D<T> pmin = min(p1,p2);
            Point2D<T> pmax = max(p1,p2);
            if( orientation(pmin,pmax,p) >= 0){
                cnt++;
            }
        } 
    }
    return cnt % 2 == 1;
}

void solve(){
	cin>>n>>m;
	vector<Point2D<ll>> P(n);
	for(int i = 0 ; i < n ; i++){
		ll x,y; cin>>x>>y;
		P[i] = {x,y};
	}
	while(m--){
		ll x,y; cin>>x>>y;
		Point2D<ll> p = {x,y};
		bool flag = false;
		for(int i = 0 ; i < n ; i++){
			auto p1 = P[i];
			auto p2 = P[next(i)];
			if (orientation(p1,p2,p)  == 0 && is_in(p1,p2,p)){
				cout<<"BOUNDARY"<<"\n";
				flag = true;
				break;
			}
		}
		if(flag) continue;
		
		bool ans = insise_polygon_handle_overflow(P,p);
		if (ans) cout<<"INSIDE"<<"\n";
		else cout<<"OUTSIDE"<<"\n";
	}
	
}


int main(){
	int t = 1; //cin>>t;
	while(t--){
		solve();
	}
	
	return 0;	
}


