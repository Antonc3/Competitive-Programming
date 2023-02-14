#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template<class T>
struct Point {
typedef Point P;
T x, y;
explicit Point(T x=0, T y=0) : x(x), y(y) {}
bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
P operator+(P p) const { return P(x+p.x, y+p.y); }
P operator-(P p) const { return P(x-p.x, y-p.y); }
P operator*(T d) const { return P(x*d, y*d); }
P operator/(T d) const { return P(x/d, y/d); }
T dot(P p) const { return x*p.x + y*p.y; }
T cross(P p) const { return x*p.y - y*p.x; }
T cross(P a, P b) const { return (a-*this).cross(b-*this); }
T dist2() const { return x*x + y*y; }
double dist() const { return sqrt((double)dist2()); }
// angle to x−axis in interva l [−pi , pi ]
double angle() const { return atan2(y, x); }
P unit() const { return *this/dist(); } // makes d is t ()=1
P perp() const { return P(-y, x); } // rotates +90 degrees
P normal() const { return perp().unit(); }
// returns point rotated ’a ’ radians ccw around the origin
P rotate(double a) const {
return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
friend ostream& operator<<(ostream& os, P p) {
return os << "(" << p.x << "," << p.y << ")"; }
};

typedef Point<double> P;
double segDist(P& s, P& e, P& p) {
if (s==e) return (p-s).dist();
auto d = (e-s).dist2(), t = min(d,max(.0,(p-s).dot(e-s)));
return ((p-s)*d-(e-s)*t).dist()/d;
}

template<class P> bool onSegment(P s, P e, P p) {
  return segDist(s,e,p) < 1e-10;  
}
template<class P>
bool inPolygon(vector<P> &p, P a, bool strict = true) {
  int cnt = 0, n = sz(p);
  rep(i,0,n) {
    P q = p[(i + 1) % n];
    if (segDist(p[i] , q , a) <= 1e-10) return !strict;
    cnt ^= ((a.y<p[i].y) - (a.y<q.y)) * a.cross(p[i], q) > 0;
  }
  return cnt;
}

template<class T>
T polygonArea2(vector<Point<T>>& v) {
T a = v.back().cross(v[0]);
rep(i,0,sz(v)-1) a += v[i].cross(v[i+1]);
return a;
}

int n;
vector<P> points;

vector<P> createPolygon(int sides, double dist){
  vector<P> toReturn;
  Point<double> start = Point<double>(dist,0);
  for(int i = 0; i < sides; i++){
    toReturn.push_back(start);
    start = start.rotate(2*M_PI/sides);
  }
  return toReturn;
}

int pointsInPolygon(vector<P> polygon, bool strict){
  int cnt = 0;
  for(int i = 0; i < points.size(); i++){
    // cout << points[i] << endl;
    // cout << inPolygon(polygon,points[i],strict)<<endl;
    if(inPolygon(polygon,points[i],strict)){
      cnt++;
    }
    // cout << cnt << endl;
  }
  return cnt;
}

void solve(){
  cin >> n;
  for(int i = 0; i < n; i++){
    double x,y;
    cin >> x >> y;
    points.push_back(P(x,y));
  }
  double ans = 0.0;
  int sides = 0;
  for(int i = 3; i <= 8; i++){
    vector<Point<double>> innerPolygon; 
    double l = 0.0, h = 1000000.0;
    while(h-l >= 1e-10){
      double mid = (h+l)/2;
      innerPolygon = createPolygon(i,mid);
      if(pointsInPolygon(innerPolygon, true)==0){
        l = mid;
      }
      else{
        h = mid;
      }
    }
    vector<Point<double>> outerPolygon; 
    l = 0.0, h = 1000000.0;
    while(h-l >= 1e-10){
      double mid = (h+l)/2;
      outerPolygon = createPolygon(i,mid);
      if(pointsInPolygon(outerPolygon, false)==n){
        h = mid;
      }
      else{
        l = mid;
      }
    }
    double parea = polygonArea2(innerPolygon)/polygonArea2(outerPolygon);
    if(parea > ans){
      sides = i;
      ans = parea;
    }
    
  }
  cout << setprecision(10)<<sides << " " << ans << endl;
}

int main() {
  solve();
}
