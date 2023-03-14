#include <bits/stdc++.h>
using namespace std;
typedef pair<double,double> pii;
#define F first
#define S second
typedef long long ll;

ll INF = 1e9;
int n;
vector<int> x;
vector<int> v;

pii intersect(pii a, pii b){
    return {max(a.F,b.F),min(a.S,b.S)};
}

bool check(double val){
    //cout << "checking val: " << val << endl;
    pii cur = {-1e9,1e9};
    for(int i = 0; i < n; i++){
        double lb = max(-1.0*INF,1.0*x[i]-val*v[i]);
        double ub = min(+1.0*INF,1.0*x[i]+val*v[i]);
        //cout << "lb: " << lb << " ub " << ub << endl;
        cur = intersect(cur,{lb,ub});
        if(cur.F > cur.S) return false;
    }
    return true;
}

int main(){
    cin >> n;
    for(int i =0 ; i < n; i++){
        int a,b;
        cin >> a >> b;
        x.push_back(a);
        v.push_back(b);
    }
    double l = 0, r = 2e9;
    double best = r;
    for(int i = 0; i < 100; i++){
        double mid = (l+r)/2;
        if(check(mid)){
            r = mid;
            best = mid;
        }
        else{
            l = mid;
        }
    }
    cout << setprecision(10) << best << endl;
}
