#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const bool DEBUG = false;
int n,d;
vector<int> arr;

int bl, br;
bool check(double val){
    if(DEBUG) cout << "checking: " << val << endl;
    vector<double> prefix(n+1,0);
    vector<double> m(n+2,0);
    vector<int> strt(n+2,0);
    prefix[0] = 0;
    m[0] = 0;
    strt[0] = 0;
    
    if(DEBUG) cout << prefix[0] << " ";
    for(int i = 1; i <= n; i++){
        prefix[i] = prefix[i-1]+arr[i-1]-val;
        strt[i] = strt[i-1];
        m[i] = m[i-1];
        if(DEBUG) cout << prefix[i] << " ";
        if(prefix[i] < m[i]){
            m[i] = prefix[i];
            strt[i] = i;
        }
    }
    if(DEBUG) cout <<endl<<"m[] ";
    for(int i =0; i < n; i++){
        if(DEBUG) cout << m[i] << " ";
    }
    if(DEBUG) cout << endl;
    for(int r = d; r <= n; r++){
        if(DEBUG) cout << "prefix[r] " << prefix[r] << " m[r-d] " << m[r-d-1] << endl;
        if(prefix[r] >= m[r-d]){
            if(DEBUG) cout << "r: " << r << endl;
            bl = strt[r-d]+1;
            br = r;
            return true;
        }
    }
    return false;
}

int main(){
    cin >> n >> d;
    arr = vector<int>(n);
    for(int &x : arr) cin >> x;
    double l = 0, r = 1e9;
    double best = 0;
    for(int i =0 ; i < 100; i++){
        double mid = (l+r)/2;
        if(check(mid)){
            best = mid;
            l = mid;
        }
        else{
            r = mid;
        }
    }
    check(best);
    if(DEBUG) cout << best << endl;
    cout << bl << " " << br << endl;
}
