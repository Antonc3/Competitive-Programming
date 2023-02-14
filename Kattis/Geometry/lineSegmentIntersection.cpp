#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<double, double> pdd;
#define F first
#define S second

template<class T> int sgn(T x) {return (x>0)-(x<0);}

double cross(pdd a, pdd b){
	return (a.F*b.S-a.S*b.F);
}

double dot(pdd a, pdd b){
	return a.F*b.F+a.S+b.S;
}

pdd scalar(pdd a, double num){
	return {a.F*num, a.S*num};
}

pdd add(pdd a, pdd b){
	return {a.F+b.F, a.S+b.S};
}

pdd sub(pdd a, pdd b){
	return {a.F-b.F,a.S-b.S};
}

bool onsegment(pdd s, pdd e, pdd check){
	bool colin = (cross(sub(s,check),sub(e,check))) == 0;
	bool onseg = colin && dot(sub(s,check),sub(e,check)) <= 0;
	return onseg;
}

void solve(){
	pdd a,b,c,d;
	cin >> a.F >> a.S >> b.F >> b.S >> c.F >> c.S >> d.F >> d.S;
	double oa = cross(sub(b,a),sub(c,a));
	double ob = cross(sub(b,a),sub(d,a));
	double oc = cross(sub(d,c),sub(a,c));
	double od = cross(sub(d,c),sub(b,c));
	if(sgn(oa)*sgn(ob) < 0 && sgn(oc)*sgn(od) < 0){
		pdd intersection = scalar(sub(scalar(a,od),scalar(b,oc)),1/(od-oc));
		if(abs(intersection.F) <= 1e-3) intersection.F = 0.0;
		if(abs(intersection.S) <=1e-3) intersection.S = 0.0;
		printf("%.2f %.2f\n", intersection.F, intersection.S);
		return;
	}
  set<pdd> ans;
	if(onsegment(a,b,c)) ans.insert(c);
	if(onsegment(a,b,d)) ans.insert(d);
	if(onsegment(c,d,a)) ans.insert(a);
	if(onsegment(c,d,b)) ans.insert(b);
	if(ans.size() == 0){
		printf("none\n");
		return;
	}
	for(pdd pnt : (ans)){
		if(abs(pnt.F) <= 1e-3) pnt.F = 0.0;
		if(abs(pnt.S) <=1e-3) pnt.S = 0.0;
		printf("%.2f %.2f ", pnt.F, pnt.S);
	}
	printf("\n");
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}
