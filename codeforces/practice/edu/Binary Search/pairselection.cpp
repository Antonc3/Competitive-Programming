#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
typedef pair<int,int> pii;
#define F first
#define S second

int n,k;
vector<pii> v;

bool check(double val){
    vector<double> arr;
    for(int i = 0; i < n; i++){
        arr.push_back(1.0*v[i].F-v[i].S*val);
    }
    sort(arr.begin(),arr.end(), greater<double>());
    double sum = 0;
    for(int i = 0; i < k; i++){
        sum+=arr[i];
    }
    return sum >= 0;
}

int main(){
    cin >> n >> k;
    for(int i =0; i < n; i++){
        int a,b;
        cin >> a >> b;
        v.push_back({a,b});
    }
    double l = 0.0, r = 1e9;
    double best = 0;
    for(int i=0;i<100;i++){
        double mid = (l+r)/2;
        if(check(mid)){
            l = mid;
            best = l;
        }
        else{
            r = mid;
        }
    }
    cout << setprecision(10) << best << endl;
}
