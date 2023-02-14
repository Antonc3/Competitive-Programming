#include <bits/stdc++.h>

using namespace std; 
typedef long long ll; 
ll n, m, A[65][65];

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cin >> n >> m; 
    for (ll i = 1; i <= n; ++i) 
    for (ll j = 1; j <= m; ++j) cin >> A[i][j]; 

    ll cnt0 = 0, cnt1 = 0, cnt2 = 0; 
    for (ll i = 1; i <= n; ++i) 
    for (ll j = 1; j <= m; ++j) 
    if (A[i][j] == 0) ++cnt0; 
    else if (A[i][j] == 1) ++cnt1; 
    else ++cnt2; 

    if (cnt0 >= 2) cout << 0; 
    else if (cnt0 == 1) {
        if (n == 1) {
            ll minn = 1000;
            if (A[1][1] != 0) minn = min(minn, A[1][1]); 
            if (A[1][m] != 0) minn = min(minn, A[1][m]); 
            cout << minn; 
        }
        else if (m == 1) {
            ll minn = 1000; 
            if (A[1][1] != 0) minn = min(minn, A[1][1]); 
            if (A[n][1] != 0) minn = min(minn, A[n][1]); 
            cout << minn; 
        }
        else if (cnt1) cout << 1; 
        else cout << 2; 
    }
    else {
        if (cnt2 % 2 == 0) cout << 0; 
        else cout << (1LL << (cnt2 / 2)); 
    }
}