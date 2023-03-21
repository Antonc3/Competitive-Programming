#include <bits/stdc++.h>
using namespace std;

int n,k;

bool check(double x, vector<int> &arr){
    int cnt = 0;
    for(int i : arr){
        cnt+=(int) ((double) i / x);
    }
    if(cnt >= k) return true;
    return false;
}

int main(){
    cin >> n >> k;
    vector<int> arr(n);
    for(int &x : arr) cin >> x;
    double l = 0, r = 1e7;
    double best = 0;
    for(int i = 0; i < 300; i++){
        double mid = (l+r)/2;
        if(check(mid, arr)){
            best = mid;
            l = mid; 
        }
        else{
            r = mid;
        }
    }
    cout << setprecision(10) << best << endl;
}
