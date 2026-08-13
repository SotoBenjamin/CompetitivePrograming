#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;


template<typename T>
struct Point{
	T x,y;
	Point(T xx, T yy) : x(xx) , y(yy) {};
	Point<T> operator + (Point<T>& o){ 
		return {this->x + o.x , this->y + o.y};
	};
	
		
};


int main(){
	Point<int> p1(1,3) , p2(2,3);
	Point<int> p = p1 + p2;
	
	return 0;
}
