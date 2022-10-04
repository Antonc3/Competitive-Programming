#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    int r3 = n-2;
    int r1 = r3/3;
    int r2 = r3-r1-2;
    // cout << "1: " << r1 << ", 2: " << r2 << " 3: " << 1 << endl;
    cout << min(abs(r2-r1),min(abs(r2-1),abs(r1-1)))<<endl;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}