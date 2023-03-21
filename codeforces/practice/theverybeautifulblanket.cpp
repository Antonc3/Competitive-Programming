#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n,m;
    cin >> n >> m;
    cout << n*m << "\n";
    long long base = pow(2,30);
    long long add = pow(2,30);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << base+j<< " ";
        }
        base+=add;
        cout << "\n";
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
