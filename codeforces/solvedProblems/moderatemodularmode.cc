#include <bits/stdc++.h>

using namespace std;


void solve(){
    long long x, y;
    cin >> x >> y;
    if(x > y){
        cout << (long long) x+y << endl;
    }
    else{
        cout << (long long) (x*floor(y/x)+y)/2 << endl;
    }
}


int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    } 
}